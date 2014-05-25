;;; EXERCICE 59 :

;;; augmentation : alpha * LISTE[COUPLE[alpha nat]] -> LISTE[COUPLE[alpha nat]]
;;; (augmentation e L) renvoie la liste d'associations initiale dans laquelle la frequence de l'element a
;;; a ete augmente 1

(define (augmentation e L)
  (if (pair? L)
      (if (equal? (caar L) e)
          (cons (list (caar L) (+ 1 (cadar L))) (cdr L))
          (cons (car L) (augmentation e (cdr L))))
      (cons (list e 1) ())))

(verifier augmentation
          (augmentation 'a '()) => ((a 1))
          (augmentation 'a '((b 1) (c 1))) => ((b 1) (c 1) (a 1))
          (augmentation 'c '((b 1) (c 1) (a 1))) => ((b 1) (c 2) (a 1)))


;;; frequence : LISTE[alpha] -> LISTE[COUPLE[alpha nat]]
;;; (frequence L) renvoie la liste d'associations correspondant a la frequence d'apparition 
;;; de chaque element dans la liste

(define (frequence L)
  (if (pair? L)
      (augmentation (car L) (frequence (cdr L)))
      (list)))

(verifier frequence
          (frequence '(a b a b c b)) => ((b 3) (c 1) (a 2))
          (frequence '(a b c d e)) => ((e 1) (d 1) (c 1) (b 1) (a 1))
          (frequence '()) => ())


;;; nbre-occ : alpha * LISTE[alpha] -> nat
;;; (nbre-occ e L) renvoie le nombre d'occurrences dans la liste L

(define (nbre-occ e L)
  (if (pair? L)
      (let ((Freq (frequence L)))
        (if (assoc e Freq)
            (cadr (assoc e Freq))
            0))
      0))

(verifier nbre-occ
          (nbre-occ 'a '(a b a c d a b)) => 3
          (nbre-occ 'a '(c d b b b)) => 0)


;;; tous-plus-frequents? : nat * LISTE[COUPLE[alpha nat]] -> bool
;;; (tous-plus-frequents? n L) rend vrai si tous les elements de la liste d'associations L ont la frequence
;;; superieure ou egale au nombre n donne, rend faux sinon.

(define (tous-plus-frequents? n L)
  (if (pair? L)
      (and (<= n (cadar L)) (tous-plus-frequents? n (cdr L)))
      #t))

(verifier tous-plus-frequents
          (tous-plus-frequents? 5 '()) => #t
          (tous-plus-frequents? 3 '((b 3) (c 4) (a 2))) => #f
          (tous-plus-frequents? 2 (frequence '(a b d a c d a b c))) => #t)


;;; liste-plus-frequents : nat * LISTE[COUPLE[alpha nat]] -> LISTE[COUPLE[alpha nat]]
;;; (liste-plus-frequents n L) renvoie la liste d'associations des elements 
;;; dont la frequence est superieure ou egale au nombre n donne

(define (liste-plus-frequents n L)
  (if (pair? L)
      (if (<= n (cadar L))
          (cons (car L) (liste-plus-frequents n (cdr L)))
          (liste-plus-frequents n (cdr L)))
      (list)))

(verifier liste-plus-frequents 
          (liste-plus-frequents 3 '((b 3) (c 4) (a 2))) => ((b 3) (c 4))
          (liste-plus-frequents 2 (frequence '(a b d a a b))) => ((b 2) (a 3)))
