;;; EXERCICE 54 : TRIPLET & LISTE DE N-UPLETS

;;; rendNom : NUPLET[string int string] -> string
;;; (rendNom Fiche) rend le nom du personnage

(define (rendNom Fiche)
  (car Fiche))

(verifier rendNom
          (rendNom (list "Gandalf" 55 "mage")) => "Gandalf")


;;; rendNiveau : NUPLET[string int string] -> int
;;; (rendNiveau Fiche) rend le nom du personnage

(define (rendNiveau Fiche)
  (cadr Fiche))

(verifier rendNiveau
          (rendNiveau (list "Gandalf" 55 "mage")) => 55)


;;; rendClasse : NUPLET[string int string] -> string
;;; (rendClasse Fiche) rend la classe du personnage

(define (rendClasse Fiche)
  (caddr Fiche))

(verifier rendClasse
          (rendClasse (list "Gandalf" 55 "mage")) => "mage")


;;; augmenteNiveau : NUPLET[string int string] -> NUPLET[string int string]
;;; (augmenteNiveau Fiche) renvoie Fiche dont le niveau a ete augmente de 1

(define (augmenteNiveau Fiche)
  (cons (car Fiche) (cons (+ 1 (cadr Fiche)) (cddr Fiche))))

(verifier augmenteNiveau
          (augmenteNiveau (list "Gandalf" 55 "mage")) => ("Gandalf" 56 "mage")
          (augmenteNiveau '("Bilbo" 31 "voleur")) => ("Bilbo" 32 "voleur"))


;;; rendNom-bis : LISTE[COUPLE[string alpha]] -> alpha
;;; (rendNom-bis) rend le nom du personnage

(define (rendNom-bis L)
  (and (pair? L) (assoc "nom" L) (cadr (assoc "nom" L))))

(verifier rendNom-bis
          (rendNom-bis '(("nom" "Gandalf") ("niveau" 55) ("classe" "mage"))) => "Gandalf"
          (rendNom-bis '(("niveau" 34) ("classe" "chasseur") ("nom" "Legolas"))) => "Legolas"
          (rendNom-bis '(("niveau" 70) ("classe" "demoniste"))) => #f)


;;; rendValeur : LISTE[COUPLE[string valeur]] -> valeur
;;; (rendValeur v L) rend la valeur du champ correspondant, si le champ n'est pas trouve alors elle rend faux

(define (rendValeur v L)
  (and (pair? L) (assoc v L) (cadr (assoc v L))))

(verifier rendValeur
          (rendValeur "nom" '(("nom" "Gimli")("niveau" 32)("classe" "guerrier"))) => "Gimli"
          (rendValeur "classe" '(("niveau" 34) ("nom" "Legolas") ("classe" "chasseur"))) => "chasseur"
          (rendValeur "age" '(("nom" "Gandalf") ("niveau" 55) ("classe" "mage"))) => #f)


;;; augmenteNiveau-bis : LISTE[COUPLE[string valeur]] -> LISTE[COUPLE[string valeur]]
;;; (augmenteNiveau-bis L) rend la liste L en augmentant le niveau de 1

(define (augmenteNiveau-bis L)
  (if (pair? L)
      (if (equal? "niveau" (caar L))
          (cons (list (caar L) (+ 1 (cadar L))) (cdr L))
          (cons (car L) (augmenteNiveau-bis (cdr L))))
      #f))
      
      
(verifier augmenteNiveau-bis
          (augmenteNiveau-bis '(("nom" "Gandalf") ("niveau" 55) ("classe" "mage")))
          => (("nom" "Gandalf") ("niveau" 56) ("classe" "mage"))
          (augmenteNiveau-bis '(("nom" "Bilbo") ("classe" "voleur") ("niveau" 31)))
          => (("nom" "Bilbo") ("classe" "voleur") ("niveau" 32)))

