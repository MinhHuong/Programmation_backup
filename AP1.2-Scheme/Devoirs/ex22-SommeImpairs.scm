;;; EXERCICE 22 : SOMME DES N PREMIERS IMPAIRS

;;; somme-impairs : nat -> nat
;;; (somme-impairs n) rend la somme de n premiers entiers naturels impairs

(define (somme-impairs n)
  (if (= n 0)
      0
      (+ (- (* 2 n) 1) (somme-impairs (- n 1)))))

(verifier somme-impairs
          (somme-impairs 0) => 0
          (somme-impairs 1) => 1
          (somme-impairs 2) => 4
          (somme-impairs 3) => 9
          (somme-impairs 4) => 16
          (somme-impairs 5) => 25)
