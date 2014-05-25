;;; puissance : Nombre * nat -> Nombre
;;; (puissance x n) renvoie un nombre a la puissance n

(define (puissance x n)
  (if (< n 1)
      1
      (* x ( puissance x (- n 1)))))
(verifier puissance
          (puissance 3 3)
          (puissance 1 4)
          (puissance 4 0)
          (puissance 0.5 2)          
          (puissance -0.5 2)
          (puissance 2 10))


;;; power : Nombre * nat -> Nombre
;;; (power a b) renvoie un nombre a la puissance n

(define (power a b)
  (cond ((< b 1) 1)
        ((even? b) (* (power a (quotient b 2)) (power a (quotient b 2))))
        (else (* a (power a (quotient b 2)) (power a (quotient b 2))))))

(power 2 5)
(power 2 4)
(power 2 0)


;;; puissanceRapide : Nombre * nat -> Nombre
;;; (puissanceRapide x n) 

(define (puissanceRapide x n)
  (if (= n 0)
      1
      (let ((P (puissanceRapide x (quotient n 2))))
        (if (even? n)
            (* P P)
            (* P P x)))))

(puissanceRapide 2 3)
(puissanceRapide 2 4)


;;; fib : nat -> nat
;;; (fib n) renvoie le resultat de la suite Fibbonacci d'apres le nombre n 

(define (fib n)
  (if (or (= n 0) (= n 1)) ;; (< n 2)
      1
      (+ (fib (- n 1)) (fib (- n 2)))))

(verifier fib
          (fib 0) => 1 
          (fib 1) => 1
          (fib 2) => 2
          (fib 3) => 3
          (fib 4) => 5
          (fib 5) => 8
          (fib 6) => 13)


;;; fact : nat -> nat
;;; (fact n) renvoie le resultat de n!

(define (fact n)
  (if (= n 0)
      1
      (* n (fact (- n 1)))))

(fact 0)
(fact 1)
(fact 2)
(fact 3)
(fact 4)
(fact 5)
