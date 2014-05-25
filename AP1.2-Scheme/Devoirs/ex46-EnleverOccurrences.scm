;;; EXERCICES 46 : ENLEVER TOUTES LES OCCURRENCES D'UN ELEMENT

;;; moins-occurrences : alpha * LISTE[alpha] -> LISTE[alpha]
;;; (moins-occurrences elt L) etant donnes un element elt et une liste L, 
;;; renvoie la liste privee de toutes les occurrences de cet element

(define (moins-occurrences elt L)
  (if (pair? L)
      (if (not (equal? (car L) elt))
          (cons (car L) (moins-occurrences elt (cdr L)))
          (moins-occurrences elt (cdr L)))
      (list)))

(verifier moins-occurrences
          (moins-occurrences 3 (list 1 3 4 3 5 5 3)) => (1 4 5 5)
          (moins-occurrences 3 (list 2 4 1 5)) => (2 4 1 5)
          (moins-occurrences "ma" (list "ma" "me" "ma" "mi" "mo" "ma" )) => ("me" "mi" "mo"))
