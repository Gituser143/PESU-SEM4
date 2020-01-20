.text
  LDR r0, =A
  LDR r1, =B
  MOV r3, #4
 loop:
  LDR r4, [r0], #4
  LDR r5, [r1], #4
  MUL r6, r5, r4
  ADD r7, r7, r6
  SUBs r3, r3, #1
  BNE loop
  SWI 0x011


.data
  A: .word 1,2,3,4
  B: .word 2,3,4,5
