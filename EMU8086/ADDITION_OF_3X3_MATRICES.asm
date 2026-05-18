MOV SI,1000H
MOV DI, 1010H
MOV BP, 1020H
MOV CX, 09H
L1:
    MOV AX,[SI]
    MOV BX,[DI]
    ADD AX, BX
    MOV [BP], AX
    INC SI
    INC DI
    INC BP
    DEC CX
    JNZ L1
HLT    