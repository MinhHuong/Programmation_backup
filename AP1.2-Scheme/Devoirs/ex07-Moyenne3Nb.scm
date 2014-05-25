;;; EXERCICE 7 : CALCULER LA MOYENNE

;;; moyenne : Nombre^3 -> Nombre
;;; (moyenne x y z) renvoie la moyenne de 3 parametres x,y,z

(define (moyenne x y z)
  (/ (+ x y z) 3))

(moyenne 3 6 -3)
(moyenne -3 0 3)
(moyenne 1 2 1.0)


;;; moyenne-ponderee : Nombre^6 -> Nombre
;;; (moyenne-ponderee a x b y c z) renvoie la moyenne ponderee de 6 parametres
;;; formule : moyPon = (ax + by + cz)/(a + b + c)

(define (moyenne-ponderee a x b y c z)
  (/ (+ (* a x) (* b y) (* c z)) (+ a b c)))

(moyenne-ponderee 1 2 2 3 3 4)
(moyenne-ponderee 1 2 5 3 4 6)
