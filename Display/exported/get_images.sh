#!/bin/bash

WORKDIR="$(readlink -f $(dirname $(readlink -f "$0")))"
IMAGEDIR="${WORKDIR}/external_images"


# download flags
curl https://upload.wikimedia.org/wikipedia/en/a/a4/Flag_of_the_United_States.svg -o ${IMAGEDIR}/flag_USA.svg

# download club logos
curl https://upload.wikimedia.org/wikipedia/commons/6/66/HSV-Logo.svg -o ${IMAGEDIR}/HSV-Logo.svg