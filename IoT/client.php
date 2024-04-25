<?php
error_reporting(E_ALL);

function print_error($message)
{
    echo $message . socket_strerror(socket_last_error()) . "\n";
}

$port = 8080;
$address = gethostbyname(('localhost'));

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
    print_error("socket_create() failed: reason: ");
}

echo "Attempting to connect to '$address' in port '$port'...\n";
$result = socket_connect($socket, $address, $port);
if ($result === false)
{
    print_error("socket_connect() failed: reason:");
}

echo "Connection establised successfully\n";
$buf = socket_read($socket, 1024);
echo $buf;