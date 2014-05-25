;;;;;
;;;;;  DEVOIR SUR TABLE 2013
;;;;;


;;;;
;;;; QUESTION 1 : ==============================================
;;;;

;;; fac : nat -> nat
;;; (fac n) rend la factorielle de n

(define (fac n)
  (if (= n 0)
      1
      (* n (fac (- n 1)))))


;;; binom : nat * nat -> nat
;;; (binom n k) rend le coefficient binomial de n et k

(define (binom n k)
  (if (< n k)
      0
      (/ (fac n) (* (fac k) (fac (- n k))))))

(verifier binom
          (binom 5 0) => 1
          (binom 5 3) => 10
          (binom 5 4) => 5
          (binom 5 5) => 1
          (binom 5 6) => 0)


;;; aks-ok? : nat * nat -> bool
;;; (aks-ok? n k) rend vrai si (binom n k) est divisible par n, rend faux sinon
;;; HYPOTHESE : 0 < k <= n

(define (aks-ok? n k)
  (= (remainder (binom n k) n) 0))


;;; aks-tous-ok? : nat * nat -> bool
;;; (aks-tous-ok? n m) rend vrai si pour tout k appartient a [1,m], (binom n k) est divisible par n,
;;; rend faux sinon
;;; HYPOTHESE : 1 < m <= n

(define (aks-tous-ok? n m)
  (if (= m 1)
      #t
      (and (aks-ok? n m) (aks-tous-ok? n (- m 1)))))


;;; aks-premier? : nat -> bool
;;; (aks-premier? n) rend vrai si n est un nombre premier, faux sinon

(define (aks-premier? n)
  (and (> n 1) (aks-tous-ok? n (- n 1))))

