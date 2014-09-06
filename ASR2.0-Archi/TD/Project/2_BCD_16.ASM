;;;;;=================================================;;;;;
;;;;;						      ;;;;;
;;;;;   CHUONG TRINH CHUYEN DOI TU HE 2 SANG HE 16    ;;;;;
;;;;;						      ;;;;;
;;;;;=================================================;;;;;

	CLO
	
	MOV	CL,C0		; CL duoc su dung nhu con tro, tro toi C0
	
INPUT:
	IN	00

	CMP	AL,0D		; Neu nguoi dung go ENTER --> chuong trinh ngung viec nhap du lieu
	JZ	PLACE_IN_RAM

	SUB	AL,30		; Chuyen tu gia tri ASCII sang gia tri thuc de tinh toan
	PUSH	AL		; Luu gia tri AL vao stack
	INC	BL		; Tang so luong bit len
		
	MOV	[A0],BL		; [A0] chua tong so luong bit

	JMP	INPUT


PLACE_IN_RAM: 			; Tinh vi tri bit hien thi trong RAM ( 12 bit he 2 --> 3 bit he 16 )
				
	DIV	BL,4		; Lay tong so bit chia cho 4 --> biet so chu so ben he 16
	SUB	BL,1		; Phai tru 1 vi bat dau tu C0
	ADD	BL,CL 		; Dich con tro trong RAM len 


PREPARE:

	MOV	DL,[A0]		; Chuyen tong so luong bit vao DL 
	SUB	DL,4		; Moi lan xu li se chuyen doi 4 bit he 2 sang 1 ky tu he 16  
				; --> Lay tong so bit tru di 4
	MOV	[A0],DL		; Luu tong so bit sau khi tru 4 tro lai vao [A0]
		
	MOV	CL,0		; CL chua ket qua sau khi doi tu he 2 sang he 16
	MOV	DL,1		; DL dung de chua he so 2 luy thua, vi du : 2^0, 2^1, 2^2, 2^3,...

BCD_TO_16:			; Moi lan chay BCD_TO_16 se chuyen 4 bit he 2 sang 1 ky tu he 16
	
	CMP	DL,10
	JZ 	PRINT

	POP 	AL		; Lay gia tri AL tu stack ra de xu ly
	MUL 	AL,DL		; Nhan AL cho DL (he so luy thua 2)
	ADD 	CL,AL		; Ket qua luu vao CL
	MUL 	DL,2		; Sau 1 vong lap DL se nhan len 2

		
	JMP 	BCD_TO_16

PRINT:

	CMP 	CL,A		; So sanh gia tri trong CL voi 10
	JS 	_0_TO_9		; CL < 10   --> ky tu he 16 nam trong khoang [0,9]
	JNS 	A_TO_F		; Nguoc lai --> ky tu he 16 nam trong khoang [A,F]

_0_TO_9:			
	ADD 	CL,30		; Cong 30 vao CL de hien thi theo ma ASCII so 0...9
	MOV 	[BL],CL			
	DEC	BL		; Tang vi tri cua con tro BL trong RAM ( BL dung de in ra so )

	JMP	AFTER_PRINT

A_TO_F:
	ADD	CL,37		; Cong 37 vao CL de hien thi theo ma ASCII ky tu A...F
	MOV	[BL],CL
	DEC	BL

	JMP	AFTER_PRINT

AFTER_PRINT:

	MOV	DL,[A0]		; Kiem tra xem tong so luong bit he 2 con bao nhieu
	CMP	DL,0		; Neu BL bang 0 --> chuong trinh da xu li het cac bit he 2
	JZ	QUIT		; Cac bit he 2 da duoc xu li het --> chuyen sang gia doan tinh toan 
				; vi tri de hien thi trong RAM
	JNZ	PREPARE		; Neu chua thi tiep tuc chay PREPARE

QUIT: 
	END
