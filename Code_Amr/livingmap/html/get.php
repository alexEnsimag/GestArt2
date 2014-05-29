<?php 

$q=$_GET["q"];
$proto_id=$_GET["id"];
   
function get_protos(){
/*** mysql hostname ***/
include('db.php');

 /*** The SQL SELECT statement ***/
    $sql = "SELECT * FROM exp_protos";
    foreach ($dbh->query($sql) as $row)
        {
        print $row['nom'] .' - '. $row['structures'] . '<br />';
        }

    /*** close the database connection ***/
    $dbh = null;
 }
 
 
function get_likes($proto_id){
/*** mysql hostname ***/
include('db.php');

 /*** The SQL SELECT statement ***/
    $sql = "SELECT exp_likes.nb_likes,exp_likes.proto_id,exp_protos.id,exp_protos.nom FROM exp_likes INNER JOIN exp_protos ON exp_protos.id=exp_likes.proto_id WHERE exp_likes.proto_id = ".$proto_id."";
    foreach ($dbh->query($sql) as $row)
        {
        echo $row['nom'].' - ';
        echo $row['nb_likes'] .'';
        }

    /*** close the database connection ***/
    $dbh = null;
 }
 
 
 function get_comments($proto_id){
/*** mysql hostname ***/
include('db.php');

 /*** The SQL SELECT statement ***/
    $sql = "SELECT exp_comments.comment,exp_comments.quand,exp_comments.qui,exp_comments.proto_id,exp_protos.id,exp_protos.nom FROM exp_comments INNER JOIN exp_protos ON exp_protos.id=exp_comments.proto_id WHERE exp_comments.proto_id = ".$proto_id."";
    
    $output = '';
    foreach ($dbh->query($sql) as $row)
       {
        $output .= $row['quand'] .'<br/>';
        $output .= $row['qui'] .'<br/>';
        $output .= $row['comment'] .'<br/>';
      }
    echo $output;

    $dbh = null;
 }
 


if($q=="comments"){
	get_comments($proto_id);
}else if($q=="likes"){
	get_likes($proto_id);
}




?>