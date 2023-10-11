<!DOCTYPE html>
<html>
<head>
  <title>Connexion ou inscription</title>
  <link rel="stylesheet" type="text/css" href="ceres.css">
</head>
<body>
  <header>
    <div id="feas">
    </div>

    <div id="tase">
      Direction Centrale de la Police Routiere
    </div>
  </header>
  <h2>Bienvenue sur la page</h2>
  <div class="container">
    <h2>Connexion ou Inscription</h2>
    <form action="login.php" method="post">
      <input type="text" name="code_agent" placeholder="Code_agent" required>
      <input type="password" name="password" placeholder="Mot de passe" required>
      <input type="submit" value="Se connecter">
    </form>
    <p>Pas encore inscrit ? <a href="Inscrire.php">Inscrivez-vous ici</a></p>
  </div>


  
</body>
</html>


