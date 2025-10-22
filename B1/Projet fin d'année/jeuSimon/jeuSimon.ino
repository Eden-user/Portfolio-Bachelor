#include <Wire.h> // Bibliothèque I2C pour communiquer avec l'écran OLED
#include <Adafruit_GFX.h> // Bibliothèque graphique pour dessiner sur l'écran
#include <Adafruit_SSD1306.h> // Contrôle spécifique pour les écrans SSD1306
#include <EEPROM.h> // Utilisé pour stocker le high score même après redémarrage

// Configuration de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Pas de pin de reset utilisée
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Définition des broches
const int buttonPins[4] = { 13, 12, 14, 27 }; // Boutons pour les couleurs (rouge, bleu, vert, jaune)
const int ledPins[4] = { 32, 33, 26, 15 };    // LEDs correspondantes
const int buzzerPin = 25; // Buzzer pour les sons

// Boutons de contrôle
const int btnDiffUp = 19;  // Changer la difficulté
const int btnReset = 18;   // Réinitialiser le jeu
const int btnStart = 17;   // Lancer le jeu
const int btnVolume = 16;  // Changer le volume

// Variables du jeu
int pattern[100]; // Tableau pour stocker la séquence de couleurs
int level = 0;    // Niveau actuel
int highScore = 0; // Meilleur score sauvegardé
int difficulty = 1; // 1 = Facile, 2 = Moyen, 3 = Difficile, 4 = Infini
int volume = 2;     // 1 = Bas, 2 = Moyen, 3 = Fort
bool inGame = false; // Le jeu est-il en cours ?

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200; // Anti-rebond des boutons

// Déclarations des fonctions utilisées plus bas
void drawMenu();
void playGame();
void showColor(int index);
void playTone(int index);
int getDelayTime();
void clearScreen();
void gameOver();
int waitForButton();
void celebrateVictory();
void startGame();
int getMaxLevel();
String getDifficultyLabel();
String getVolumeLabel();

void setup() {
  Serial.begin(115200); // Pour le débogage série

  // Initialisation des boutons et LEDs
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Boutons en pull-up
    pinMode(ledPins[i], OUTPUT); // LEDs en sortie
  }
  pinMode(buzzerPin, OUTPUT);

  // Boutons de contrôle
  pinMode(btnVolume, INPUT_PULLUP);
  pinMode(btnDiffUp, INPUT_PULLUP);
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnReset, INPUT_PULLUP);

  // Lecture du high score sauvegardé
  EEPROM.begin(4);
  highScore = EEPROM.read(0);

  // Initialisation de l’écran OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 failed"));
    while (true); // Boucle infinie en cas d’échec
  }

  randomSeed(analogRead(0)); // Initialisation du générateur aléatoire
  drawMenu(); // Affiche le menu au démarrage
}

void loop() {
  if (!inGame) {
    // Gestion du menu quand le jeu n’est pas lancé
    static bool btnPressed = false;

    if (millis() - lastDebounceTime < debounceDelay) return;

    // Changer la difficulté
    if (digitalRead(btnDiffUp) == LOW && !btnPressed) {
      difficulty = (difficulty % 4) + 1;
      drawMenu();
      btnPressed = true;
      lastDebounceTime = millis();
    }
    // Changer le volume
    else if (digitalRead(btnVolume) == LOW && !btnPressed) {
      volume = (volume % 3) + 1;
      drawMenu();
      btnPressed = true;
      lastDebounceTime = millis();
    }
    // Lancer le jeu
    else if (digitalRead(btnStart) == LOW && !btnPressed) {
      startGame();
      btnPressed = true;
      lastDebounceTime = millis();
    }
    // Réinitialisation de l’état des boutons
    else if (digitalRead(btnDiffUp) == HIGH &&
             digitalRead(btnVolume) == HIGH &&
             digitalRead(btnStart) == HIGH) {
      btnPressed = false;
    }
  } else {
    // Le jeu est en cours
    playGame();
  }
}

// Affiche le menu principal
void drawMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("> Simon Game Menu <");

  display.setCursor(0, 16);
  display.println("  Press Start");

  display.setCursor(0, 26);
  display.print("  Difficulty: ");
  display.println(getDifficultyLabel());

  display.setCursor(0, 36);
  display.print("  Volume: ");
  display.println(getVolumeLabel());

  display.setCursor(0, 46);
  display.print("  High Score: ");
  display.println(highScore);

  display.display();
}

