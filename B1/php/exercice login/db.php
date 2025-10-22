 <?php
    define("USER", "root");
    define("PASSWORD", "");
    define("DSN", "mysql:host=localhost;dbname=hexagone");

    try {
        $pdo = new PDO(DSN, USER, PASSWORD);
        echo"connexion à la bdd reussie";
    } catch (PDOException $e) {
        die("Error: " . $e->getMessage());
        
    }
    ?>