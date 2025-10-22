<?php include("header.php"); ?>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST" and (isset($_POST["firstName"]) and isset($_POST["lastName"]) and isset($_POST["email"]) and isset($_POST["password"])) and isset($_POST["password2"])) {
    $firstName = $_POST['firstName'];
    $lastName = $_POST['lastName'];
    $email = $_POST['email'];
    $password = $_POST['password'];
    $password2 = $_POST['password2'];
    if ($password == $password2) {
        $password = password_hash($password, PASSWORD_DEFAULT);
        $sql = "INSERT INTO users(firstName, lastName, email, password) VALUES (:firstName,:lastName,:email,:password)";
        $statement = $pdo->prepare($sql);
        $statement->execute(
            array(
                ':firstName' => $firstName,
                ':lastName' => $lastName,
                ':email' => $email,
                ':password' => $password
            )
        );

        $lastid = $pdo->lastInsertId();
        $_SESSION["email"] = $email;
        $_SESSION["id_user"] = $lastid;

        header("Location: index.php");
    } else {
        echo "Passwords don't match.";
    }
}
?>

<h1>Register</h1>
<p>Already have an account ?
    <br>
    <a href="login.php">Log in</a>
</p>
<div class="form">
    <form action="register.php" method="post">
        <label for="firstName">First Name</label>
        <br>
        <input type="text" name="firstName" id="firstName" required>
        <br>
        <label for="lastName">Last Name</label>
        <br>
        <input type="text" name="lastName" id="lastName" required>
        <br>
        <label for="email">Email</label>
        <br>
        <input type="email" name="email" id="email" required>
        <br>
        <label for="password">Password</label>
        <br>
        <input type="password" name="password" id="password" required>
        <br>
        <label for="password2">Confirm password</label>
        <br>
        <input type="password" name="password2" id="password2" required>
        <br>
        <button type="submit">Register</button>
    </form>
</div>

<?php include("footer.php"); ?>