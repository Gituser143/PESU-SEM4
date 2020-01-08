  MOV r0, #10
  MOV r1, #10
  EORs r3, r1, r0
  BEQ add
  SUB r2, r1, r0
  B end


add:
  ADD r2, r1, r0

end:
  SWI 0x011
