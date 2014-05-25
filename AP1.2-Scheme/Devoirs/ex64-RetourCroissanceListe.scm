;;; EXERCICE 64 : RETOUR SUR LA CROISSANCE D'UNE LISTE


;;; QUESTION 1 : =========================================

;;; inf : Nombre * (Nombre + #f) -> (Nombre + #f)
;;; (inf x y) rend x si y est un nombre & x est inferieur ou egal a y
;;; rend #f sinon

(define (inf x y)
  (and (number? y) (<= x y) x))

(verifier inf
          (inf 2 1) => #f
          (inf 2 2) => 2
          (inf 2 3) => 2
          (inf 2 #f) => #f
          (inf 2 #t) => #f)


;;; croissance-reduce? : LISTE[Nombre] -> bool
;;; (croissance-reduce? L) teste si une liste est croissante au sens large
;;; HYPOTHESE : tous les nombres de L < 1000

(define (croissance-reduce? L)
  (and (reduce inf 1000 L) #t))

(verifier croissance-reduce?
          (croissance-reduce? (list 1 2 4 4 6 999)) => #t
          (croissance-reduce? (list 1 2 5 4 8)) => #f
          (croissance-reduce? (list 5 4 3 2 1)) => #f
          (croissance-reduce? (list 6)) => #t
          (croissance-reduce? (list)) => #t)


;;; QUESTION 3 : =========================================

;;; combine : (alpha -> alpha) * LISTE[alpha] -> alpha
;;; (combine f L) rend (f e1 (f e2 ...(f eN-1 eN) ...))
;;; si L est la liste non vide (e1 e2 ... eN).
;;; ERREUR lorsque la liste est vide

(define (combine f L)

  ;; dernier_elem : LISTE[alpha] -> alpha
  ;; (dernier_elem H) rend le dernier element de la liste H
  (define (dernier_elem H)
    (cond
     ( (not (pair? H)) #t )
     ( (not (pair? (cdr H))) (car H) )
     ( else (dernier_elem (cdr H)))))
  
  (reduce f (dernier_elem L) L))


;;; croissance-combine?  : LISTE[Nombre] -> bool
;;; (croissance-combine L) teste si une liste de nombres est croissante au sens large

(define (croissance-combine? L)
  (and (combine inf L) #t))

(verifier croissance-combine?
          (croissance-combine? (list 1 2 4 4 6 999)) => #t
          (croissance-combine? (list 1 2 5 4 8)) => #f
          (croissance-combine? (list 5 4 3 2 1)) => #f
          (croissance-combine? (list 6)) => #t
          (croissance-combine? (list)) => #t)
          
          
;;; QUESTION 5 : =========================================

;;; inf2 : (Nombre + #f) * Nombre -> Nombre + #f
;;; (inf2 x y) rend y si x est un nombre, inferieur ou egal a y,
;;; et sinon rend #f

(define (inf2 x y)
  (and (number? x) (number? y) (<= x y) y))

(verifier inf2
          (inf2 4 4) => 4
          (inf2 4 5) => 5
          (inf2 4 3) => #f
          (inf2 #f 5) => #f)


;;; croissante-accumulee? : LISTE[Nombre] -> bool
;;; (croissante-accumulee L) teste si une liste de nombres est croissante au sens large

(define (croissance-accumulee? L)
  
  ;; dernier_elem : LISTE[alpha] -> alpha
  ;; (dernier_elem H) rend le dernier element de la liste H
  (define (dernier_elem H)
    (cond
     ( (not (pair? H)) #t )
     ( (not (pair? (cdr H))) (car H) )
     ( else (dernier_elem (cdr H)))))
    
  (and (reduce inf2 (dernier_elem L) L) #t))

(croissance-accumulee? (list 1 2 4 4 6 999))
(croissance-accumulee? (list 1 2 9 4 8))
(croissance-accumulee? (list 6))
(croissance-accumulee? (list))
(croissance-accumulee? (list 5 4 3 1))
