# SOMME DES ENTIER DE 1 A N

BOUCLE
	load N
	sub K
	jneg END

	load RESULT
	add K
	store RESULT

	loadi 1
	add K
	store K

	jmp BOUCLE

END
	halt 0

N word 5
K word 1
RESULT word 0
