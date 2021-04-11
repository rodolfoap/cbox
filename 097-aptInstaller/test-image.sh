#!/bin/bash

cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION

set -x
docker run -ti --rm helloworld:${VERSION} dpkg -L helloworld		|sed 's/^/\t/'|sed '/helloworld\/html/q'
docker run -ti --rm helloworld:${VERSION} apt-cache show helloworld	|sed 's/^/\t/'
docker run -ti --rm helloworld:${VERSION} helloworld			|sed 's/^/\t/'
docker run -ti --rm helloworld:${VERSION} man helloworld		|sed 's/^/\t/'
