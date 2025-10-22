<?php

header("Content-Type: application/json");

if ($_SERVER["REQUEST_METHOD"] === "POST") { //récupère les données de mon formulaire
    if (isset($_POST["id_categ"])) {
        $id = intval($_POST["id_categ"]);

        try {
            //connexion à la base de données
            $pdo = new PDO("mysql:host=localhost;dbname=taskmanager", "root", "");
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            //préparation des requêtes
            $stmt = $pdo->prepare("DELETE FROM categories WHERE id_category = ?;");
            $stmt2 = $pdo->prepare("UPDATE tasks SET id_category = 1 WHERE id_category = ?;");
            //execution de la transaction
            $pdo->beginTransaction();
            if ($stmt->execute([$id]) && $stmt2->execute([$id])) {
                $pdo->commit();
                echo json_encode(["success" => true]);
                header("Location: index.php");
            } else {
                echo json_encode(["success" => false, "error" => "Échec de la suppression."]);
            }
        } catch (PDOException $e) {
            echo json_encode(["success" => false, "error" => $e->getMessage()]);
        }
    } else {
        echo json_encode(["success" => false, "error" => "ID manquant."]);
    }
}

?>