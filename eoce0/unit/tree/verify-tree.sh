#!/bin/bash
#
# verify-tree.sh - script to validate tree functionality
#
match=0
mismatch=0
total=0

#COMPONENT_LIST="mktree:7 addnode:36 searchtree:25 traverse:48 grabnode:0 cptree:0 rmtree:0"
COMPONENT_LIST="mktree:7 addnode:36 searchtree:25 traverse:44 cptree:12 rmtree:6 grabnode:12"
compath="$(echo $0 | cut -d'/' -f1)/"
if [ -z "${compath}" ]; then
	compath="."
fi

echo "======================================================"
echo "=     Verifying Doubly-Linked Tree Functionality     ="
echo "======================================================"

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

	printf "%12s " "[${comscript}]"

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

echo "======================================================"
printf "[RESULTS]    Total: %3s, Matches: %3s, Mismatches: %3s\n" "${total}" "${match}" "${mismatch}"
echo "======================================================"
exit 0
