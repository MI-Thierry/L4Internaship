<?php
$age = 15;
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>L4 NIT Internship</title>
</head>

<body>
    <h2>Flow control in PHP</h2>
    <p>
        <?php
        if ($age < 10) {
            echo "You're a kid.";
        } else if ($age < 20) {
            echo "You're a teenager.";
        } else {
            echo "You're an adult.";
        }; ?>
    </p>
    <p>
        <?php if ($age < 10) : ?>
            <p>You're a kid.</p>
        <?php elseif ($age < 20) : ?>
            <p>You're a teenager.</p>
        <?php else : ?>
            <p>You're an adult.</p>
        <?php endif; ?>
</p>
</body>

</html>