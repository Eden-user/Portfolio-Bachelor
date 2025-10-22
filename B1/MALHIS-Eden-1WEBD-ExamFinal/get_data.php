<?php
$id_user = $_SESSION["id_user"];
//récupère toutes les catégories
$sql2 = "SELECT id_category, categoryName FROM categories";
$statement2 = $pdo->prepare($sql2);
$statement2->execute();
$result2 = $statement2->fetchAll(PDO::FETCH_ASSOC); ?>
<div class="filtres">
    <!--boutons pour filtrer les résultats-->
    <form method="GET" action="index.php">
        <button type="submit" name="filter" value="all">All Tasks</button>
        <button type="submit" name="filter" value="completed">Completed</button>
        <button type="submit" name="filter" value="pending">Pending</button>
    </form>
</div>

<!--récupère pour chaque catégorie les taches de l'utilisateur-->
<?php foreach ($result2 as $category) {
    $sql = 'SELECT id_task, id_category, taskName, dueDate, taskDescription, Recurrence, Completion FROM tasks WHERE id_user = :id_user AND id_category = :id_category';
    $filter = isset($_GET["filter"]) ? $_GET["filter"] : "all";
    if ($filter == "completed") { //filtration des tâches avant requête
        $sql .= " AND Completion = 1";
    } elseif ($filter == "pending") {
        $sql .= " AND Completion = 0";
    }
    $statement = $pdo->prepare($sql);
    $statement->execute(params: array(':id_user' => $id_user, ':id_category' => $category["id_category"]));
    $result = $statement->fetchAll(PDO::FETCH_ASSOC);


    /*if (empty($result)) {
        echo "<p>No tasks assigned yet.</p>";
    }*/
    ?>
    <!--affichage des taches réparties dans les différentes catégories, la catégorie par défaut n'affiche pas son nom.-->

    <div class="categories">
        <?php if ($category["id_category"] != 1): ?>
            <h3 class="categName"><?= $category["categoryName"] ?> </h3>
            <form action="delete_categ.php" method="POST">
                <input type="hidden" name="id_categ" value="<?= $category["id_category"] ?>">
                <button type="submit" class="delete">Delete Category</button> <!-- bouton pour effacer directement une catégorie-->
            </form>
        <?php endif; ?>
        <?php foreach ($result as $task): ?>
            <div class="tasks">
                <h4><?= $task["taskName"] ?></h4>
                <p><?= $task["taskDescription"] ?></p>
                <?php if ($task["dueDate"] != "0000-00-00"): ?>
                    <h4> Due on <?= $task["dueDate"] ?></h4>
                <?php endif; ?>
                <form action="complete.php" method="POST"> <!-- checkbox : cochée=tâche complète, modification directe en BDD-->
                    <input type="hidden" name="id_task" value="<?= $task["id_task"] ?>">
                    Complete ? <input type="checkbox" class="checkbox" name="completed" value="1" <?= $task["Completion"] == 1 ? 'checked' : '' ?>
                        onchange="this.form.submit()">
                    <!--ligne pas de moi, complete la checkbox en fonction de la variable Completion de ma BDD, et en cas de changement envoie une requete post qui permet de mettre à jour la BDD.-->
                </form>
                <!-- ébauche overlay, ne fonctionne pas -->
                <!--<div class="overlay updatetask">
                    <div class="insideoverlay">
                        <?php //include("update_task.php") ?>
                    </div>
                </div class="updatebutton">
                <button type="submit">Update task</button>
                </form>-->
                <form action="delete_task.php" method="POST"> <!--bouton permet d'effacer directement une tâche en bdd-->
                    <input type="hidden" name="id_task" value="<?= $task["id_task"] ?>">
                    <button type="submit" class="delete">Delete task</button>
                </form>
            </div>
        <?php endforeach; ?>
    </div>
<?php }
?>