#!/bin/bash
clear
# ALL COLOURS FOR SCRIPT
orange=$'\033[0;33m'
lblue=$'\033[1;34m'
red=$'\033[0;31m'
blue=$'\033[34m'
green=$'\033[0;32m'
lgreen=$'\033[1;32m'
reset=$'\033[0m'
#HEADER

echo "${blue}                    .__                                         "${reset};
echo "${blue}______  __ __  _____|  |__        ________  _  _______  ______  "${reset};
echo "${orange}\____ \|  |  \/  ___/  |  \      /  ___/\ \/ \/ /\__  \ \____ \ "${reset};
echo "${blue}|  |_> >  |  /\___ \|   Y  \     \___ \  \     /  / __ \|  |_> >"${reset};
echo "${orange}|   __/|____//____  >___|  /____/____  >  \/\_/  (____  /   __/ "${reset};
echo "${blue}|__|              \/     \/_____/    \/               \/|__|    "${reset};
echo "${blue}            __                   __                             "${reset};
echo "${blue}          _/  |_  ____   _______/  |_  ___________              "${reset};
echo "${orange}          \   __\/ __ \ /  ___/\   __\/ __ \_  __ \             "${reset};
echo "${blue}           |  | \  ___/ \___ \  |  | \  ___/|  | \/             "${reset};
echo "${orange}           |__|  \___  >____  > |__|  \___  >__|                "${reset};
echo "${blue}                     \/     \/            \/                    "${reset};
echo ;
echo "${orange}                by @sshakya for @42Paris                      "${reset};
echo ;
echo "${orange}   run the tester with \"-D\" as an argument for debug mode       "${reset};
echo "${orange}   run your own tests as well !!								"${reset};
echo ;
echo ;
#
#  DEBUG 
#
if [[ "$1" == "-D" ]]
	then
		DEBUG=1
	else
		DEBUG=0
fi
#
# CHECK OS
#

UNAME=`uname`;
TEMP=0

if [[ "$UNAME" == "Linux" ]]
	then
		if [[ ! -f "./checker_linux" ]]
			then
				curl https://projects.intra.42.fr/uploads/document/document/8387/checker_linux -o checker_linux > /dev/null
				chmod 755 checker_linux
			else
				TEMP=1
		fi
		CHECKER=./checker_linux
	else
		if [[ ! -f "./checker_Mac" ]]
			then
				curl https://projects.intra.42.fr/uploads/document/document/8386/checker_Mac -o checker_Mac > /dev/null
				chmod 755 checker_Mac
			else
				TEMP=1
		fi
		CHECKER=./checker_Mac
fi

# CHECK FOR STACK SIZE 5

echo ;
NTESTS=20
count=1
avg=0
MAX=0
MIN=2147483647
echo "${lblue}5 stack -- running ${NTESTS} tests ${reset}"
while [ "$count" -le $NTESTS ]
do
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`;
	echo $ARG
	TOT=`./push_swap $ARG | wc -l`
	./push_swap $ARG | ./$CHECKER $ARG
	./push_swap $ARG
	if [ "$TOT" -ge "$MAX" ]
		then
			MAX=${TOT}
	fi
	if [ "$TOT" -le "$MIN" ]
		then
			MIN=${TOT}
	fi
	avg=$((avg+TOT))
	let "count += 1"
done

avg=$((avg/NTESTS))
echo -n "${blue}Average move count is : ${reset}"
echo $avg
echo "${orange} MAX =${reset} ${MAX}"
echo "${green} MIN =${reset} ${MIN}"


echo ;
