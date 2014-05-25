;;; EXERCICE 19 : DESSINER D'UNE TOUR

;;; tour : Nombre^4 -> Image
;;; (tour x y l h) rend l'image d'une tour de coin bas-gauche (x y), une marche est de hauteur h & largeur l
;;; et de largeur de l'etage a base L
;;; HYPOTHESE : x,y appartiennent a [-1,1], 0 <= l < L/2, h >= 0, L >= 0

(define (tour x y L l h)
  (overlay
   (fill-triangle x y (+ x L) y x (+ y h))
   (fill-triangle x (+ y h) (+ x L) y (+ x L) (+ y h))
   (fill-triangle (+ x l) (+ y h) (+ x l) (+ y (* 2 h)) (+ x (- L l)) (+ y h))
   (fill-triangle (+ x l) (+ y (* 2 h)) (+ x (- L l)) (+ y h) (+ x (- L l)) (+ y (* 2 h))))) 

(tour -1 -1 1.5 0.5 0.5)
(tour -0.5 -0.75 1.25 0.25 0.75)
(tour -0.75 -0.5 0.8 0.7 0.25)
(tour -1 -1 1.5 1 0.25)
