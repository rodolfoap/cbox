#
# BUILD stage ----------------------------------------------------------------------------------
#
FROM debian:10.9-slim as builder

RUN DEBIAN_FRONTEND=noninteractive apt update
RUN DEBIAN_FRONTEND=noninteractive apt -y install build-essential cmake
#RUN python3 -m pip install conan
#RUN conan profile new default --detect
#RUN conan profile update settings.compiler.libcxx=libstdc++11 default
#RUN conan remote add gtd https://git.gtd-international.com/api/v4/packages/conan
#RUN conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
#RUN conan remote add conan https://api.bintray.com/conan/conan/conan-center

# Actual build
#ARG CI_JOB_TOKEN
#RUN CONAN_PASSWORD="${CI_JOB_TOKEN}" conan user ci_user -r gtd -p
COPY . /app/
RUN /app/build-app.sh

#
# TARGET stage ----------------------------------------------------------------------------------
#
#FROM ubuntu:20.04
#MAINTAINER RodolfoAP <rodolfo.alcazar@gtd.eu>
#CMD /usr/bin/test_sendreceive

# Actual install
#COPY --from=builder /app/build/meia_sendreceive-*-linux.deb /tmp/
#RUN dpkg -i /tmp/meia_sendreceive-*-linux.deb
#RUN rm -f   /tmp/meia_sendreceive-*-linux.deb

