;; EXERCICE 24 : CALCUL DU PGCD

;;; pgcd-if : nat * nat -> nat
;;; (pgcd-if m n) renvoie le plus grand commun diviseur de 2 nombres naturels m & n

(define (pgcd-if m n)
  (if (= n 0)
      m
      (if (= m 0)
          n
          (if (< m n)
              (pgcd-if m (- n m))
              (pgcd-if (- m n) n)))))

(verifier pgcd-if
          (pgcd-if 4 0) => 4
          (pgcd-if 0 5) => 5
          (pgcd-if 23 16) => 1
          (pgcd-if 12 36) => 12)


;;; pgcd-cond : nat * nat -> nat
;;; (pgcd-if m n) renvoie le plus grand commun diviseur de 2 nombres naturels m & n

(define (pgcd-cond m n)
  (cond
   ((= n 0) m)
   ((= m 0) n)
   ((< m n) (pgcd-cond m (- n m)))
   (else (pgcd-cond (- m n) n))))

(verifier pgcd-cond
          (pgcd-cond 4 0) => 4
          (pgcd-cond 287 91) => 7
          (pgcd-cond 23 16) => 1
          (pgcd-cond 21 6) => 3)
   
    
;;; pgcd-bis : nat * nat -> nat
;;; (pgcd-bis m n) renvoie le plus grand commun diviseur de 2 nombres naturels m & n

(define (pgcd-bis m n)
  (if (= n 0)
      m
      (pgcd-bis n (remainder m n))))

(verifier pgcd-bis
          (pgcd-bis 287 91) => 7
          (pgcd-bis 4 0) => 4
          (pgcd-bis 0 5) => 5
          (pgcd-bis 23 36) => 1)
