	CLO

	MOV 	AL,4
	CALL 	40

	MOV 	AL,5
	CALL 	45

	MOV 	CL,5
	CALL	50
	
	MOV	CL,5
	CALL	55 

	;double a number
	ORG 	40
	MUL 	AL,2
	RET

	;invert bits
	ORG 	45
	NOT 	AL
	RET

	;factoriel
	ORG 	50
	MOV	AL,1
	MOV	BL,1
FAC:
	MUL 	AL,BL
	INC	BL
	DEC 	CL
	CMP 	CL,0
	JNZ	FAC
	RET

	;factoriel recursif
	ORG	55
BASE:
	MOV	DL,1
	PUSH	AL
	POP	BL
	MUL	AL,BL
FACRES:
	CMP	CL,0
	JZ	BASE
	PUSH	CL
	POP	AL
	MUL	AL,CL
	;CALL	55
	RET

END