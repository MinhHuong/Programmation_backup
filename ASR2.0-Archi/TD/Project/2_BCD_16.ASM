;;;;;=================================================;;;;;
;;;;;						      ;;;;;
;;;;;   CHUONG TRINH CHUYEN DOI TU HE 2 SANG HE 16    ;;;;;
;;;;;						      ;;;;;
;;;;;=================================================;;;;;

	CLO

	MOV	BL,0		; BL dung de tinh so bit nhap vao
	MOV	[A1],BL		; Luu gia tri cua BL vao dia chi [A1]

	MOV	AL,B0		; AL dung lam con tro, tro toi dia chi [B0]
	MOV	[A2],AL		; [A2] dung de luu dia chi ma AL tro toi

INPUT:
	IN	00

	CMP	AL,0D		; Neu nguoi dung go ENTER --> chuong trinh ngung viec nhap du lieu
	JZ	TRANSFORM

	SUB	AL,30		; Chuyen tu gia tri ASCII sang gia tri thuc de tinh toan
	PUSH	AL		; Luu gia tri AL vao stack
	INC	BL		; Tang so luong bit len
		
	MOV	[A0],BL		; [A0] chua tong so luong bit

	JMP	INPUT

TRANSFORM:
	MOV	BL,[A0]		
	SUB	BL,4		; Moi lan xu li se chuyen doi 4 bit he 2 sang 1 ky tu he 16  
				; --> Lay tong so bit tru di 4
	MOV	[A0],BL		; Luu tong so bit sau khi tru 4 tro lai vao [A0]

	MOV	BL,0		
	MOV	CL,0		; CL chua ket qua sau khi doi tu he 2 sang he 16
	MOV	DL,1		; DL dung de chua he so 2 luy thua, vi du : 2^0, 2^1, 2^2, 2^3,...

BCD_TO_16:			; Moi lan chay BCD_TO_16 se chuyen 4 bit he 2 sang 1 ky tu he 16
	CMP 	BL,4
	JZ 	SUITE

	POP 	AL		; Lay gia tri AL tu stack ra de xu ly
	MUL 	AL,DL		; Nhan AL cho DL (he so luy thua 2)
	ADD 	CL,AL		; Ket qua luu vao CL
	MUL 	DL,2		; Sau 1 vong lap DL se nhan len 2

	INC 	BL		
	JMP 	BCD_TO_16

SUITE:	
	MOV	AL,[A2]		; [A2] dung lam dia chi de chua ket qua sau khi doi sang he 16
	MOV	[AL],CL		; Gan ket qua CL vao con tro AL
	INC	AL		; Tang vi tri cua AL tren RAM
	MOV	[A2],AL		; Luu vi tri cua AL vao [A2]

	MOV	DL,[A1]		; [A1] dung de chua so luong cac ky tu he 16 (tu he 2 doi sang)
	ADD	DL,1		; Sau 1 lan chay TRANSFORM, tang so luong ky tu he 16
	MOV	[A1],DL		; DL dung lam bien trung gian, ket qua cuoi cung luu lai vao [A1]

	MOV	BL,[A0]		; Kiem tra xem tong so luong bit he 2 con bao nhieu
	CMP	BL,0		; Neu BL bang 0 --> chuong trinh da xu li het cac bit he 2
	JZ	TINH_RAM	; Cac bit he 2 da duoc xu li het --> chuyen sang gia doan tinh toan 
				; vi tri de hien thi trong RAM
	JNZ	TRANSFORM	; Neu chua thi tiep tuc chay TRANSFORM

TINH_RAM: 
	MOV	BL,C0		; Gan vi tri xuat ra cua ky tu dau tien vao BL ( luu o [C0] )

	MOV	AL,[A2]		; Vi tri [A2] luc nay khong tro den dung gia tri hien ra man hinh
	DEC	AL		; Can phai giam vi tri luu trong [A2] xuong 1 bac de tro den dung
				; so dau tien can xuat ra man hinh

BEFORE_PRINT:
	CMP	DL,0		; DL luc nay dang luu so luong ky tu he 16 can xuat ra man hinh
	JZ	QUIT		; Neu DL = 0 --> tat ca cac ky tu da duoc xuat ra man hinh --> Thoat
	JNZ	PRINT		; Neu DL > 0 --> tiep tuc xuat ra man hinh

PRINT:
	MOV	CL,[AL]		; Gan so dau tien can in vao CL ( [AL] chua dia chi tro den so can in )

	CMP 	CL,A		; So sanh gia tri trong CL voi 10
	JS 	_0_TO_1		; CL < 10   --> ky tu he 16 nam trong khoang [0,9]
	JNS 	A_TO_F		; Nguoc lai --> ky tu he 16 nam trong khoang [A,F]

_0_TO_1:			
	ADD 	CL,30		; Cong 30 vao CL de hien thi theo ma ASCII so 0...9
	MOV 	[BL],CL		
		
	DEC	DL		; Giam so luong ky tu he 16 can in 
	INC	BL		; Tang vi tri cua con tro BL trong RAM ( BL dung de in ra so )
	DEC	AL		; Giam vi tri cua con tro AL den so can in ( AL tro den so can in )

	JMP	BEFORE_PRINT

A_TO_F:
	ADD	CL,37		; Cong 37 vao CL de hien thi theo ma ASCII ky tu A...F
	MOV	[BL],CL

	DEC	DL
	INC	BL
	DEC	AL

	JMP	BEFORE_PRINT

QUIT: 
	END
