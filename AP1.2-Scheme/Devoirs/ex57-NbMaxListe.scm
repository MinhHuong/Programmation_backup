;;; EXERCICE 57 : NOMBRE D'OCCURRENCES DU MAXIMUM D'UNE LISTE

;;; qui-combien : LISTE[Nombre] -> NUPLET[Nombre nat]
;;; (qui-combien L) rend le doublet forme du maximum de L et de son nombre d’occurrences
;;; HYPOTHESE : L est non vide

(define (qui-combien L)
  (if (not (pair? (cdr L)))     
      (list (car L) 1)
      (let ((res (qui-combien (cdr L))))
      (if (> (car L) (car res))
          (list (car L) 1)
          (if (= (car L) (car res))
              (list (car L) (+ 1 (cadr res)))
              (list (car res) (cadr res)))))))

(verifier qui-combien
          (qui-combien '(1 8 2 8 6 5 8)) => (8 3)
          (qui-combien '(3)) => (3 1)
          (qui-combien '(9 1 5 2 3 9 1 1 0)) => (9 2)
          (qui-combien '(4 6 2 7 1 6)) => (7 1)
          (qui-combien '(4 4 4 4 )) => (4 4)
          (qui-combien '(5 5 1 5 5 1 4)) => (5 4))


;;; nombre-de-max : LISTE[Nombre] -> nat
;;; (nombre-de-max L) etant donnee une liste L rend le nombre d'occurrences du maximum dans 1 liste de nombres

(define (nombre-de-max L)
  (cadr (qui-combien L)))

(verifier nombre-de-max
          (nombre-de-max '(3 4 5 6 1 4 6)) => 2
          (nombre-de-max '(1 2 3 5 1 7)) => 1
          (nombre-de-max '(3 3 3 3 3 3)) => 6
          (nombre-de-max '(2)) => 1)