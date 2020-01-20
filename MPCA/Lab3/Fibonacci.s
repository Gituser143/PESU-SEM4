.text
  MOV r0, #0
  MOV r1, #1
  LDR r2, =A
  MOV r4, #8
  
 loop:
  STR r0,[r2], #4
  ADD r3, r0, r1
  MOV r0,r1
  MOV r1,r3
  SUBs r4,r4,#1
  BNE loop
  
  SWI 0x011

.data
  A: .word 00, 00, 00, 00
