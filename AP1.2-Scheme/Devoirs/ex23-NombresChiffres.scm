;;; EXERCICES 23 : NOMBRES & CHIFFRES

;;; somme-des-chiffres : nat -> nat
;;; (somme-des-chiffres n) rend la somme des chiffres du nombre naturel n

(define (somme-des-chiffres n)
  (let ((r (remainder n 10)) (q (quotient n 10)))
  (if (= q 0)
      r
      (+ r (somme-des-chiffres q)))))

(verifier somme-des-chiffres
          (somme-des-chiffres 546) => 15
          (somme-des-chiffres 19) => 10
          (somme-des-chiffres 0) => 0
          (somme-des-chiffres 1) => 1)


;;; nombre-de-chiffres : nat -> nat
;;; (nombre-de-chiffres n) rend le nombre de chiffres signficatifs du nombre naturel n

(define (nombre-de-chiffres n)
  (let ((q (quotient n 10)))
    (if (= q 0)
        1
        (+ 1 (nombre-de-chiffres q)))))

(verifier nombre-de-chiffres 
          (nombre-de-chiffres 461) => 3
          (nombre-de-chiffres 21) => 2
          (nombre-de-chiffres 1) => 1
          (nombre-de-chiffres 0) => 1)


;;; existe-chiffre? : nat * nat -> bool
;;; (existe-chiffre? c n) rend vrai si le chiffre c est trouve dans le nombre natural n, rend faux sinon

(define (existe-chiffre? c n)
  (let ((q (quotient n 10)) (r (remainder n 10)))
    (if (= q 0)
        (= c r)
        (or (= c r) (existe-chiffre? c q)))))

(verifier existe-chiffre? 
          (existe-chiffre? 2 52) => #t
          (existe-chiffre? 5 254) => #t
          (existe-chiffre? 6 67) => #t
          (existe-chiffre? 9 13) => #f)


;;; nombre-de-bits : nat -> nat
;;; (nombre-de-bits n) rend le nombre de bits significatifs (chiffre binaire : 0 ou 1) 
;;; dans l’ecriture en base 2 d’un entier naturel n donne en base 10.

(define (nombre-de-bits n)
  (if (= (quotient n 2) 0)
      1
      (+ 1 (nombre-de-bits (quotient n 2)))))

(verifier nombre-de-bits 
          (nombre-de-bits 0) => 1
          (nombre-de-bits 2) => 2
          (nombre-de-bits 7) => 3
          (nombre-de-bits 32) => 6)


;;; nombre-de-chiffres-dans-base : nat * nat -> nat
;;; (nombre-de-chiffres-dans-base b n) rend le nombre de chiffres significatifs d'1 nombre de base 10
;;; dans le base m

(define (nombre-de-chiffres-dans-base b n)
  (if (= (quotient n b) 0)
      1
      (+ 1 (nombre-de-chiffres-dans-base b (quotient n b)))))

(verifier nombre-de-chiffres-dans-base
          (nombre-de-chiffres-dans-base 2 59) => 6
          (nombre-de-chiffres-dans-base 7 59) => 3
          (nombre-de-chiffres-dans-base 16 59) => 2)

;;; pos : nat * nat -> nat
;;; (pos x y) rend le chiffre du nombre entier x a la position y, rend 0 si la position y n'est pas dans n

(define (pos x y)
  (if (or (= y 0) (= x 0))
      0
      (if (= y 1)
          (remainder x 10)
          (pos (quotient x 10) (- y 1)))))

(verifier pos
          (pos 148 1) => 8
          (pos 148 2) => 4
          (pos 148 3) => 1
          (pos 148 4) => 0
          (pos 148 0) => 0
          (pos 0 3) => 0)
