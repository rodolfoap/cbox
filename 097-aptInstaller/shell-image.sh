#!/bin/bash

cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION
set -x

docker run -ti --rm --entrypoint=/bin/bash helloworld:${VERSION}
