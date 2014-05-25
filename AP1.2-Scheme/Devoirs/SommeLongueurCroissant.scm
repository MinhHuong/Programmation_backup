;;; somme : LISTE[Nombre] -> Nombre
;;; (somme L) rend la somme des elements de L, rend 0 pour la liste vide

(define (somme L)
  (if (pair? L)
      (+ (car L) (somme (cdr L)))
      0))


;;; longueur : LISTE[alpha] -> nat
;;; (longueur L) renvoie la longueur d'une liste

(define (longueur L)
  (if (pair? L)
      (+ 1 (longueur (cdr L)))
      0))

(verifier longueur
          (longueur (list 1 2 3)) => 3
          (longueur (list (list 1 3) (list 4 6))) => 2
          (longueur (list)) => 0
          (longueur 0) => 0)


;;; croissant : LISTE[alpha] -> bool
;;; (croissant L) renvoie vrai si la liste est croissante, rend faux sinon.

(define (croissant L)
  (if (pair? L)
      (if (pair? (cdr L))          
          (if (< (car L) (cadr L))
              (croissant (cdr L))
              #f)
          #t)
      #t))

(verifier croissant
          (croissant (list 1 2 3)) => #t
          (croissant (list)) => #t
          (croissant (list 5 4 3 6)) => #f
          (croissant (list 5 4 3 2)) => #f
          (croissant (list 0)) => #t)