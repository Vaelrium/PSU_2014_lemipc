#! /bin/bash

declare -i x=0

(sleep 30; killall lemipc)&

xfce4-terminal -e ./lemipc

for var in 0 1 2 3 4 5 6 7 8 9
do
    xfce4-terminal -e ./lemipc
done

#./lemipc

