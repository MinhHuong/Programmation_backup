#calculer la somme des elements dans le tableau
BOUCLE
	#if K < N ?
	load N
	sub K
	jzero FIN

	#add new value
	loadi T
	add K
	store PTR

	#addtion
	loadx PTR
	add RESULT
	store RESULT

	#K++
	loadi 1
	add K
	store K

	jmp BOUCLE

FIN
	halt 0

N word 6
K word 0
PTR word 0
RESULT word 0
T word 1 #T[0]
  word 2 #T[1]
  word 3 #T[2]
  word 4 #T[3]
  word 5 #T[4]
  word 6 #T[5]
