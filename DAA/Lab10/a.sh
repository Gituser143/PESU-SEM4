#! /bin/bash
gcc myopen.c
./a.out > temp
rm final
while IN= read -r LINE
do
  grep "^$LINE$" /usr/share/dict/words >> final
done < temp
