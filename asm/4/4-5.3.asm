DATAS SEGMENT
    X DW 6FH
    Y DW 0EE0H
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV DX,X
    MOV AX,Y
    
    SHR DX,1
    RCR AX,1
    SHR DX,1
    RCR AX,1
    SHR DX,1
    RCR AX,1
    SHR DX,1
    RCR AX,1
    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START