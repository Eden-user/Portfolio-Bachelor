<?php include("header.php"); ?>

<?php
if (isConnected()) {
    header("Location: index.php");
}
if ($_SERVER["REQUEST_METHOD"] == "POST" and (isset($_POST["email"]) and isset($_POST["password"]))) {
    $email = $_POST['email'];
    $password = $_POST['password'];
    $sql = "SELECT * FROM users WHERE email = :email";
    $statement = $pdo->prepare($sql);
    $statement->execute(
        array(
            ':email' => $email
        )
    );
    $user = $statement->fetch();
    if ($user) {
        if (password_verify($password, $user['password'])) {
            $_SESSION["email"] = $user['email'];
            $_SESSION["id_user"] = $user['id_user'];

            header("Location: index.php");
        } else {
            echo "Wrong password !";
        }
    } else {
        echo "Email not found.";
    }
}
;

?>

<h1>Log in</h1>
<div class="Form">
    <form action="login.php" method="post">
        <label for="email">Email</label>
        <input type="email" name="email" id="email" required>
        <br>
        <label for="password">Password</label>
        <input type="password" name="password" id="password" required>
        <br>
        <button type="submit">Log in</button>
        <br>
        <a href="register.php">Not registered yet ?</a>
    </form>
</div>
<?php include("footer.php"); ?>