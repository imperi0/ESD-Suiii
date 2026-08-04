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
	LDR R3,=DST
	;LDR R2,=SRC
	LDR R0,=0x12345678
	LDR R1,=0xABCDEF12
	MOV R4, R0
	STR R0, [R3]
	STR R1, [R3, #4] 
	; 00 : 78 
	; 01 : 56 
	; 02 : 34 
	; 03 : 12 
	; 04 : 12 
	; 05 : EF 
	; 06 : CD 
	; 07 : AB
STOP B STOP	
	AREA mydata, DATA, READWRITE
DST DCD 0