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
    <title>Planification de repas</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Menus de la semaine</h1>
    <h2>Pour cette semaine vous sont proposés...</h2>
    <div class="rangée">
    <div class="card">
        <h3>Les entrées</h3>
        <ul>
        <?php echo display_sorted($entrées); ?>
        </ul>
    </div>
    <div class="card">
        <h3>Les plats</h3>
        <ul>
        <?php echo display_sorted($plats); ?>
        </ul>
    </div>
    <div class="card">
        <h3>Les desserts</h3>
        <ul>
        <?php echo display_sorted($desserts); ?>
        </ul>
    </div>
    </div>
    <h2>Pour générer votre liste de menu pour les midis de la semaine, cliquez sur ce bouton : </h2>
    <button type="button" class ="button_index" onclick="window.location.href='menu.php'">Générer les menus</button>
</body>

</html>