;;; EXERCICE 1 : PREMIER PAS EN SCHEME

;;; Question 2 :

"Tests d’egalite"
(equal? "essai" "essai")
(equal? "essai" "essai ")
(equal? "3" 3)
(equal? 4 5)
(equal? 4 4)
(equal? 4 (* 2 2))


"Tests d’egalite numerique"
;;; (= "essai" "essai")
(= 4 5)
(= 4 4)
(= (+ 2 2) 4)


"Tests sur number?"
(number? 45.12)
(number? -45)
(number? (+ 40 5))
(number? "essai")
(number? "3")


"Tests sur positive?"
(positive?
 45.12)
(positive?
 -45)
(positive?
 (+ 40 5))
;;;(positive? "essai")


"Tests sur remainder"
(remainder 10 5)
(remainder 5 10)
;;;(remainder 10 0)


"Tests d’applications"
;;;(= 3)
;;;(3 + 2)
;;;(3)
3

;;; QUESTION 3

;;; 1)

(= 100 (/ (+ 2 (* 3 (+ 4 96 )) (- 72)) 100))

(integer? 45.12)

(not #t)

(max 4 6)

(quotient 10 3)

(remainder 20 7)


;;; 2)

( > (+ 5 7) (/ 10 5) )

(odd? (- (+ 5 4) 3 ))

(even? (- (+ 5 4) 3 ))

(+ (/ 6 3) (- 8 2) (* 3 8))

;;; 3)

(+ (* 10 10 10) (* 9 10 10) (* 3 10) 6)

(+ (* 10 (+ 3 (* 10 (+ 9 (* 1 10))))) 6) 


;;; Question 4 : Dessiner

(draw-line -1 0 1 0)

(draw-line 0 1 0 -1)

(fill-triangle 1 1 -1 -1 -1 1)

(fill-triangle -1 1 0 0 -1 -1)

(fill-triangle 1 1 0 0 1 -1)

(overlay (draw-line 1 0 -1 0.5) (draw-line 1 0 -1 -0.5))

(draw-ellipse 1 1 -1 -1)

(draw-ellipse -0.5 -1 0.5 1)
         
(fill-ellipse 1 1 -1 -1)

(fill-ellipse -1 -0.5 1 0.5)

(overlay (fill-triangle -1 1 0 0 -1 -1) (fill-triangle 1 1 0 0 1 -1))

(overlay (fill-ellipse -1 -0.5 1 0.5) (fill-ellipse -0.5 -1 0.5 1)) 
         
(overlay (fill-ellipse -1 -0.5 1 0.5) (fill-ellipse -0.5 -1 0.5 1) 
         (fill-ellipse 1 1 0.3 0.3) (fill-ellipse 0.3 -1 1 -0.3)
         (fill-ellipse -1 -1 -0.3 -0.3) (fill-ellipse -1 0.3 -0.3 1))


;;; Question 5 : Dessiner un rectangle

;;; fill-rectangle1 : Nombre * Nombre * Nombre * Nombre -> Image
;;; (fill-rectangle1 x y z t) produit une image carree blanche contenant
;;; un rectangle noir (2 hinh tam giac ghep lai)
(define (fill-rectangle1 x y z t)
  (overlay
   (fill-triangle x y z t x t)
   (fill-triangle x y z t z y) ) )



;;; fill-rectangle2 : Nombre * Nombre * Nombre * Nombre -> Image
;;; (fill-rectangle2 x y z t) produit une image carree blanche contenant
;;; un rectangle noir.
;;; Dung toa do diem trai duoi (x,y) va chieu cao (z), chieu ngang (t)
(define (fill-rectangle2 x y z t)
  (overlay
   (fill-triangle x y (+ x z) (+ y t) x (+ y t))
   (fill-triangle x y (+ x z) (+ y t) (+ x z) y) ) )


(fill-rectangle1 0 0 0.45 0.75)
(fill-rectangle2 0 0 0.45 0.75)
(fill-rectangle1 -0.45 -0.45 0.60 0.45)
(fill-rectangle2 -0.45 -0.45 0.60 0.45)

