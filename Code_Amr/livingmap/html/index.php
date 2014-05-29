<!DOCTYPE html>
<html>
<head>
<title>LivingMap</title>
	
	    <link href="css/style.css" rel="stylesheet"/>

       
    </head>
        <?php
    $proto_id = $_GET["id"];
    
?>
    <body style="background-position: center center;background-size:cover;background-image:url('css/img/<?php echo $proto_id ?>.jpg')">

    <div id="fond">
	    <div id="titre">
<?php
    include('db.php');

 /*** The SQL SELECT statement ***/
    $sql = "SELECT * FROM exp_protos WHERE id=".$proto_id."";
    foreach ($dbh->query($sql) as $row)
        {
        echo "<h1>";
        print $row['nom'];
        echo "</h1>";
        echo "<h2>";
        print $row['structures'];
        echo "</h2>";
        }

    /*** close the database connection ***/
    $dbh = null;

    ?>
	    </div>
            <div id="haut">

        <form id="like" method="post">
            <input type="hidden" name="proto_id" value="<?php echo $proto_id ?>" />
            <input type="hidden" name="action" value="like" />
            <input type="submit" name="form_submit" value="&hearts; J'aime !" class="button" />
        </form>
    </div>
    
    
    <div id="bas">
         <form id="comment" method="post">
            <input type="hidden" name="proto_id" value="<?php echo $proto_id ?>" />
            <input type="hidden" name="action" value="comment" />
            <input type="text" name="qui" placeholder="Votre nom" class="txtinput" /><br/>
            <textarea name="content" placeholder="Qu'en pensez-vous ?"></textarea><br/>
            <input type="submit" name="form_submit" value="Je commente !" class="button" />
        </form>
    </div>
    </div>
       
       	 <script type="text/javascript" src="js/jquery.min.js"></script>
	 <script type="text/javascript" src="js/jquery-ui.js"></script>
        <script type="text/javascript">
            
        $(document).ready(function(){
        
			$("#like").submit(function(e) {
				$.ajax({
					type: "POST",
					url: "feedback.php",
					data: $(e.target).serialize(),
					dataType: "json",
					beforeSend:function(){
						$(".alert-error,.alert-success").hide();
					},
					success: function(data){
						$("#haut").animate({backgroundColor: "#aeff35"}, 500 );
						$("#haut .button").animate({backgroundColor: "#aeff35"}, 500);
					}
				});
				return false;
			});
				/////////////
				$("#comment").submit(function(e) {
				$.ajax({
					type: "POST",
					url: "feedback.php",
					data: $(e.target).serialize(),
					dataType: "json",
					beforeSend:function(){
						$(".alert-error,.alert-success").hide();
					},
					success: function(data){
						$("#bas").animate({backgroundColor: "#aeff35"}, 500 );
					}
				});
				return false;
			});			});
        </script>

    </body>
</html>