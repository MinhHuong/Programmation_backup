;;; minListe : LISTE[Nombre] -> Nombre
;;; (minListe L) qui etant donne 1 liste non vide, renvoie la valeur minimum de la liste
;;; HYPOTHESE : L non vide

(define (minListe L)
  (if (pair? L)
      (if (pair? (cdr L))
          (if (> (car L) (cadr L))
              (minListe (cdr L))
              (if (and (pair? (cddr L)) (> (car L) (minListe(cddr L))))
                  (minListe (cddr L))
                  (car L)))
          (car L))
      (list)))

(verifier minListe
          (minListe (list 1 3 8 5 7 8 2)) => 1
          (minListe (list -23)) => -23
          (minListe (list 9 7 3 11)) => 3
          (minListe (list 1 3 5 9 7 11 10)) => 1
          (minListe (list 1 3 9 7 5 14 11 0)) => 0)


;;; effacer : alpha * LISTE[alpha] -> LISTE[alpha]
;;; (effacer n L) rend une liste qui n'a pas d'element n

(define (effacer n L)
  (if (pair? L)
      (if (equal? n (car L))
          ;(effacer n (cdr L))
          (cdr L)
          (cons (car L) (effacer n (cdr L))))
      (list)))

(effacer 1 (list 4 1 5 6))
(effacer 4 (list 1 3 7))
(effacer 1 (list 1 5 7 1 6 9))
      

;;; sort : LISTE[Nombre] -> LISTE[Nombre]
;;; (sort L) rend une liste triee

(define (sort L)
  (if (pair? L)
      (cons (minListe L) (sort (effacer (minListe L) L)))
      (list)))

(sort '(2 4 5 1 9 3 7))
(sort '(5 4 7 1))
(sort '(1 4 7 4 1 8))
(sort '(3 3 3 3 3))