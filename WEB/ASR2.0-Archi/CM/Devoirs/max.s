	load X
	sub Y
	jneg OUI
	load X
	jmp NON

OUI
	load Y

NON
	store MAX
	halt 0

A word 3
B word 5
MAX word 0

