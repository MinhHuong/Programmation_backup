;;; gonflebis : LISTE[alpha] -> LISTE[alpha]
;;; (gonflebis L) etant donnee une liste L, rend la liste dont chaque element est repete d'un nombre
;;; aleatoire d'occurrences

(define (gonflebis L)  
  ;; repete-aleatoire : alpha * alpha -> LISTE[alpha]
  ;; (repete-aleatoire a b) rend la liste dont chaque element est repete d'un nombre aleatoire nombre
  ;; d'occurrences  
  (define (repete-aleatoire a b)
  
    ; repete : alpha -> LISTE[alpha]
    ; (repete x) rend la liste dont l'element de la liste initiale est repete x fois    
    (define (repete x)
      (if (> x 0)
          (cons a (repete (- x 1)))
          (list)))
    
    (append (repete (random 9)) b))
  
  (reduce repete-aleatoire (list) L))
   
(gonflebis '(1 2 3 4))
(gonflebis '())
(gonflebis '(1))