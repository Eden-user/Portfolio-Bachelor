<?php
include("config.php");
include("fonctions.php");
include("database.php");
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Menus</title>
    <link rel="stylesheet" href="styles.css">
</head>
<section>
    <h1>Menus planifiés cette semaine</h1>
    <div class="grille">
        <?php generate_week($entrées, $plats, $desserts, $jours); ?>
        <div class="card menu_card">
            <button type="button" onclick="window.location.href='menu.php'">Générér une autre planification</button>
        </div>
        <div class="card menu_card">
            <button type="button" onclick="window.location.href='index.php'">Retour à l'accueil</button>
        </div>
    </div>


</section>

</html>