<?php
$student = 'Bonheur';
$age = 13;
$school = 'Rusizi';
define("PI", 3.141);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>L4 NIT Internship</title>
</head>

<body>
    <h1>Student description</h1>
    <h2>The student's name is <?php echo $student ?></h1>
        <p>
            <?php echo $student ?> who're born in
            <?php echo 2024 - $age; ?> have
            <?php echo $age; ?> years old is the most stuborn boy in
            <?php echo $school ?> secondary school.
        </p>
        <p>The value of PI is <?php echo PI; ?></p>
</body>

</html>