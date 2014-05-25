;;; EXERCICE 43 : SCHEMA DE HORNER

;;; horner : Nombre * LISTE[Nombre] -> Nombre
;;; (horner x L) renvoie la valeur du polynome en le nombre n, etant donne L la liste de coefficient

(define (horner x L)
  (if (pair? L)
      (if (pair? (cdr L))
          (+ (car L) (* x (horner x (cdr L))))
          (car L))
      0))

(verifier horner
          (horner 3 (list 1 3 0 5 0 1)) => 388
          (horner 2 (list 9 3 4 1 2)) => 71
          (horner 4 (list)) => 0
          (horner 5 (list 3)) => 3)
