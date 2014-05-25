# MULTIPLICATION

BOUCLE
	load Y
	sub I
	store Y
	jneg END

	load RESULT
	add X
	store RESULT

	jmp BOUCLE

END
	halt 0

X word 5
Y word 3
I word 1
RESULT word 0
