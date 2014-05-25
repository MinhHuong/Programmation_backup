;;; EXERCICE 9 : SUR L'ALTERNATIVE

;;; maximum : Nombre^3 -> Nombre
;;; (maximum x y z) renvoie le plus grand nombre parmi les 3 nombres saisis

(define (maximum x y z)
  (if (> x y)
      (if (> x z)
          x
          z)
      (if (> z y)
          z
          y)))

(verifier maximum
          (maximum 6 2 9) => 9)


;;; maximum-bis : Nombre^3 -> Nombre
;;; (maximum-bis a b c) renvoie le plus grand nombre parmi les 3 nombres saisis, en utilisant "max" dans ref

(define (maximum-bis a b c)
  (max a b c))

(verifier maximum-bis
          (maximum-bis 5 4 1) => 5)

;;; maximum-ter : Nombre^3 -> Nombre
;;; (maximum-ter t u v) renvoie le plus grand nombre parmi 3 nombres saisis, en utilisant "<=" au lieu de ">"

(define (maximum-ter t u v)
  (if (<= t u)
      (if (<= u v)
          v 
          u)
      (if (<= t v)
          v
          t)))

(verifier maximum-ter
          (maximum-ter 1 3 5) => 5
          (maximum-ter 7 4 11) => 11)
