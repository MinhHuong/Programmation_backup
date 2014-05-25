;;; EXAMEN 2009

;;; EXERCICE 1 : =========================================

;;; somme-fractions : nat -> nat

(define (somme-fractions n)
  (if (= n 0)
      0.0
      (+ (/ n (+ n 1)) (somme-fractions (- n 1)))))

(verifier somme-fractions
          (somme-fractions 0) => 0.0
          (somme-fractions 1) => 0.5
          (somme-fractions 2) => 1.1666666666666665
          (somme-fractions 7) => 5.2821428571428575)


;;; somme-divisibles : nat * 3 -> nat
;;; HYPOTHESE : p non nul, n <= m

(define (somme-divisibles n m p)
  (if (= n m)
      (if (= (remainder n p) 0)
          n
          0)
      (if (= (remainder n p) 0)
          (+ n (somme-divisibles (+ n 1) m p))
          (somme-divisibles (+ n 1) m p))))

(verifier somme-divisibles
          (somme-divisibles 1 1 2) => 0
          (somme-divisibles 2 2 2) => 2
          (somme-divisibles 1 7 2) => 12
          (somme-divisibles 1 10 7) => 7)


;;; fixe-taille : nat * LISTE[nat] -> LISTE[nat]

(define (fixe-taille n L)
  (if (= n 0)
      (list)
      (if (pair? L)          
          (cons (car L) (fixe-taille (- n 1) (cdr L)))
          (cons 0 (fixe-taille (- n 1) L)))))

