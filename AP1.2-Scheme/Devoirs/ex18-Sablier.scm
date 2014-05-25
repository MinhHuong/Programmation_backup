;;; EXERCICE 18 : DESSINER LE SABLIER

;;; sablier : Nombre^4 -> Image
;;; (sablier x y l h) rend l'image d'un sablier de coin bas-gauche (x y), hauteur h & largeur l
;;; HYPOTHESE : x,y appartiennent a [-1,1], l >= 0, h >= 0

(define (sablier x y l h)
  (overlay
   (fill-triangle x y (+ x l) y (+ x (/ l 2)) (+ y (/ h 2)))
   (fill-triangle (+ x (/ l 2)) (+ y (/ h 2)) (+ x l) (+ y h) x (+ y h))))

(sablier -1 -1 2 2)
(sablier -0.5 -0.5 0.75 1.5)
(sablier 0.5 0.5 0.3 0.25)
(sablier -0.25 -0.75 0.3 0.9)
