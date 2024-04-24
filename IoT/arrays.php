<?php
$number = 5;
$students = ["Paul", "Sam", "Sifa", "Hertier", "Lagrange", "Newton"];
$studentsDetails = [
    [
        'name' => 'Paul',
        'age' => 14,
        'school' => 'Nyamagabe'
    ],
    [
        'name' => 'Sam',
        'age' => 20,
        'school' => 'Masisi'
    ],
    [
        'name' => 'Hertier',
        'age' => 10,
        'school' => 'Goma'
    ],
];
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
    <h2>Arrays in PHP</h2>
    <h3>List of students</h3>
    <ol class="list-group">
        <?php foreach ($students as $student) : ?>
            <li class="list-group-item"><?php echo $student; ?></li>
        <?php endforeach; ?>
    </ol>

    <h2>List of students and their descriptions.</h2>
        <?php foreach ($studentsDetails as $studentDetails) : ?>
            <div class="card">
                <p class="card-title">Student's name is <?php echo $studentDetails['name']; ?></p>
                <p class="card-text">Student's age is <?php echo $studentDetails['age']; ?></p>
                <p class="card-text">Student's school is <?php echo $studentDetails['school']; ?></p>
            </div>
        <?php endforeach; ?>
</body>

</html>