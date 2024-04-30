// Sockets server
<?php
function print_error($message)
{
    echo $message . socket_strerror(socket_last_error()) . "\n";
}

function println($msg)
{
    echo "$msg\n";
}

define('DB_HOST', 'localhost');
define('DB_USER', 'L4NIT');
define('DB_PASSWORD', 'L4NIT@2024');
define('DB_NAME', 'weather_informations');

$address = '192.168.198.35';
$port = 8080;
$db_conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);

if ($db_conn->connect_error) {
    println("Failed to connect to the data base");
    die();
}

println("The app is starting.");
$srv_sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($srv_sock === false) {
    print_error("socket_create() failed: reason:");
    die();
}

if (socket_bind($srv_sock, $address, $port) === false) {
    print_error("socket_bind() failed: reason:");
    die();
}

if (socket_listen($srv_sock, 5) === false) {
    print_error("socket_listen() failed: reason:");
    die();
}

$msgsock = socket_accept($srv_sock);
if ($msgsock === false) {
    print_error("socket_accept() failed: reason:");
    die();
}

println("Client is connected.");
while (true) {
    $buf = socket_read($msgsock, 1024, PHP_NORMAL_READ);
    if ($buf !== false) {
        $info = json_decode($buf, true);

        $land_plot = $info['land_plot'];
        $temp = $info['temperature'];
        $hum = $info['humidity'];

        $sql = "INSERT INTO l4nit_measuring(id, land_plot, temperature, humidity, entry_date) VALUES
        (NULL, '$land_plot', '$temp', '$hum', current_timestamp())";

        if (mysqli_query($db_conn, $sql)) {
            println($buf);
        }
    } else {
        socket_close($msgsock);
        $msgsock = socket_accept($srv_sock);
    }
}
