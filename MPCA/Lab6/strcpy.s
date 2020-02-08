.text
  LDR r0, =S
  LDR r1, =A
loop:
  LDRb r2, [r0], #1
  STRb r2, [r1], #1
  CMP r2, #0
  BNE loop

  LDR r0, =S
  SWI 0x02
  SWI 0x011
.data
  S: .asciz "strcpy works"
  A: .asciz ""
