<?php
//connexion à la base de donnée
define("USER", 'root');
define("PASSWORD", '');
define("DNS", 'mysql:host=localhost;dbname=taskmanager');

try {
    $pdo = new PDO(DNS, USER, PASSWORD);
} catch (PDOException $e) {
    die("Error ! : " . $e->getMessage());
}
?>