(verifier aks-premier?
          (aks-premier? 5) => #t
          (aks-premier? 4) => #f
          (aks-premier? 3) => #t
          (aks-premier? 2) => #t
          (aks-premier? 1) => #f
          (aks-premier? 0) => #f)


;;; liste-premiers : nat -> LISTE[nat]
;;; (liste-premiers n) donne la liste des nombres premiers qui sont inferieurs ou egaux a n

(define (liste-premiers n)
  (if (> n 1)
      (if (aks-premier? n)
          (cons n (liste-premiers (- n 1)))
          (liste-premiers (- n 1)))
      (list)))


;;; produit : nat * nat -> nat
;;; (produit m n) donne le produit des entiers compris entre m et n lorsque m < n
;;; Par convention : si m > n, (produit m n) vaut 1

(define (produit m n)
  (if (<= m n)
      (* m (produit (+ m 1) n))
      1))

(verifier produit 
          (produit 1 5) => 120
          (produit 3 5) => 60
          (produit 5 5) => 5
          (produit 6 5) => 1)


;;; binom-opt : nat * nat -> nat
;;; (binom-opt n k) se comporte comme la fonction (binom n k)

(define (binom-opt n k)
  (if (>= n k)
      (/ (produit (+ (- n k) 1) n) (produit 1 k))
      0))

(verifier binom-opt
          (binom-opt 5 0) => 1
          (binom-opt 5 3) => 10
          (binom-opt 5 4) => 5
          (binom-opt 5 5) => 1
          (binom-opt 5 6) => 0)


;;;; 
;;;; QUESTION 2 : ===============================================
;;;;

;;; non-binaire : Bit -> Bit
;;; (non-binaire b) inverse le bit de b

(define (non-binaire b)
  (if (= b 1) 0 1))


;;; non : LISTE[Bit] -> LISTE[Bit]
;;; (non B) generalise le non-binaire aux chaines de bits

(define (non B)
  (map non-binaire B))

(verifier non
          (non '(1 0)) => (0 1)
          (non '(1 1 0 0 1 0 1 0)) => (0 0 1 1 0 1 0 1)
          (non '()) => ())


;;; et-binaire : Bit * Bit -> Bit
;;; (et-binaire a b) combine 2 bits pour produire un bit resultat

(define (et-binaire a b)
  (if (and (= a 1) (= b 1))
      1
      0))


;;; et : LISTE[Bit] * LISTE[Bit] -> LISTE[Bit]
;;; (et B1 B2) combine par un et-logique les bits de B1 et B2
;;; HYPOTHESE : B1 et B2 ont la meme longueur

(define (et B1 B2)
  (if (pair? B1)
      (cons (et-binaire (car B1) (car B2)) (et (cdr B1) (cdr B2)))
      (list)))

(verifier et
          (et '(1 0 1 1 0 0 1) 
              '(0 1 1 0 0 1 1)) => (0 0 1 0 0 0 1))


;;; ou : LISTE[Bit] * LISTE[Bit] -> LISTE[Bit]
;;; (ou B1 B2) combine par un ou-logique les bits de B1 et B2
;;; HYPOTHESE : B1 et B2 ont la meme longuer

(define (ou B1 B2)
  
  ;; ou-binaire : Bit * Bit -> Bit
  ;; (ou-binaire a b) combine 2 bits par un ou-logique pour produire un bit resultat
  (define (ou-binaire a b)
    (if (and (= a 0) (= b 0))
        0
        1))
  
  (if (pair? B1)
      (cons (ou-binaire (car B1) (car B2)) (ou (cdr B1) (cdr B2)))
      (list)))

(verifier ou
          (ou '() '()) => ()
          (ou '(0 1 1) '(1 0 1)) => (1 1 1)
          (ou '(1 0 1 1 0 0 1) '(0 1 1 0 0 1 1)) => (1 1 1 1 0 1 1))


;;; non-et : LISTE[Bit] * LISTE[Bit] -> LISTE[Bit]
;;; (non-et B1 B2) combine par 1 non-et-logique les bits de B1 et B2

(define (non-et B1 B2)
  (non (et B1 B2)))

(verifier non-et
          (non-et '(1 0 1 1 0 0 1) '(0 1 1 0 0 1 1)) => (1 1 0 1 1 1 0))


;;;; 
;;;; QUESTION 4
;;;;

;;; bcd-chiffre : nat -> LISTE[Bit]
;;; (bcd-chiffre n) code un chiffre decimal en une chaine de bits de longueur 4
;;; HYPOTHESE : 0 <= n <= 9

(define (bcd-chiffre n)
  (list (remainder (quotient n 8) 2)
        (remainder (quotient n 4) 2)
        (remainder (quotient n 2) 2)
        (remainder n 2)))

(verifier bcd-chiffre
          (bcd-chiffre 0) => (0 0 0 0)
          (bcd-chiffre 1) => (0 0 0 1)
          (bcd-chiffre 2) => (0 0 1 0)
          (bcd-chiffre 3) => (0 0 1 1)
          (bcd-chiffre 4) => (0 1 0 0)
          (bcd-chiffre 5) => (0 1 0 1)
          (bcd-chiffre 6) => (0 1 1 0)
          (bcd-chiffre 7) => (0 1 1 1)
          (bcd-chiffre 8) => (1 0 0 0)
          (bcd-chiffre 9) => (1 0 0 1))


;;; bcd : LISTE[nat] -> LISTE[Bit]
;;; (bcd D) retourne le codage binaire de l'entier D code en decimal

(define (bcd D)
  (if (pair? D)
      (append (bcd-chiffre (car D)) (bcd (cdr D)))
      (list)))

(verifier bcd
          (bcd '(6 0 9)) => (0 1 1 0 0 0 0 0 1 0 0 1)
	  (bcd '(1 0 0)) => (0 0 0 1 0 0 0 0 0 0 0 0)
	  (bcd '(0)) => (0 0 0 0)
	  (bcd '()) => ())


;;; renverse : LISTE[alpha] -> LISTE[alpha]
;;; (renverse L) retourne une liste composee des elements de L en sens inverse

(define (renverse L)
  (if (pair? L)
      (append (renverse (cdr L)) (list (car L)))
      (list)))
  
(verifier renverse 
	  (renverse '(1 2 3 4 5)) => (5 4 3 2 1)
	  (renverse '(1 0 0 0 0 1 1 1 0 0 1)) => (1 0 0 1 1 1 0 0 0 0 1)
	  (renverse '()) => ())


;;; bin-inv : nat -> LISTE[Bit]
;;; (bin-inv n) retourne le codage binaire en sens inverse de l'entier n

(define (bin-inv n)
  (if (= n 0)
      (list)
      (cons (remainder n 2) (bin-inv (quotient n 2)))))

(verifier bin-inv
	  (bin-inv 609) => (1 0 0 0 0 1 1 0 0 1))


;;; bin : nat -> LISTE[Bit]
;;; (bin n) retourne le codage binaire de l'entier n

(define (bin n)
  (renverse (bin-inv n)))

(verifier bin
	  (bin 609) => (1 0 0 1 1 0 0 0 0 1))
