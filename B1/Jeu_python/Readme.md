<h1>Flappy Birb</h1>
Clone du jeu Flappy Bird développé en Python avec Pygame dans le cadre des cours de B1 à l'École Hexagone.<br>
<h2>Description</h2>
Jeu simple inspiré de Flappy Bird où le joueur contrôle un oiseau qui doit éviter des tuyaux en volant. Le jeu inclut un système de score, un menu de démarrage et un écran de game over.<br>
<h2>Technologies utilisées</h2>

Python 3<br>
Pygame - Bibliothèque pour le développement de jeux 2D<br>

<h2>Fonctionnalités</h2>
<ul>
<li>Menu de démarrage</li>
<li>Contrôle au clavier (ESPACE pour sauter)</li>
<li>Génération procédurale des obstacles</li>
<li>Système de score</li>
<li>Détection de collisions</li>
<li>Écran de game over avec possibilité de recommencer</li>
<li>Physique simple (gravité, vélocité)</li>
</ul>

<h2>Installation et lancement</h2>
<h3>Prérequis</h3>
bash - pip install pygame
<h3>Lancer le jeu</h3>
bash - python birb.py
<h2>Commandes</h2>

ESPACE - Sauter (menu et jeu)<br>
R - Recommencer après un game over<br>
Fermer la fenêtre - Quitter le jeu<br>

<h2>Structure du code</h2>
<h3>Gestion des états du jeu</h3>
<ul>
  <li>
    menu : écran d'accueil
  </li>
  <li>
    playing : jeu en cours
  </li>
  <li>
    game_over : écran de fin
  </li>
</ul>

<h3>Éléments principaux</h3>
<ul>
  <li>
    Bird : rectangle jaune avec physique (gravité, saut)
  </li>
  <li>
    Pipes : obstacles verts générés aléatoirement
  </li>
  <li>
    Ground : sol marron
  </li>
  <li>
    Score : compteur basé sur les tuyaux passés
  </li>
</ul>
<h2>Concepts appliqués</h2>
<ul>
  <li>
Programmation orientée objet : gestion des entités du jeu
  </li>
  <li>
Boucle de jeu : game loop à 60 FPS
  </li>
  <li>
Physique simple : gravité et vélocité
  </li>
  <li>
Génération procédurale : création aléatoire des obstacles
  </li>
  <li>
Gestion d'états : menu, jeu, game over
  </li>
  <li>
Détection de collisions : entre rectangles (rect.colliderect)
  </li>
  <li>
Événements clavier : contrôle du joueur
  </li>
</ul>
<h2>Améliorations possibles</h2>
<ul>
  <li>
Ajouter des sprites graphiques
  </li>
  <li>
Système de high score sauvegardé
  </li>
  <li>
Effets sonores
  </li>
  <li>
Animations de l'oiseau
  </li>
  <li>
Difficulté 
  </li>
  </ul>
