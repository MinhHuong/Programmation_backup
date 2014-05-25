;;;;; DEVOIR FINAL 2009

;;;; EXERCICE 1 : =====================================

;;; s : nat -> Nombre
;;; (s n) donne la valeur de 1 + 1/2^2 + 1/3^2 + ... + 1/n^2
;;; HYPOTHESE : n > 0

(define (s n)
  (if (= n 1)
      1
      (+ (/ 1 (* n n)) (s (- n 1)))))

(verifier s
          (s 1) => 1
          (s 2) => 5/4
          (s 3) => 49/36)


;;; approx-pi : nat -> Nombre
;;; (approx-pi n) donne la valeur approchee de pi au rang n 
;;; HYPOTHESE : n > 0

(define (approx-pi n)
  (sqrt (* 6 (s n))))



;;;; EXERCICE 2 : =======================================

;;; liste-meme-taille : LISTE[alpha] * LISTE[alpha] -> bool
;;; (liste-meme-taille L1 L2) teste si 2 listes ont la meme taille

(define (liste-meme-taille L1 L2)
  (if (and (pair? L1) (pair? L2))
      (liste-meme-taille (cdr L1) (cdr L2))
      (and (not (pair? L1)) (not (pair? L2)))))

(verifier liste-meme-taille
          (liste-meme-taille '(1 2 3) '(3 4 5)) => #t
          (liste-meme-taille '(1) '(2 3)) => #f
          (liste-meme-taille '() '()) => #t
          (liste-meme-taille '(1) '()) => #f)


;;;; EXERCICE 3 : ========================================

;;; decompose : nat -> LISTE[nat]
;;; (decompose n) rend la liste des chiffres apparaissant dans l'ecriture de n

(define (decompose n)
  (if (< n 10)
      (list n)
      (cons (remainder n 10) (decompose (quotient n 10)))))

(verifier decompose
          (decompose 567) => (7 6 5)
          (decompose 56) => (6 5)
          (decompose 5) => (5)
          (decompose 0) => (0)
          (decompose 3) => (3))

;;; renverse : LISTE[alpha] -> LISTE[alpha]
;;; (renverse L) etant donne une liste L, donne la liste composee des elements de L 
;;; dans le sens inverse

(define (renverse L)
  (if (pair? L)
      (append (renverse (cdr L)) (list (car L)))
      (list)))

(verifier renverse
          (renverse (list 1 2 3 4)) => (4 3 2 1)
          (renverse (list "je" "tu" "il")) => ("il" "tu" "je")
          (renverse (list)) => ())

;;; liste-egale? : LISTE[alpha] * LISTE[alpha] -> bool
;;; (liste-egale? L1 L2) teste si les 2 listes L1 et L2 sont egales 
;;; (composees de memes elements et ces elements dans le meme ordre)

(define (liste-egale? L1 L2)
  (if (and (pair? L1) (pair? L2))
      (if (equal? (car L1) (car L2))
          (liste-egale? (cdr L1) (cdr L2))
          #f)
      (and (not (pair? L1)) (not (pair? L2)))))

(verifier liste-egale?
          (liste-egale? (list 2 3 4) (list 1 2 3 4)) => #f
          (liste-egale? (list "je" "tu" "il") (list "je" "tu" "il")) => #t
          (liste-egale? (list "je" "tu" "elle") (list "je" "elle" "tu")) => #f
          (liste-egale? (list "je" "tu") (list)) => #f
          (liste-egale? (list) (list "je" "tu")) => #f
          (liste-egale? (list) (list)) => #t)

;;; palindrome? : nat -> bool
;;; (palindrome? n) teste si le nombre naturel n est un palindrome

(define (palindrome? n)
  (let ((chiffres (decompose n)))
    (liste-egale? chiffres (renverse chiffres))))

(verifier palindrome?
          (palindrome? 454) => #t
          (palindrome? 4) => #t
          (palindrome? 1001) => #t
          (palindrome? 100) => #f)

;;; liste-palindrome? : nat * nat -> LISTE[nat]
;;; (liste-palindrome? n m) rend la liste des entiers compris entre n et m inclus 
;;; qui sont des palindromes
;;; HYPOTHESE : n <= m

(define (liste-palindrome n m)
  (if (> n m)
      (list)
      (let ((res-rec (liste-palindrome (+ n 1) m)))
      (if (palindrome? n)
          (cons n res-rec)
          res-rec))))

(verifier liste-palindrome
          (liste-palindrome 0 10) => (0 1 2 3 4 5 6 7 8 9)
          (liste-palindrome 20 35) => (22 33)
          (liste-palindrome 100 140) => (101 111 121 131))


;;;; EXERCICE 4 : =======================================

;;; puiss : Nombre * nat -> Nombre
;;; (puiss x n) donne la valeur de x^n

(define (puiss x n)
  (if (= n 0)
      1
      (* x (puiss x (- n 1)))))

(verifier puiss
          (puiss 2 3) => 8
          (puiss 5 0) => 1)

;;; fact : nat -> nat
;;; (fact n) calcule la factorielle de l'entier n

(define (fact n)
  (if (= n 0)
      1
      (* n (fact (- n 1)))))

(verifier fact
          (fact 0) => 1
          (fact 1) => 1
          (fact 2) => 2
          (fact 3) => 6
          (fact 4) => 24
          (fact 5) => 120)

;;; u : Nombre * nat -> Nombre
;;; (u x n) donne la valeur de la suite u.x(n)

(define (u x n)
  (if (= n 0)
      1
      (+ (u x (- n 1)) (/ (* (puiss (- 1) n) (puiss x (* 2 n))) (fact (* 2 n))))))

;;; u-liste : Nombre * nat -> LISTE[Nombre]
;;; (u-liste x n) renvoie la liste de ( u.x(n) u.x(n-1) ... u.x(1) u.x(0) )

(define (u-liste x n)
  (if (= n 0)
      (list 1)
      (cons (u x n)
            (u-liste x (- n 1)))))

(verifier u-liste
          (u-liste pi 0) => (1)
          (u-liste pi 3) => (-1.2113528429825005 0.1239099258720886 -3.934802200544679 1))

;;; v-liste : Nombre * nat -> LISTE[Nombre]
;;; (v-liste x n) donne la liste de ( v.x(n) v.x(n-1) ... v.x(1) v.x(0) )

(define (v-liste x n)
  (if (= n 0)
      (list 1)
      (if (= n 1)
          (list (- 1 (/ (* x x) 2)))
          (let ((res-rec1 (v-liste x (- n 1)))
                (res-rec2 (v-liste x (- n 2))))
            (cons (- res-rec1 
                     (/ (* (- res-rec1 res-rec2) (* x x))
                        (* 2 n (- (* 2 n) 1))))
                  res-rec1)))))

(verifier v-liste
          (u-liste pi 0) => (1)
          (u-liste pi 3) => (-1.2113528429825005 0.1239099258720886 -3.934802200544679 1))


;;;; EXERCICE 5 : ==================================

;;; insertion-triee : Nombre * LISTE[Nombre] -> LISTE[Nombre]
;;; (insertion-triee x L) renvoie la liste ou x a ete ajoutee de telle sorte que
;;; les elements sont toujours ranges en ordre croissant
;;; HYPOTHESE : L est deja range en ordre croissant

(define (insertion-triee x L)
  (if (pair? L)
      (if (>= x (car L))
          (cons (car L) (insertion-triee x (cdr L)))
          (cons x L))
      (list x)))

(verifier insertion-triee
          (insertion-triee 3 (list 1 2 4 5)) => (1 2 3 4 5)
          (insertion-triee 3.5 (list 4.5 8.0)) => (3.5 4.5 8.0)
          (insertion-triee 3 (list 1 2 3 4)) => (1 2 3 3 4)
          (insertion-triee 47 (list 13 20 45)) => (13 20 45 47)
          (insertion-triee 47 (list)) => (47))

;;; tri-insertion : LISTE[Nombre] -> LISTE[Nombre]
;;; (tri-insertion L) renvoie la liste L triee selon l'algorithme ci-dessus

(define (tri-insertion L)
  (if (pair? L)
      (insertion-triee (car L) (tri-insertion (cdr L)))
      (list)))

(verifier tri-insertion
          (tri-insertion '(3 6 2 5)) => (2 3 5 6)
          (tri-insertion '()) => ()
          (tri-insertion '(1)) => (1)
          (tri-insertion '(8 4)) => (4 8))