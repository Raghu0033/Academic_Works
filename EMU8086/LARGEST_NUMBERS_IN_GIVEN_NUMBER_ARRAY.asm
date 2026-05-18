MOV SI, 1000H  
MOV DI,2000H
MOV CL, 5
MOV AX,[SI]

LOOP1:
    ADD SI,02
    DEC CL   
    JZ SKIP
    CMP AX,[SI]
    JAE LOOP1  
    MOV AX, [SI]
    JMP LOOP1         
    
SKIP:
    MOV [DI],AX
    HLT
    