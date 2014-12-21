;;;;;=======================================================;;;;;
;;;;;							    ;;;;;
;;;;;     CHUONG TRINH CHUYEN DO SO HE 10 THANH SO BU 2     ;;;;;
;;;;;							    ;;;;;
;;;;;=======================================================;;;;;

	CLO

;;;=============================================
ASCII_INPUT:			
	IN	00	

	CMP	AL,0D		; Neu nguoi dung nhap ENTER --> chuong trinh ngung viec nhan input
	JZ	CONVERT_TO_10

	SUB	AL,30		; Lay AL tru 30 de nhan duoc gia tri thuc su dung trong tinh toan
	PUSH	AL		; Luu gia tri cua AL vao stack
	
	INC	DL		; DL dung de dem so chu so ( vd: 127 co 3 chu so )
	
	JMP	ASCII_INPUT

;;;=============================================
CONVERT_TO_10:			
	MOV	AL,0		; AL dung de luu gia tri sau khi doi tu he 2 sang he 10
	MOV	CL,1		; CL la luy thua 10 ( vd: 10^0, 10^1, 10^2... ), luc nay CL = 10^0 = 1

CALCULATE:			; Tinh theo chieu hang don vi -> hang chuc -> hang tram
	CMP	DL,0
	JZ	CONVERT_TO_2

	POP	BL		; Lay gia tri cua stack luu vao BL 
	MUL	BL,CL		; Lay BL nhan voi luy thua 10
	ADD	AL,BL		; Cong gia tri roi luu vao AL
	MUL	CL,A		; Sau moi vong lap, CL nhan len 10
	DEC	DL		

	JMP	CALCULATE
	
;;;=============================================
CONVERT_TO_2:
	MOV	CL,C7		; CL tro den dia chi [C7] trong RAM ( in tu sau ra truoc )
	MOV	DL,8		; 8 bit de viet so bu 2 

CONVERT_AND_INVERT:		; Chuyen tu he so 10 sang he so 2 dong thoi dao nguoc cac bit cua he 2
	PUSH	AL			
	POP	BL
	
	MOD	BL,2
	ADD	BL,30

	CMP	BL,30		; So sanh bit de dao nguoc
	JZ	_0_TO_1

_1_TO_0:			; Neu bit = 1 --> dao nguoc thanh bit 0
	MOV	BL,30
	JMP	CONTINUE

_0_TO_1:			; Neu bit = 0 --> dao nguoc thanh bit 1
	MOV	BL,31

CONTINUE:	
	MOV	[CL],BL		; Gan gia tri cua BL vao dia chi CL tro toi
	DEC	CL		; Giam vi tri cua CL

	DIV	AL,2

	DEC	DL		
	CMP	DL,0		; Qua trinh convert-invert se ngung lai khi 8 bit da duoc xu ly
	JNZ	CONVERT_AND_INVERT
	
	JMP	ADD_1		; Buoc cuoi cung : them 1 vao so bu 1 de duoc so bu 2 hoan chinh


;;;=============================================
ADD_1:
	MOV	CL,C7		; Dieu chinh lai CL --> cho CL tro vao bit cuoi cung trong day 8 bit

TEST_0_OR_1:
	MOV	AL,[CL]		
	CMP	AL,30		
	JZ	FINISH_BY_0

FINISH_BY_1:			; Xu ly khi +1 vao bit 1
	MOV	AL,30		; Neu AL la bit 1 thi sau khi +1 se bang bit 0. Sau do se tiep tuc 
				; xet den cac bit tiep theo de xu ly viec 1+1=0, nho 1
	MOV	[CL],AL		
	DEC	CL

	CMP	CL,BF		; Dieu kien de dung chuong trinh
	JNZ	TEST_0_OR_1	
	JMP	FINISH

FINISH_BY_0:			; Xu ly khi +1 vao bit 0
	MOV	AL,31		
	MOV	[CL],AL
	JMP	FINISH

;;;=============================================
FINISH:
	END
