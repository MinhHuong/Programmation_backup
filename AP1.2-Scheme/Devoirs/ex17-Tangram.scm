;;; EXERCICE 17 : TANGRAM

;;; scale-draw-line : Nombre ^ 5 -> Image
;;; (scale-draw-line s x y z t) trace un segment sur lequel on applique un facteur d'echelle
;;; HYPOTHESE : s,x,y,z,t appartiennent a [-1,1]

(define (scale-draw-line s x y z t)
  (draw-line (* s x) (* s y) (* s z) (* s t)))


;;; scale-square : Nombre ^ 4 -> Image
;;; (scale-square s) rend l'image d'un contour
;;; HYPOTHESE : 0 <= s <= 1

(define (scale-square s)  
  (overlay
   (scale-draw-line s -1 -1 -1 1)
   (scale-draw-line s -1 1 1 1)
   (scale-draw-line s 1 1 1 -1)
   (scale-draw-line s 1 -1 -1 -1)))


;;; scale-tangram : Nombre ^ 4 -> Image
;;; (scale-tangram s) rend l'image d'un tangram selon le facteur d'echelle
;; HYPOTHESE : 0 <= s <= 1

(define (scale-tangram s)
  (overlay
   (scale-draw-line s -1 -1 1 1)
   (scale-draw-line s -1 1 0.5 -0.5)
   (scale-draw-line s 0 -1 1 0)
   (scale-draw-line s 0.5 0.5 1 0)
   (scale-draw-line s -0.5 -0.5 0.5 -0.5)
   (scale-square s)))

(scale-tangram 0.9)
(scale-tangram 0.75)
(scale-tangram 0.5)
(scale-tangram 0.25)
(scale-tangram 0)
(scale-tangram 1)
