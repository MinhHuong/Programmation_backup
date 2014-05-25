;;; EXERCICE 51 : DEGONFLER UNE LISTE

;;; gonfler : LISTE[alpha] -> LISTE[alpha]
;;; (gonfler y) rend une liste dont chaque element est repete d'un nombre aleatoire de fois

(define (gonfler y)  
  
  ;;; repete-aleatoire : nat -> LISTE[alpha]
  ;;; (rept-ale x) rend une liste contenant un element x qui est repete d'un nombre aleatoire de fois
  
  (define (repete-aleatoire x)
    
    ;; repete-x : nat -> LISTE[alpha]
    ;; (repete-x z) rend une liste contenant un element x qui est repete z fois
    
    (define (repete-x z)
      (if (> z 0)
          (cons x (repete-x (- z 1)))
          (list)))
    
    (let ((t (+ 1 (random 9))))
      (repete-x t)))
  
  (if (pair? y)
      (append (repete-aleatoire (car y)) (gonfler (cdr y)))
      (list)))

(gonfler (list 1 2 1 4))


;;; degonfler : LISTE[alpha] -> LISTE[alpha]
;;; (degonfler L) rend la liste dans laquelle toutes les occurrences consecutives d'un meme element dans L
;;; sont remplacees par un seul

(define (degonfler L)
  (if (pair? L)
      (if (pair? (cdr L))
          (if (equal? (car L) (cadr L))
              (degonfler (cdr L))
              (cons (car L) (degonfler (cdr L))))
          L)
      (list)))

(verifier degonfler
          (degonfler (list 1 1 1 1 2 2 2 1 1 4 4 4 4 4)) => (1 2 1 4)
          (degonfler (gonfler (list 1 2 1 4))) => (1 2 1 4)
          (degonfler (gonfler (list 1 1 4))) => (1 4))


;;; degonfler-renverse : LISTE[alpha] -> LISTE[alpha]
;;; (degonfler-renverse L) rend la liste en sens inverse, dans laquelle toutes les occurrences multiples
;;; successives sont remplacees par une seule

(define (degonfler-renverse L)
  (if (pair? L)
      (let ((res (degonfler L)))
      (append (degonfler-renverse (cdr res)) (list (car res))))
      (list)))

(verifier degonfler-renverse
          (degonfler-renverse (list 1 1 1 1 2 2 2 1 1 4 4 4 44)) => (44 4 1 2 1)
          (degonfler-renverse (gonfler (list 1 2 4 4 1 4))) => (4 1 4 2 1)
          (degonfler-renverse (list 4 3 5 6)) => (6 5 3 4))

