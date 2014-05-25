;;; EXERCICE 8 : QUOTIENT & RESTE

;;;( = n (+ (* (quotient m n) m) (remainder m n)))
;;; n = qm + r
;;; q = (quotient m n)
;;; r = (remainder m n)

(verifier quotient
          (quotient 15 2) => 7
          (quotient 15 3) => 5
          (quotient 15 4) => 3
          (quotient 15 27) => 0)

(verifier remainder
          (remainder 15 2) => 1
          (remainder 15 3) => 0
          (remainder 15 4) => 3
          (remainder 15 27) => 15)
          

(verifier quotient
          (quotient 15 -4) => -3
          (quotient -15 4) => -4
          (quotient -15 -4) => 4)

(verifier remainder
          (remainder 15 -4) => 3 
          (remainder -15 4) => 1 
          (remainder -15 -4) => 1)


;;; 456 = 6 + 5*10 + 4*10*10 = (5 + 4*10)*10 + 6
;;;     = (quotient 456 100)*100 + (quotient 56 10)*10 + (remainder 56 10)

(+ (remainder 456 10) 
   (* (remainder (quotient 456 10) 10) 10) 
   (* (remainder (quotient (quotient 456 10) 10) 10) 10 10))


;;; 53980 = 0 + 8*10 + 9*100 + 3*1000 + 5*10000
