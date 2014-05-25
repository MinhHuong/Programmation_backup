;;; liste_n_0 : nat -> LISTE[Nombre]
;;; (liste_n_0 n) etant donne un nombre naturel n, rend la liste (u(n) u(n-1)...u(0))

(define (liste_n_0 n)
  (if (= n 0)
      (list 4)
      (cons (+ 2 (* 4 (/ (car (liste_n_0 (- n 1))) 3))) (liste_n_0 (- n 1)))))

(verifier liste_n_0
          (liste_n_0 0) => (4)
          (liste_n_0 1) => (22/3 4)
          (liste_n_0 2) => (106/9 22/3 4)
          (liste_n_0 3) => (478/27 106/9 22/3 4))


;;; liste_0_n : nat * nat -> LISTE[Nombre]
;;; (liste_0_n x n) etant donne 1  nombre naturel n & la valeur de base x, rend la liste (u(0) u(1)...u(n))

(define (liste_0_n x n)
  (if (= n 0)
      (list x)
      (cons x (liste_0_n (+ 2 (* 4 (/ x 3))) (- n 1)))))       

(verifier liste_0_n
          (liste_0_n 4 0) => (4)
          (liste_0_n 4 1) => (4 22/3)
          (liste_0_n 4 2) => (4 22/3 106/9)
          (liste_0_n 4 3) => (4 22/3 106/9 478/27))