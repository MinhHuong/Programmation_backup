;;; EXERCICE 50 : LISTE D'UNE CERTAINE LONGUEUR

;;; lg? : nat * LISTE[alpha] -> bool
;;; (lg? n L) verifier si une liste L a de taille n

(define (lg? n L)
  (if (pair? L)
      (lg? (- n 1) (cdr L))
      (= n 0)))

(verifier lg?
          (lg? 0 (list)) => #t
          (lg? 2 (list "a" "bb" "ccc")) => #f
          (lg? 2 (list "a" "bb")) => #t)


; (define (lg-fausse? n L)
;  (if (> n 0)
;      (lg-fausse? (- n 1) (cdr L))
;      (not (pair? L)) ) )

; Cette definition est fausse car si n > (longueur L), c-a-d L est deja vide mais n > 0, 
; alors la definition continue les appels recursifs alors que L est vide ==> erreur 