<h1>Companion - Task Manager</h1>

Gestionnaire de tâches web avec système de gamification développé dans le cadre de l'examen de développement web en B1 à l'École Hexagone.

</div>

---

<h2>Concept</h2>

Application web de gestion de tâches avec une mascotte (Barnaby, un ours en peluche violet) dont l'humeur change en fonction de la productivité de l'utilisateur. Le concept mêle fonctionnalité et gamification avec un ton volontairement sarcastique.

<h2>Technologies utilisées</h2>

<table>
<tr>
<td><strong>PHP</strong></td>
<td>Logique serveur et gestion de sessions</td>
</tr>
<tr>
<td><strong>MySQL</strong></td>
<td>Base de données (PDO)</td>
</tr>
<tr>
<td><strong>HTML5/CSS3</strong></td>
<td>Interface utilisateur</td>
</tr>
<tr>
<td><strong>JavaScript/jQuery</strong></td>
<td>Interactions dynamiques (overlays, slideshow)</td>
</tr>
</table>

<h2>Fonctionnalités</h2>

<h3>Gestion utilisateur</h3>
<ul>
  <li>
    Inscription et connexion sécurisée
  </li>
  <li>
    Hash des mots de passe (password_hash)
  </li>
  <li>
    Système de sessions
  </li>
</ul>

<h3>Gestion des tâches</h3>
<ul>
  <li>
    Création, suppression de tâches
  </li>
  <li>
    Description, date d'échéance
  </li>
  <li>
    Marquage complétion (checkbox)
  </li>
  <li>
    Filtrage : toutes/complétées/en attente
  </li>
</ul>

<h3>Système de catégories</h3>
<ul>
  <li>
    Création de catégories personnalisées
  </li>
  <li>
    Suppression de catégories (tâches réassignées automatiquement)
  </li>
  <li>
    Catégorie par défaut
  </li>
</ul>

<h3>Gamification</h3>
<ul>
  <li>
    Mascotte Barnaby dont l'état change selon la productivité
  </li>
  <li>
    Slideshow automatique entre différents états (Happy/Unhappy/Dead)
  </li>
</ul>

<h2>Structure de la base de données</h2>

```sql
users
├── id_user (PK)
├── firstName, lastName
├── email
├── password (hashé)
└── timestamps

categories
├── id_category (PK)
└── categoryName

tasks
├── id_task (PK)
├── id_user (FK)
├── id_category (FK)
├── taskName
├── taskDescription
├── dueDate
└── Completion (boolean)
```

<h2>Architecture du projet</h2>

```
companion/
├── index.php              # Page principale
├── header.php             # Navigation et session
├── footer.php             # Pied de page
├── database.php           # Connexion PDO
├── login.php / register.php / logout.php
├── get_data.php           # Récupération et affichage des tâches
├── newtask.php            # Formulaire création tâche (overlay)
├── newcategory.php        # Formulaire création catégorie (overlay)
├── complete.php           # Mise à jour statut tâche
├── delete_task.php        # Suppression tâche
├── delete_categ.php       # Suppression catégorie
├── pet.php                # Page présentation Barnaby
├── about.php              # À propos (ton sarcastique)
├── style.css              # Styles
├── index.js               # jQuery (overlays, slideshow)
└── Eden-BDD-taskmanager.sql
```

## Points techniques

<details>
<summary><strong>Sécurité</strong></summary>

- Hachage des mots de passe
- Requêtes préparées (protection SQL injection)
- Échappement des entrées utilisateur (htmlspecialchars)
- Gestion des sessions

</details>

<details>
<summary><strong>Base de données</strong></summary>

- Relations entre tables (clés étrangères)
- Transactions SQL pour suppressions complexes
- Réassignation automatique lors de suppression de catégorie

</details>

<details>
<summary><strong>UX/UI</strong></summary>

- Overlays modaux pour formulaires (jQuery)
- Filtrage dynamique des tâches
- Design responsive
- Thème visuel cohérent

</details>

<details>
<summary><strong>JavaScript</strong></summary>

- Affichage/masquage overlays
- Slideshow automatique des images
- Soumission automatique checkbox

</details>

## Fonctionnalités non implémentées

- Système de mise à jour des tâches (overlay préparé mais non fonctionnel)
- Logique précise de changement d'état de Barnaby basée sur la productivité réelle
- Système de récurrence des tâches

## Compétences démontrées

- Architecture MVC simplifiée (séparation logique/présentation)
- CRUD complet (Create, Read, Update, Delete)
- Gestion d'authentification
- Manipulation base de données relationnelle
- JavaScript/jQuery pour interactions dynamiques
- Design d'interface utilisateur
- Gestion de projet web complet
