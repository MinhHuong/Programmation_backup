	CLO
	MOV	CL,BC

ASCII_INPUT:			;;; Program : convert decimal to complement by 2 (binary)
	IN	00		;;; (maximum : 127)

	CMP	AL,0D		;;; Press Enter to stop typing the number
	JZ	COMPARE

	MOV	[CL],AL
	INC	CL		
	INC	DL		;;; Count the figures (eg, 123 has 3 figures)
	
	JMP	ASCII_INPUT

COMPARE:
	MOV	AL,0
	DEC	CL

	CMP	DL,3
	JZ	_3_NUMBERS
	
	CMP	DL,2
	JZ	_2_NUMBERS

	CMP	DL,1
	JZ	_1_NUMBER

;;;================================	
_3_NUMBERS:
	CALL	B2		;;; Calculate the unit
	ADD	AL,BL

	CALL	B2		;;; Calculate the tens column
	MUL	BL,A		;;; A(16)=10(10)
	ADD	AL,BL

	CALL	B2		;;; Calculate the hundreds column
	MUL	BL,64		;;; 64(16)=100(10)
	ADD	AL,BL

	JMP	CONVERT_TO_2	;;; After these operations, the final result is saved in AL

_2_NUMBERS:
	CALL	B2
	ADD	AL,BL

	CALL	B2
	MUL	BL,A
	ADD	AL,BL
	
	JMP	CONVERT_TO_2

_1_NUMBER:
	CALL	B2
	ADD	AL,BL

	JMP	CONVERT_TO_2

;;;===================================
CONVERT_TO_2:
	MOV	CL,C7
	MOV	DL,8		;;; 8 bits to write the binary number

CONVERT_AND_INVERT:		;;; Convert from 10 to 2 and invert the binary number
	PUSH	AL		;;; at the same time
	POP	BL
	
	MOD	BL,2
	ADD	BL,30

	CMP	BL,30
	JZ	_0_TO_1

_1_TO_0:
	MOV	BL,30
	JMP	CONTINUE

_0_TO_1:
	MOV	BL,31

CONTINUE:	
	MOV	[CL],BL
	DEC	CL

	DIV	AL,2		
	DEC	DL		;;; This procedure wil stop when 8 bits are all written
	CMP	DL,0
	JNZ	CONVERT_AND_INVERT
	
	JMP	ADD_1		;;; The last step : add 1 & we'll have the exact result

;;;===================================
ADD_1:
	MOV	CL,C7

TEST_0_OR_1:
	MOV	AL,[CL]
	CMP	AL,30
	JZ	FINISH_BY_0

FINISH_BY_1:
	MOV	AL,30
	MOV	[CL],AL
	DEC	CL

	CMP	CL,BF
	JNZ	TEST_0_OR_1
	JMP	FINISH

FINISH_BY_0:
	MOV	AL,31
	MOV	[CL],AL
	JMP	FINISH
	
;;;===================================
	ORG	B2		;;; A program converting from ASCII code to Decimal number
				;;; ( eg, 31(ASCII) = 1(Decimal) )
	MOV	BL,[CL]
	SUB	BL,30
	DEC	CL

	RET
;;;===================================
FINISH:
	END
