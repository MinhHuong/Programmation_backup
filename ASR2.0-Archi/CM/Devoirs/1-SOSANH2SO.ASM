	MOV DL,0
	MOV BL,AF	;	BL tro den vi tri o nho AF
	CALL 50
	MOV [A1],BL
	MOV [A0],DL
	MOV BL,9F
	CALL 50
	MOV [91],BL
	MOV [90],DL

	MOV AL,[A0]
	CMP AL,[90]
	JS SO2
	JZ KT
SO2:
	MOV DL,32
	MOV [C1],DL
	JMP FIN
SO1:
	MOV DL,31
	MOV [C1],DL
	JMP FIN
KT:
	MOV BL,92
	MOV CL, A2
TEST:	MOV AL,[BL]
	MOV DL, [CL]
	INC BL
	INC CL
	CMP AL,DL
	JZ TEST
	JNS SO2
	JMP SO1


ORG 50
	MOV CL,0
Rep:
	IN	00	; Wait for key press - Store it in AL.
	CALL 	75
	INC 	CL
	PUSH 	AL
	CMP	AL,0D	; Was it the Enter key? (ASCII 0D)
	JNZ	Rep
	PUSH CL
	POP DL
NHANSO:
	POP AL
	MOV [BL],AL
	DEC BL
	DEC CL
	CMP CL,0
	JNZ NHANSO	
	RET
	
	ORG 75		;	Ham nhap va kiem tra SO
NUMBER:
	CMP AL,0D
	JZ THOAT
	CMP AL,30
	JS NHAP
	CMP AL,39
	JNS NHAP
	JMP THOAT
NHAP:
	IN 00		;	Nhap ky tu vao
	JMP NUMBER	;	Nhay len tren kiem tra coi phai la So hay khong
THOAT:
	RET

	

FIN:
END