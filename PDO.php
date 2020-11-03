
<?php

try
{
$bdd = new PDO('mysql:host=localhost;dbname=project;charset=utf8', 'root', '');
}
catch(Exception $e)
{
        die('Erreur : '.$e->getMessage());
}

$reponse = $bdd->query('SELECT Ndsdv, VbatVide, SOC,  Ri, Jour, Heure FROM testeur_de_batterie WHERE Ndsdv =\'' . $_GET['Ndsdv'] . '\'');


while ($donnees = $reponse->fetch())
{
?>
    <p>

    <strong>Numero de serie du véhicule</strong> : <?php echo $donnees['Ndsdv']; ?><br />

    La tension à vide est de <?php echo $donnees['VbatVide']; ?> volt et la résistance interne est de <?php echo $donnees['Ri']; ?> Ohm.<br />

    La batterie est <?php echo $donnees['SOC']; ?>.<br/> La batterie a été testé le <?php echo $donnees['Jour']; ?> à <?php echo $donnees['Heure']; ?><br/><br/>
   </p>


<?php
}
$reponse->closeCursor(); 
?>

<html>
<head>
<title> Résultat de la recherche</title>
<style type="text/css">
 body {
    background-image: url("Voiture du background.jpg");}</style></head>
	<a href="http://localhost/Project/HTLM&PHP.php"><img src="fleche.png"><font size=5><br/>Retour à la recherche</font></a>
	</html>


