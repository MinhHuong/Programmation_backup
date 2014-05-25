;;; EXERCICE 3 : PERIODE D'UN PENDULE
;;; pendule : Nombre -> Nombre
;;; (pendule L) renvoie la periode en secondes d'un pendule

(define (pendule L) 
  (* 2 pi (sqrt (/ L 981))))

(pendule 3)
(pendule 4)
(pendule 5.2)
