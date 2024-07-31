#!/bin/sh
CURRENT_DOWN=`ifconfig eth1 |grep bytes|cut -d ":" -f2|cut -d " " -f1 | grep [0-9]`
CURRENT_UP=`ifconfig eth1 |grep bytes|cut -d ":" -f3 | cut -d " " -f1 | grep [0-9]`

ONLINE=0;
OFFLINE=0;

ping -c1 www.google.com > /dev/null 2> /dev/null
if [ "$?" -eq "0" ];
then
	ONLINE=60;
else
	ping -c1 www.yahoo.com > /dev/null 2> /dev/null
	if [ "$?" -eq "0" ];
	then
		ONLINE=60;
	else
		ping -c1 www.sunet.se > /dev/null 2> /dev/null
		if [ "$?" -eq "0" ];
		then
			ONLINE=60;
		else
			OFFLINE=60;
		fi
	fi
fi

`/home/viktor/dev/cpp/stat/stat /home/viktor/dev/cpp/stat/stat.db $CURRENT_DOWN $CURRENT_UP $ONLINE $OFFLINE`
