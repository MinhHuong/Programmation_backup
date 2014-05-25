;;; rectangle : Nombre^4 -> Image
;;; (rectangle x y l h) renvoie l'image d'un rectangle de coin bas-gauche (x,y), de largeur l & hauter h

(define (rectangle x y l h)
  (overlay 
   (fill-triangle x y (+ x l) y (+ x l) (+ y h))
   (fill-triangle x y x (+ y h) (+ x l) (+ y h))))

(rectangle -1 -1 0.25 0.25)


;;; pyramide1 : nat * Nombre^4 -> Image
;;; (pyramide1 n x y l h) renvoie l'image d'une pyramide de n etages, de coin bas-gauche (x,y), 
;;; chaque marche a pour hauteur h & largeur l
;;; HYPOTHESE : 0 <= l < (1-x)/(2n-1), 0 <= h < (1-y)/n, -1 <= x < 1, -1 <= y < 1

(define (pyramide1 n x y l h)
  (if (= n 1)
      (rectangle x y l h)
      (overlay
       (rectangle x y (* (- (* 2 n) 1) l) h) 
       (pyramide1 (- n 1) (+ x l) (+ y h) l h))))

(pyramide1 4 -1 -1 0.25 0.25)
(pyramide1 4 0.5 0.5 0.76 0.2)
(pyramide1 3 0.1 0.1 0.8 0.3)
(pyramide1 3 0.1 0.1 0.18 0.3)
(pyramide1 3 0.1 0.1 0.15 0.25)
(pyramide1 3 -1 -1 0 0)


;;; pyramide2 : nat * Nombre4 -> Image
;;; (pyramide2 n x y l h) renvoie l'image d'une pyramide de n etages, de coin bas-gauche (x,y), 
;;; chaque marche a pour hauteur h & largeur l
;;; et renvoie des erreurs si les dimensions ne sont pas compatibles
;;; HYPOTHESE : l >= 0, h >= 0, -1 <= x < 1, -1 <= y < 1

(define (pyramide2 n x y l h) 
  (if (< (- 1 x) (* (- (* 2 n) 1) l))
      "ERREUR : La largeur l de la pyramide n'est pas compatible au cadre du dessin"
      (if (< (- 1 y) (* n h))
          "ERREUR : La hauter h de la pyramide n'est pas compatible au cadre du dessin"
          (pyramide1 n x y l h))))

(pyramide2 4 -1 -1 0.25 0.25)
(pyramide2 4 -1 -1 0.5 0.5)
(pyramide2 4 -1 -1 0.25 0.75)
(pyramide2 3 0.1 0.1 0.18 0.3)


;;; pyramide3 : nat * Nombre^4 -> Image
;;; (pyramide3 n x y l h) renvoie l'image d'une pyramide de n etages, de coin bas-gauche (x,y), 
;;; chaque marche a pour hauteur h & largeur l
;;; et si les dimensions ne sont pas compatibles, elle modifie des parametres de maniere que la pyramide
;;; soit toujours tenue dans la cadre du dessin
;;; HYPOTHESE : l >= 0, h >= 0, -1 <= x < 1, -1 <= y < 1

(define (pyramide3 n x y l h)
  (cond
   ( (and (< (- 1 x) (* (- (* 2 n) 1) l)) (>= (- 1 y) (* n h))) (pyramide1 n x y (/ (- 1 x) (- (* 2 n) 1)) h))
   ( (and (< (- 1 y) (* n h)) (>= (- 1 x) (* (- (* 2 n) 1) l))) (pyramide1 n x y l (/ (- 1 y) n)))
   ( (and (< (- 1 x) (* (- (* 2 n) 1) l)) (< (- 1 y) (* n h))) (pyramide1 n x y 
                                                                          (/ (- 1 x) (- (* 2 n) 1)) 
                                                                          (/ (- 1 y) n)))
   (else (pyramide1 n x y l h))))

(pyramide3 4 -1 -1 0.5 0.5)
(pyramide3 6 -1 -1 0.5 0.75)
(pyramide3 2 -1 -1 0.25 0.25)
(pyramide3 5 -0.5 -0.5 0.25 0.25)
(pyramide3 4 0.5 0.5 0.5 0.5)
(pyramide3 2 0 0 1 1)
(pyramide3 5 0 0 1 1)
(pyramide3 3 0.9 0.9 1 1)
(pyramide3 1 0.5 0.5 0.23 0.1)