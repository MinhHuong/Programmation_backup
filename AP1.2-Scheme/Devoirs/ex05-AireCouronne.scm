;;; EXERCICE 5 : AIDE D'UNE COURONNE

;;; aire-disque : Nombre -> Nombre
;;; (aire-disque r) renvoie l'aire du disque de rayon r

(define (aire-disque r)
  (* pi r r))

(aire-disque 1)


;;; aire-couronne1 : Nombre * Nombre -> Nombre
;;; (aire-couronne1 r1 r2) renvoie l'aire de la couronne du rayon interieur r1 
;;; et rayon exterieur r2

(define (aire-couronne1 r1 r2)
  (- (aire-disque r2) (aire-disque r1)))

(aire-couronne1 1 2)


;;; aire-couronne2 : Nombre * Nombre -> Nombre
;;; (aire-couronne2 r1 r2) fonctionne comme aire-couronne1, mais elle retourne une erreur
;;; si r1 > r2

(define (aire-couronne2 r1 r2)
  (if (> r1 r2) 
      "Erreur : le rayon interieur est plus grand que le rayon exterieur"
      (aire-couronne1 r1 r2)))

(aire-couronne2 4 3)
(aire-couronne2 3 5)
