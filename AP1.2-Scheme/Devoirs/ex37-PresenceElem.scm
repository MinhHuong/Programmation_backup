;;; EXERCICE 37 : PRESENCE D'UN ELEMENT

;;; est-dans : alpha * LISTE[alpha] -> bool
;;; (est-dans? c L) rend vrai si et seulment si c existe dans la liste L

(define (est-dans? c L)
  (if (pair? L)
      (if (equal? c (car L))
          #t
          (est-dans? c (cdr L)))
      #f))

(verifier est-dans?
          (est-dans? 3 (list 1 8 2 3 4 )) => #t
          (est-dans? 8 (list 2 4 3 1 5)) => #f)


;;; est-dans-bis : alpha * LISTE[alpha] -> bool
;;; (est-dans-bis? c L) rend vrai si et seulemnt si c existe dans la liste L

(define (est-dans-bis? c L)
  (and (pair? L) (or (equal? c (car L)) (est-dans-bis? c (cdr L)))))

(verifier est-dans-bis?
          (est-dans-bis? 3 (list 1 8 2 3 4 )) => #t
          (est-dans-bis? 8 (list 2 4 3 1 5)) => #f)
