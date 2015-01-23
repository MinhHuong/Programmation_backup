# DIVISION

BOUCLE
	load X
	sub Y
	jneg END
	store X

	loadi 1
	add RESULT
	store RESULT

	jmp BOUCLE

END
	load X
	store REMAIN
	halt 0

X word 14
Y word 3
RESULT word 0
REMAIN word 0
