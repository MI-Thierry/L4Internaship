// For testing purposes only
<?php
error_reporting(E_ALL);

function println($msg)
{
    echo "$msg\n";
}
function print_error($message)
{
    echo $message . socket_strerror(socket_last_error()) . "\n";
}

$port = 27015;
$address = '192.168.198.35';

println("The app is starting.");
$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
    print_error("socket_create() failed: reason: ");
    die();
}

echo "Attempting to connect to '$address' in port '$port'...\n";
$result = socket_connect($socket, $address, $port);
if ($result === false) {
    print_error("socket_connect() failed: reason:");
    die();
}

while (true) {
    sleep(5);
    $info = [
        'land_plot' => 'KN87 St7 Kigali',
        'temperature' => rand(10, 50),
        'humidity' => rand(0, 100),
    ];

    $msg = json_encode($info);
    socket_write($socket, $msg, strlen($msg));
}
