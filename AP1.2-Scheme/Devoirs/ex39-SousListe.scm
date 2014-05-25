;;; EXERCICE 39 : TOUT CE QUI N'EST PAS FAUX EST VRAI

;;; sous-liste-ou-faux : alpha * LISTE[alpha] -> LISTE[alpha] ou bool
;;; (sous-liste-ou-faux e L) renvoie la plus grande sous-liste suffixe de L dont le premier element est e, 
;;; si e apparait dans L et la valeur #f sinon

(define (sous-liste-ou-faux e L)
  (if (pair? L)
     (if (equal? e (car L))
         L
         (sous-liste-ou-faux e (cdr L)))
      #f))

(verifier sous-liste-ou-faux
          (sous-liste-ou-faux 1 (list 2 3 1 4 1)) => (1 4 1)
          (sous-liste-ou-faux 5 (list 2 3 1 4 1)) => #f
          (sous-liste-ou-faux "jo" (list "ema" "zoe" "jo")) => ("jo")
          (sous-liste-ou-faux 4 (list)) => #f)


;;; suivant : alpha * LISTE[alpha] -> alpha ou bool
;;; (suivant e L)  renvoie l'element suivant la premiere occurrence de e dans L, si e apparait dans L et 
;;; si la premiere occurrence de e dans L n’est pas en derniere position dans L, 
;;; et renvoie #f sinon

(define (suivant e L)
  ;; suivant-non-vide : alpha * LISTE[alpha] -> alpha ou bool
  ;; (suivant-non-vide e L) (de meme consigne que (suivant e L)
  ;; HYPOTHESE : la liste L est non-vide
  (define (suivant-non-vide e L)
    (if (pair? (cdr L))
        (if (equal? e (car L))
            (cadr L)
            (suivant e (cdr L)))
        #f))
  
  (if (pair? L)
      (suivant-non-vide e L)
      #f))
      
(verifier suivant
          (suivant 1 (list 1 4 6 3 2 1 7)) => 4
          (suivant 2 (list 1 4 6 3 2 1 7)) => 1
          (suivant 7 (list 1 4 6 3 2 1 7)) => #f
          (suivant 5 (list 1 4 6 3 2 1 7)) => #f)
