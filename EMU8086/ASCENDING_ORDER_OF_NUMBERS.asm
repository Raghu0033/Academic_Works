; ASCENDING 
STEP1:
    MOV SI,3000H
    MOV BX,6
STEP2:
    MOV DL,[SI]
    MOV AL,[SI+1]
    CMP AL,DL
    JBE STEP3
    MOV [SI],DL
    MOV [SI+1],AL
STEP3:
    INC SI
    DEC BX
    JNZ STEP2
HLT