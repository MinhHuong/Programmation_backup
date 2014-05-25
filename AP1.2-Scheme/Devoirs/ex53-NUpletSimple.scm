;;; EXERCICE 53 : N-UPLETS SIMPLES

;;; abscisse : COUPLE[Nombre Nombre] -> Nombre
;;; (abscisse P) etant donne un point, rend la valeur corredpondant a l'abscisse du point

(define (abscisse P)
  (car P))

(verifier abscisse
          (abscisse '(0.5 4.2)) => 0.5)


;;; ordonnee : COUPLE[Nombre Nombre] -> Nombre
;;; (ordonnee P) etant donne un point, rend la valeur correspondant a l'ordonnee du point

(define (ordonnee P) 
  (cadr P))

(verifier ordonnee
          (ordonnee '(0.5 4.2)) => 4.2)


;;; estDansDroite? : COUPLE[Nombre Nombre] * Nombre Nombre -> bool
;;; (estDansDroite? P a b) etant donne le point P, 2 nombres reels a & b, rend vrai si P appartient a
;;; la droite d'equation y = ax + b, rend faux sinon

(define (estDansDroite? P a b)
  (= (ordonnee P) (+ (* a (abscisse P)) b)))

(verifier estDansDroite?
          (estDansDroite? '(1.5 6) 2 3) => #t)


;;; donneCoef : COUPLE[Nombre Nombre] ^ 2 -> COUPLE[Nombre Nombre]
;;; (donneCoef P1 P2) etant donnes 2 points P1 P2 de differents abscisses, rend le n-uplet compose 
;;; par les valeurs a & b telles que y = ax + b soit l'equation de la droite passant par P1 & P2

(define (donneCoef P1 P2)
  (let* ( (a (/ (- (ordonnee P1) (ordonnee P2)) (- (abscisse P1) (abscisse P2))))
          (b (- (ordonnee P1) (* a (abscisse P1)))))
    (list a b)))

(verifier donneCoef
          (donneCoef (list 1 1) (list 5 9)) => (2 -1))
