#!/bin/bash
cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION
set -eux

doxygen doc/Doxyfile &> doc.$(date +%s).log
