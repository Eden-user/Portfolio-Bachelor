#include <Wire.h> // Communication I2C pour l'écran OLED
#include <Adafruit_GFX.h> // Fonctions graphiques de base
#include <Adafruit_SSD1306.h> // Contrôle de l'écran SSD1306
#include <EEPROM.h> // Stockage de données persistantes (high score)

// Configuration de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Définition des broches des boutons et LEDs
const int buttonPins[4] = { 13, 12, 14, 27 }; // Boutons de couleur
const int ledPins[4] = { 32, 33, 26, 15 }; // LEDs correspondantes
const int buzzerPin = 25; // Buzzer pour les sons

// Boutons de contrôle du menu
const int btnDiffUp = 19;  // Changer difficulté
const int btnReset = 18;   // Réinitialiser partie
const int btnStart = 17;   // Démarrer partie
const int btnVolume = 16;  // Changer le volume

// Variables de jeu
int pattern[100]; // Stocke la séquence à reproduire
int level = 0;    // Niveau actuel
int highScore = 0; // Meilleur score sauvegardé
int difficulty = 1; // 1=Facile, 2=Moyen, 3=Difficile, 4=Infini
int volume = 2;     // 1=Bas, 2=Moyen, 3=Fort
bool inGame = false; // Le jeu est-il en cours ?

// Anti-rebond pour les boutons
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200;

// Déclarations de fonctions
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
  Serial.begin(115200);

  // Configuration des boutons et LEDs
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT);
  pinMode(btnVolume, INPUT_PULLUP);
  pinMode(btnDiffUp, INPUT_PULLUP);
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnReset, INPUT_PULLUP);

  // Lecture du high score
  EEPROM.begin(4);
  highScore = EEPROM.read(0);

  // Initialisation de l'écran OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Erreur écran OLED"));
    while (true);
  }

  randomSeed(analogRead(0)); // Initialisation aléatoire
  drawMenu(); // Affiche le menu principal
}

void loop() {
  if (!inGame) {
    static bool btnPressed = false;

    // Anti-rebond
    if (millis() - lastDebounceTime < debounceDelay) return;

    if (digitalRead(btnDiffUp) == LOW && !btnPressed) {
      difficulty = (difficulty % 4) + 1;
      drawMenu();
      btnPressed = true;
      lastDebounceTime = millis();
    } else if (digitalRead(btnVolume) == LOW && !btnPressed) {
      volume = (volume % 3) + 1;
      drawMenu();
      btnPressed = true;
      lastDebounceTime = millis();
    } else if (digitalRead(btnStart) == LOW && !btnPressed) {
      startGame();
      btnPressed = true;
      lastDebounceTime = millis();
    } else if (digitalRead(btnDiffUp) == HIGH &&
               digitalRead(btnVolume) == HIGH &&
               digitalRead(btnStart) == HIGH) {
      btnPressed = false;
    }
  } else {
    playGame();
  }
}

// Affiche le menu principal sur l'écran OLED
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

// Retourne le nom de la difficulté
String getDifficultyLabel() {
  switch (difficulty) {
    case 1: return "Easy";
    case 2: return "Medium";
    case 3: return "Hard";
    case 4: return "Infinite";
  }
  return "Unknown";
}

// Retourne le niveau de volume actuel
String getVolumeLabel() {
  switch (volume) {
    case 1: return "Low";
    case 2: return "Medium";
    case 3: return "High";
  }
  return "Unknown";
}

// Niveau maximum à atteindre selon la difficulté
int getMaxLevel() {
  switch (difficulty) {
    case 1: return 20;
    case 2: return 30;
    case 3: return 50;
    default: return 1000;
  }
}

// Lancer une nouvelle partie
void startGame() {
  inGame = true;
  level = 0;
  pattern[0] = random(0, 4);
}

// Fonction principale du jeu
void playGame() {
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

  for (int i = 0; i <= level; i++) {
    int input = waitForButton();
    if (input == -1 || input != pattern[i]) {
      gameOver();
      return;
    }
  }

  level++;
  if (difficulty != 4 && level >= getMaxLevel()) {
    celebrateVictory();
    return;
  }

  if (level < 100) {
    pattern[level] = random(0, 4);
  }

  delay(800);
}

// Attend un bouton de couleur et retourne son index
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

// Affiche la couleur sélectionnée sur l'OLED
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

// Joue le son correspondant à la couleur
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

// Calcule le délai en fonction de la difficulté
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

// Écran de fin de partie
void gameOver() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.setTextColor(SSD1306_WHITE);
  display.println("Game Over!");
  display.display();

  tone(buzzerPin, 200, 500);
  delay(1000);

  if (level > highScore) {
    highScore = level;
    EEPROM.write(0, highScore);
    EEPROM.commit();
  }

  inGame = false;
  drawMenu();
}

// Affiche un écran de victoire 
void celebrateVictory() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.setTextColor(SSD1306_WHITE);
  display.println("Congratulations!");
  display.setCursor(10, 30);
  display.println("You beat the game!");
  display.display();

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
