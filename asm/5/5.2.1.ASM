DATAS SEGMENT
    ;此处输入数据段代码  
    string DB 'CONGRATULATION!',0DH,0AH,24H
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
	MOV DL,DS:[0000H]
	MOV DH,DS:[0005H]
	
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
