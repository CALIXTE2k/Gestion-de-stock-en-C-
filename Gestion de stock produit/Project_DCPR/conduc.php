<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Enregistrer conducteur</title>
    <link rel="stylesheet" href="form.css">

</head>
<body>
    <?php
 include("header.php")
?>
<h2>ENREGISTREMENT CONDUCTEUR</h2>
<section>
<form method="post" action="#" >
    <div class="user-details">
        <div class="input-box">
            <span class="details">
                Nom
            </span>
            <input type="text" placeholder="Entrer  nom " required>
        </div>

        <div class="input-box">
            <span class="details">
                No dossier
            </span>
            <input type="text" placeholder="Entrer No dossier" required>
        </div>

        <div class="input-box">
            <span class="details">
                Prenom
            </span>
            <input type="text" placeholder="Entrer prenom" required>
        </div>

        <div class="input-box">
            <span class="details">
                Sexe
            </span>
            <input type="text" placeholder="Entrer sexe" required>
        </div>

        <div class="input-box">
            <span class="details">
                Nif
            </span>
            <input type="text" placeholder="Entrer  nif" required>
        </div>

    </div>

    <div class="button">
        <input type="submit" value="Enregistrer">
    </div>

</form>
</section>
<footer>
<?php
include("footer.php")
?>
</footer>
</body>    
</html>