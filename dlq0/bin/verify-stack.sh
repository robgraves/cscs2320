#!/bin/bash
#
# verify-stack.sh - script to validate stack functionality
#
match=0
mismatch=0
total=0

COMPONENT_LIST="mkstack:9 cpstack:11 rmstack:10 push:18 pop:19 peek:20 isempty:5"
compath="$(echo $0 | cut -d'/' -f1)/"
if [ -z "${compath}" ]; then
	compath="."
fi

echo "===================================================="
echo "=    Verifying Doubly-Linked Stack Functionality   ="
echo "===================================================="

for component in ${COMPONENT_LIST}; do

	comscript=`echo ${component} | cut -d':' -f1`
	comtotal=`echo ${component} | cut -d':' -f2`
	output=$(${compath}/verify-${comscript}.sh 2>/dev/null | grep 'Mismatches:')
	nchk=$(echo ${output} | cut -d',' -f3 | cut -d':' -f2)

	mchk=$(echo ${output} | cut -d',' -f2 | cut -d':' -f2)

	let mmtot=mchk+nchk
	if [ "${mmtot}" -lt "${comtotal}" ]; then
		let nchk=${comtotal}-mchk
	fi

	let match=match+mchk
	let mismatch=mismatch+nchk

	printf "%10s " "[${comscript}]"

	fchk=$(echo ${output} | cut -d',' -f1 | cut -d':' -f2)
	if [ "${fchk}" -eq 0 ]; then
		echo "***  NOT CURRENTLY OPERATIONAL  ***"
	else
		if [ "${fchk}" -lt "${comtotal}" ]; then
			fchk="${comtotal}"
		fi

		let total=${total}+fchk
		printf "Total: %3s, Matches: %3s, Mismatches: %3s\n" "${fchk}" "${mchk}" "${nchk}"
	fi

done

echo   "===================================================="
printf " [RESULTS] Total: %3s, Matches: %3s, Mismatches: %3s\n" "${total}" "${match}" "${mismatch}"
echo   "===================================================="
exit 0
