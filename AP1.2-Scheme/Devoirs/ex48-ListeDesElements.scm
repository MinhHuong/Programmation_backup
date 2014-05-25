;;; EXERCICE 48 : LISTE DES ELEMENTS D'UNE LISTE

;;; liste0aN : Nombre ^ 2 * nat -> LISTE[Nombre]
;;; (liste0aN u r n) renvoie la liste (u(0) u(1) ... u(n))

(define (liste0aN u r n)
  (if (= n 0)
      (list u)
      (cons u (liste0aN (* r u) r (- n 1)))))

(verifier liste0aN
          (liste0aN 1 2 0) => (1)
          (liste0aN 3 1 4) => (3 3 3 3 3))


;;; listeNaO : Nombre ^ 2 * nat -> LISTE[Nombre]
;;; (listeNa0 u r n) renvoie la liste (u(n) u(n-1)...u(0))

(define (listeNa0 u r n)
  (if (= n 0)
      (list u)
      (cons (* r (car (listeNa0 u r (- n 1)))) (listeNa0 u r (- n 1)))))

(verifier listeNa0
          (listeNa0 1 5 2) => (25 5 1)
          (listeNa0 1 0 2) => (0 0 1)
          (listeNa0 3 4 1) => (12 3))


;;; liste-fib : nat -> LISTE[nat]
;;; (liste-fib n) renvoie la liste des valeurs de la suite Fibonacci selon le nombre naturel n

(define (liste-fib n)
  (cond
   ( (= n 0) (list 1) )
   ( (= n 1) (list 1 1) )
   ( else
     (let ((resFib (liste-fib (- n 1))) (resFib2 (liste-fib (- n 2))))
     (cons (+ (car resFib) (car resFib2)) resFib)))))

(verifier liste-fib
          (liste-fib 0) => (1)
          (liste-fib 1) => (1 1)
          (liste-fib 4) => (5 3 2 1 1)
          (liste-fib 5) => (8 5 3 2 1 1))

      