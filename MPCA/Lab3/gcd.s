.text
  MOV r0, #75
  MOV r1, #25
loop:
  CMP r1,r0
  BEQ gcd
  BMI swapsub
  SUB r1,r1,r0
  B loop
  
 gcd:
  MOV r3,r1
  SWI 0x011
  
 swapsub:
  SUB r0,r0,r1
  B loop
  
