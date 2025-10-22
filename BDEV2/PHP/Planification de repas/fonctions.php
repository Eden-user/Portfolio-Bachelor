<?php
function display_sorted($list)
{
    $txt = "";
    sort($list);
    foreach ($list as $x) {
        $append = "<li>$x<br></li>";
        $txt = $txt . $append;
    }
    return $txt;

}

function take_random(&$list_copy)
{
    $rand_index = array_rand($list_copy, 1);
    echo $list_copy[$rand_index];
    array_splice($list_copy, $rand_index, 1);
}

function generate_week($entrées_copy, $plats_copy, $desserts_copy, $jours)
{
    foreach ($jours as $jour) {
        echo "<div class='card menu_card'>";
        echo "<h3>$jour</h3>";
        echo "<p><b>Entrée: </b>";
        take_random($entrées_copy);
        echo "</p>";
        echo "<p><b>Plat: </b>";
        take_random($plats_copy);
        echo "</p>";
        echo "<p><b>Dessert: </b>";
        take_random($desserts_copy);
        echo "</p>";
        echo "</div>";
    }
}