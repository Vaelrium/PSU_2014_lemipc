#! /bin/bash

(sleep 30; killall valgrind lemipc)&

xfce4-terminal -e ./lemipc

for var in {0..20}
do
    valgrind ./lemipc&
    sleep 0.1
done

ME=`whoami`

IPCS_S=`ipcs -s | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`
IPCS_M=`ipcs -m | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`

for id in $IPCS_S 
do
    ipcrm -s $id;
done

for id in $IPCS_M 
do
    ipcrm -m $id;
done

#./lemipc

