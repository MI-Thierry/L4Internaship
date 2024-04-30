// Project user interface
<?php
define('DB_HOST', 'localhost');
define('DB_USER', 'L4NIT');
define('DB_PASSWORD', 'L4NIT@2024');
define('DB_NAME', 'weather_informations');

$db_conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
if ($db_conn->connect_error) {
    println("Failed to connect to the data base");
    die();
}
$sql = 'SELECT * FROM l4nit_measuring';
$result = mysqli_query($db_conn, $sql);
$weatherData = mysqli_fetch_all($result, MYSQLI_ASSOC);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>L4 NIT Internship</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Roboto:wght@400;700&display=swap');

        table {
            border-collapse: collapse;
            margin: 0 auto;
            width: 90%;
            font-family: sans-serif;
        }

        th,
        td {
            padding: 10px;
            text-align: left;
            border: 1px solid #ddd;
        }

        th {
            background-color: #f2f2f2;
            position: sticky;
            top: 0;
        }

        tr:nth-child(even) {
            background-color: #f9f9f9;
        }

        .title {
            margin-left: 10px;
            text-align: center;
            font-size: 2rem;
            font-weight: bold;
            margin-bottom: 1rem;
        }
    </style>
</head>

<body>
    <h2 class="centered">Kigali Weather condition data</h2>
    <div class="card centered" style="width: 50rem; margin: 5">
        <table>
            <tr>
                <th>N°</th>
                <th>Land plot</th>
                <th>Temperature</th>
                <th>Humidity</th>
                <th>Entry date</th>
            </tr>
            <?php foreach ($weatherData as $data) : ?>
                <tr>
                    <th class="table-elem"><?php echo $data['id']; ?></th>
                    <th><?php echo $data['land_plot']; ?></th>
                    <th><?php echo $data['temperature']; ?></th>
                    <th><?php echo $data['humidity']; ?></th>
                    <th><?php echo date('d/m/Y h:m', strtotime($data['entry_date'])); ?></th>
                </tr>
            <?php endforeach; ?>
        </table>
    </div>
</body>

</html>