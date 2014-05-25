;;;;;                       ;;;;;
;;;;; DEVOIR SUR TABLE 2012 ;;;;;
;;;;;                       ;;;;;


;;;; 
;;;; QUESTION 1 : =============================================================
;;;;

;;; maj-note : Nombre -> Nombre
;;; (maj-note x) majore les notes selon un critere determine
;;; HYPOTHSE : 0 <= x  <= 20

(define (maj-note x)
  (cond
   ( (< x 9.5) x )
   ( (and (>= x 9.5) (< x 12.0)) (+ x 0.5) )
   ( (and (>= x 12.0) (< x 15.0)) (+ x 1.0) )
   ( (and (>= x 15.0) (< x 18.0)) (+ x 1.5) )
   ( else 20.0)))

(verifier maj-note
	  (maj-note 8) => 8
	  (maj-note 9.5) => 10.0
	  (maj-note 12) => 13.)


;;; maj-L-notes : LISTE[Nombre] -> LISTE[Nombre]
;;; (maj-L-notes L) rend la liste obtenue en majorant toutes les notes de L selon la regle enoncee dans la question
;;; precedente
;;; HYPOTHESE : Les notes sont comprises entre 0 et 20

(define (maj-L-notes L)
  (map maj-note L))

(verifier maj-L-notes
	  (maj-L-notes '(8 9.5 12 10 17 13 19 14)) => (8 10. 13. 10.5 18.5 14. 20. 15.)
	  (maj-L-notes '()) => ())


;;;;
;;;; QUESTION 2 : ==================================================
;;;;

;;; syr : nat * nat -> nat
;;; (syr a n) renvoie la valeur de la fonction Syracuse
;;; HYPOTHESE : a > 1

(define (syr a n)
  (if (= (remainder n a) 0)
      (quotient n a)
      (+ n 1 (quotient n a))))

(verifier syr
	  (syr 2 20) => 10
	  (syr 2 9) => 14
	  (syr 3 15) => 5
	  (syr 3 10) => 14)


;;; orbite : nat * nat * nat -> LISTE[nat]
;;; (orbite a p k) renvoie l'orbite au rang k de p pour a
;;; HYPOTHESE : a > 1

(define (orbite a p k)
  (if (= k 0)
      (list p)
      (let ((res-rec (orbite a p (- k 1))))
      (cons (syr a (car res-rec)) res-rec))))

(verifier orbite
	  (orbite 2 7 15) => (1 2 1 2 1 2 4 8 5 10 20 13 26 17 11 7)
	  (orbite 3 7 15) => (47 35 26 19 14 10 7 21 63 47 35 26 19 14 10 7)
	  (orbite 3 7 0) => (7))


;;; max-liste : LISTE[Nombre] -> Nombre
;;; (max-liste L) renvoie le plus grand element de la liste L
;;; HYPOTHESE : L non vide

(define (max-liste L)
  (if (pair? (cdr L))
      (max (car L) (max-liste (cdr L)))
      (car L)))


;;; apogee : nat * nat * nat -> nat
;;; (apogee a p k) renvoie le plus grand nombre apparaissant dans l'orbite au rang k de p pour a
;;; HYPOTHESE : a > 1

(define (apogee a p k)
  (max-liste (orbite a p k)))

(verifier apogee
	  (apogee 2 7 15) => 26)


;;;;
;;;; QUESTION 3 :
;;;;

;;; liste-reste : LISTE[int] * int -> LISTE[int]
;;; (liste-reste L d) rend la liste des restes de la division euclidienne par d des elements de la liste L
;;; HYPOTHESE : d non nul

(define (liste-reste L d)
  (if (pair? L)
      (cons (remainder (car L) d) (liste-reste (cdr L) d))
      (list)))

(verifier liste-reste
	  (liste-reste '(2 4 6 8 10) 2) => (0 0 0 0 0)
	  (liste-reste '(1 2 3 4 5 6 7 8 9 10) 10) => (1 2 3 4 5 6 7 8 9 0)
	  (liste-reste '(3 5 7 9 11) 2) => (1 1 1 1 1)
	  (liste-reste '() 4) => ()
	  (liste-reste '(3 8 10 12 15 98 102) 10) => (3 8 0 2 5 8 2))


;;; puiss : Nombre * nat -> Nombre
;;; (puiss x n) rend x^n

(define (puiss x n)
  (if (= n 0)
      1
      (* x (puiss x (- n 1)))))


;;; liste-puiss : Nombre * nat -> LISTE[Nombre]
;;; (liste-puiss x n) rend la liste des n premieres puissances de x

(define (liste-puiss x n)
  (if (= n 0)
      (list)
      (append (liste-puiss x (- n 1)) (list (puiss x (- n 1))))))

(verifier liste-puiss
	  (liste-puiss 10 5) => (1 10 100 1000 10000)
	  (liste-puiss 10 3) => (1 10 100)
	  (liste-puiss 10 2) => (1 10)
	  (liste-puiss 10 1) => (1)
	  (liste-puiss 10 0) => ())


;;; ruban-pascal : nat * nat -> LISTE[nat]
;;; (ruban-pascal d p) rend la liste des restes de la division euclidienne des p premieres puissances de 10 par d
;;; HYPOTHESE : d non nul

(define (ruban-pascal d p)
  (liste-reste (liste-puiss 10 p) d))

(verifier ruban-pascal
	  (ruban-pascal 1 5) => (0 0 0 0 0)
	  (ruban-pascal 2 5) => (1 0 0 0 0)
	  (ruban-pascal 3 10) => (1 1 1 1 1 1 1 1 1 1)
	  (ruban-pascal 7 10) => (1 3 2 6 4 5 1 3 2 6))


;;; nb-chiffre : nat -> nat
;;; (nb-chiffre n) rend le nombre de chiffres significatifs de l'ecriture de l'entier n dans la base 10

(define (nb-chiffre n)
  (if (< n 10)
      1
      (+ 1 (nb-chiffre (quotient n 10)))))

(verifier nb-chiffre
	  (nb-chiffre 4321) => 4
	  (nb-chiffre 432) => 3
	  (nb-chiffre 43) => 2
	  (nb-chiffre 4) => 1
	  (nb-chiffre 1) => 1
	  (nb-chiffre 0) => 1)


;;; liste-chiffre : nat -> LISTE[nat]
;;; (liste-chiffre n) rend la liste des chiffres dans l'ecrituree de l'entier n dans la base 10,
;;; les chiffres de l'unite en tete de la liste

(define (liste-chiffre n)
  (if (< n 10)
      (list n)
      (cons (remainder n 10) (liste-chiffre (quotient n 10)))))

(verifier liste-chiffre
	  (liste-chiffre 4321) => (1 2 3 4)
	  (liste-chiffre 432) => (2 3 4)
	  (liste-chiffre 43) => (3 4)
	  (liste-chiffre 4) => (4)
	  (liste-chiffre 1) => (1)
	  (liste-chiffre 0) => (0))


;;; mult-liste : LISTE[Nombre] * LISTE[Nombre] -> Nombre
;;; (mult-liste L1 L2) rend la somme des produits des elements de L1 et L2 d meme rang.
;;; Par convention, si les 2 listes sont vides, la fonction rend 0
;;; HYPOTHESE : L1 et L2 ont la meme longueur

(define (mult-liste L1 L2)
  (if (pair? L1)
      (+ (* (car L1) (car L2)) (mult-liste (cdr L1) (cdr L2)))
      0))

(verifier mult-liste
	  (mult-liste '(1 4 9) '(1 10 100)) => 941
	  (mult-liste '(4 9) '(10 100)) => 940
	  (mult-liste '(9) '(100)) => 900
	  (mult-liste '() '()) => 0)


;;; nombre-P : nat * nat -> nat
;;; (nombre-P n d) rend la somme des produits des elements de la liste des chiffres composants de l'ecriture de n
;;; et des elements du ruban de Pascal dont la longueur est egale au nombre de chiffres dans l'ecriture de n
;;; HYPOTHESE : d non nul

(define (nombre-P n d)
  (mult-liste (liste-chiffre n) (ruban-pascal d (nb-chiffre n))))

(verifier nombre-P
	  (nombre-P 4321 7) => 37
	  (nombre-P 4321 10) => 1
	  (nombre-P 2 5) => 2)


;;; liste-longueur : nat -> COUPLE[LISTE[nat] nat]
;;; (liste-longueur n) rend un couple forme de la liste des chiffres de n 
;;; et du nombre de chiffres dans l'ecriture de n

(define (liste-longueur n)
  (if (< n 10)
      (list (list n) 1)
      (let ((res-rec (liste-longueur (quotient n 10))))
      (list (cons (remainder n 10) (car res-rec))
	    (+ 1 (cadr res-rec))))))

(verifier liste-longueur
	  (liste-longueur 1) => ((1) 1)
	  (liste-longueur 12) => ((2 1) 2)
	  (liste-longueur 123) => ((3 2 1) 3)
	  (liste-longueur 1234) => ((4 3 2 1) 4))


;;; nombre-P-bis : nat * nat -> nat
;;; (nombre-P-bis n d) rend la somme des produits des elements de la liste des chiffres composants de l'ecriture de n
;;; et des elements du ruban de Pascal dont la longueur est egale au nombre de chiffres dans l'ecriture de n
;;; HYPOTHESE : d non nul

(define (nombre-P-bis n d)
  (let ((res-rec (liste-longueur n)))
    (mult-liste (car res-rec) (ruban-pascal d (cadr res-rec)))))

(verifier nombre-P-bis
	  (nombre-P-bis 4321 7) => 37
	  (nombre-P-bis 4321 10) => 1
	  (nombre-P-bis 2 5) => 2)
