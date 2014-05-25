;;; EXAM 2013 :

;;; EXERCICE 1 :

;;; maj-note : Nombre -> Nombre
;;; (maj-note x) majore la note entree selon 1 critere determine
;;; HYPOTHESE : 0 <= x  <= 20

(define (maj-note x)
  (cond 
   ( (and (>= x 9.5) (< x 12.0)) (+ x 0.5) )
   ( (and (>= x 12.0) (< x 15.0)) (+ x 1.0) )
   ( (and (>= x 15.0) (< x 18.0)) (+ x 1.5) )
   ( (>= x 18.0) 20.0 )
   ( else x )))

(verifier maj-note
          (maj-note 8) => 8
          (maj-note 9.5) => 10.0
          (maj-note 12) => 13.)


;;; maj-L-notes : LISTE[Nombre] -> LISTE[Nombre]
;;; (maj-L-notes L) majore les notes dans la liste L
 
(define (maj-L-notes L)
  (map maj-note L))

(verifier maj-L-notes
          (maj-L-notes '(8 9.5 12 10 17 13 19 14)) => (8 10. 13. 10.5 18.5 14. 20. 15.)
          (maj-L-notes '()) => ())


;;; EXERCICE 2

;;; syr : nat * nat -> nat
;;; (syr a n) rend la valeur de la fonction Syracuse 
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


;;; orbite : nat ^ 3 -> LISTE[nat]
;;; (orbite a p k) rend l'orbite au rang k pour a
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
;;; (max-liste L) rend le nombre plus grand de la liste L

(define (max-liste L)
  (if (pair? (cdr L))
      (max (car L) (max-liste (cdr L)))
      (car L)))


;;; apogee : Nat * Nat * Nat -> Nat
;;; (apogee a p k) renvoie le plus grand nombre apparaissant dans
;;; l’orbite au rang k de p pour a.
;;; HYPOTHESE : a > 1

(define (apogee a p k)
  (max-liste (orbite a p k)))

(verifier apogee
          (apogee 2 7 15) => 26)


;;; mys : nat * nat * nat -> Nat
;;; (mys a p k) rend le plus grand nombre dans la liste formee par (orbite a p k)
;;; (meme travail que apogee)


;;; EXERCICE 3

;;;liste-reste : LISTE[int] * int -> LISTE[int]
;;;(liste-reste L d) rend la liste des restes de la division euclienne par d
;;; des éléments de la liste d’origine
;;; HYPOTHESE : d non nul

(define (liste-reste L n)
  (if (pair? L)
      (cons (remainder (car L) n) (liste-reste (cdr L) n))
      (list)))

(verifier liste-reste
          (liste-reste (list 2 4 6 8 10) 2) => (0 0 0 0 0)
          (liste-reste (list 1 2 3 4 5 6 7 8 9 10) 10) => (1 2 3 4 5 6 7 8 9 0)
          (liste-reste (list 3 5 7 9 11) 2) => (1 1 1 1 1)
          (liste-reste (list) 4) => ()
          (liste-reste (list 3 8 10 12 15 98 102) 10) => (3 8 0 2 5 8 2))


;;; puiss: Nombre * nat -> Nombre
;;; (puiss x n) rend x^n

(define (puiss x n)
  (if (= n 0)
      1
      (* x (puiss x (- n 1)))))


;;; liste-puiss: Nombre * nat -> LISTE[Nombre]
;;; (liste-puiss x n) rend la liste des n premières puissances de x

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
;;; (ruban-pascal d p) rend la liste des restes de la division euclidienne des p premieres puissances 
;;; de 10 par d

(define (ruban-pascal d p)
  (liste-reste (liste-puiss 10 p) d))

(verifier ruban-pascal
          (ruban-pascal 1 5) => (0 0 0 0 0)
          (ruban-pascal 2 5) => (1 0 0 0 0)
          (ruban-pascal 3 10) => (1 1 1 1 1 1 1 1 1 1)
          (ruban-pascal 7 10) => (1 3 2 6 4 5 1 3 2 6))


;;; nb-chiffre : nat -> nat
;;; (nb-chiffre n) rend le nombre de chiffres significatifs dans l’écriture
;;; de l’entier n en base 10

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
;;; (liste-chiffre n) rend la liste des chiffres de l’écriture de n
;;; en base 10, le chiffre des unités en tête de la liste résultat

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
;;; (mult-liste L1 L2) rend la somme des produits des elements de L1 & L2 de meme rang
;;; HYPOTHESE : L1 et L2 ont la meme longueur

(define (mult-liste L1 L2)
  (if (pair? L1)
      (+ (* (car L1) (car L2)) (mult-liste (cdr L1) (cdr L2)))
      0))

(verifier mult-liste
          (mult-liste (list 1 4 9) (list 1 10 100)) => 941
          (mult-liste (list 4 9) (list 10 100)) => 940
          (mult-liste (list 9) (list 100)) => 900
          (mult-liste (list) (list)) => 0)


;;; nombre-P: nat * nat -> nat
;;; (nombre-P n d) rend la somme des produits des éléments de la
;;; liste des chiffres composants l’écriture de n et des éléments du ruban
;;; de Pascal dont la longueur est égale au nombre de chiffres dans l’écriture
;;; de n
;;; HYPOTHESE : d est non nul

(define (nombre-P n d)
  (mult-liste (liste-chiffre n) (ruban-pascal d (nb-chiffre n))))

(verifier nombre-P
          (nombre-P 4321 7) => 37
          (nombre-P 4321 10) => 1
          (nombre-P 2 5) => 2)


;;; liste-longueur : nat -> COUPLE[LISTE[nat] nat]
;;; (liste-longueur n) rend un couple forme de la liste des chiffres de n & du nombre de chiffres 
;;; dans l'ecriture de n

(define (liste-longueur n)
  (if (< n 10)
      (list (list n) 1)
      (let* ((quot (quotient n 10))
            (res-rec (liste-longueur quot)))
      (list (cons (remainder n 10) (car res-rec))
            (+ 1 (cadr res-rec))))))

(verifier liste-longueur 
          (liste-longueur 1) => ((1) 1)
          (liste-longueur 12) => ((2 1) 2)
          (liste-longueur 123) => ((3 2 1) 3)
          (liste-longueur 1234) => ((4 3 2 1) 4))


;;; nombre-P-bis : nat * nat -> nat
;;; (nombre-P-bis n d) rend la somme des produits des éléments de la
;;; liste des chiffres composants l’écriture de n et des éléments du ruban
;;; de Pascal dont la longueur est égale au nombre de chiffres dans l’écriture
;;; de n
;;; HYPOTHESE : d est non nul

(define (nombre-P-bis n d)
  (let ((res-rec (liste-longueur n)))
    (mult-liste (car res-rec) (ruban-pascal d (cadr res-rec)))))

(verifier nombre-P-bis
          (nombre-P-bis 4321 7) => 37
          (nombre-P-bis 4321 10) => 1
          (nombre-P-bis 2 5) => 2)


;;; EXERCICE 4 :

;;; poly1: -> Poly
;;; (poly1) renvoie le polynôme P(x) = 14 + x - 4 x^2

(define (poly1)
  (list 14 1 -4))


;;; poly2: -> Poly
;;; (poly2) renvoie le polynôme P(x) = x + 3 x^2 + 5 x^7

(define (poly2)
  (list 0 1 3 0 0 0 0 5))


;;; poly3: -> Poly
;;; (poly3) renvoie le polynôme P(x) = 4

(define (poly3)
  (list 4))


;;; polynul: -> Poly
;;; (polynul) renvoie le polynôme nul P(x) = 0

(define (polynul)
  (list 0))


;;; p-nul? : Poly -> bool
;;; (p-nul? P) teste si un polynome est nul on non

(define (p-nul? P)
  (and (not (pair? (cdr P))) (= (car P) 0)))

(verifier p-nul?
          (p-nul? (poly2)) => #f
          (p-nul? (poly3)) => #f
          (p-nul? (polynul)) => #t)


;;; p-degre : Poly -> nat
;;; (p-degre P) renvoie le degre du polynome P

(define (p-degre P)
  (if (pair? (cdr P))
      (+ 1 (p-degre (cdr P)))
      0))

(verifier p-degre
          (p-degre (poly1)) => 2
          (p-degre (poly2)) => 7
          (p-degre (poly3)) => 0
          (p-degre (polynul)) => 0)


;;; p-valeur : Nombre * Poly -> Nombre
;;; (p-valeur x P) renvoie la valeur du polynome P en x

(define (p-valeur x P)
  (if (pair? P)
      (+ (car P) (* x (p-valeur x (cdr P))))
      0.0))

(verifier p-valeur
          (p-valeur 0.0 (poly1)) => 14.0
          (p-valeur 1.0 (poly1)) => 11.0
          (p-valeur 2.0 (poly1)) => 0.0
          (p-valeur 2.5 (polynul)) => 0.)


;;; p-racine? : Nombre * Poly -> bool
;;; (p-racine? x P) teste si x est racine de P 

(define (p-racine? x P)
  (= (p-valeur x P) 0))

(verifier p-racine
          (p-racine? 0.0 (poly1) ) => #f
          (p-racine? 1.0 (poly1) ) => #f
          (p-racine? 2.0 (poly1) ) => #t
          (p-racine? 2.5 (polynul) ) => #t)


;;; EXERCICE 5 :

;;; p-add: Poly * Poly -> Poly
;;; (p-add P1 P2) effectue l'addition de deux polynomes

(define (p-add P1 P2)
  (if (and (pair? P1) (pair? P2))
      (cons (+ (car P1) (car P2)) (p-add (cdr P1) (cdr P2)))
      (if (pair? P1)
          P1
          P2)))

(verifier p-add
          (p-add (poly1) (polynul)) => (14 1 -4)
          (p-add (polynul) (poly2)) => (0 1 3 0 0 0 0 5)
          (p-add (poly1) (poly2)) => (14 2 -1 0 0 0 0 5))


;;; p-add-liste : LISTE[Poly] -> Poly
;;; (p-add-liste L) renvoie le polynome correspondant a l'addition de tous les polynomes P1 + P2 +...+ Pn

(define (p-add-liste L)
  (if (not (pair? L))
      (polynul)
      (p-add (car L) (p-add-liste (cdr L)))))

(verifier p-add-liste
          (p-add-liste (list)) => (0)
          (p-add-liste (list (poly1) (poly2))) => (14 2 -1 0 0 0 0 5)
          (p-add-liste (list (polynul) (poly1) (poly2) (poly3))) => (18 2 -1 0 0 0 0 5))


;;; p-add-liste-fct : LISTE[Poly] -> Poly
;;; (p-add-liste-fct L) renvoie le polynome correspondant a l'addition de tous les polynomes P1 + P2 +...+ Pn

(define (p-add-liste-fct L)
  (reduce p-add (polynul) L))
  
(verifier p-add-liste-fct
          (p-add-liste-fct (list)) => (0)
          (p-add-liste-fct (list (poly1) (poly2))) => (14 2 -1 0 0 0 0 5)
          (p-add-liste-fct (list (polynul) (poly1) (poly2) (poly3))) => (18 2 -1 0 0 0 0 5))
