#!/bin/bash

cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION
sed -i '/image:.*helloworld:/s/:[0-9.]*$/:'${VERSION}'/' docker-compose.yaml
docker-compose up
