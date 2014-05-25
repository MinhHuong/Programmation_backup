;;; EXERCICE 25 : SUITES RECURSIVES

;;; valeur-capital : nat * Nombre * Nombre -> Nombre
;;; (valeur-capital n t K) rend la valeur du capital K apres n annees, selon le taux d'interet t (%)
;;; HYPOTHESE : t >= 0, K >= 0

(define (valeur-capital n t K)
  (if (= n 0)
      K
      (* (+ 1 (/ t 100)) (valeur-capital (- n 1) t K))))

(verifier valeur-capital
          (valeur-capital 0 10 500) => 500
          (valeur-capital 1 10 500) => 550
          (valeur-capital 2 10 500) => 605
          (valeur-capital 3 10 0) => 0
          (valeur-capital 4 0 500) => 500)


;;; valeur-epargne : nat * Nombre * Nombre -> Nombre
;;; (valeur-epargne n t A) rend la valeur epargnee apres n annees, selon le taux d'interet t(%)
;;; HYPOTHESE : t >= 0, A >= 0)

(define (valeur-epargne n t A)
  (if (= n 0)
      A
      (+ A (* (+ 1 (/ t 100)) (valeur-epargne (- n 1) t A)))))

(verifier valeur-epargne
          (valeur-epargne 0 10 500) => 500
          (valeur-epargne 1 10 500) => 1050
          (valeur-epargne 2 10 500) => 1655
          (valeur-epargne 10 0 500) => 5500)
