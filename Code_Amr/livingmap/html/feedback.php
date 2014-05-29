<?php 

$proto_id=$_POST["proto_id"];
$action=$_POST["action"];


/*** mysql hostname ***/
include('db.php');

if($action=="like"){
	 /*** The SQL SELECT statement ***/
	$dbh->exec("UPDATE exp_likes SET nb_likes=nb_likes+1 WHERE proto_id=".$proto_id."");
	/*** close the database connection ***/
	$dbh = null;
 }else{
 	$qui = $_POST['qui'];
	$comment = $_POST['content'];
	$quand = date("Y-m-j H:i:s");
 	 /*** The SQL SELECT statement ***/
	$dbh->exec("INSERT INTO exp_comments (proto_id,comment,qui,quand) VALUES ('".$proto_id."','".$comment."','".$qui."','".$quand."')");
	
	/*** close the database connection ***/
	
	$dbh = null;

	 
 }
 