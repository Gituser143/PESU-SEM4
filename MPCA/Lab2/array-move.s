.text
  LDR r0, =A
  MOV r3, #4
  LDR r4, =C
loop:
  LDR r5, [r0]
  STR r5, [r4]
  ADD r4, r4, #4
  ADD r0, r0, #4
  SUBs r3, r3, #1
  BNE loop
  
  
.data
  A: .word 10, 20, 30, 40
  C: .word 00, 00, 00, 00
