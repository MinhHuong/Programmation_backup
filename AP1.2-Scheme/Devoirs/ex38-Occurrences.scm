;;; EXERCICE 38 : NOMBRE D'OCCURRENCES D'1 ELEMENT DANS 1 LISTE

;;; nombre-occurrences : alpha * LISTE[alpha] -> nat
;;; (nombre-occurrences e L) rend le nombre d'occurrences de e dans L, rend 0 si la liste est vide

(define (nombre-occurrences e L)
  (if (pair? L)
      (if (equal? e (car L))
          (+ 1 (nombre-occurrences e (cdr L)))
          (nombre-occurrences e (cdr L)))
      0))

(verifier nombre-occurrences
          (nombre-occurrences 3 (list 1 3 2 3 6 5)) => 2
          (nombre-occurrences 3 (list)) => 0
          (nombre-occurrences "me" (list "me" "ma" "me" "meuh" "me")) => 3)
