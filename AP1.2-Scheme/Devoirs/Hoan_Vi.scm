;;; BAI TAP : Xuat ra list cac so duoc hoan vi


;;; them_so_list : alpha * LISTE[LISTE[alpha]] -> LISTE[LISTE[alpha]]
;;; (them_so_list n L) them so n vao cac list nho trong L

(define (them_so_list n L)
  (if (pair? L)
      (cons (cons n (car L)) (them_so_list n (cdr L)))
      (list)))

(them_so_list 1 '((2) (3)))
(them_so_list 1 '( (2 3) (3 2)))


;;; them_hoan_vi : alpha * LISTE[alpha] -> LISTE[LISTE[alpha]]
;;; (them_hoan_vi n L) xuat ra list gom cac list da duoc them so n vao cac vi tri co the them

(define (them_hoan_vi n L)
  (if (pair? L)
      (cons (cons n L)
            (them_so_list (car L) (them_hoan_vi n (cdr L))))
      (list (list n))))

(them_hoan_vi 1 '(2 3))
(them_hoan_vi 1 '(2 3 4))


;;; insert : alpha * LISTE[LISTE[alpha]] -> LISTE[LISTE[alpha]]
;;; (insert n L) xuat ra list ghep cac hoan vi lai voi nhau

(define (insert n L)
  (if (pair? L)
      (append (them_hoan_vi n (car L)) (insert n (cdr L)))
      (list)))

(insert 1 '( (2 3) (3 2)))
(insert 2 '( (3 4) (4 3)))
(insert 1 '( (2 3) ))
(insert 2 '( (3) ))


;;; hoan_vi : LISTE[alpha] -> LISTE[LISTE[alpha]]
;;; (hoan_vi L) xuat ra list cac hoan vi tu cac phan tu cua list L

(define (hoan_vi L)
  (if (pair? (cdr L))
      (insert (car L) (hoan_vi (cdr L)))
      (list L)))

(hoan_vi '(1 2 3))
(hoan_vi '(1 2 3 4))