;;; EXERCICE 6 : CALCUL D'UN PRIX TTC

;;; prix-ttc : Nombre * Nombre => Nombre 
;;; (prix-ttc ht taux) renvoir le prix de TTC
;;; formule : TTC = HT + HT*TAUX = HT*(1 + TAUX)

(define (prix-ttc ht taux)
  (* ht (+ 1 (/ taux 100))))

(verifier prix-ttc
          (prix-ttc 20 18) => 118/5
          (prix-ttc 50 15) => 115/2)


;;; prix-ht : Nombre * Nombre -> Nombre
;;; (prix-ht ttc taux) renvoie le prix de HT
;;; formule : HT = TTC/(1 + TAUX)

(define (prix-ht ttc taux)
  (/ ttc (+ 1 (/ taux 100))))

(verifier prix-ht
          (prix-ht (/ 118 5) 18) => 20
          (prix-ht (/ 115 2) 15) => 50)
