DATAS SEGMENT
    ;�˴��������ݶδ���  
    X DW 101H
    Y DW 102H
    Z DW 103H
    V DW 104H
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV CX,WORD PTR V
    MOV DX,WORD PTR Z
    SUB CX,DX
    
    MOV AX,Y
    CWD
    DIV CX
    MOV BX,CX
    
    MOV AX,Y
    MOV CX,Z
    ADD AX,CX
    
    SUB AX,BX
    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
