<?php
include("db.php");
$mot_de_passe = password_hash($_POST["password"], PASSWORD_DEFAULT);
$email = $_POST["email"];
$nom = $_POST['nom'];
$prenom = $_POST['prenom'];
$email = $_POST['email'];
$sql = "INSERT INTO users (firstname,lastname,email,password) VALUES (:prenom, :nom,  :email, :mot_de_passe)";

$statement = $pdo->prepare($sql);
$statement->execute(array(":mot_de_passe"=> $mot_de_passe, ":email"=> $email,":nom"=> $nom, ":prenom"=> $prenom));
header("Location: login.php");
?>