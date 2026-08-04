	AREA RESET, DATA, READONLY
	EXPORT __Vectors
	
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	
	LDR R2, [R0, #0]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
	LDR R2, [R0, #4]!
	STR R2, [R1, #4]!
	
STOP 
	B STOP

SRC DCD 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678
	AREA mydata ,DATA ,READWRITE

DST DCD 0
	END