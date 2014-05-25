;;; liste_fib1 : nat -> LISTE[nat]
;;; (liste_fib1 n) rend la liste contenant de n valeurs de la suite Fibbonacci 
;;; dans l'ordre : (fib(n) fib(n-1)...fib(0)

(define (liste_fib1 n)
  (if (= n 0)
      (list 1)
      (if (= n 1)
          (list 1 1)
          (cons (+ (car (liste_fib1 (- n 1))) (car (liste_fib1 (- n 2)))) (liste_fib1 (- n 1))))))

(verifier liste_fib1
          (liste_fib1 0) => (1)
          (liste_fib1 1) => (1 1)
          (liste_fib1 2) => (2 1 1)
          (liste_fib1 3) => (3 2 1 1)
          (liste_fib1 4) => (5 3 2 1 1)
          (liste_fib1 5) => (8 5 3 2 1 1))