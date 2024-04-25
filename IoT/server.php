<?php
error_reporting(E_ALL);
set_time_limit(0);
ob_implicit_flush();

function print_error($message)
{
    echo $message . socket_strerror(socket_last_error()) . "\n";
}

$address = gethostbyname('localhost');
$port = 8080;

$srv_sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($srv_sock === false) {
    print_error("socket_create() failed: reason:");
}

if (socket_bind($srv_sock, $address, $port) === false) {
    print_error("socket_bind() failed: reason:");
}

if (socket_listen($srv_sock, 5) === false) {
    print_error("socket_listen() failed: reason:");
}

$msgsock = socket_accept($srv_sock);
if ($msgsock === false) {
    print_error("socket_accept() failed: reason:");
}
echo "Connection is established.";
$msg = "Hey! client this is PHP testing server.";
socket_write($msgsock, $msg, strlen($msg));