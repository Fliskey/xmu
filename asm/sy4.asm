DATAS SEGMENT
    X DW 0102H
	Y DW 0103H
	Z DW 0104H
	V DW 0105H 
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV AX,WORD PTR X
	MOV BX,WORD PTR Y
	IMUL BX
	MOV CX,AX
	MOV BX,DX
	MOV AX,WORD PTR Z
	CWD
	ADD CX,AX
	ADC BX,DX
	SUB CX,0540H
	SBB BX,0
	MOV AX,WORD PTR V
	CWD
	SUB AX,CX
	SBB DX,BX
	MOV BX,WORD PTR X
	IDIV BX
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START