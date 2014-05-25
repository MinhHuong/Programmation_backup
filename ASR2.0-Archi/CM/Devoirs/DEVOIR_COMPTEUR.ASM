;;; A : arreter le compteur
;;; B : demarrer & continuer le compteur
;;; C : reset le compteur

	JMP	START

	DB 	70
	DB 	90

	DB 	FA 	;L 0
	DB 	0A 	;L 1
	DB 	B6 	;L 2
	DB 	9E 	;L 3
	DB 	4E 	;L 4
	DB 	DC 	;L 5
	DB 	FC 	;L 6
	DB 	8A 	;L 7
	DB 	FE 	;L 8
	DB 	DE 	;L 9

START:
	STI
	MOV	CL,0
	OUT 	07

	MOV 	DL,04
	MOV 	AL,[DL]
	OUT 	02

	MOV 	BL,04
	MOV 	AL,[BL]
	INC 	AL
	OUT 	02
	
	CMP	CL,2
	JZ	BOUCLE
	JMP	START

DIZAINE:
	MOV 	BL,04
	MOV 	AL,[BL]
	INC 	AL
	OUT 	02

	INC 	DL
	MOV 	AL,[DL]
	OUT 	02

BOUCLE: 

STOP:
	CMP	CL,1
	JZ	STOP

	CMP	CL,2
	JZ	CONTINUE

	CMP	CL,3
	JZ	START

CONTINUE:
	MOV 	AL,[BL]
	INC 	AL
	OUT 	02

	INC 	BL
	CMP 	BL,0E
	JNZ 	BOUCLE 

	CMP 	DL,0D
	JNZ 	DIZAINE
	JMP	START

;-----------------------------------
	ORG	70
	IRET

;------ si un bouton est appuye------
	ORG 	90

	IN	07

	CMP	AL,41
	JZ	BUTTONA

	CMP 	AL,42	
	JZ	BUTTONB

	CMP 	AL,43
	JZ	BUTTONC

BUTTONA:
	MOV 	CL,1
	IRET

BUTTONB:
	MOV 	CL,2
	IRET

BUTTONC:
	MOV	CL,3
	IRET

END