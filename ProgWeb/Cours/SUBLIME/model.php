<?php

class Model {
	// La connection au serveur de BD
	var $db;
	
	// Le contenu du panier
	var $panier;
    
	/**
	 * Se connecte au serveur SQL et recharge le panier d'après les variables postées
	 */
	function Model ($paramsDB, $variables) {
		// Connection au serveur
		$this->db=mysql_pconnect(
			$paramsDB['host'],
    		$paramsDB['user'],
    		$paramsDB['pass']
    	);
    	mysql_select_db($paramsDB['db'],$this->db);

		// Creation du panier    	
    	$this->panier = array();

    	// Chargement du contenu si il existe
    	foreach ($variables as $variable => $valeur)
    	{
			if (preg_match('/identifiant(\d+)/', $variable, $matches))
			{
				$this->addPanier(
					$variables['identifiant'.$matches[1]],
					$variables['quantite'.$matches[1]]
				);
			}
		}
	}
    
	/**
	 * Retourne l'ensemble des meubles
	 */    
	function getMeubles() {
		$meubles = array();
		$query=mysql_query("SELECT * FROM meuble",$this->db); 
		while ($row=mysql_fetch_array($query,MYSQL_ASSOC)) {
			array_push($meubles, $row);
		}
		return $meubles;
	}
    

	/**
	 * Retourne un meuble selon son identifiant
	 */    
	function getMeubleByID($id) {
		$query=mysql_query("SELECT * FROM meuble WHERE id_meuble=$id",$this->db);
		$row=mysql_fetch_array($query,MYSQL_ASSOC);
		return $row;
	}


	
?>
