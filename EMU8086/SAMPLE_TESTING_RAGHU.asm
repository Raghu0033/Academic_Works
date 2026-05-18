MOV SI, 1000H  
MOV DI,2000H
MOV CL, 5
MOV BX,[SI]

LOOP1:
    MOV AX,[SI]
    INC SI
    CMP BX,[SI]
    JAE LOOP2  
    MOV BX, [SI]
LOOP2:
    DEC CL   
    JZ SKIP
    JMP LOOP1         
    
SKIP:
    MOV [DI],BX
    HLT
    