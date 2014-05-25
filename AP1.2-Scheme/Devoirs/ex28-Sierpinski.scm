;;; sierpinski : Nombre ^ 6 * nat -> Image
;;; (sierpinski a b c d e f n) rend l'image des triangles Sierpinski 
;;; dont (a b) (c d) (e f) les coordonnes des points, n le rang du triangle
;;; HYPOTHESE : A(a,b), B(c,d) et C(e,f) ne sont pas alignes => vecteur AB != k * (vecteur AC)
;;; => (c-a)/(e-a) != (d-b)(f-b)
;;; et a,b,c,d,e,f appartiennent a [-1,1]

(define (sierpinski a b c d e f n)
  (if (= n 0)
      (fill-triangle a b c d e f)
      (overlay
       (sierpinski a b (/ (+ a e) 2) (/ (+ b f) 2) (/ (+ a c) 2) (/ (+ b d) 2) (- n 1))
       (sierpinski (/ (+ a e) 2) (/ (+ b f) 2) e f (/ (+ c e) 2) (/ (+ d f) 2) (- n 1))
       (sierpinski (/ (+ a c) 2) (/ (+ b d) 2) c d (/ (+ c e) 2) (/ (+ f d) 2) (- n 1)))))

(sierpinski -1 -1 1 -1 1 1 0)
(sierpinski -1 -1 1 -1 1 1 1)
(sierpinski -1 -1 1 -1 1 1 2)
(sierpinski -0.5 -0.75 0.5 0.5 -0.75 0.8 3)
(sierpinski -0.75 -0.25 0.5 1 -0.7 0.5 3)


;;; sierpinski-iso : Nombre^4 * nat -> Image
;;; (sierpinski-iso x y l h n) rend l'image des triangles Sierpinski, pour les triangles isoceles,
;;; dont le coin bas-gauche (x y), l: la largeur du cote de base, h: la hauteur du triangle, n: le rang 
;;; HYPOTHESE : 0 < l <= 1-x (les 3 points ne sont pas alignes & le triangle se tient dans le cadre), 
;;;             0 < h <= 1-y (ci-dessus)  
;;;             x,y appartiennent a [-1,1]

(define (sierpinski-iso x y l h n)
  (if (= n 0)
      (fill-triangle x y (+ x l) y (+ x (/ l 2)) (+ y h))
      (overlay
       (sierpinski-iso x y (/ l 2) (/ h 2) (- n 1))
       (sierpinski-iso (+ x (/ l 2)) y (/ l 2) (/ h 2) (- n 1))
       (sierpinski-iso(+ x (/ l 4)) (+ y (/ h 2)) (/ l 2) (/ h 2) (- n 1)))))

(sierpinski-iso -1 -1 2 2 0)
(sierpinski-iso -1 -1 2 2 1)
(sierpinski-iso -1 -1 2 2 2)
(sierpinski-iso -1 -1 2 2 3)
(sierpinski-iso -0.5 -1 1.5 1.75 3)


;;; sierpinski-equi : Nombre^3 * nat -> Image
;;; (sierpinski-equi x y l n) rend l'image des triangles Sierpinski, pour les triangles equilateraux
;;; dont le coin bas-gauche (x y), l: la longueur d'un cote, n: le rang du triangle
;;; HYPOTHESE : 0 < l <=  1-x (les 3 points ne sont pas alignes & le triangle se tient dans le cadre)
;;;             0 < (sqrt 3)*l/2 <= 1-y (la hauteur d'un triangle equilateral) 
;;; x,y appartiennent a [-1,1]

(define (sierpinski-equi x y l n)
  (let ((h (* l (sqrt 3) 0.5)))
    (if (= n 0)
        (fill-triangle x y (+ x l) y (+ x (/ l 2)) (+ y h))
        (overlay
         (sierpinski-equi x y (/ l 2) (- n 1))
         (sierpinski-equi (+ x (/ l 2)) y (/ l 2) (- n 1))
         (sierpinski-equi (+ x (/ l 4)) (+ y (/ h 2)) (/ l 2) (- n 1))))))

(sierpinski-equi -1 -1 2 0)
(sierpinski-equi -1 -1 2 1)
(sierpinski-equi -1 -1 2 2)
(sierpinski-equi -1 -1 2 3)
