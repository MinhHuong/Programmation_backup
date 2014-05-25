;;; EXERCICE 44 : LISTE DES CARRES D'UNE LISTE

;;; carre : Nombre -> Nombre
;;; (carre n) rend le carre d'un nombre n

(define (carre n)
  (* n n))


;;; liste-carres : LISTE[Nombre] -> LISTE[Nombre]
;;; (liste-carres L) renvoie la liste des carres des elements d'une liste de nombres L

(define (liste-carres L)
  (if (pair? L)
      (cons (carre (car L)) (liste-carres (cdr L)))
      (list)))

(verifier liste-carres
          (liste-carres(list 1 8 2 4 6 5 3)) => (1 64 4 16 36 25 9))
