<?php
define('DB_HOST', 'localhost');
define('DB_USER', 'L4NIT');
define('DB_PASS', 'L4NIT@2024');
define('DB_NAME', 'l4nit_shift_2');

$connection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);

if ($connection->connect_error) {
    die('Connection failed');
}

$sql = 'SELECT * FROM students_list';
$result = mysqli_query($connection, $sql);
$students = mysqli_fetch_all($result, MYSQLI_ASSOC);
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>L4 NIT Internship</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
</head>

<body>
    <h2>Managing database in PHP</h2>
    <table class="table">
        <tr>
            <th>N</th>
            <th>Name</th>
            <th>Birth day</th>
            <th>Entry date</th>
        </tr>
        <?php foreach ($students as $student) : ?>
            <tr>
                <td><?php echo $student['id']; ?></td>
                <td><?php echo $student['name']; ?></td>
                <td><?php echo $student['birth_day']; ?></td>
                <td><?php echo $student['date']; ?></td>
            </tr>
        <?php endforeach; ?>
    </table>
</body>

</html>