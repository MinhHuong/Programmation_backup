;;; EXERCICE 19/02

(define (MyListe)
  (list (list 1 "Tuan" "Male") 
        (list 2 "Nam" "Male") 
        (list 4 "Minh" "Male") 
        (list 9 "Thao" "Female") 
        (list 3 "Tam" "Female")))


;;; minListe : LISTE[COUPLE[Nombre alpha]] -> Nombre
;;; (minListe L) qui etant donne 1 liste non vide, renvoie la valeur minimum de la liste
;;; HYPOTHESE : L non vide

(define (minListe L)
  (if (not (pair? L))
      (list)
      (if (not (pair? (cdr L)))
          (caar L)
          (if (<= (caar L) (minListe (cdr L)))
              (caar L)
              (minListe (cdr L))))))


;;; effacer : LISTE[COUPLE[Nombre alpha]] -> LISTE[COUPLE[Nombre alpha]]
;;; (effacer L) xoa couple co element min ra khoi list ( () ()...() )

(define (effacer n L)
  (if (pair? L)
      (if (equal? n (car L))
          (effacer n (cdr L))
          (cons (car L) (effacer n (cdr L))))
      (list)))


;;; sortID : LISTE[COUPLE[nat string]] -> LISTE[COUPLE[nat string]]
;;; (sortID L) sap xep danh sach theo ID

(define (sortID L)
  (if (not (pair? L))
      (list)
      (if (not (pair? (cdr L)))
          L
          (cons 
           (cons (minListe L) (cdr (assoc (minListe L) L))) 
           (sortID (effacer (assoc (minListe L) L) L))))))


;;; sortComplet : LISTE[COUPLE[nat string]] -> LISTE[COUPLE[nat string]]
;;; (sortComplet L) la ham hoan chinh de sap xep MyListe (co them vao ("ID" "Name") o dau)

(define (sortComplet L)
  (cons (list "ID" "Name") (sortID L)))

(sortComplet (MyListe))


;;; selectID : LISTE[COUPLE[nat string]] -> LISTE[nat]
;;; (selectID L) xuat list chua cac ID

(define (selectID L)
  (define (extraitID x)
    (car x))
  
  (map extraitID L))

(selectID (MyListe))


;;; selectName : LISTE[COUPLE[nat string]] -> LISTE[string]
;;; (selectName L) xuat list chua cac Name

(define (selectName L)
  (define (extraitName y)
    (cadr y))
    
  (map extraitName (MyListe)))

(selectName (MyListe))


;;; effacerCol :

(define (effacerCol L)
  (define (effacer t)
    (cdr t))
   
   (map effacer L))

(effacerCol (MyListe))


;;; MyListe2 

(define (MyListe2)
  (list 
   (list "ID" "NAME" "SEXE")
   (list 1 "Tuan" "Male") 
   (list 2 "Nam" "Male") 
   (list 4 "Minh" "Male") 
   (list 9 "Thao" "Female") 
   (list 3 "Tam" "Female")))


;;; select : string * LISTE[COUPLE[nat string]] -> LISTE[nat + string]
;;; (select n L) xuat list cua field nguoi su dung mong muon (n la ten field can nhap)

(define (select n L)
    (define (extrait z)
      (car z))
  
  (if (not (pair? L))
      (list)
      (if (not (pair? (car L)))
          "erreur : field not found"
          (if (equal? n (caar L))
              (map extrait L)
              (select n (effacerCol L))))))
      
(select "ID" (MyListe2))
(select "NAME" (MyListe2))
(select "SEXE" (MyListe2))
(select "PLACE" (MyListe2))

(cons (car (MyListe2)) (sortID (cdr (MyListe2))))
