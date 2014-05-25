;;; EXERCICE 45 : LISTE DES ELEMENTS PLUS GRANDS QU'UN NOMBRE DONNE

;;; plus-grands : Nombre * LISTE[Nombre] -> LISTE[Nombre]
;;; (plus-grands e L) etant donne le nombre e & la liste L, rend la liste des elements de L
;;; qui sont superieurs ou egaux a e

(define (plus-grands e L)
  (if (pair? L)
      (if (>= (car L) e)
          (cons (car L) (plus-grands e (cdr L)))
          (plus-grands e (cdr L)))
      (list)))

(verifier plus-grands
          (plus-grands 3 (list 1 8 2 4 5 5 3)) => (8 4 5 5 3)
          (plus-grands 8 (list 2 4 3 1 5)) => ())
