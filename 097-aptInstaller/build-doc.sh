#!/bin/bash
set -x

cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION
doxygen doc/Doxyfile &> doc.$(date +%s).log
