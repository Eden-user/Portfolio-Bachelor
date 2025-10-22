<?php
include("db.php");
if (isset($_POST["email"]) && isset($_POST["password"])) {
    $email = $_POST["email"];
    $password = $_POST["password"];
    /*   password_verify($password) */
    $sql = "SELECT  firstname, lastname, password, email FROM users WHERE email = :toto";
    $statement = $pdo->prepare($sql);
    $statement->execute(array(':toto' => $email));
    $result = $statement->fetchAll(PDO::FETCH_ASSOC);
    if (password_verify($password, $result[0]['password'])) {
        session_start();
        $_SESSION["firstname"] =  $result[0]['firstname'];
        $_SESSION["lastname"] =  $result[0]['lastname'];
        $_SESSION["email"] =  $result[0]['email'];
        header("Location: read.php");

    }
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form method="POST">
        <input type="email" name="email" placeholder=" votre email">
        <input type="password" name="password" placeholder="votre mot de passe">
        <input type="submit" value="Envoyer">
    </form>
</body>

</html>