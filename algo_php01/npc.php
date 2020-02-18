<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="utf-8">
	<meta name="viewport" content="width=device-width">
  </head>
  <body>
  
  <?php
  
if(isset($_POST['inputnpc']) != null and is_string(htmlentities($_POST['inputnpc'])) and htmlentities($_POST['inputnpc']) != ""){

	$texts = file_get_contents("data/text.json");
	$texts = json_decode($texts, true);

	$npcs = file_get_contents("data/Npcs.json");
	$npcs = json_decode($npcs, true, 8);

	$assoc = [];

	foreach ($npcs as $npc){
		
		if(array_key_exists($npc['nameId'], $texts['texts']) and array_key_exists('nameId', $npc) and array_key_exists('look', $npc)){
			$tmp = [$texts['texts'][$npc['nameId']], $npc['look']];
			if(isset($tmp) and is_string($tmp[0]) and $tmp[0] != "_empty_" and stristr($tmp[0], htmlentities($_POST['inputnpc']))){
				array_push($assoc, $tmp);
			}
		}
		
	}

	if($assoc){
		foreach ($assoc as $display){
			
			$src = 'https://static.ankama.com/dofus/renderer/look/'.bin2hex($display[1]).'/full/1/500_500-10.png';
			echo '<p>'.$display[0].'</p><a href="'.$src.'">Cliquez ici</a></p>';

			/*
			$image = 'https://static.ankama.com/dofus/renderer/look/'.bin2hex($display[1]).'/full/1/200_200-10.png';
			if ($fp = curl_init($image)){
				$imageData = base64_encode(file_get_contents($image));
				$src = 'data:image/png;base64,'.$imageData;
				echo '<div><p>'.$display[0].'</p><img src="'.$src.'" </img>';
				$fp = curl_close($fp);
			} 

			else {

			
			}
			*/


		}
	}
	else{
		echo 'Tous les chemins mènent au monde des Douze ... sauf celui-là';
	} 
}
  ?>
  </body>
  </html>
