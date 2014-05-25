;;; EXERCICE 11 : DEFINIR ET (AND), OU (OR), NON (NOT)

;;; ou : bool * bool -> bool
;;; (ou x y) rend true lorsque x ou y vaut true

(define (ou x y)
  (if x
      #t
      y))

(verifier ou
          (ou #t #t) => #t
          (ou #t #f) => #t
          (ou #f #f) => #f)

;;; et : bool * bool -> bool
;;; (et x y) rend true lorsque x et y valent true

(define (et x y)
  (if x
      y
      #f))

(verifier et
          (et #t #f) => #f
          (et #t #t) => #t
          (et #f #f) => #f)
  
;;; non : bool -> bool
;;; (non x) rend true ssi x vaut false

(define (non x)
  (if x
      #f
      #t))

(verifier non
          (non #t) => #f
          (non #f) => #t)
