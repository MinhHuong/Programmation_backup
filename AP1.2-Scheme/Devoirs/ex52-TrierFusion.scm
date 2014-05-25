;;; EXERCICE 52 : TRI PAR FUSION

;;; interclassement : LISTE[Nombre] ^ 2 -> LISTE[Nombre]
;;; (interclassement L1 L2) etant donnees 2 listes croissantes, construit une liste croissante 
;;; HYPOTHESE : L1 et L2 sont non vides & croissantes

(define (interclassement L1 L2)
  (if (and (pair? L1) (pair? L2))
      (if (> (car L1) (car L2))
          (cons (car L2) (interclassement L1 (cdr L2)))
          (if (= (car L1) (car L2))
              (interclassement L1 (cdr L2))
              (cons (car L1) (interclassement (cdr L1) L2))))
      (if (pair? L1)
          L1
          L2)))

(verifier interclassement
          (interclassement '(2 4 6 8) '(1 3 4 5 7)) => (1 2 3 4 5 6 7 8)
          (interclassement '(1 3 5) '(2 4)) => (1 2 3 4 5)
          (interclassement '() '(2 4 5 7 9)) => (2 4 5 7 9)
          (interclassement '(3 5 7 9 10) '(1 2 3 4 6)) => (1 2 3 4 5 6 7 9 10))


;;; pos-paires : LISTE[alpha] -> LISTE[alpha]
;;; (pos-paires L) rend la liste des elements en position paire dans la liste initiale

(define (pos-paires L)
  (if (pair? L)
      (if (pair? (cdr L))
          (cons (car L) (pos-paires (cddr L)))
          (cons (car L) ()))
      (list)))


;;; pos-impaires : LISTE[alpha] -> LISTE[alpha]
;;; (pos-impaires L) rend la liste des elements en position impaire dans la liste initiale

(define (pos-impaires L)
  (if (pair? L)
      (if (pair? (cdr L))
          (cons (cadr L) (pos-impaires (cddr L)))
          (list))
      (list)))

(verifier pos-paires
          (pos-paires '(a b c d e f g h)) => (a c e g)
          (pos-impaires '(a b c d e f g h)) => (b d f h)
          (pos-paires '(12)) => (12)
          (pos-impaires '(12)) => ())


;;; tri-fusion : LISTE[Nombre] -> LISTE[Nombre]
;;; (tri-fusion L) etant donne une liste de nombres, retourne une liste en ordre strictement croissant 
;;; (chaque element dans la liste initiale n'apparait qu'une fois)

(define (tri-fusion L)
  (if (pair? L)
      (if (pair? (cdr L))
          (interclassement (tri-fusion (pos-paires L)) (tri-fusion (pos-impaires L))) 
          L)
      (list)))
                        
(verifier tri-fusion
          (tri-fusion '(5 1 8 9 1 2 4 3 10 13 1 6 11 7)) => (1 2 3 4 5 6 7 8 9 10 11 13)
          (tri-fusion '(1 1 1 1)) => (1)
          (tri-fusion '()) => ()
          (tri-fusion '(4)) => (4))


;;; pos-paires-impaires : LISTE[alpha] -> COUPLE[LISTE[alpha]]
;;; (pos-paires-impaires L) renvoie le couple dont le premier est la liste des elements en position paire
;;; dans la liste initiale L, le deuxieme des elements en position impaire

(define (pos-paires-impaires L)
  (list (pos-paires L) (pos-impaires L)))

(verifier pos-paires-impaires
          (pos-paires-impaires '(a b c d e f g h)) => ((a c e g) (b d f h))
          (pos-paires-impaires '(a b c d e f g h i)) => ((a c e g i) (b d f h))
          (pos-paires-impaires '(a)) => ((a) ())
          (pos-paires-impaires '()) => (() ()))


;;; tri-fusion-mieux : LISTE[Nombre] -> LISTE[Nombre]
;;; (tri-fusion-mieux L) meme consigne que (tri-fusion L)

(define (tri-fusion-mieux L)
  (if (pair? L)
      (if (pair? (cdr L))
          (interclassement (tri-fusion (car (pos-paires-impaires L))) 
                           (tri-fusion (cadr (pos-paires-impaires L))))
          L)
      (list)))

(verifier tri-fusion-mieux
          (tri-fusion-mieux '(5 1 8 9 1 2 4 3 10 13 1 6 11 7)) => (1 2 3 4 5 6 7 8 9 10 11 13)
          (tri-fusion-mieux '(1 1 1 1)) => (1)
          (tri-fusion-mieux '()) => ()
          (tri-fusion-mieux '(4)) => (4))