(verifier fixe-taille
          (fixe-taille 0 '(1 2 3 4 5)) => ()
          (fixe-taille 4 '(1 2 3 4 5)) => (1 2 3 4)
          (fixe-taille 4 '(1 2)) => (1 2 0 0))


;;; EXERCICE 2 : =========================================

;;; evt-source : Evenement -> string

(define (evt-source L)
  (car L))

(verifier evt-source
          (evt-source (list "pressuriseur" 12 "haute temperature")) => "pressuriseur")

;;; evt-instant : Evenement -> nat

(define (evt-instant L)
  (cadr L))

(verifier evt-instant
          (evt-instant (list "pressuriseur" 12 "haute temperature")) => 12)

;;; evt-infos : Evenement -> string

(define (evt-infos L)
  (caddr L))

(verifier evt-infos
          (evt-infos (list "pressuriseur" 12 "haute temperature")) => "haute temperature")


;;; detection: string * LISTE[Evenement] -> Evenement + #f
;;; (detection info L) retourne le premier événement
;;; associé à info dans la liste L, ou retourne #f
;;; s’il n’y pas d’événement correspondant dans L.

(define (detection s L)
  (if (pair? L)
      (if (equal? s (evt-infos (car L)))
          (car L)
          (detection s (cdr L)))
      #f))

(verifier detection
          (detection "alerte" (list (list "pressuriseur" 12 "haute temperature")
                                    (list "reacteur" 24 "surchauffe")
                                    (list "turbine" 41 "alerte")))
          => ("turbine" 41 "alerte")
          (detection "alerte" (list (list "pressuriseur" 12 "haute temperature")
                                    (list "reacteur" 24 "alerte")
                                    (list "turbine" 41 "alerte")))
          => ("reacteur" 24 "alerte")
          (detection "alerte" (list (list "pressuriseur" 12 "haute temperature")
                                    (list "reacteur" 24 "surchauffe")))
          => #f
          (detection "alerte" (list)) => #f)


;;; filtrer-source : string * LISTE[Evenement] -> LISTE[Evenement]

(define (filtrer-source s L)
  (if (pair? L)
      (if (equal? s (evt-source (car L)))
          (cons (car L) (filtrer-source s (cdr L)))
          (filtrer-source s (cdr L)))
      (list)))

(verifier filtrer-source
          (filtrer-source "reacteur" (list (list "pressuriseur" 12 "haute température")
                                           (list "reacteur" 24 "surchauffe")
                                           (list "turbine" 41 "alerte")
                                           (list "reacteur" 57 "alerte")
                                           (list "refroidisseur" 61 "avarie")
                                           (list "reacteur" 79 "explosion")))
          => (("reacteur" 24 "surchauffe") ("reacteur" 57 "alerte") ("reacteur" 79 "explosion")))


;;; filtrer-source-fct : string * LISTE[Evenement] -> LISTE[Evenement]

(define (filtrer-source-fct s L)
  (define (compare a)
    (equal? s (evt-source a)))
  
  (filter compare L))

(verifier filtrer-source-fct
          (filtrer-source-fct "reacteur" (list (list "pressuriseur" 12 "haute température")
                                           (list "reacteur" 24 "surchauffe")
                                           (list "turbine" 41 "alerte")
                                           (list "reacteur" 57 "alerte")
                                           (list "refroidisseur" 61 "avarie")
                                           (list "reacteur" 79 "explosion")))
          => (("reacteur" 24 "surchauffe") ("reacteur" 57 "alerte") ("reacteur" 79 "explosion")))


;;; EXERCICE 3 : =================================

;;; flux-ordonne : LISTE[Evenement] -> bool

(define (flux-ordonne? L)
  (if (pair? L)
      (if (pair? (cdr L))
          (if (<= (evt-instant (car L)) (evt-instant (cadr L)))
              (flux-ordonne? (cdr L))
              #f)
          #t)
      #t))

(verifier flux-ordonne?
          (flux-ordonne? (list (list "pressuriseur" 12 "haute temperature")
                               (list "reacteur" 24 "alerte") (list "turbine" 41 "alerte")))
          => #t
          (flux-ordonne? (list (list "pressuriseur" 12 "haute temperature")
                               (list "reacteur" 24 "alerte")
                               (list "générateur" 24 "baisse production")
                               (list "turbine" 41 "alerte")))
          => #t
          (flux-ordonne? (list (list "pressuriseur" 12 "haute temperature")
                               (list "reacteur" 44 "alerte")
                               (list "turbine" 41 "alerte")))
          => #f
          (flux-ordonne? (list (list "pressuriseur" 12 "haute temperature"))) => #t
          (flux-ordonne? (list)) => #t)


;;; fusion-flux : LISTE[Evenement] ^ 2 -> LISTE[Evenement]
;;; HYPOTHESE : L1 et L2 sont deja ordonnees

(define (fusion-flux L1 L2)
  (if (pair? L1)
      (if (pair? L2)
          (if (flux-ordonne? (list (car L1) (car L2)))
              (cons (car L1) (fusion-flux (cdr L1) L2))
              (cons (car L2) (fusion-flux L1 (cdr L2))))
          L1)
      L2))

(fusion-flux (list (list "pressuriseur" 12 "haute temperature")
		   (list "reacteur" 24 "alerte") (list "turbine" 41 "alerte"))
	     (list (list "condensateur" 17 "manque eau")
		   (list "générateur" 33 "baisse voltage")))

;;; fusion-nflux: LISTE[LISTE[Evenement]] -> LISTE[Evenement]
;;; (fusion-nflux LL) retourne la fusion ordonnee de tous les flux de LL
;;; HYPOTHESE: tous les flux de LL sont correctement ordonnés

(define (fusion-nflux LL)
  (if (pair? LL)
      (fusion-flux (car LL) (fusion-nflux (cdr LL)))
      (list)))

(fusion-nflux (list (list (list "pressuriseur" 12 "haute temperature")
                         (list "reacteur" 24 "alerte"))
                   (list (list "condensateur" 17 "manque eau")
                         (list "générateur" 33 "baisse voltage"))
                   (list (list "test" 1 "dang lam bai")
                         (list "tam" 17 "ba noi")
                         (list "lolol" 50 "cung dang lam bai"))))
