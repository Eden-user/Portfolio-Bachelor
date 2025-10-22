<?php
include_once("database.php");
//récupération contenu formulaire overlay nouvelle tâche
if ($_SERVER["REQUEST_METHOD"] == "POST" and (isset($_POST["taskName"]) and isset($_POST["taskDescription"]) and isset($_POST["categoryName"]) and isset($_POST["dueDate"]))) {
    $id_user = $_SESSION["id_user"];
    try {
        //récupération de toutes les catégories
        $sql2 = "SELECT * FROM categories";
        /*categories.id_category, categories.categoryName FROM categories LEFT JOIN tasks ON categories.id_category = tasks.id_category WHERE tasks.id_user = :id_user";*/
        $statement2 = $pdo->prepare($sql2);
        $statement2->execute();//(array(':id_user' => $id_user));
        $result2 = $statement2->fetchAll(PDO::FETCH_ASSOC);

        $categInput = htmlspecialchars($_POST["categoryName"], ENT_QUOTES, 'UTF-8');
        //compare la catégorie input aux catégories en BDD, si existante assignée à la tâche, sinon (ou si champ vide) catégorie par défaut. 
        // Manque la création directement ici d'une nouvelle catégorie si le champ est renseigné mais la catégorie n'existe pas encore.
        $id_category = 1;
        foreach ($result2 as $row2) {
            if ($categInput == $row2["categoryName"]) {
                $id_category = $row2["id_category"];
                break;
            }
        }

        //préparation et execution de la requete sql qui crée une nouvelle tâche

        $taskName = htmlspecialchars($_POST['taskName'], ENT_QUOTES, 'UTF-8');
        $taskDescription = htmlspecialchars($_POST['taskDescription'], ENT_QUOTES, 'UTF-8');
        $dueDate = $_POST['dueDate'];
        $sql = "INSERT INTO tasks(id_user, id_category, taskName, dueDate, taskDescription) VALUES (:id_user, :id_category, :taskName, :dueDate, :taskDescription)";
        $statement = $pdo->prepare($sql);
        $statement->execute(
            array(
                ':id_user' => $id_user,
                ':id_category' => $id_category,
                ':taskName' => $taskName,
                ':dueDate' => $dueDate,
                ':taskDescription' => $taskDescription,

            )
        );
        if ($statement->rowCount() > 0) {
            echo "Task $taskName has been successfully added. <br>";
            header("Location: index.php");
            exit();
        } else {
            echo "Erreur : Task could not be added. <br>";
        }

    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }

}
?>
<div class="overlayContent">
    <div class="crossTitle">
        <h3>Create a new task</h3>
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
            <button type="submit" class="submitTask">Create new task</button>
        </form>
    </div>
</div>