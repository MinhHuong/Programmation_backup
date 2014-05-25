;;; BAI TAP : XUAT RA CHUOI CON TU 1 LIST

;;; them_phan_tu : alpha * LISTE[LISTE[alpha]] -> LISTE[LISTE[alpha]]
;;; (them_phan_tu n L) xuat ra list sau khi cac list con ben trong da duoc them vao phan tu n o vi tri dau

(define (them_phan_tu n L)
  (define (add a)
    (cons n a))
  (map add L))

(them_phan_tu 1 '( () (2) (3) (2 3) ))


;;; chuoi_con : LISTE[alpha] -> LISTE[LISTE[alpha]]
;;; (chuoi_con L) xuat ra list cac chuoi con cua L

(define (chuoi_con L)
  (if (pair? (cdr L))
      (append (them_phan_tu (car L) (chuoi_con (cdr L)))
              (chuoi_con (cdr L)))
      (list L ())))

(chuoi_con '(1 2 3))
(chuoi_con '(1))
(chuoi_con '(1 2))