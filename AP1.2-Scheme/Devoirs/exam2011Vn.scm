;;; EXAMEN 2011

;;; EXERCICE 1 :

;;; f : nat -> nat

(define (f n)
  
  ;;; g : nat -> nat
  (define (g n)
    (if (= n 0)
        2
        (+ (* 2 (f (- n 1))) (g (- n 1)))))
  
  (if (= n 0)
      1
      (+ (f (- n 1)) (* 2 (g (- n 1))))))

;;; g : nat -> nat

(define (g n)
  (if (= n 0)
      2
      (+ (* 2 (f (- n 1))) (g (- n 1)))))

(verifier f
          (f 1) => 5
          (f 2) => 13)

(verifier g 
          (g 1) => 4
          (g 2) => 14)


;;; liste-fg : nat -> LISTE[COUPLE[nat nat]]

(define (liste-fg n)
  (if (= n 0)
      (list (list 1 2))
      (cons (list (+ (caar (liste-fg (- n 1))) (* 2 (cadar (liste-fg (- n 1)))))
                  (+ (* 2 (caar (liste-fg (- n 1)))) (cadar (liste-fg (- n 1)))))
            (liste-fg (- n 1)))))

(verifier liste-fg
          (liste-fg 3) => ((41 40) (13 14) (5 4) (1 2))
          (liste-fg 0) => ((1 2)))


;;; EXERCICE 2 : ==============================================

;;; plage-elt : nat * LISTE[nat] -> LISTE[nat]

(define (plage-elt x L)
  (if (pair? L)
      (if (= x (car L))  
          (cons (car L) (plage-elt x (cdr L)))
          (list))
      (list)))

(verifier plage-elt
          (plage-elt 1 '(1 1 2 1 1 1 3)) => (1 1)
          (plage-elt 1 '(1 2 1 1 1 3)) => (1)
          (plage-elt 1 '(2 1 1 1 3)) => ()
          (plage-elt 1 '(11 38)) => ()
          (plage-elt 5 '()) => ())


;;; premiere-plage: LISTE[nat] -> LISTE[nat]

(define (premiere-plage L)
  (if (pair? L)
      (plage-elt (car L) L)
      (list)))

(verifier premiere-plage
          (premiere-plage '(1 1 2 1 1 1 3)) => (1 1)
          (premiere-plage '(11 38)) => (11)
          (premiere-plage '(42)) => (42)
          (premiere-plage '()) => ())


;;; decoupe-elt : nat * LISTE[nat] -> LISTE[nat]

(define (decoupe-elt x L)
  (if (pair? L)
      (if (= x (car L))
          (decoupe-elt x (cdr L))
          L)
      (list)))

(verifier decoupe-elt
          (decoupe-elt 1 '(1 1 2 1 1 1 3)) => (2 1 1 1 3)
          (decoupe-elt 2 '(1 1 2 1 1 1 3)) => (1 1 2 1 1 1 3)
          (decoupe-elt 7 '(1 1 2 1 1 1 3)) => (1 1 2 1 1 1 3)
          (decoupe-elt 11 '(11 11)) => ()
          (decoupe-elt 5 '()) => ())


;;; decoupe: LISTE[nat] -> LISTE[nat]

(define (decoupe L)
  (if (pair? L)
      (decoupe-elt (car L) L)
      (list)))

(verifier decoupe
          (decoupe '(1 1 2 1 1 1 3)) => (2 1 1 1 3)
          (decoupe '(11 38)) => (38)
          (decoupe '(42 42 42)) => ()
          (decoupe '()) => ())


;;; liste-plages : LISTE[nat] -> LISTE[LISTE[nat]]

(define (liste-plages L)
  (if (pair? L)
      (cons (premiere-plage L) (liste-plages (decoupe L)))
      (list)))

(verifier liste-plages
          (liste-plages '(1 1 2 1 1 1 3)) => ((1 1) (2) (1 1 1) (3))
          (liste-plages '(11 38)) => ((11) (38))
          (liste-plages '(42)) => ((42))
          (liste-plages '()) => ())


;;; length: Liste[alpha] -> nat
;;; (length L) rend le nombre d'elements que contient L

(define (length L)
  (if (pair? L)
      (+ 1 (length (cdr L)))
      0))


;;; tailles-plages : LISTE[LISTE[nat]] -> LISTE[nat]

(define (tailles-plages L)
  (map length L))

(verifier tailles-plages
          (tailles-plages '((1 1) (2) (1 1 1) (3))) => (2 1 3 1)
          (tailles-plages '((11) (38))) => (1 1)
          (tailles-plages (liste-plages '(42))) => (1)
          (tailles-plages (liste-plages '())) => ())


;;; EXERCICE 3 : NUMERATION MAYA

;;; nb->glyphe : nat -> Glyphe
;;; HYPOTHESE : 0 <= n <= 19

(define (nb->glyphe n)
  (if (= n 0)
      (list 0 0)
      (list (remainder n 5) (quotient n 5))))
           
(verifier nb->glyphe
          (nb->glyphe 17) => (2 3)
          (nb->glyphe 0) => (0 0)
          (nb->glyphe 10) => (0 2))


;;; glyphe->nb : Glyphe -> nat

(define (glyphe->nb G)
  (+ (car G) (* 5 (cadr G))))

(verifier glyphe->nb
          (glyphe->nb '(1 3)) => 16
          (glyphe->nb '(0 0)) => 0
          (glyphe->nb '(4 0)) => 4)


;;; EXERCICE 4 : =======================================

;;; nb->maya : nat -> LISTE[Glyphe]

(define (nb->maya n)
  (if (< n 20)
      (list (nb->glyphe n))
      (cons (nb->glyphe (remainder n 20)) (nb->maya (quotient n 20)))))

(verifier nb->maya
          (nb->maya 112211) => ((1 2) (0 2) (0 0) (4 2))
          (nb->maya 340) => ((0 0) (2 3))
          (nb->maya 17) => ((2 3))
          (nb->maya 0) => ((0 0)))


;;; maya->nb : LISTE[Glyphe] -> nat

(define (maya->nb G)
  (if (pair? G)
      (+ (glyphe->nb (car G)) (* 20 (maya->nb (cdr G)))) 
      0))

(verifier maya->nb
          (maya->nb '((1 2) (0 2) (0 0) (4 2))) => 112211
          (maya->nb '((0 0) (2 3))) => 340
          (maya->nb '((2 3))) => 17
          (maya->nb '((0 0))) => 0
          (maya->nb '()) => 0)


;;; maya->nb-bis : LISTE[Glyphe] -> nat

(define (maya->nb-bis G)
  
  (define (trans a b)
    (+ (glyphe->nb a) (* b 20)))
  
  (reduce trans 0 G))


(verifier maya->nb-bis
          (maya->nb-bis '((1 2) (0 2) (0 0) (4 2))) => 112211
          (maya->nb-bis '((0 0) (2 3))) => 340
          (maya->nb-bis '((2 3))) => 17
          (maya->nb-bis '((0 0))) => 0
          (maya->nb-bis '()) => 0)