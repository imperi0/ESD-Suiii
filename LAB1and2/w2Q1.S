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
	LDR R0,=SRC
	LDR R1,=DST
	; LDR R2, [R0]
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
	LDR R2, [R0], #4
	STR R2, [R1], #4
	
STOP 
	B STOP

SRC DCD 0x1234ABCD, 0x1234ABCF, 0x1234ABD1, 0x1234ABD3, 0x1234ABD5, 0x1234ABD7, 0x1234ABD9, 0x1234ABDB, 0x1234ABDD, 0x1234ABDF
	AREA mydata, DATA, READWRITE
	
DST DCD 0x00000000

	END