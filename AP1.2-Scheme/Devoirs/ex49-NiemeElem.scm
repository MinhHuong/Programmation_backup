;;; EXERCICE 49 : RECHERCHE DE N-IEME ELEMENT DANS UNE LISTE

;;; n-ieme : nat * LISTE[alpha] -> alpha
;;; (n-ieme) rend l'element a la n-ieme position dans la liste L, rend d'erreur losrque le traitement est
;;; impossible, le message d'erreur indique pourquoi le traitement est impossible

(define (n-ieme i L)
  (if (= i 0)
      (if (pair? L)
          (car L)
          "n-ieme : position trop grande")
      (if (> i 0)
          (n-ieme (- i 1) (cdr L))
          "n-ieme : position doit etre >= 0")))
   

(verifier n-ieme
          (n-ieme 0 (list 2 3 5 7)) => 2
          (n-ieme 4 (list 2 4 3 5 7 6)) => 7
          (n-ieme 3 (list 8 2 6)) => "n-ieme : position trop grande"
          (n-ieme -1 (list 8 2)) => "n-ieme : position doit etre >= 0")
