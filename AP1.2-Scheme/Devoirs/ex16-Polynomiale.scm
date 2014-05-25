;;; EXERCICE 16 : POLYNOMIALE

;;; polynomiale : Nombre^5 -> Nombre
;;; (polynomiale a b c d x) rend la valeur de la fonction qui a x associee ax^3 + bx^2 + cx + d
;;; ax^3 + bx^2 + cx + d = x(x(ax+b) + c) + d --> Le nombre de multiplication : 3

(define (polynomiale a b c d x)
  (+ d (* x (+ c (* x (+ b (* a x)))))))

(verifier polynomiale 
          (polynomiale 1 1 1 1 2) => 15
          (polynomiale 1 1 1 1 3) => 40)


;;; polynomialeRec : Nombre * nat -> Nombre
;;; (polynomialeRec x n) rend la valeur de la fonction a x associee x^3 + x^2 + x + 1 (cas particulier)
;;; On utilise la fonction recursive de l'equation 1 + x + x^2 + x^3 +...+x^n
;;; Si n = 0 : eq(0,x) = 1
;;; Si n > 0 : eq(n,x) = 1 + x*eq(n-1,x)

(define (polynomiale2 n x)
  (if (= n 0)
      1
      (+ 1 (* x (polynomiale2 (- n 1) x)))))

(verifier polynomiale2
          (polynomiale2 3 2) => 15
          (polynomiale2 4 2) => 31)


;;; pol-carre : Nombre^4 -> Nombre
;;; (pol-carre a b c x) rend la valeur de la fonction qui a x associee ax^4 + bx^2 + c = x*x*(a*x*x + b) + c
;;; Le nombre de multiplication : 4

(define (pol-carre a b c x)
  (let ((X (* x x)))
    (+ (* a X X) (* b X) c)))

(verifier pol-carre
          (pol-carre 1 1 1 2) => 21
          (pol-carre 1 1 1 3) => 91)


;;; pol-carre-rec : Nombre * nat -> Nombre
;;; (pol-carre-rec n x) rend la valeur de la fonction qui a x associee : x^(n) + x^(n-2) +...+ 1
;;; HYPOTHESE : n est un nombre pair

(define (pol-carre-rec n x)
  (if (= n 0)
      1
      (let ((carre (* x x)))
      (+ 1 (* carre (pol-carre-rec (- n 2) x))))))

(verifier pol-carre-rec
          (pol-carre-rec 0 3) => 1
          (pol-carre-rec 2 2) => 5
          (pol-carre-rec 4 2) => 21
          (pol-carre-rec 6 2) => 85)
