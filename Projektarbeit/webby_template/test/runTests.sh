#!/bin/bash
# ---------------------------------------------
#
# execute some simple tests against a webserver
# 01/2024 Helmut Lindner
#
# ---------------------------------------------
TESTCASE_FILE="tests.dat"
ANSI_RED="\u001B[31m"
ANSI_GREEN="\u001B[32m"
ANSI_RESET="\u001B[0m"

test_number=0
tests_successful=0
tests_failed=0
debug=0;

# ---------------------------------------------
#
# do_test()
# execute a test  that returns a simple string
# Parameters:
#   $1 ... Method (GET, POST)
#   $2 ... Url to test
#   $3 ... expected result (regex)
#   $4 ... POST parameters
#
# ---------------------------------------------
do_test() {
  echo "------------------------------"
  ((test_number++))
  if [[ ${1} == "G" ]]; then
    res=$(curl -s --get "${2}" | tr -d '\0')
  else
    res=$(curl -s -X POST -H "Content-Type: text/plain" -d "${4}" "${2}" | tr -d '\0')
  fi
  # if debug is set, print url, expected and response, limited to 80 chars
  if [[ $debug -eq 1 ]]; then
    echo -e "Debug -Test ${test_number}- \n\tUrl: ${2}\n\tExpected: ---${3}---\n\tResponse: ---${res:0:79}---" 
  fi
  result=$(echo "${res}" | grep "${3}")
  if [[ "${result}" =~ "${3}" ]]; then
    echo -e "Test ${test_number} ${2} ${ANSI_GREEN}successful${ANSI_RESET}"
    ((tests_successful++))
    return 0
  else
    echo -e "Test ${test_number} ${2} ${ANSI_RED}failed${ANSI_RESET}"
    ((tests_failed++))
    return 1
  fi
}

if [ "$1" == "-d" ]; then
  debug=1
fi

oldIFS=$IFS
IFS=$'\n'
for line in $(cat "${TESTCASE_FILE}"); do
  if [[ "${line}" =~ "#"+ ]]; then
    continue;
  fi
  meth=$(echo ${line} | cut -d'$' -f1)
  url=$(echo ${line} | cut -d'$' -f2)
  pat=$(echo ${line} | cut -d'$' -f3)
  body=$(echo ${line} | cut -d'$' -f4)
  do_test ${meth} "${url}" "${pat}" "${body}"
done
IFS=$oldIFS

echo -e "=============================================================="
echo -e "Test Summary\n\t${test_number} tests executed."
echo -e "\t${ANSI_GREEN}${tests_successful} successful tests.${ANSI_RESET}"
if [[ $tests_failed -gt 1 ]]; then
  echo -e "\t${ANSI_RED}${tests_failed} test(s) failed.${ANSI_RESET}"
fi
echo -e "=============================================================="

exit 0
