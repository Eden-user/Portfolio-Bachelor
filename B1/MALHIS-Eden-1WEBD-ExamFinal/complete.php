<?php include("header.php");

if (isset($_POST["id_task"])) {
    $id_task = $_POST["id_task"];
    $completion = isset($_POST["completed"]) ? 1 : 0;

    $sql = "UPDATE tasks SET Completion = :completion WHERE id_task = :id_task";
    $statement = $pdo->prepare($sql);
    $statement->execute(array(':completion' => $completion, ':id_task' => $id_task));

    header("Location: index.php");
}
include("footer.php");
?>