;;; EXERCICE 65 : HORNER

;;; horner-reduce : Nombre * LISTE[Nombre] -> Nombre
;;; (horner-reduce x L) rend l'evaluation, pour la valeur x, du polynome 
;;; a0 + a1.x + a2.x^2 + ... + an.x^n, si L estla liste de ses coefficients '(a0 a1 ... an)

(define (horner-reduce x L)
  (define (horner a b)
    (+ a (* x b)))
  
  (reduce horner 0 L))

(verifier horner-reduce
          (horner-reduce 3 (list 1 3 0 5 0 1)) => 388
          (horner-reduce 2 (list 9 3 4 1 2)) => 71
          (horner-reduce 4 (list)) => 0
          (horner-reduce 5 (list 3)) => 3)
