;;; EXERCICE 41 : VARIATIONS AUTOUR DU SIGNE DES ELEMENTS D'UNE LISTE

;;; meme-signe? : Nombre * Nombre -> bool
;;; (meme-signe? a b) renvoie vrai si les 2 nombres a & b sont de meme signe, rend faux sinon

(define (meme-signe? a b)
  (> (* a b) 0))

(verifier meme-signe?
          (meme-signe? -1 1) => #f
          (meme-signe? 1 1) => #t
          (meme-signe? -1 -1) => #t)


;;; nb-meme-signe : int * LISTE[int] -> nat
;;; (nb-meme-signe n L) rend le nombre d'elements de la liste L qui ont le meme signe que le nombre entier n
;;; par convention, rend 0 si la liste L est vide

(define (nb-meme-signe n L)
  (if (pair? L)
      (let ((Signe (nb-meme-signe n (cdr L))))
      (if (meme-signe? n (car L))
          (+ 1 Signe)
          Signe))
      0))
 
(verifier nb-meme-signe
          (nb-meme-signe 3 (list -1 2 3 -5)) => 2
          (nb-meme-signe -1 (list 2 3 -5 -6 -7)) => 3)


;;; nb-chgt-signe : LISTE[int] -> nat
;;; (nb-chgt-signe L), etant donne une liste d'entiers non nul L, rend le nombre de fois que
;;; les 2 nombres consecutifs de L n'ont pas le meme signe.

(define (nb-chgt-signe L)
  ;; nb-chgt-signe-non-vide : LISTE[int] -> nat
  ;; (nb-chgt-signe-non-vide) : fait la meme consigne que (nb-chgt-signe L)
  ;; HYOPOTHESE : L est une liste non vide
  (define (nb-chgt-signe-non-vide L)
    (if (pair? (cdr L))
        (let ((Signe (nb-chgt-signe-non-vide (cdr L))))
          (if (meme-signe? (car L) (cadr L))
              Signe
              (+ 1 Signe)))
        0))
  
  (if (pair? L)
      (nb-chgt-signe-non-vide L)
      0))
    
  
(verifier nb-chgt-signe
          (nb-chgt-signe (list -1 2 -3 -4)) => 2
          (nb-chgt-signe (list -1 -4 5 -5 3 6 -9 1)) => 5)