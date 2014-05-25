;;; quotient-reste : nat * nat -> COUPLE[nat nat]
;;; (quotient-reste p q) rend la couple forme du quotient et du reste de la division euclidienne de p par q
;;; HYPOTHESE : p different que 0

(define (quotient_reste n p)
  (if (>= n p)
      (let ((divise (quotient_reste (- n p) p)))
        (list (+ (car divise) 1) (cadr divise)))
        (list 0 n)))

(quotient_reste 15 2)
(quotient_reste 4 3)
(quotient_reste 19 4)
(quotient_reste 15 5)
