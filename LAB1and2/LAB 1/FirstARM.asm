	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #0x123
	MOV R1, #0123 
	MOV R2, #-1
	MOV R3, #2_10101010
	MOV R4, #8_176
STOP
	B STOP
	END 