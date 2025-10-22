<?php
include("db.php");
$id = $_GET['id'];
$sql = "SELECT * FROM users WHERE id_user = :id";
$statement = $pdo->prepare($sql);
$statement->execute(array("id" => $id));
$result =  $statement->fetch(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form id="form1" action="update.php" method="POST">
        <input type="text" name="lastname" value=" <?php echo $result['lastname'] ?>"/>
        <input type="text" name="firstname" value=" <?php echo $result['firstname'] ?>" />
        <input type="text" name="email"  value=" <?php echo $result['email'] ?>" />
        <input type="hidden" name="id" value=" <?php echo $result['id_user'] ?>" />
        <input type="submit" value="Modifier" />
    </form>
</body>

</html>
<?php


?>