;;; EXERCICE 63 : EXERCICES AVEC "REDUCE"

;;; QUESTION 1 :

;;; somme : LISTE[Nombre] -> Nombre
;;; (somme L) rend la somme des nombres dans la liste L

(define (somme L)
  
  (define (plus_elem a b)
    (+ a b))
  
  (reduce plus_elem 0 L))

(verifier somme
          (somme '(1 2 3 4 5)) => 15
          (somme '()) => 0
          (somme '(1)) => 1)


;;; somme-carres : LISTE[Nombre] -> Nombre
;;; (somme-carres L) rend la somme des carres des nombres dans la liste L

(define (somme-carres L)
  
  (define (plus_elem_carre a b)
    (+ (* a a) b))
  
  (reduce plus_elem_carre 0 L))

(verifier somme-carres
          (somme-carres '(1 2 3)) => 14
          (somme-carres '()) => 0
          (somme-carres '(4)) => 16)


;;; max_liste : LISTE[Nombre] -> Nombre
;;; (max_liste L) rend le maximum d'une liste non vide de nombres
;;; HYPOTHESE : L non vide

(define (max_liste L)
  
  (define (comparer a b)
    (if (>= a b) a b))

  (reduce comparer (car L) L))

(verifier max_liste
          (max_liste '(4 5 1 3 9 3 9)) => 9
          (max_liste '(1)) => 1)


;;; nombre-occurrences : LISTE[alpha] -> nat
;;; (nombre-occurrendes n L) rend le nombre d'occurrences d'un element donne dans la liste L
;;; Par convention : rend 0 si n n'existe pas dans la liste

(define (nombre-occurrences n L)
  
  (define (compter a b)
    (if (equal? a n)
        (+ 1 b)
        b))
  
  (reduce compter 0 L))

(verifier nombre-occurrences
          (nombre-occurrences 5 '(5 4 6 5 7 9 5)) => 3
          (nombre-occurrences 5 '()) => 0
          (nombre-occurrences 4 '(1 2 3 5 6)) => 0)


;;; superposition : LISTE[Image] -> Image
;;; (superposition L) etant donnee d'une liste d'images L rend l'image resultant de la superposition 
;;; de toutes les images de L

(define (superposition L)    
  (reduce overlay (empty-image) L))

(superposition (list
                (fill-triangle 0 0 1 0.5 0.5 1)
                (fill-triangle 0 0 1 -0.5 0.5 -1)
                (fill-triangle 0 0 -1 -0.5 -0.5 -1)
                (fill-triangle 0 0 -1 0.5 -0.5 1)))