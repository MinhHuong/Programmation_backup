;;;;;                       ;;;;;
;;;;; DEVOIR SUR TABLE 2011 ;;;;;
;;;;;                       ;;;;;


;;;; QUESTION 1 :


;;; intervalle : nat * nat -> LISTE[nat]
;;; (intervalle n p) rend la liste contenant des entiers naturels compris entre n et p inclus en ordre croissant

(define (intervalle n p)
  (if (> n p)
      (list)
      (cons n (intervalle (+ n 1) p))))

(verifier intervalle 
	  (intervalle 2 6) => (2 3 4 5 6)
	  (intervalle 3 3) => (3))


;;; est-diviseur? : nat * nat -> bool
;;; (est-diviseur? n p) rend vrai si n est 1 diviseur de p, rend faux sinon
;;; HYPOTHESE : n non nul

(define (est-diviseur? n p)
  (= (remainder p n) 0))

(verifier est-diviseur?
	  (est-diviseur? 2 4) => #t
	  (est-diviseur? 4 2) => #f
	  (est-diviseur? 2 3) => #f)


;;; recup-diviseurs : nat * LISTE[nat] -> LISTE[nat]
;;; (recup-diviseurs n L) renvoie la liste des elements de L qui sont des diviseurs de n
;;; HYPOTHESE : L ne contient pas 0

(define (recup-diviseurs n L)
  (define (diviseur? s)
    (= (remainder n s) 0))
  (filter diviseur? L))

(verifier recup-diviseurs
	  (recup-diviseurs 13 '()) => ()
	  (recup-diviseurs 13 '(3 1 8)) => (1)
	  (recup-diviseurs 20 '(1 2 3 4 5 6 7 8 9)) => (1 2 4 5)
	  (recup-diviseurs 2 '(3 4 5 6 7)) => ())


(define (recup-bis n L)
  (if (pair? L)
      (if (est-diviseur? (car L) n)
	  (cons (car L) (recup-bis n (cdr L)))
	  (recup-bis n (cdr L)))
      (list)))

(verifier recup-bis
	  (recup-bis 13 '()) => ()
	  (recup-bis 13 '(3 1 8)) => (1)
	  (recup-bis 20 '(1 2 3 4 5 6 7 8 9)) => (1 2 4 5)
	  (recup-bis 2 '(3 4 5 6 7)) => ())


;;; liste-diviseurs : nat -> LISTE[nat]
;;; (liste-diviseurs n) rend la liste des diviseurs de n

(define (liste-diviseurs n)
  (recup-diviseurs n (intervalle 1 n)))

(verifier liste-diviseurs
	  (liste-diviseurs 12) => (1 2 3 4 6 12)
	  (liste-diviseurs 17) => (1 17)
	  (liste-diviseurs 1) => (1))


;;; liste-taille2? : LISTE[alpha] -> bool
;;; (liste-taille2? L) teste si une liste a exactement 2 elements

(define (liste-taille2? L)
  (and (pair? L) (pair? (cdr L)) (not (pair? (cddr L)))))

(verifier liste-taille2?
	  (liste-taille2? '()) => #f
	  (liste-taille2? '("je" "tu" "ils")) => #f
	  (liste-taille2? '("je" "tu")) => #t
	  (liste-taille2? '(#t)) => #f
	  (liste-taille2? '(1 2 3)) => #f
	  (liste-taille2? '(-1 7)) => #t)


;;; est-premier? : nat -> bool
;;; (est-premier? n) teste si un nombre naturel n est premier

(define (est-premier? n)
  (liste-taille2? (liste-diviseurs n)))

(verifier est-premier?
	  (est-premier? 12) => #f
	  (est-premier? 17) => #t
	  (est-premier? 1) => #f)


;;;; 
;;;; QUESTION 2 
;;;;

;;; nb-decomp : nat * nat -> nat
;;; (nb-decomp n q) calcule la valeur de d(n,q)
;;; HYPOTHESE : n > 0, q > 0

(define (nb-decomp n q)
  (cond
   ( (or (= n 1) (= q 1)) 1 )
   ( (and (> n 1) (<= n q)) (+ (nb-decomp n (- n 1)) 1) )
   ( else (+ (nb-decomp n (- q 1)) (nb-decomp (- n q) q)) )))


;;;; 
;;;; QUESTION 3
;;;;

;;; min-liste : LISTE[Nombre] -> Nombre
;;; (min-liste L) rend le nombre minimum de la liste L
;;; HYPOTHESE : L non vide

(define (min-liste L)
  (if (pair? (cdr L))
      (min (car L) (min-liste (cdr L)))
      (car L)))

(verifier min-liste
	  (min-liste '(1)) => 1
	  (min-liste '(4 1 6)) => 1
	  (min-liste '(2.0 6.6 -3.5 0.1)) => -3.5)


;;; max-liste : LISTE[Nombre] -> Nombre
;;; (max-liste L) rend le nombre maximum de la liste L
;;; HYPOTHESE : L non vide

(define (max-liste L)
  (if (pair? (cdr L))
      (max (car L) (max-liste (cdr L)))
      (car L)))

(verifier max-liste
	  (max-liste '(1)) => 1
	  (max-liste '(4 1 6)) => 6
	  (max-liste '(2.0 6.6 -3.5 0.1)) => 6.6)


;;; ecart-max : LISTE[Nombre] -> Nombre
;;; (ecart-max L) renvoie l'ecart entre le plus petit et le plus grand element de la liste L
;;; HYPOTHESE : L non vide

(define (ecart-max L)
  (- (max-liste L) (min-liste L)))

(verifier ecart-max
	  (ecart-max '(1)) => 0
	  (ecart-max '(4 1 6)) => 5
	  (ecart-max '(2.0 6.6 -3.5 0.1)) => 10.1)


;;; min-max-liste : LISTE[Nombre] -> COUPLE[Nombre Nombre]
;;; (min-max-liste L) renvoie le couple (a,b) dans lequel a est le nombre minimum et b le maximum de la liste L
;;; HYPOTHESE : L non vide

(define (min-max-liste L)
  (if (pair? (cdr L))
      (let ((res-rec (min-max-liste (cdr L))))
	(list (min (car L) (car res-rec))
	      (max (car L) (cadr res-rec))))
	(list (car L) (car L))))

(verifier min-max-liste
	  (min-max-liste '(1)) => (1 1)
	  (min-max-liste '(4 1 6)) => (1 6)
	  (min-max-liste '(2.0 6.6 -3.5 0.1)) => (-3.5 6.6))


;;; ecart-max2 : LISTE[Nombre] -> Nombre
;;; (ecart-max2 L) renvoie l'ecart entre le plus petit et le plus grand element de la liste L
;;; HYPOTHESE : L non vide

(define (ecart-max2 L)
  (let ((res-rec (min-max-liste L)))
    (- (cadr res-rec) (car res-rec))))


;;; normalise : Nombre ^ 3 -> Nombre
;;; (normalise a b x) calcule la valeur de x normalisee par a et b
;;; HYPOTHESE : a <= x <= b, a != b

(define (normalise a b x)
  (/ (- x a) (- b a)))

(verifier normalise
	  (normalise 1 10 1) => 0
	  (normalise 1 10 10) => 1
	  (normalise 1 10 8) => 7/9
	  (normalise 1 10 2) => 1/9)


;;; normalise-liste : Nombre * Nombre * LISTE[Nombre] -> LISTE[Nombre]
;;; (normalise-liste a b L) renvoie la liste des elements de L normalises par a et b

(define (normalise-liste a b L)
  (if (pair? L)
      (cons (normalise a b (car L)) (normalise-liste a b (cdr L)))
      (list)))

(verifier normalise-liste
	  (normalise-liste 1 1 '()) => ()
	  (normalise-liste 1 10 '(1 2 8 10)) => (0 1/9 7/9 1))


(define (normalise-liste-bis a b L)
  (define (normalise s)
    (/ (- s a) (- b a)))
  
  (map normalise L))

(verifier normalise-liste-bis
	  (normalise-liste-bis 1 1 '()) => ()
	  (normalise-liste-bis 1 10 '(1 2 8 10)) => (0 1/9 7/9 1))


;;;;
;;;; QUESTION 4 
;;;;


;;; nb-diff : LISTE[alpha] * LISTE[alpha] -> nat
;;; (nb-diff L1 L2) renvoie le nombre d'elements de L1 et L2 de meme rang qui sont differents 
;;; HYPOTHESE : L1 et L2 ont la meme longueur

(define (nb-diff L1 L2)
  (if (pair? L1)
      (if (not (equal? (car L1) (car L2)))
	  (+ 1 (nb-diff (cdr L1) (cdr L2)))
	  (nb-diff (cdr L1) (cdr L2)))
      0))

(verifier nb-diff
	  (nb-diff '() '()) => 0
	  (nb-diff '("a" "b" "c") '("A" "B" "C")) => 3
	  (nb-diff '("a" "b" "c") '("a" "B" "C")) => 2
	  (nb-diff '(1 2 3) '(4 5 6)) => 3
	  (nb-diff '(4 5 6) '(5 6 7)) => 3
	  (nb-diff '(4 5 6) '(6 5 4)) => 2
	  (nb-diff '(7 8 9 10 11) '(7 8 9 10 11)) => 0)


;;; insertion-avant : alpha * alpha * LISTE[alpha] -> LISTE[alpha]
;;; (insertion-avant x y L) rend une liste L dans laquelle x a ete ajoute devant la premiere occurrence de y
;;; si y apparait dans L, a la fin sinon

(define (insertion-avant x y L)
  (if (pair? L)
      (if (equal? y (car L))
	  (cons x L)
	  (cons (car L) (insertion-avant x y (cdr L))))
      (list x)))

(verifier insertion-avant
	  (insertion-avant "a" "z" '("b" "c" "z" "d" "z")) => ("b" "c" "a" "z" "d" "z")
	  (insertion-avant "a" "z" '("z" "z")) => ("a" "z" "z")
	  (insertion-avant "a" "y" '("b" "c" "z")) => ("b" "c" "z" "a")
	  (insertion-avant "a" "y" '()) => ("a")
	  (insertion-avant 1 2 '(5 4 3 2 1)) => (5 4 3 1 2 1))


;;; suppr-nieme : LISTE[alpha] * nat -> LISTE[alpha]
;;; (suppr-nieme L n) renvoie la liste L privee de son n-ieme element si L contient au moins n element, rend L sinon
;;; HYPOTHESE : n > 0

(define (suppr-nieme L n)
  (if (pair? L)
      (if (= n 1)
	  (cdr L)
	  (cons (car L) (suppr-nieme (cdr L) (- n 1))))
      (list)))

(verifier suppr-nieme
	  (suppr-nieme '("a" "b" "c" "d") 1) => ("b" "c" "d")
	  (suppr-nieme '("a" "b" "c" "d") 2) => ("a" "c" "d")
	  (suppr-nieme '("a" "b" "c" "d") 6) => ("a" "b" "c" "d")
	  (suppr-nieme '() 2) => ()
	  (suppr-nieme '(0 1 2 3 4 5 6) 4) => (0 1 2 4 5 6))
