;;;; EXERCICE 1 : =====================================

;;; delete-elem : alpha * LISTE[alpha] -> LISTE[alpha]
;;; (delete-elem n L) efface l'element n de la liste L

(define (delete-elem n L)
  (if (pair? L)
      (if (equal? n (car L))
          (cdr L)
          (cons (car L) (delete-elem n (cdr L))))
      (list)))

(verifier delete-elem
          (delete-elem 3 '(1 3 4)) => (1 4)
          (delete-elem 5 '(6 7 8 9)) => (6 7 8 9)
          (delete-elem 2 '()) => ())

;;; longueur : LISTE[alpha] -> nat
;;; (longueur L) donne la taille de la liste L

(define (longueur L)
  (if (pair? L)
      (+ 1 (longueur (cdr L)))
      0))

;;; egal-liste : LISTE[alpha] * 2 -> bool
;;; (egal-liste L1 L2) teste si 2 listes sont composees de meme elements (par necessairement
;;; dans le meme ordre)

(define (egal-liste L1 L2)
  (if (and (pair? L1) (pair? L2))
      (if (= (longueur L1) (longueur L2))
          (egal-liste (cdr L1) (delete-elem (car L1) L2))
          #f)
      (and (not (pair? L1)) (not (pair? L2)))))
  
  
(verifier egal-liste
          (egal-liste '(1 2 3) '(3 2 1)) => #t
          (egal-liste '(4 5) '(5 6)) => #f
          (egal-liste '() '()) => #t
          (egal-liste '(3 4 5) '(3 4 5)) => #t)


;;;; EXERCICE 2 : =================================

;;; ajout-au-couple : alpha * LISTE[COUPLE[alpha]] -> LISTE[COUPLE[alpha]]
;;; (ajout-au-couple n L) renvoie la liste des couples L de telle sorte que n a ete ajoute
;;; a la premiere position a chaque couple

(define (ajout-au-couple n L)
  (if (pair? L)
      (cons (cons n (car L)) (ajout-au-couple n (cdr L)))
      (list)))

(verifier ajout-au-couple
          (ajout-au-couple 1 '((2 3) (4 5))) => ((1 2 3) (1 4 5))
          (ajout-au-couple 3 '((2))) => ((3 2))
          (ajout-au-couple 3 '()) => ())

;;; gen : alpha * LISTE[COUPLE[alpha]] -> LISTE[COUPLE[alpha]]
;;; (gen n L) rend la liste des couples comme : 1 (3 4 5) => ((1 4 5) (3 1 5) (3 4 1))

(define (gen n L)
  (if (pair? L)
      (cons (cons n (cdr L)) (ajout-au-couple (car L) (gen n (cdr L))))
      (list)))

(verifier gen
          (gen 1 '(2 3 4)) => ((1 3 4) (2 1 4) (2 3 1))
          (gen 4 '(2)) => ((4))
          (gen 5 '()) => ())


;;;; EXERCICE 3 : ===================================

;;; sous-liste : LISTE[alpha] * LISTE[COUPLE[alpha]] -> bool
;;; (sous-liste L1 L2) teste si L1 est une sous-liste de L2

(define (sous-liste L1 L2)
  (if (and (pair? L1) (pair? L2))
      (if (egal-liste L1 (car L2))
          #t
          (sous-liste L1 (cdr L2)))
      (and (not (pair? L1)) (not (pair? L2)))))

(verifier sous-liste
          (sous-liste '(1 3 1) '((1 2) (3) (1 3 1))) => #t
          (sous-liste '(2 3) '((1 3 4) (3 2) (1))) => #t
          (sous-liste '() '()) => #t
          (sous-liste '() '((1 2 3) (3))) => #f
          (sous-liste '(4 5) '()) => #f)

;;; remove-liste : LISTE[LISTE[alpha]] -> LISTE[LISTE[alpha]]
;;; (remove-liste L) efface les sous-listes qui sont egales (pas necessairement dans le meme
;;; ordre

(define (remove-liste L)
  (if (pair? L)
      (if (sous-liste (car L) (remove-liste (cdr L)))
          (remove-liste (cdr L))
          (cons (car L) (remove-liste (cdr L))))
      (list)))

(verifier remove-liste
          (remove-liste '( (1 3 1) (2 3) (3) (1 1 3) (2) (3 2) (3))) 
          => ((1 1 3) (2) (3 2) (3)))


;;;; EXERCICE 4 : ====================================

;;; gen-au-couple : nat * LISTE[COUPLE[alpha]] -> LISTE[COUPLE[alpha]]
;;; (gen-au-couple n L) evolue le deroulement de la fonction (gen n L)

(define (gen-au-couple n L)
  (if (pair? L)
      (append (gen n (car L)) (gen-au-couple n (cdr L)))
      (list)))

(verifier gen-au-couple
          (gen-au-couple 1 '((2 3) (4 5))) => ((1 3) (2 1) (1 5) (4 1))
          (gen-au-couple 1 '((2 3) (4 5) (6 7))) => ((1 3) (2 1) (1 5) (4 1) (1 7) (6 1)))
  
;;; sub-N-gen : nat * LISTE[alpha] -> LISTE[NUPLET[alpha]]
;;; (sub-N-gen n L) renvoie les sous-listes de L dont la longueur est n

(define (sub-N-gen n L)
  (if (> n (longueur L))
      (list)
      (if (= n (longueur L))
          (list L)
          (append (gen-au-couple (car L) (sub-N-gen n (cdr L))) 
                  (sub-N-gen n (cdr L))))))

(verifier sub-N-gen
          (sub-N-gen 2 '(1 3)) => ((1 3))
          (sub-N-gen 4 '(1 2)) => ()
          (sub-N-gen 2 '(1 3 5 9)) 
          => ((1 9) (3 1) (1 3) (5 1) (1 9) (5 1) (3 9) (5 3) (5 9)))

;;; sub-N : nat * LISTE[alpha] -> LISTE[LISTE[alpha]]
;;; (sub-N n L) renvoie les sous-listes de longueur n de la liste L

(define (sub-N n L)
  (remove-liste (sub-N-gen n L)))

(verifier sub-N
          (sub-N 2 '(3 4)) => ((3 4))
          (sub-N 2 '(3 4 5)) => ((3 5) (4 3) (4 5))
          (sub-N 2 '(1 3 5 9)) => ((1 3) (1 9) (5 1) (3 9) (5 3) (5 9)))