<?php
$numbers = [1, 2, 3, 4, 5, 6];
$students = [
    [
        'name' => 'Bonheur',
        'age' => 15,
        'school' => 'Rusizi'
    ],
    [
        'name' => 'Anna',
        'age' => 10,
        'school' => 'Nyamagabe'
    ],
    [
        'name' => 'Paul',
        'age' => 45,
        'school' => 'Congo'
    ],
];

foreach ($students as $student) {
    if ($student['name'] == 'Anna') {
        echo 'This student is stuborn';
    }
    echo $student['name'];
    echo $student['age'];
    echo $student['school'];
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>L4 NIT Internship</title>
</head>

<body>
    <h2>Arrays in PHP</h2>
    <?php foreach ($students as $student) : ?>
        <?php if ($student['name'] == 'Anna') : ?>
            <p>This student is stuborn</p>
        <?php endif ?>
        <p>
            The student name is <?php echo $student['name']; ?>, he is
            <?php echo $student['age']; ?> and he studies in
            <?php echo $student['school'] ?>
        </p>
        <?php endforeach ?>'
</body>

</html>