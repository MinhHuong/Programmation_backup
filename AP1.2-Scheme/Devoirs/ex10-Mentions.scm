;;; EXERCICE 10 : CALCUL DE MENTIONS

;;; mention : Nombre -> string
;;; (mention note) renvoie la mention d'apres la note saisie
;;; HYPOTHESE : 0 <= note <= 20

(define (mention note)
  (if (>= note 16)
      "TB"
      (if (and (< note 16) (>= note 14))
          "B"
          (if (and (< note 14) (>= note 12))
              "AB"
              (if (and (< note 12) (>= note 10))
                  "Passable"
                  "Elimine")))))

(verifier mention
          (mention 5) => "Elimine"
          (mention 11) => "Passable"
          (mention 15) => "B"
          (mention 19) => "TB")


;;; mention-cond : Nombre -> string
;;; (mention-cond note) renvoie la mention d'apres la note saisie
;;; HYPOTHESE : 0 <= note <= 20

(define (mention-cond note)
  (cond
   ( (>= note 16) "TB")
   ( (and (< note 16) (>= note 14)) "B")
   ( (and (< note 14) (>= note 12)) "AB")
   ( (and (< note 12) (>= note 10)) "Passable")
   (  else "Elimine")))
    
    
(verifier mention-cond
          (mention-cond 5) => "Elimine"
          (mention-cond 11) => "Passable"
          (mention-cond 15) => "B"
          (mention-cond 19) => "TB")
