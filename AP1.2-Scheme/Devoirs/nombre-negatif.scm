;;; nombre-negatif1? : Valeur -> bool
;;; (nombre-negatif1? nb) renvoie vrai (#t) si le nombre saisi est negatif, faux (#f) sinon.
;;; 1re version, qui a 1 "if"

(define (nombre-negatif1? nb)
  (if (number? nb)
      (negative? nb)
      #f))

(nombre-negatif1? 3)
(nombre-negatif1? -3)
(nombre-negatif1? 0)
(nombre-negatif1? "hello")


;;; Autre definition pour la meme fonction, qui a alors un "and"
;;; nombre-negatif2? : Valeur -> bool
;;; (nombre-negatif2? n) renvoie vrai (#t) si le nombre saisi est negatif, faux (#f) sinon.

(define (nombre-negatif2? n)
  (and (number? n) (negative? n)))

(nombre-negatif2? 3)
(nombre-negatif2? -3)
(nombre-negatif2? 0)
(nombre-negatif2? "world")
  
