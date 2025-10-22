<?php
//idem que newtask
include_once("database.php");
if ($_SERVER["REQUEST_METHOD"] == "POST" and (isset($_POST["newCategoryName"]))) {
    try {
        $categoryName = htmlspecialchars($_POST['newCategoryName'], ENT_QUOTES, 'UTF-8');
        $sql = "INSERT INTO categories(categoryName) VALUES (:categoryName)";
        $statement = $pdo->prepare($sql);
        $statement->execute(
            array(
                ':categoryName' => $categoryName,
            )
        );
        if ($statement->rowCount() > 0) {
            echo "Category $categoryName has been successfully added. <br>";
            header("Location: index.php");
            exit();
        } else {
            echo "Erreur : Category could not be added. <br>";
        }

    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }

}
?>
<div class="overlayContent">
    <div class="crossTitle">
        <h3>Create a new category</h3>
        <div class="cross">
            <p>X</p>
        </div>
    </div>
    <div class="formNewTask">
        <form action="index.php" method="post">
            <input type="text" name="newCategoryName" placeholder="Category name" required>
            <br>
            <button type="submit" class="submitCategory">Create new category</button>
        </form>
    </div>
</div>