<?php
include("db.php");
$id = $_POST['id'];
$nom = $_POST['lastname'];
$prenom = $_POST['firstname'];
$email = $_POST['email'];

$sql = 'UPDATE users SET lastname = :nom, firstname = :prenom, email = :email WHERE id_user = :id';
$statement = $pdo->prepare($sql);
$statement->execute(
    array(
        ':nom' => $nom,
        ':prenom' => $prenom,
        ':email' => $email,
        ':id' => $id
    )
);
header('Location: read.php');
?>
