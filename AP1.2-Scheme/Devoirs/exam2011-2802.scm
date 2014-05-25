;;; EXAMEN 2011

;;; EXERCICE 1 :

;;; nb-triangulaire : nat -> nat

(define (nb-triangulaire k)
  (if (= k 0)
      0
      (+ k (nb-triangulaire (- k 1)))))

(verifier nb-triangulaire
          (nb-triangulaire 0) => 0
          (nb-triangulaire 1) => 1
          (nb-triangulaire 2) => 3
          (nb-triangulaire 3) => 6)


;;; liste-nb-triang : nat -> LISTE[nat]

(define (liste-nb-triang k)
  (if (= k 0)
      (list 0)
      (let ((res-rec (liste-nb-triang (- k 1))))
      (cons (+ k (car res-rec)) res-rec))))

(verifier liste-nb-triang
          (liste-nb-triang 0) => (0)
          (liste-nb-triang 1) => (1 0)
          (liste-nb-triang 2) => (3 1 0)
          (liste-nb-triang 3) => (6 3 1 0)
          (liste-nb-triang 4) => (10 6 3 1 0)
          (liste-nb-triang 5) => (15 10 6 3 1 0)
          (liste-nb-triang 6) => (21 15 10 6 3 1 0))


;;; EXERCICE 2 :

;;; liste-base-compl : void -> LISTE[COUPLE[Base]]

(define (liste-base-compl)
  (list (list "A" "T") 
        (list "T" "A")
        (list "G" "C")
        (list "C" "G")))

(verifier liste-base-compl
          (liste-base-compl) => (("A" "T") ("T" "A") ("G" "C") ("C" "G")))


;;; base-compl : string -> string

(define (base-compl s)
  (cadr (assoc s (liste-base-compl))))

(verifier base-compl
          (base-compl "A") => "T"
          (base-compl "T") => "A"
          (base-compl "G") => "C"
          (base-compl "C") => "G")


;;; brin-compl? : LISTE[Base] * LISTE[Base] -> bool

(define (brin-compl? L1 L2)
  (if (pair? L1)
      (if (pair? L2)
          (if (equal? (base-compl (car L1)) (car L2))
              (brin-compl? (cdr L1) (cdr L2))
              #f)
          #f)
      (not (pair? L2))))

(verifier brin-compl?
          (brin-compl? (list) (list)) => #t
          (brin-compl? (list) '("A" "T")) => #f
          (brin-compl? '("G" "C") (list)) => #f
          (brin-compl? '("G") '("C")) => #t
          (brin-compl? '("A" "T" "G" "C") '("A" "A" "C" "G")) => #f
          (brin-compl? '("A" "T" "G" "C") '("T" "A" "C" "G")) => #t)


;;; brin-compl : LISTE[Base] -> LISTE[Base]

(define (brin-compl L)
  (map base-compl L))

(verifier brin-compl
          (brin-compl '()) => ()
          (brin-compl '("A" "A" "A" "T" "T" "T" )) => ("T" "T" "T" "A" "A" "A")
          (brin-compl '("A" "T" "G" "C")) => ("T" "A" "C" "G")
          (brin-compl '("C" "C")) => ("G" "G")
          (brin-compl '("G")) => ("C")
          (brin-compl '("A" "T" "A" "T" "A" "T" )) => ("T" "A" "T" "A" "T" "A"))


;;; brin-prefixe : LISTE[Base] * LISTE[Base] -> bool

(define (brin-prefixe? L1 L2)
  (if (pair? L1)
      (if (pair? L2)
          (if (equal? (car L1) (car L2))
              (brin-prefixe? (cdr L1) (cdr L2))
              #f)          
          #f)
      #t))

(verifier brin-prefixe?
          (brin-prefixe? '() '("A" "T")) => #t
          (brin-prefixe? '("A") '("A" "T")) => #t
          (brin-prefixe? '("A" "T") '("A" "T")) => #t
          (brin-prefixe? '("A" "T" "G") '("A" "T")) => #f
          (brin-prefixe? '("A") '()) => #f
          (brin-prefixe? '("C") '("A" "T")) => #f)


;;; sous-brin? : LISTE[Base] ^ 2 -> bool

(define (sous-brin? L1 L2)
  (if (pair? L1)
      (if (pair? L2)
          (if (brin-prefixe? L1 L2)
              #t
              (sous-brin? L1 (cdr L2)))
          #f)
      #t))

(verifier sous-brin?
          (sous-brin? '() '()) => #t
          (sous-brin? '("A" "T") '()) => #f
          (sous-brin? '() '("A" "T")) => #t
          (sous-brin? '("A" "G") '("T" "C" "A" "A" "G")) => #t
          (sous-brin? '("A" "G") '("C" "A" "A" "G")) => #t
          (sous-brin? '("A" "G") '("A" "A" "G")) => #t
          (sous-brin? '("A" "G") '("A" "G")) => #t
          (sous-brin? '("A" "G") '("G")) => #f
          (sous-brin? '("T") '("T" "C" "A" "A" "G")) => #t
          (sous-brin? '("T" "G") '("T" "C" "A" "A" "G")) => #f)


;;; nb-occ-brin : LISTE[Base] ^ 2 -> nat

(define (nb-occ-brin L1 L2)
  (if (pair? L2)
      (if (brin-prefixe? L1 L2)
          (+ 1 (nb-occ-brin L1 (cdr L2)))
          (nb-occ-brin L1 (cdr L2)))
      0))

(verifier nb-occ-brin
          (nb-occ-brin '("A" "G") '()) => 0
          (nb-occ-brin '("A" "G") '("G" "C")) => 0
          (nb-occ-brin '("A" "G") '("A" "G")) => 1
          (nb-occ-brin '("A" "G") '("G" "A" "G")) => 1
          (nb-occ-brin '("A" "A") '("A" "A" "A" "A")) => 3
          (nb-occ-brin '("A" "G") '("A" "G" "A" "G")) => 2
          (nb-occ-brin '("C" "T") '("A" "A" "A" "A")) => 0)