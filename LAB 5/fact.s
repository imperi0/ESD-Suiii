	AREA RESET, DATA, READONLY
	EXPORT __Vectors
	
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	
	MOV R0,#3
	MOV R2,#1

UP
	MUL R2, R2, R0
	SUBS R0, R0, #1
	BNE UP

STOP
	B STOP