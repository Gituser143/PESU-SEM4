  MOV r0, #11
  ANDs r1, r0, #1
  BEQ odd
  MOV r2, #1
  b end
  
odd:
  MOV r2, #0  
 
end:
  SWI 0x011
