<?php
include("db.php");
$id = $_GET['id'];
$sql = ' DELETE FROM users WHERE id_user = :id';
$statement = $pdo->prepare($sql);
$statement->execute(
    array('id' => $id)
);
header('Location: read.php');
?>