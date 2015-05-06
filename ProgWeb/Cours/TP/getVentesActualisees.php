
<?php

// Commence avec un nombre aléatoire de planches vendues
$totalVendu = 1012;

// Reflète les nouvelles ventes
srand((double)microtime() * 1000000);
$totalVendu = $totalVendu + rand(0,1000);

$prix = 249.95;
$cout = 84.22;
$benefParPlanche = $prix - $cout;
$benef = $totalVendu * $benefParPlanche ;

echo $totalVendu;
?>
