
MOV R0,#1
MOV R1,R0,LSL #7
MOV R2,R0,LSL #5
ADD R3,R0,R0,LSL #1
RSB r3,r3,r3,LSL #3
ADD R5,R1,R2
ADD R5,R5,R3

MOV R0,#1
MOV R4,R0,LSL #7
MOV R6,R0,LSL #6
ADD R7,R0,R0,LSL #1
RSB r7,r7,r7,LSL #3
ADD R8,R4,R6
ADD R8,R8,R7
