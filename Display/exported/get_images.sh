#!/bin/bash

WORKDIR="$(readlink -f $(dirname $(readlink -f "$0")))"
IMAGEDIR="${WORKDIR}/external_images"


# doenload club logos
curl https://upload.wikimedia.org/wikipedia/commons/6/66/HSV-Logo.svg -o ${IMAGEDIR}/HSV-Logo.svg