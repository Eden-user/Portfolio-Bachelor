# Simon Game - ESP32

Réimplémentation du jeu électronique Simon sur ESP32 avec écran OLED et boîtier imprimé en 3D.  
Projet de fin d'année en B1 à l'École Hexagone.

</div>

---

## Description

Clone du jeu de mémoire Simon utilisant un microcontrôleur ESP32, un écran OLED, 4 boutons/LEDs de couleur et un buzzer. Le projet inclut la conception du boîtier en 3D pour un produit fini complet.

## Matériel utilisé

<table>
<tr>
<td><strong>ESP32</strong></td>
<td>Microcontrôleur principal</td>
</tr>
<tr>
<td><strong>Écran OLED SSD1306</strong></td>
<td>128x64 pixels (I2C)</td>
</tr>
<tr>
<td><strong>4 boutons + LEDs</strong></td>
<td>Rouge, Bleu, Vert, Jaune</td>
</tr>
<tr>
<td><strong>Buzzer piézo</strong></td>
<td>Retour sonore</td>
</tr>
<tr>
<td><strong>Boîtier imprimé 3D</strong></td>
<td>Modèle .3mf inclus</td>
</tr>
</table>

## Fonctionnalités

**Gameplay**
- Reproduction fidèle du jeu Simon
- Séquences de couleurs croissantes à mémoriser
- Retour visuel (LEDs) et sonore (buzzer)
- Écran OLED pour affichage des informations

**Modes de jeu**
- **Facile** : 20 niveaux, délai 1000ms
- **Moyen** : 30 niveaux, délai 600ms
- **Difficile** : 50 niveaux, délai 300ms
- **Infini** : vitesse progressive jusqu'à 150ms

**Paramètres**
- 3 niveaux de volume (Low/Medium/High)
- Sauvegarde du high score en EEPROM
- Menu de navigation complet
- Bouton reset en cours de partie

**Interface**
- Menu principal avec paramètres
- Affichage des couleurs sur OLED
- Écran Game Over
- Célébration de victoire avec animations

## Brochage

```
ESP32 Pins:
├── Boutons couleur : 13, 12, 14, 27
├── LEDs : 32, 33, 26, 15
├── Buzzer : 25
├── Boutons contrôle :
│   ├── Difficulté : 19
│   ├── Reset : 18
│   ├── Start : 17
│   └── Volume : 16
└── I2C OLED : SDA/SCL (default)
```

## Structure du code

```cpp
Fonctions principales :
├── setup() : Initialisation hardware et EEPROM
├── loop() : Gestion menu et jeu
├── drawMenu() : Affichage menu OLED
├── playGame() : Boucle de jeu principale
├── waitForButton() : Lecture input joueur
├── showColor() : Affichage sur OLED
├── playTone() : Génération sons
├── gameOver() : Fin de partie
└── celebrateVictory() : Animation victoire
```

## Bibliothèques utilisées

```cpp
#include <Wire.h>              // Communication I2C
#include <Adafruit_GFX.h>      // Graphiques de base
#include <Adafruit_SSD1306.h>  // Contrôle écran OLED
#include <EEPROM.h>            // Sauvegarde high score
```

## Concepts appliqués

<details>
<summary><strong>Programmation embarquée</strong></summary>

- Gestion des entrées/sorties (GPIO)
- Communication I2C avec périphériques
- Gestion des interruptions (debouncing)
- Stockage persistant (EEPROM)

</details>

<details>
<summary><strong>Électronique</strong></summary>

- Montage avec breadboard ou PCB
- Boutons en pull-up
- Contrôle de LEDs
- Buzzer piézo pour le son

</details>

<details>
<summary><strong>Conception 3D</strong></summary>

- Modélisation du boîtier (.3mf)
- Adaptation aux dimensions du hardware
- Impression 3D pour produit fini

</details>

<details>
<summary><strong>Game design</strong></summary>

- Gestion d'états (menu/jeu/game over)
- Difficulté progressive
- Feedback utilisateur (son + visuel)
- Sauvegarde de progression

</details>

## Fichiers du projet

```
simon-game-esp32/
├── jeuSimon.ino           # Code principal (version commentée)
├── sketch_jul4a.ino       # Version alternative
├── boitier_simon.3mf      # Modèle 3D du boîtier
└── README.md
```

## Installation

1. Installer l'IDE Arduino avec support ESP32
2. Installer les bibliothèques Adafruit (GFX + SSD1306)
3. Connecter les composants selon le brochage
4. Téléverser le code sur l'ESP32
5. (Optionnel) Imprimer le boîtier en 3D

## Améliorations possibles

- Ajouter des animations sur l'écran OLED
- Implémenter un mode multijoueur
- Enregistrer plusieurs high scores
- Ajouter des effets sonores variés
- Créer des patterns prédéfinis (mélodies)
- Batterie rechargeable pour version portable
- Du fait de problèmes de soudure le prototype dans le boitier 3D n'a pas fonctionné le jour de l'examen, mais la version breadboard était opérationnel

## Compétences démontrées

- Programmation C/C++ pour microcontrôleurs
- Gestion de périphériques (I2C, GPIO)
- Conception électronique
- Modélisation et impression 3D
- Intégration hardware/software
- Gestion de projet complet (code + boîtier)
