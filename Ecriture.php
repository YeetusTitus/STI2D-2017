<?php
     $host = "localhost"; 
     $user = "root"; 
     $pass = ""; 
     $bdd = "project"; 
	
echo"test mysql";
if (isset($_GET['Ndsdv']) )  
{
$Ndsdv=$_GET['Ndsdv']; 
$SOC=$_GET['SOC'];
$Ubatvide=$_GET['Ubatvide'];
$Ri=$_GET['Ri'];
$connexion=mysql_connect($host,$user,$pass) OR die('<p>Connexion impossible à la base de données</p>');
	mysql_select_db($bdd);


$query = "INSERT testeur_de_batterie set Ndsdv='$Ndsdv', Ubatvide='$Ubatvide', SOC='$SOC', Ri='$Ri',Jour='$Jour', Heure='$Heure'";

	  $result = mysql_query($query);	
	  } 
	  else $Ndsdv="vide";  
?>