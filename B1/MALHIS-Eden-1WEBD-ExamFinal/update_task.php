<?php
header("Content-Type: application/json");

//récupération des données du formulaire de mise à jour.

if ($_SERVER["REQUEST_METHOD"] == "POST" and (isset($_POST["taskName"]) and isset($_POST["id_task"]) and isset($_POST["taskDescription"]) and isset($_POST["categoryName"]) and isset($_POST["dueDate"]))) {
    try {
        $sql2 = "SELECT * FROM categories";
        $statement2 = $pdo->prepare($sql2);
        $statement2->execute();
        $result2 = $statement2->fetchAll(PDO::FETCH_ASSOC);

        $categInput = htmlspecialchars($_POST["categoryName"], ENT_QUOTES, 'UTF-8');
        //récupération de l'id de catégorie correspondant
        $id_category = 1;
        foreach ($result2 as $row2) {
            if ($categInput == $row2["categoryName"]) {
                $id_category = $row2["id_category"];
                break;
            }
        }
        //mise à jour de la tâche
        $id_task = $_POST["id_task"];
        $taskName = htmlspecialchars($_POST['taskName'], ENT_QUOTES, 'UTF-8');
        $taskDescription = htmlspecialchars($_POST['taskDescription'], ENT_QUOTES, 'UTF-8');
        $dueDate = $_POST['dueDate'];
        $sql = "UPDATE tasks SET id_category = :id_category, taskName = :taskName, dueDate = :dueDate, taskDescription = :taskDescription WHERE id_task = :id_task";
        $statement = $pdo->prepare($sql);
        if (
            $statement->execute(
                array(
                    ':id_category' => $id_category,
                    ':taskName' => $taskName,
                    ':dueDate' => $dueDate,
                    ':taskDescription' => $taskDescription,
                    ':id_task' => $id_task,
                )
            )
        ) {
            echo json_encode(["success" => true]);
        } else {
            echo json_encode(["success" => false, "error" => "Échec de la mise à jour."]);
        }
    } catch (PDOException $e) {
        echo json_encode(["success" => false, "error" => $e->getMessage()]);
    }
}
?>
<div class="overlayContent">
    <div class="crossTitle">
        <h3>Update this task</h3>
        <div class="cross">
            <p>X</p>
        </div>
    </div>
    <div class="formNewTask">
        <form action="index.php" method="post">
            <input type="text" name="taskName" placeholder="Task name" required>
            <br>
            <input type="text" name="taskDescription" placeholder="Description">
            <br>
            <input type="text" name="categoryName" placeholder="Category name">
            <br>
            <input type="date" name="dueDate">
            <br>
            <input type="hidden" name="id_task" value="<?= $task["id_task"] ?>">
            <button type="submit" class="submitTask">Update task</button>
        </form>
    </div>
</div>