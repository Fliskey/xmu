DATAS SEGMENT
    X DW 23H  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV AX,0
    MOV AX,X
    MOV CL,3
    SHL AX,CL
    MOV BX,0
    MOV BX,X
    SHL BX,1
    ADD AX,BX
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
