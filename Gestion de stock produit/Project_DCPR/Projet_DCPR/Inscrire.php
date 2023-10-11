<!DOCTYPE html>
<html>
<head>
  <link rel="stylesheet" href="melch.css">
<!-- <style>
body {
  background: linear-gradient(to right, blue, red);
}

#loader {
  position: fixed;
  left: 0px;
  top: 0px;
  width: 100%;
  height: 100%;
  z-index: 9999;
  background: url('images/pnh.svg') center no-repeat #fff;

display: flex;
  flex-direction: column;
  width: 300px;
}

label {
  margin-top: 10px;
}

input[type="submit"] {
  margin-top: 20px;
}
input[type="submit"]{
    background-color: green;
    color: white;
}
</style> -->
<script>
window.addEventListener("load", function(){
    var loader = document.getElementById("loader");
    setTimeout(function(){
        loader.style.display = "none";  
    }, 3000);
});
function validateForm() {
  // Add your validation code here
}

function submitForm(event) {
  event.preventDefault();
  
  if (validateForm()) {
    // Add your code to submit the form data to your server here
  }
}
</script>
</head>
<body>
<header>
    <div id="feas">
    </div>

    <div id="tase">
      Direction Centrale de la Police Routiere
    </div>
  </header>

<div class="container">

<form action="#" method="post">
  <input type="text" id="code" name="code" placeholder="Code d'agent" required>
  
  <input type="name" id="affectation" name="affectation" placeholder="Affection">
  
  <input type="text" id="nom" name="nom" placeholder="Nom">
  
  <input type="name" id="prenom" name="prenom" placeholder="Prenom">
  
  <label for="sexe">Sexe:</label>
<select id="sexe" name="sexe" placeholder="Code d'agent">
  <option value="">Sélectionnez...</option>
  <option value="homme">Homme</option>
  <option value="femme" selected>Femme</option>
  <option value="autre">Autre</option>
</select>

  
  <input type="submit" value="S'inscrire">
</form>
</div>


</body>
</html>


