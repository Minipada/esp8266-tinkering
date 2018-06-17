<?php
$filename_nasim = "nasim.txt";
$filename_david = "david.txt";

# Someone pressed a button
if (isset($_GET["david"]) ){
  $myfile = fopen($filename_david, "w") or die("Unable to open file!");
  fclose($myfile);
  echo "FileCreatedDavid";
}

if (isset($_GET["nasim"])) {
  $myfile = fopen($filename_nasim, "w") or die("Unable to open file!");
  fclose($myfile);
  echo "FileCreatedNasim";
}

if (isset($_GET["isdimmednasim"]) and file_exists($filename_david)) {
  unlink($filename_david);
  echo "HitTheLightsNasim";
}

if (isset($_GET["isdimmeddavid"]) and file_exists($filename_nasim)) {
  unlink($filename_nasim);
  echo "HitTheLightsDavid";
}


?>