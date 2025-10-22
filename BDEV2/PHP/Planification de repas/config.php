<?php
define("USER", 'root');
define("PASSWORD", '');
define("DNS", 'mysql:host=localhost;dbname=Planification_de_repas');

try {
    $pdo = new PDO(DNS, USER, PASSWORD);
} catch (PDOException $e) {
    die("Error ! : " . $e->getMessage());
}