// Retourne le label de difficulté selon la valeur
String getDifficultyLabel() {
  switch (difficulty) {
    case 1: return "Easy";
    case 2: return "Medium";
    case 3: return "Hard";
    case 4: return "Infinite";
  }
  return "Unknown";
}

// Retourne le label du volume
String getVolumeLabel() {
  switch (volume) {
    case 1: return "Low";
    case 2: return "Medium";
    case 3: return "High";
  }
  return "Unknown";
}

// Retourne le niveau maximum selon la difficulté
int getMaxLevel() {
  switch (difficulty) {
    case 1: return 20;
    case 2: return 30;
    case 3: return 50;
    default: return 1000; // Mode infini
  }
}

// Initialise une nouvelle partie
void startGame() {
  inGame = true;
  level = 0;
  pattern[0] = random(0, 4); // Commence avec une couleur aléatoire
}

// Fonction principale du jeu
void playGame() {
  // Affiche la séquence à suivre
  for (int i = 0; i <= level; i++) {
    if (digitalRead(btnReset) == LOW) {
      gameOver();
      return;
    }

    showColor(pattern[i]);
    playTone(pattern[i]);
    digitalWrite(ledPins[pattern[i]], HIGH);
    delay(getDelayTime());
    digitalWrite(ledPins[pattern[i]], LOW);
    clearScreen();
    delay(200);
  }

  // Lecture des entrées utilisateur
  for (int i = 0; i <= level; i++) {
    int input = waitForButton();
    if (input == -1 || input != pattern[i]) {
      gameOver();
      return;
    }
  }

  // Étape suivante
  level++;
  if (difficulty != 4 && level >= getMaxLevel()) {
    celebrateVictory();
    return;
  }

  if (level < 100) {
    pattern[level] = random(0, 4); // Ajoute une nouvelle note
  }

  delay(800);
}

// Attend l'appui d'un des 4 boutons de couleur
int waitForButton() {
  while (true) {
    if (digitalRead(btnReset) == LOW) return -1;

    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        showColor(i);
        playTone(i);
        digitalWrite(ledPins[i], HIGH);
        delay(300);
        digitalWrite(ledPins[i], LOW);
        clearScreen();
        delay(200);
        return i;
      }
    }
  }
}

// Affiche la couleur actuelle sur l'écran OLED
void showColor(int index) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(20, 20);
  display.setTextColor(SSD1306_WHITE);
  if (index == 0) display.println("RED");
  if (index == 1) display.println("BLUE");
  if (index == 2) display.println("GREEN");
  if (index == 3) display.println("YELLOW");
  display.display();
}

// Joue le son correspondant à une couleur
void playTone(int index) {
  int freq = 0;
  switch (index) {
    case 0: freq = 261; break;
    case 1: freq = 329; break;
    case 2: freq = 392; break;
    case 3: freq = 523; break;
  }
  int duration = volume * 100;
  tone(buzzerPin, freq, duration);
}

// Calcule le délai selon la difficulté ou la vitesse croissante (mode infini)
int getDelayTime() {
  if (difficulty == 4) {
    int t = 1000 - level * 20;
    return (t < 150) ? 150 : t;
  }

  switch (difficulty) {
    case 1: return 1000;
    case 2: return 600;
    case 3: return 300;
  }

  return 800;
}

// Efface l'écran OLED
void clearScreen() {
  display.clearDisplay();
  display.display();
}

// Gère la fin de partie
void gameOver() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.setTextColor(SSD1306_WHITE);
  display.println("Game Over!");
  display.display();

  tone(buzzerPin, 200, 500);
  delay(1000);

  // Sauvegarde le score si meilleur
  if (level > highScore) {
    highScore = level;
    EEPROM.write(0, highScore);
    EEPROM.commit();
  }

  inGame = false;
  drawMenu();
}

// Affiche un message de victoire
void celebrateVictory() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.setTextColor(SSD1306_WHITE);
  display.println("Congratulations!");
  display.setCursor(10, 30);
  display.println("You beat the game!");
  display.display();

  // Animation avec LEDs et buzzer
  for (int i = 0; i < 3; i++) {
    for (int l = 0; l < 4; l++) digitalWrite(ledPins[l], HIGH);
    tone(buzzerPin, 880, 300);
    delay(400);
    for (int l = 0; l < 4; l++) digitalWrite(ledPins[l], LOW);
    delay(200);
  }

  if (level > highScore) {
    highScore = level;
    EEPROM.write(0, highScore);
    EEPROM.commit();
  }

  delay(2000);
  inGame = false;
  drawMenu();
}
