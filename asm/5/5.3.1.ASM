DATAS SEGMENT
    ;此处输入数据段代码  
    PACKED DB 0010H
    UNPACKED DB 0040H
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV DX,0AH
    MOV CL,4
    MOV SI,0
    MOV DI,0
CONVERT:	MOV AL,[SI+PACKED]
	MOV AH,AL
	AND AL,0FH
	SHR AH,CL
	MOV [DI+UNPACKED],AH
	ADD DI,1
	MOV [DI+UNPACKED],AL
	DEC DX
	JNZ CONVERT
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
