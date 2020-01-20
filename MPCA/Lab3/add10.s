.text
  MOV r0, #10
  LDR r1, =A
  LDR r4, =B
  loop:
  LDRb r2, [r1], #1
  ADD r3,r3,r2
  SUBs r0,r0,#1
  BNE loop
  STR r3,[r4]
  SWI 0x011
.data
  A: .byte 1,2,3,4,5,6,7,8,9,10
  B: .word 00
