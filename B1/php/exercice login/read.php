<?php
include("db.php");
$sql = "SELECT * FROM users";
$sth = $pdo->query($sql);
$result = $sth->fetchAll(PDO::FETCH_ASSOC);
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <table border="3">
        <style>
            table {
                width: 100%;
                border-collapse: collapse;
            }

            table,
            th,
            td {
                border: 1px solid black;
            }
        </style>
        <tr>
            <th>Firstname</th>
            <th>Lastname</th>
            <th>Email</th>
            <th colspan="2"> Action</th>
        </tr>
        <?php
        foreach ($result as $row) {
            echo "<tr>";
            echo "<td>" . $row['firstname'] . "</td>";
            echo "<td>" . $row['lastname'] . "</td>";
            echo "<td>" . $row['email'] . "</td>";
            echo '<td><a href="update_form.php?id='  . $row['id_user'].' ">Modifier</a></td>';
            echo '<td><a href="delete.php?id='  . $row['id_user'].' ">Suprimer</a></td>';
            echo "</tr>";
            
        }
        ?>
    </table>
</body>

</html>