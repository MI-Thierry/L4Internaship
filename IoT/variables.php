<?php
$name = "Paul";
$age = 18;
$school = "G.S Buringa";
define('PI', 3.141);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>L4 NIT Internship</title>
</head>

<body>
    <h1>Variables in PHP</h1>
    <h2>Student description for <?php echo $name; ?></h2>
    <p>
        This student with name of
        <?php echo $name; ?> who're born in
        <?php echo 2024 - $age; ?> have
        <?php echo $age; ?> years old and he studies in
        <?php echo $school; ?> secondary school and he's the
        most stuborn boy in the whole class.
    </p>
    <p>The value of PI is <?php echo PI; ?></p>
</body>

</html>