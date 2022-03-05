#!/bin/bash

#!/bin/bash

usage() {
   cat << EOF

usage: ${1} - Converts TI Cartridge to .h file for use in Classic99v4

EOF
}

[ "${1}" == "" ] && {
    usage
    exit 1
}

[ ! -f "${1}" ] && {
    printf "Missing File: %s\n" "${1}"
    usage
    exit 2
}

GROM=${1}
NAME="$(echo ${GROM}|cut -f 1 -d '.')"

DATA=$(hexdump -v "${GROM}" | awk '{print "  0x"$2", 0x"$3", 0x"$4", 0x"$5", 0x"$6", 0x"$7", 0x"$8", 0x"$9", 0x"$10", 0x"$11", 0x"$12", 0x"$13", 0x"$14", 0x"$15", 0x"$16", 0x"$17","}'|grep -v "0x,"| sed '$s/,$/\n};/')

printf "#include <stdint.h>\n\nconst uint8_t %s[] = {\n" "${NAME}"
printf "%s\n" "${DATA}"
