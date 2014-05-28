	CLO
	MOV	CL,A0		

START:
	IN	00

	CMP	AL,0D		; If the user press ENTER, the program stops receiving input button
	JZ	TRANSFORM	

	PUSH	AL		; Push ASCII value to stack
	INC	DL		; DL is used to count the number's figures (eg, 123 has 3 figures)

	JMP	START

TRANSFORM:			; Tranform the ASCII value to real value of the number
	MOV	[B0],DL		; Store the value of DL to the address B0 to use it later

BEGIN:
	POP	BL		

	CMP	BL,39		; Compare BL with 39 (ASCII), if BL <= 39 ---> 0 to 9
	JS	_0_TO_9		; 			      if BL > 39  ---> A to F	
	JNS	A_TO_F	

_0_TO_9:
	SUB	BL,30
	MOV	[CL],BL	
	INC	CL
	DEC	DL

	CMP	DL,0
	JNZ	BEGIN

	JMP	PLACE_IN_RAM

A_TO_F:
	SUB	BL,37
	MOV	[CL],BL
	INC	CL
	DEC	DL

	CMP	DL,0
	JNZ	BEGIN

	JMP	PLACE_IN_RAM
	
PLACE_IN_RAM:			; Calculate the position to place the pointer in RAM
	MOV	DL,[B0]		; Pop DL from B0

	MUL	DL,4
	SUB	DL,1
	MOV	CL,C0
	ADD	CL,DL	

	MOV	DL,A0

CONVERT_10_2:
	MOV	BL,0
	MOV	AL,[DL]

BOUCLE:
	PUSH	AL

	CMP	BL,4
	JZ	SUITE
	
	MOD	AL,2	
	ADD	AL,30
	MOV	[CL],AL

	POP	AL
	DIV	AL,2

	INC	BL
	DEC	CL

	JMP	BOUCLE

SUITE:
	INC	DL
	
	CMP	CL,BF
	JNZ	CONVERT_10_2

FINISH:
	END
