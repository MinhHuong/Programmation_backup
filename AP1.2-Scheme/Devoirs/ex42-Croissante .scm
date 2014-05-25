;;; EXERCICE 42 : LISTE CROISSANTE

;;; croissante? : LISTE[Nombre] -> bool
;;; (croissante? L) rend vrai si la liste est croissante au sens large 
;;; (meme la liste vide & la liste d'un seul element est croissante, rend faux sinon

(define (croissante? L)
  ;; croissante-nonvide? : LISTE[Nombre] -> bool
  ;; (croissante-nonvide? L) fait la meme consigne que (croissante? L), mais elle prend L une liste non vide
  (define (croissante-nonvide L)
    (if (pair? (cdr L))
        (if (<= (car L) (cadr L))
            (croissante-nonvide (cdr L))
            #f)
        #t))
  
  (if (pair? L)
      (croissante-nonvide L)
      #t))

(verifier croissante?
          (croissante? (list 1 2 4 4 6 8)) => #t
          (croissante? (list 1 2 5 4 8)) => #f
          (croissante? (list 6)) => #t
          (croissante? (list)) => #t)


;;; croissante-bis? : LISTE[Nombre] -> bool
;;; (croissante-bis? L) fait la meme consigne que (croissante? L)

(define (croissante-bis? L)
  (or (not (pair? L)) (not (pair? (cdr L))) (and (<= (car L) (cadr L)) (croissante-bis? (cdr L)))))

(verifier croissante-bis
          (croissante-bis? (list 1 2 4 4 6 8)) => #t
          (croissante-bis? (list 1 2 5 4 8)) => #f
          (croissante-bis? (list 6)) => #t
          (croissante-bis? (list)) => #t)
