;;;;;================================================;;;;;
;;;;;						     ;;;;;
;;;;;     CHUONG TRINH CHUYEN TU HE 16 SANG HE 2     ;;;;;
;;;;;						     ;;;;;
;;;;;================================================;;;;;

	CLO
			
	MOV	CL,C0		; CL tro toi dia chi [C0] trong RAM de hien thi day bit

;;;=============================================
INPUT:
	IN	00

	CMP	AL,0D		; Neu nguoi dung nhap ENTER --> chuong trinh ngung nhan input
	JZ	PLACE_IN_RAM	

	CMP	AL,3A		; Xet xem AL la ky tu 0...9 hay A...F
	JS	_0_TO_9
	JNS	_A_TO_F

_0_TO_9:
	SUB	AL,30
	JMP	CONTINUE

_A_TO_F:
	SUB	AL,37

CONTINUE:
	PUSH	AL		; Luu AL vao stack ( sau khi chuyen qua gia tri thuc su de tinh toan )
	INC	DL

	JMP	INPUT

;;;=============================================
PLACE_IN_RAM:			; Tinh vi tri hien thi tren RAM ( day bit hien thi tu sau ra truoc )
	MUL	DL,4	
	SUB	DL,1		
	MOV	CL,C0
	ADD	CL,DL


;;;=============================================
CONVERT_10_2:
	MOV	BL,0
	POP	AL		; Lay gia tri tu stack ra luu vao AL de tinh toan

BOUCLE:				; Moi lan BOUCLE chay la mot ky tu he 16 duoc chuyen qua he 2
	CMP	BL,4		; Khi da xu ly xong 4 bit ( he 2 ) cho 1 ky tu he 16 --> nhay qua
				; ky tu he 16 ke tiep
	JZ	NEXT_CHARACTER

	PUSH	AL
	POP	DL
	
	MOD	DL,2
	ADD	DL,30
	MOV	[CL],DL

	DIV	AL,2

	INC	BL
	DEC	CL

	JMP	BOUCLE

NEXT_CHARACTER:	
	CMP	CL,BF		; Dieu kien dung chuong trinh : khi con tro CL chi den dia chi [BF]
	JNZ	CONVERT_10_2

;;;=============================================
FINISH:
	END
