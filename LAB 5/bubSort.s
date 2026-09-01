	AREA RESET, AREA, READONLY
	EXPORT __Vectors
	
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY

Reset_Handler
	