<div align="center">

# Cyberpunk Simulator 2.0

Jeu de rôle textuel en C++ inspiré de l'univers Cyberpunk.  
Projet libre en B1 à l'École Hexagone - Objectif : créer un jeu de rôle en POO.

</div>

---

## Description

Simulateur RPG en ligne de commande où le joueur incarne un mercenaire dans un univers cyberpunk. Projet développé librement pour appliquer les concepts de programmation orientée objet : le jeu propose un système de classes, de missions aléatoires, d'améliorations et de sauvegarde/chargement de personnage.

## Technologies utilisées

<table>
<tr>
<td><strong>C++</strong></td>
<td>Langage principal</td>
</tr>
<tr>
<td><strong>POO</strong></td>
<td>Héritage, polymorphisme, encapsulation</td>
</tr>
<tr>
<td><strong>STL</strong></td>
<td>Vectors, strings, file streams</td>
</tr>
</table>

## Fonctionnalités

**Système de personnage**
- Création de personnage avec nom personnalisé
- Choix de classe de mercenaire (Solo, NetRunner, Techie)
- Statistiques : points de vie, réputation, argent, force d'attaque
- Bonus de classe spécifiques

**Gameplay**
- Système de missions aléatoires avec difficulté variable
- Récompenses (argent, réputation) basées sur la réussite
- Système de combat entre personnages
- Améliorations achetables (augmentations cybernétiques)

**Sauvegarde**
- Système de sauvegarde dans fichier texte
- Chargement de partie sauvegardée
- Persistance des statistiques du personnage

## Architecture orientée objet

```
Classes principales :
├── Character (classe de base)
│   ├── Attributs : firstName, lastName, lifePoints, reputation, money, attackPoints
│   └── Méthodes : displayStats(), receiveDamages(), attack()
│
├── Mercenary (hérite de Character)
│   ├── Attribut supplémentaire : mercenaryType
│   └── Méthodes : bonus() selon le type, getStats() pour sauvegarde
│
├── Mission
│   ├── Attributs : difficulty, cashReward, reputationReward
│   └── Méthode : executeMission() avec calcul aléatoire
│
├── Increase (améliorations)
│   ├── Attributs : name, bonusType, bonusValue, price
│   └── Méthode : applyEffect() sur un Character
│
└── Game (gestionnaire)
    └── Méthodes : menu(), newGame(), load(), save()
```

## Structure du projet

```cpp
cyberpunk-simulator/
├── main.cpp              // Point d'entrée
├── Game.cpp / .hpp       // Gestion menu et sauvegarde
├── Character.cpp / .hpp  // Classe de base personnage
├── Mercenary.cpp / .hpp  // Classe joueur (héritage)
├── Mission.cpp / .hpp    // Système de missions
├── Increase.cpp / .hpp   // Améliorations cybernétiques
└── character.txt         // Fichier de sauvegarde
```

## Classes de mercenaire

<table>
<tr>
<th>Classe</th>
<th>Description</th>
<th>Bonus</th>
</tr>
<tr>
<td><strong>Solo</strong></td>
<td>Spécialiste combat</td>
<td>+1 point d'attaque</td>
</tr>
<tr>
<td><strong>NetRunner</strong></td>
<td>Hacker</td>
<td>+5 réputation</td>
</tr>
<tr>
<td><strong>Techie</strong></td>
<td>Bricoleur</td>
<td>+10 points de vie</td>
</tr>
</table>

## Concepts POO appliqués

<details>
<summary><strong>Héritage</strong></summary>

- `Mercenary` hérite de `Character`
- Réutilisation du code et spécialisation
- Constructeurs avec liste d'initialisation

</details>

<details>
<summary><strong>Encapsulation</strong></summary>

- Attributs `protected` dans les classes
- Méthodes publiques pour accéder/modifier les données
- Gestion cohérente de l'état des objets

</details>

<details>
<summary><strong>Gestion mémoire</strong></summary>

- Destructeurs définis pour chaque classe
- Passage par référence (`Character &target`) pour éviter les copies

</details>

<details>
<summary><strong>STL et fichiers</strong></summary>

- Utilisation de `vector<string>` pour la sauvegarde
- Flux de fichiers (`ifstream`, `ofstream`)
- Manipulation de strings

</details>

## Fonctionnalités implémentées

- Création et personnalisation du personnage
- Système de classes avec bonus
- Missions aléatoires avec calcul de difficulté
- Combat entre personnages
- Système d'améliorations (increases)
- Sauvegarde et chargement de partie

## Améliorations possibles

- Implémenter la génération aléatoire d'améliorations
- Ajouter un système d'inventaire complet
- Développer plusieurs types de missions
- Créer des PNJ ennemis générés aléatoirement
- Ajouter une boucle de jeu principale
- Implémenter un système de progression par niveau
- Système d'armes équipables (composition d'objets)

## Compétences démontrées

- Programmation orientée objet en C++
- Conception de hiérarchie de classes
- Gestion de fichiers (lecture/écriture)
- Génération de nombres aléatoires
- Manipulation de la STL

- Architecture logicielle modulaire
