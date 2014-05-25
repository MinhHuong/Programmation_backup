;;; EXERCICE 55 : DIVISION EUCLIDIENNE

;;; quotient_reste : nat * nat -> COUPLE[nat nat]
;;; (quotient_reste m n) calcule le couple (q r) tel que m = n*q + r
;;; HYPOTHESE : n non nul

(define (quotient_reste m n)
  (if (< m n)
      (list 0 m)
      (let ((div (quotient_reste (- m n) n)))
        (list
         (+ 1 (car div)) (cadr div)))))

(verifier quotient_reste
          (quotient_reste 0 5) => (0 0)
          (quotient_reste 3 5) => (0 3)
          (quotient_reste 10 5) => (2 0)
          (quotient_reste 11 5) => (2 1))


;;; verif-euclid : nat * nat * C -> bool
;;; (verif-euclid C) verifie le resultat obtenu par la fonction precedente 

(define (verif-euclid m n C)
  (and (= (car C) (quotient m n)) (= (cadr C) (remainder m n))))

(verifier verif-euclid
          (verif-euclid 0 5 (quotient_reste 0 5)) => #t
          (verif-euclid 3 5 (quotient_reste 3 5)) => #t
          (verif-euclid 11 5 (quotient_reste 11 5)) => #t
          (verif-euclid 10 5 (quotient_reste 10 5)) => #t
          (verif-euclid 12 5 (quotient_reste 10 5)) => #f)