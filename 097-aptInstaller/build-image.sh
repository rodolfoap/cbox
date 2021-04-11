#!/bin/bash
cd "$(cd "$(dirname "${BASH_SOURCE[0]}")">/dev/null 2>&1&&pwd)"
. VERSION
set -eux

docker build \
	--build-arg VERSION \
	-t helloworld:${VERSION} \
	.
