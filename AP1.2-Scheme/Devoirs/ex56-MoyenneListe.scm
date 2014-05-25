;;; EXERCICE 56 : RETOUR SUR LA MOYENNE D'UNE LISTE DE NOMBRE

;;; somme-longueur-liste : LISTE[Nombre] -> COUPLE[Nombre Nombre]
;;; (somme-longueur-liste L) rend le couple forme par la somme et la longueur des termes de L 
;;; (et rend la liste (0 0) lorsque L est vide)

(define (somme-longueur-liste L)
  (if (pair? L)
      (let ((res (somme-longueur-liste (cdr L))))
        (list
         (+ (car L) (car res))
         (+ 1 (cadr res))))
      (list 0 0)))
      

(verifier somme-longueur-liste
          (somme-longueur-liste (list 4 12 8)) => (24 3)
          (somme-longueur-liste (list)) => (0 0))


;;; moyenne-liste : LISTE[Nombre] -> Nombre
;;; (moyenne-liste) rend la moyenne des nombres dans une liste

(define (moyenne-liste L)
  (let ((div (somme-longueur-liste L)))
  (/ (car div) (cadr div))))

(verifier moyenne-liste
          (moyenne-liste '(1 2 3)) => 2
          (moyenne-liste '(4 6 2 8)) => 5)