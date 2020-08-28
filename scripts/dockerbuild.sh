#!/bin/bash

docker run -it --rm -u $(id -u ${USER}):$(id -g ${USER}) -v $(pwd):/chos -w /chos richardchien/chcore_virt_dev:v1.0 bash -- ./scripts/build.sh
