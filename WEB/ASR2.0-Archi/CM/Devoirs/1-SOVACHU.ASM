	MOV BL,2	;	Xac dinh ky tu danh vao la ky tu thu 1 hay 2
	MOV CL,0	;	Bien Flag 1 cho biet ky tu ke tiep phai la so hay chu
VONGLAP:	
	IN 00		;	Nhap ky tu tu ban phim
	CMP CL,1	;	Neu la 1, thi phai nhap so
	JZ SO		;	Nhay den phan nhap so
CHU:			
	CALL 30		;	Goi ham nhap Chu vao
	CMP BL,0	;	Neu da danh 2 ky tu vao, thi nhay den het chuong trinh
	JZ FINISH
	CMP BL,1	;	Neu chi moi nhap 1 ky tu, thi nhay lai vong lap de nhap ky tu thu 2 vao
	JZ VONGLAP
SO:	
	CALL 60		;	Goi ham nhap So vao
	CMP BL,0	;	Neu da nhap 2 ky tu vao, thi het chuong trinh
	JNZ VONGLAP
FINISH:

	ORG 30		;	Ham kiem tra ky tu co phai la Chu khong?
BEGIN:
	CMP AL,41	;	Neu truoc chu 'A' thi khong phai chu, nhay den Again
	JS AGAIN
	CMP AL,7A	;	Neu sau chu 'z' thi khong phai la chu, nhay den Again
	JNS AGAIN
	CMP AL,5A	;	Neu truoc chu 'Z' => chu, nhay den Stop
	JS STOP	
	CMP AL,61	;	Neu sau chu 'a' => chu, nhay den Stop
	JNS STOP
AGAIN:
	CMP BL,2	;	Neu ky tu nhap vao khong phai la Chu, va la ky tu thu 1 thi nhay den cuoi ham
	JZ RETURN	;	vi ky tu dau tien co the la Chu, hoac So, nen ta di xet ky tu do co phai la So hay khong
	IN 00		;	yeu cau nhap 1 ky tu vao, va nhay len Begin de kiem tra xem do co phai la Chu khong
	JMP BEGIN
STOP:
	DEC BL		;	Neu ky tu vua nhap vao la Chu, thi , so ky tu con lai phai nhap kiem tra là BL giam di 1
	MOV CL,1	;	Vi ky tu vua nhap la la Chu, thi ky tu ke tiep phai la so, bat Flag len de nhap So
	CMP BL,1	;	in ra screen
	JZ LETTER1	;
	MOV [C1],AL
	JMP RETURN
LETTER1:
	MOV [C0],AL
	
RETURN:
	RET
	
	ORG 60		;	Ham nhap va kiem tra SO
NUMBER:
	CMP AL,30
	JS NHAP
	CMP AL,39
	JNS NHAP
	JMP THOAT
NHAP:
	CMP BL,2	;	Neu ky tu vua nhap vao khong phai la so, thi ta di den cuoi ham
	JZ QUAYLAI
	IN 00		;	Nhap ky tu vao
	JMP NUMBER	;	Nhay len tren kiem tra coi phai la So hay khong
THOAT:
	DEC BL		;	Giam so ky tu can phai nhap xuong 1 don vi
	
	CMP BL,1	;	In ra screen
	JZ KYTU1	;
	MOV [C1],AL
	JMP QUAYLAI
KYTU1:
	MOV [C0],AL
QUAYLAI:
	RET
END