.text
  LDR r0, =S
  MOV r5, #0
loop:
  LDRb r1, [r0], #1
  ADD r5, r5, #1
  CMP r1, #0
  BNE loop
  SUB r5, r5, #1
  SWI 0x011
.data
  S: .asciz "Hello world"
