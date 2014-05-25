;;; EXERCICE 47 : BEGAIE - DEBEGAIE

;;; begaie : LISTE[alpha] -> LISTE[alpha]
;;; (begaie L) etant donne une liste d'elements, renvoie la liste ou chaque element est repete

(define (begaie L)
  (if (pair? L)
      (append (list (car L) (car L)) (begaie (cdr L)))
      (list)))

(verifier begaie
          (begaie (list 1 2 3 1 4)) => (1 1 2 2 3 3 1 1 4 4)
          (begaie (list)) => ())


;;; debegaie : LISTE[alpha] -> LISTE[alpha]
;;; (debegaie L) etant donnee une liste begayee, renvoie le liste initiale

(define (debegaie L)
  (if (pair? L)
      (if (pair? (cdr L))
          (if (equal? (car L) (cadr L))
              (cons (car L) (debegaie (cddr L)))
              (debegaie (cdr L)))
          (list (car L)))
      (list)))

(verifier debegaie
          (debegaie (list 1 1 2 2 3 3 1 1 4 4)) => (1 2 3 1 4)
          (debegaie (begaie (list 1 2 3 1 4))) => (1 2 3 1 4)
          (debegaie (list 1 1)) => (1))


;;; debegaie-verif : LISTE[alpha] -> LISTE[alpha] ou bool
;;; (debegaie-verif L) etant donnee une liste L quelconque, signale une erreur lorsque L n’est pas begayee, 
;;; et sinon renvoie le debegaiement de L

(define (debegaie-verif L)
  (cond
   ( (not (pair? L)) (list) )
   ( (or (not (pair? (cdr L))) (not (equal? (car L) (cadr L)))) "erreur : liste non begayee")
   ( else (cons (car L) (debegaie-verif (cddr L))))))
  
  
(debegaie-verif (list 1 1 2 2 3 3 1 1 4 4)) 
(debegaie-verif (list 1 1 2 )) 
(debegaie-verif (list 1 2 3 3 4 4)) 
(debegaie-verif (list 1 1 2 3)) 
(debegaie-verif (list 1 2))
(debegaie-verif (list 3 3 5 5))