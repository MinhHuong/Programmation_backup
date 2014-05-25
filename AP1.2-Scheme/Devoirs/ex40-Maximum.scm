;;; EXERCICE 40 : MAXIMUM D'UNE LISTE DE NOMBRES

;;; maxListe : LISTE[Nombre] -> Nombre
;;; (maxListe L) qui etant donne 1 liste non vide, renvoie la valeur maximum de la liste
;;; HYPOTHESE : L non vide

(define (maxListe L)
  (if (not (pair? L))
      (list)
      (if (not (pair? (cdr L)))
          (car L)
          (if (>= (car L) (maxListe (cdr L)))
              (car L)
              (maxListe (cdr L))))))

(verifier maxListe
          (maxListe (list 1 3 8 5 7 8 2)) => 8
          (maxListe (list -23)) => -23
          (maxListe (list 9 7 3 11)) => 11
          (maxListe (list 1 3 5 9 7 11 10)) => 11
          (maxListe (list 1 3 9 7 5 14 11 0)) => 14)


;;; nombre-de-max : LISTE[Nombre] -> Nombre
;;; (nombre-de-max L) renvoie le nombre d’occurrences du maximum de la liste,
;;; renvoie 0 lorsque la liste est vide

(define (nombre-de-max L)
  ;; nombre-occurrences : alpha * LISTE[alpha] -> nat
  ;; (nombre-occurrences e L) rend le nombre d’occurrences de e dans L,
  ;; rend 0 si L est vide
  (define (nombre-occurrences e L)
    (if (pair? L)
        (if (equal? e (car L))
            (+ 1 (nombre-occurrences e (cdr L)))
            (nombre-occurrences e (cdr L)))
        0))
  
  (if (pair? L)
      (nombre-occurrences (maxListe L) L)
      0))

(verifier nombre-de-max
          (nombre-de-max (list 1 8 2 8 6 5 8)) => 3
          (nombre-de-max (list)) => 0
          (nombre-de-max (list 4)) => 1
          (nombre-de-max (list 4 5 8 7 8 3 7 9 8 6)) => 1)
