;;; EXERCICE 58 : LISTE DE LISTES


;;; liste-des-suffixes : LISTE[alpha] -> LISTE[LISTE[alpha]]
;;; (liste-des-suffixes L) etant donnee 1 liste L, rend la liste des sous-listes de L

(define (liste-des-suffixes L)
  (if (not (pair? L))
      (cons L ())
      (cons L (liste-des-suffixes (cdr L)))))

(verifier liste-des-suffixes
          (liste-des-suffixes (list "luc" "eve" "jo")) => (("luc" "eve" "jo") ("eve" "jo") ("jo") ())
          (liste-des-suffixes (list 1 2 3 4)) => ((1 2 3 4) (2 3 4) (3 4) (4) ())
          (liste-des-suffixes (list)) => (()))


;;; liste-sup : Nombre * LISTE[LISTE[Nombre]]
;;; (liste-sup) etant donnes un nombre x & 1 liste de nombre L renvoie la liste contenant des elements de L
;;; dont le deuxieme element est superieur ou egal a x

(define (liste-sup x L)
  (if (not (pair? L))
      (list)
      (let ((res (liste-sup x (cdr L))))
        (if (or (not (pair? (car L))) (not (pair? (cdar L))))
            res
            (if (>= (cadar L) x)
                (cons (car L) res)
                res)))))

(verifier liste-sup
          (liste-sup 3 '((1 2 3) (1 3 2) (3 4) (3) ())) => ((1 3 2) (3 4))
          (liste-sup 5 (list)) => ()
          (liste-sup 5 '((1 5 6) (1 3 4) (5) () (5 5))) => ((1 5 6) (5 5)))
