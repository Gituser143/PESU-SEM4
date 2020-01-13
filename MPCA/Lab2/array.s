.text
  LDR r0, =A
  MOV r3, #4
  LDR r4, =C
loop:
  LDR r1, [r0]
  ADD r2, r2, r1
  ADD r0, r0, #4
  SUBs r3, r3, #1
  BNE loop
  
end:
  STR r2, [r4]
  
.data
  A: .word 10, 20, 30, 40
  C: .word 00, 00, 00, 00
