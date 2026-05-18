;word addition of 64 bit;
MOV SI, 2000H
MOV DI, 3000H
MOV CL, 8
       
L1:       
MOV AX,[SI]
MOV BX,[DI]
ADD AX,BX
MOV [SI],AX

ADD SI,2 
ADD DI,2
LOOP L1
HLT