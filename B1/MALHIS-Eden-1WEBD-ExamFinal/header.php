<?php
include_once("database.php");
session_start();
function isConnected()
{
    if (isset($_SESSION["id_user"])) {
        return true;
    }
    return false;
}
?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Companion | Task Manager</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <nav>
        <h1><a href="index.php">Companion</a></h1>
        <ul>
            <li><a href="index.php">Home</a></li>
            <li><a href="pet.php">Pet</a></li>
            <li><a href="about.php">About</a></li>
        </ul>
        <div class="login">
            <?php
            if (isConnected()): ?>
                <a href="logout.php">Log out</a>
            <?php else: ?>
                <a href="login.php">Log in</a>
                <a href="register.php">Register</a>
            <?php endif; ?>
        </div>
    </nav>
    <section>