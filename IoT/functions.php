<?php
function sum($val1, $val2)
{
    $result = $val1 + $val2;
    return $result;
}

$areaFinder = function ($radius, $PI) {

    $area = $radius * $radius * $PI;
    return $area;
};
echo $areaFinder(34, 3.141);
