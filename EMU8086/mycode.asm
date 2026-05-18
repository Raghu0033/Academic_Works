MOV SI,1000H
MOV CL,[SI]
MOV AL,01
L1:MUL CL
LOOP L1
MOV [SI+1],AL
HLT
           




