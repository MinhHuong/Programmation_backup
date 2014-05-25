;;; EXERCICE 62 : AUTOUR DE "MAP"


;;; carre : Nombre -> Nombre
;;; (carre n) rend le carre du nombre donne n

(define (carre n)
    (* n n))


;;; liste-carres : LISTE[Nombre] -> LISTE[Nombre]
;;; (liste-carres L) renvoie la liste des carres des nombres de la liste L

(define (liste-carres L)  
  (map carre L))

(verifier liste-carres
          (liste-carres '(1 2 3 4)) => (1 4 9 16)
          (liste-carres '(-1 0 1)) => (1 0 1))


;;; somme-carres : LISTE[Nombre] -> Nombre
;;; (somme-carres L) renvoie la somme des carres des elements de la liste L

(define (somme-carres L)
  (define (somme-liste L)
    (if (pair? L)
        (+ (car L) (somme-liste (cdr L)))
        0))
  
  (somme-liste (map carre L)))

(verifier somme-carres
          (somme-carres(list 2 5 7 3)) => 87
          (somme-carres(list)) => 0)


;;; xmul-liste : LISTE[Nombre] * n -> LISTE[Nombre]
;;; (xmul-liste L n) renvoie la liste des elements de L multiplies par n

(define (xmul-liste L n)
  (define (fois-n x)
    (* x n))
  
  (map fois-n L))

(verifier xmul-liste
          (xmul-liste (list 1 2 3 4 5) 3.0) => (3.0 6.0 9.0 12.0 15.0)
          (xmul-liste (list 100 50 25 12 1) 2) => (200 100 50 24 2))


;;; liste-clefs : LISTE[COUPLE[alpha beta]] -> LISTE[alpha]
;;; (liste-clefs L) renvoie la liste des clefs

(define (liste-clefs L)
  (define (tire-clefs L)
    (car L))
  
  (map tire-clefs L))

(verifier liste-clefs
          (liste-clefs '((1 un) (2 deux) (3 trois))) => (1 2 3))

;;; liste-valeurs : LISTE[COUPLE[alpha beta]] -> LISTE[beta]
;;; (liste-valeurs L) renvoie la liste des valeurs

(define (liste-valeurs L)
  (define (tire-valeurs L)
    (cadr L))
  
  (map tire-valeurs L))

(verifier liste-valeurs
          (liste-valeurs '((1 un) (2 deux) (3 trois))) => (un deux trois))


;;; liste-clefs-valeurs : LISTE[alpha] * LISTE[beta] -> LISTE[COUPLE[alpha beta]]
;;; (liste-clefs-valeurs Lc Lv) rend la liste d'associations constituees par la clef de Lc 
;;; et la valeur de Lv

(define (liste-clefs-valeurs Lc Lv)
  (if (pair? Lc)
      (cons (list (car Lc) (car Lv)) (liste-clefs-valeurs (cdr Lc) (cdr Lv)))
      (list)))

(liste-clefs-valeurs '(1 2 3) '(un deux trois))


;;; mention-aliste : LISTE[LISTE[string Nombre]] -> LISTE[LISTE[string Nombre]]
;;; (mention-alisten L)  etant donnee une liste d'associations L associant a un nom d'etudiant sa note, 
;;; retourne la liste d'associations associant les noms d'etudiant de L avec leur mention

(define (mention-aliste L)
  
  (define (mention n)
    (let ((N (cadr n)) (M (car n)))
    (cond 
     ( (>= N 16) (list M "Tres bien"))
     ( (and (>= N 14) (< N 16)) (list M "Bien"))
     ( (and (>= N 12) (< N 14)) (list M "Assez bien"))
     ( (and (>= N 10) (< N 12)) (list M "Passable"))
     ( else (list M "Elimine")))))
  
  (map mention L))

(verifier mention-aliste
          (mention-aliste '(("Durand" 8.5) ("Dupond" 11) ("Morin" 12.5)))
          => (("Durand" "Elimine") ("Dupond" "Passable") ("Morin" "Assez bien"))
          (mention-aliste '(("Benichou" 14.5) ("Moreau" 18.5)))
          => (("Benichou" "Bien") ("Moreau" "Tres bien")))     


;;; N-liste-premier : LISTE[NUPLET[valeur ^ 3]] -> LISTE[valeur]
;;; (N-liste-premier L) renvoie la liste contenant le premier element de chaque n-uplet de L

(define (N-liste-premier L)
  (define (extrait-premier n)
    (car n))
  
  (map extrait-premier L))

(verifier N-liste-premier
          (N-liste-premier '(("bob" 2 10) ("leo" 12 13) ("bea" 15 13) ("luc" 4 9) ("eve" 15 16)))
          => ("bob" "leo" "bea" "luc" "eve")
          (N-liste-premier '((4 2 10) (4 12 13) (8 15 13) (10 4 9) (17 15 16)))
          => (4 4 8 10 17))
