;;; EXERCICE 61 : AUTOUR DU "FILTER"

;;; moins-occurrences : alpha * LISTE[alpha] -> LISTE[alpha]
;;; (moins-occurrences elt L) renvoie la liste privee de toutes les occurrences de cet element

(define (moins-occurrences elt L)
  (define (compare-elt? n)
    (not (equal? elt n)))
  
  (filter compare-elt? L))

(verifier moins-occurrences
          (moins-occurrences 3 (list 1 3 4 3 5 5 3)) => (1 4 5 5)
          (moins-occurrences 3 (list 2 4 1 5)) => (2 4 1 5)
          (moins-occurrences "ma" (list "ma" "me" "ma" "mi" "mo" "ma" )) => ("me" "mi" "mo"))


;;; plus-grands : Nombre * LISTE[Nombre] -> LISTE[Nombre]
;;; (plus-grands e L) rend la liste des nombres de L qui sont superieurs ou egaux a e

(define (plus-grands e L)
  (define (compare-e? n)
    (>= n e))
  
  (filter compare-e? L))

(verifier plus-grands
          (plus-grands 4 '(1 4 7 2 3 9)) => (4 7 9)
          (plus-grands 4 '()) => ())


;;; liste-plus-frequents : nat * LISTE[COUPLE[valeur nat]] -> LISTE[COUPLE[valeur nat]]
;;; (liste-plus-frequents n L) renvoie la liste d'associations des elements dont la frequence est
;;; superieure ou egale au nombre donne n

(define (liste-plus-frequents n L)
  (define (compare-frequence-n? i)
    (>= (cadr i) n))
  
  (filter compare-frequence-n? L))

(verifier liste-plus-frequents 
          (liste-plus-frequents 3 '((b 3) (c 4) (a 2))) => ((b 3) (c 4))
          (liste-plus-frequents 5 '((b 3) (c 4) (a 2))) => ()
          (liste-plus-frequents 4 '((e 1) (d 8) (b 3) (c 4) (a 2))) => ((d 8) (c 4)))


;;; liste-sup : Nombre * LISTE[LISTE[Nombre ...]] -> LISTE[LISTE[Nombre...]]
;;; (liste-sup n L) renvoie la liste contenant des elements de L dont le deuxieme element est >= a x

(define (liste-sup n L)
  (define (compare_2e_n? i)
    (and (pair? i) (pair? (cdr i)) (>= (cadr i) n)))
        
  (filter compare_2e_n? L))

(verifier liste-sup
          (liste-sup 2 '((1 2 3) (4 3) (5) () (4 1 2))) => ((1 2 3) (4 3)))


;;; N-sup : Nombre * LISTE[NUPLET[string Nombre Nombre]] -> LISTE[NUPLET[string Nombre Nombre]]
;;; (N-sup n L) renvoie la liste de n-uplets de la liste L dont le deuxieme element est >= a x

(define (N-sup n L)
  (define (compare_2e_n? i)
    (>= (cadr i) n))
  
  (filter compare_2e_n? L))

(verifier N-sup
          (N-sup 3 '((1 2 3) (4 2 4) (5 6 7) (7 6 3))) => ((5 6 7) (7 6 3)))