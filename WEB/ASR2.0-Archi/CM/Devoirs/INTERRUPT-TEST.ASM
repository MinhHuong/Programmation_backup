	JMP START
	DB	30
	DB	50

START:
	MOV	BL,A0
	STI

	INT	02
	INT	03

;================================
	ORG	30
	IRET

;================================
	ORG	50
CIN:
	OUT	07
	IN	07
	CMP	AL,0D
	JZ	BREAK
	MOV	[BL],AL
	INC	BL
	JMP	CIN
BREAK:
	IRET
		
END