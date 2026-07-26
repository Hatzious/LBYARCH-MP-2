section .data
DIVISOR dd 255.0

section .text

;needed to interface with c in assembly
default rel
bits 64

global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:

	push rbp
	mov rbp, rsp
	add rbp, 16

	PUSH R12
	PUSH RSI
	PUSH RBX

	;RBX holds size
	MOV RBX, RCX
	IMUL RBX, RDX

	CMP RBX, 0
	JE FIN
	MOV R12, 0
	MOV RSI, 0

	;create the divisor
	MOVSS XMM1, [DIVISOR]
	RCPSS XMM1, XMM1

LOOP1:
	;clear R9 of garbage
	;R9 will hold our temporary data
	MOV R9, 0
	MOV R9D, [R8 + 4 * RSI]
	CVTSI2SS XMM0, R9D;convert to float

	;do da division
	MULSS XMM0, XMM1

	;move result into memory
	MOVSS dword [R8 + 4 * RSI], XMM0

	;condition check
	INC RSI
	CMP RBX, RSI
	JE FIN
	
	JMP LOOP1
	

FIN:
	MOV RAX, 1

	POP RBX
	POP RSI
	POP R12
	pop rbp
	

	ret