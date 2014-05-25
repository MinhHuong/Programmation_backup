;;; METHODE 1 : Algorithme : S(n) = 0           , n = 0
;;;                          S(n) = S(n-1) + n  , n > 0
;;; somme_0_n_1 : nat -> nat
;;; (somme_0_n_1 n) renvoie la somme des entiers de 0 a n

(define (somme_0_n_1 n)
  (if (= n 0)
      0
      (+ n (somme_0_n_1 (- n 1)))))

(verifier somme_0_n_1
          (somme_0_n_1 0) => 0
          (somme_0_n_1 1) => 1
          (somme_0_n_1 2) => 3
          (somme_0_n_1 3) => 6
          (somme_0_n_1 4) => 10)

==> C'est juste et c'est ce qu'il fallait faire 

;;; METHODE 2 : Utiliser la formule : S = n*(n+1)/2
;;; somme_0_n_2 : nat -> nat
;;; (somme_0_n_2 n) renvoie la somme des entiers de 0 a n

(define (somme_0_n_2 n)
  (/ (* n (+ n 1)) 2))

(verifier somme_0_n_2
          (somme_0_n_2 4) => 10
          (somme_0_n_2 7) => 28
          (somme_0_n_2 0) => 0)

==> je voulais une version récursive ! la premiere est la bonne. 

;=======================================================================;

;;; METHODE 1 : Algorithme : S(n -> m) = S(0 -> m) - S(0 -> n-1)
;;; somme_n_m_1 : nat * nat -> nat
;;; (somme_n_m_1 n m) renvoie la somme des entiers naturels de n a m

(define (somme_n_m_1 n m)
  (if (>= m n)
      (- (somme_0_n_1 m) (somme_0_n_1 (- n 1)))
      "erreur"))

 ==> tu n'as pas à gérer les erreurs il faut ajouter une clause dans la spécification
 ==> et passer par la somme_0_m n'est pas efficace, tu fais beaucoup plus de calcul, de plus ta fonction n'est pas récursive, c'est somme_0_n qui l'est 
  
(verifier somme_n_m_1
          (somme_n_m_1 4 9) => 39
          (somme_n_m_1 5 7) => 18
          (somme_n_m_1 6 3) => "erreur")
  

  
;;; METHODE 2 : Algorithme : S(n,m) = n             ,  si n = m
;;;                                 = S(n,m-1) + m  ,  si n < m
;;; somme_n_m_2 : nat * nat -> nat
;;; (somme_n_m_2 n m) renvoie la somme des entiers naturels de n a m

(define (somme_n_m_2 n m)
  (if (>= m n)
      (if (= m n)     
          n
          (+ m (somme_n_m_2 n (- m 1))))
      "erreur"))
  
==> c'est ce que j'attendais, la gestion d'erreur en moins
==> mettre une clause HYPOTHESE dans la specification 
==> solution ci-desssous
;;; somme_n_m : nat * nat -> nat
;;; (somme_n_m) renvoie la somme des entiers naturels de n a m
;;; HYPOTHESE : n <= m
(define (somme_n_m n m)
  (if (= m n)     
      n
      (+ m (somme_n_m n (- m 1)))))
     

==> ci-dessous ce n'est pas récursif, en "vrai" c'est mieux mais sinon pour ce cours, le but est d'apprendre à penser récursif
(define (somme_n_m_1 n m)
  (if (>= m n)
      (- (somme_0_n_1 m) (somme_0_n_1 (- n 1)))
      "erreur"))
 
(verifier somme_n_m_2         
          (somme_n_m_2 4 9) => 39
          (somme_n_m_2 5 7) => 18
          (somme_n_m_2 9 2) => "erreur"
          (somme_n_m_2 4 4) => 4)



;;; METHODE 3 : Utiliser la formule : S = (m+n)*(le nombre de nombres naturels de n a m)/2
;;; Explication : n = 3, m = 7    
;;;               3 4 5 6 7
;;;               On a      : 3+7 = 4+6   et   5 = (3+7)/2 
;;;               alors que : (3+7)*(7-3+1)/2 = 10*(5/2) = 10*(4/2) + 10*(1/2) = 20 + 5 = 25    

===> ca marche tout le temps ? Possible et rigolo mais pas demandé


;;; somme_n_m_3 : nat * nat -> nat
;;; (somme_n_m_3 n m) renvoie la somme des entiers naturels de n a m

(define (somme_n_m_3 n m)
  (if (>= m n)
      (* (+ m n) (/ (+ (- m n) 1) 2))
      "erreur"))
  
(verifier somme_n_m_3
          (somme_n_m_3 4 9) => 39
          (somme_n_m_3 0 7) => 28
          (somme_n_m_3 7 0) => "erreur"
          (somme_n_m_3 5 5) => 5)


===> ci dessous, la clause hypothese ne marcherait pas car si on appele avec S(n, n+1) on fera un appel recursif avec S(n+1, n-1) et du coup l'hypothèse serait non respectée. Ca ne répond pas à l'exercice... 
;;; METHODE 4 : Algorithme : On utilise la formule recursive S(n,m) = m + n + S(n+1,m-1)  ,  si n < m 
;;; somme_n_m_4 : nat * nat -> nat
;;; (somme_n_m_4 n m) renvoie la somme des entiers naturels de n a m

(define (somme_n_m_4 n m)
  (if (even? (+ (- m n) 1))       
      (if (< n m) 
          (+ m n (somme_n_m_4 (+ n 1) (- m 1)))
          0)
      (if (< n m)
          (+ m n (somme_n_m_4 (+ n 1) (- m 1)))
          (/ (+ m n) 2)))
      )

(verifier somme_n_m_4
          (somme_n_m_4 4 9) => 39
          (somme_n_m_4 0 7) => 28
          (somme_n_m_4 7 2) => 0
          (somme_n_m_4 3 3) => 3)
