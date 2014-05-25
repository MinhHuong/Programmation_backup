;;; Algorithme : S(n) = 0           , n = 0
;;;              S(n) = S(n-1) + n  , n > 0
;;; somme_0_n_1 : nat -> nat
;;; (somme_0_n_1 n) renvoie la somme des entiers de 0 a n

(define (somme_0_n_1 n)
  (if (= n 0)
      0
      (+ n (somme_0_n_1 (- n 1)))))

(verifier somme_0_n_1
          (somme_0_n_1 0) => 0
          (somme_0_n_1 1) => 1
          (somme_0_n_1 2) => 3
          (somme_0_n_1 3) => 6
          (somme_0_n_1 4) => 10)

;=======================================================================;

;;; Algorithme : S(n,m) = n             ,  si n = m
;;;                     = S(n,m-1) + m  ,  si n < m
;;; somme_n_m_2 : nat * nat -> nat
;;; (somme_n_m_2 n m) renvoie la somme des entiers naturels de n a m
;;; HYPOTHESE : n <= m

(define (somme_n_m n m)
  (if (= m n)     
      n
      (+ m (somme_n_m n (- m 1)))))
    
