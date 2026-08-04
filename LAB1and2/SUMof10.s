	AREA RESET, DATA, READONLY 
	EXPORT  __Vectors 

__Vectors  
	DCD  0x10001000     
	DCD  Reset_Handler  ; reset vector 
	ALIGN 
	AREA mycode, CODE, READONLY
	ENTRY 
	EXPORT Reset_Handler 

Reset_Handler 
	LDR R0,=SRC
	
	MOV R1, #0
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2
	
	LDR R2, [R0], #4
	ADDS R1, R2

STOP 
	B STOP
	
SRC DCD 0x11111111, 0xFFFFFFFF, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111
	AREA mydata, DATA, READWRITE
	
	END