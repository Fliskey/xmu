DATAS SEGMENT
    ;�˴��������ݶδ���  
    X DW 0101H
    Y DW 0102H
    Z DW 0103H
    V DW 0104H
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV AX,WORD PTR Y
    MOV BX,WORD PTR Z
    ADD AX,BX
    
    MOV CX,V
    IMUL CX
    MOV BX,AX
    MOV CX,DX
    
    MOV AX,WORD PTR X
    CWD
    SUB AX,BX
    SBB DX,CX
    
    
    
    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START

