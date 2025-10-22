<?php
//idem que delete_categ.php
header("Content-Type: application/json");

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    if (isset($_POST["id_task"])) {
        $id = intval($_POST["id_task"]);

        try {
            $pdo = new PDO("mysql:host=localhost;dbname=taskmanager", "root", "");
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $stmt = $pdo->prepare("DELETE FROM tasks WHERE id_task = ?");

            if ($stmt->execute([$id])) {
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