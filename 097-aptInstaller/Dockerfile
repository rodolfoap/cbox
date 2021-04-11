#
# BUILD stage ----------------------------------------------------------------------------------
#
FROM debian:10.9-slim as builder

RUN export DEBIAN_FRONTEND=noninteractive
RUN apt update && apt -y install build-essential cmake doxygen
ADD https://dl.bintray.com/conan/installers/conan-ubuntu-64_1_35_0.deb /tmp
RUN dpkg -i /tmp/conan-ubuntu-64_1_35_0.deb
RUN conan profile new default --detect
RUN conan profile update settings.compiler.libcxx=libstdc++11 default
RUN conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
RUN conan remote add conan https://api.bintray.com/conan/conan/conan-center

# Actual build
COPY . /app/
RUN /app/build-app.sh

#
# TARGET stage ----------------------------------------------------------------------------------
#
FROM debian:10.9-slim
MAINTAINER RodolfoAP <rodolfoap@gmail.com>
CMD /usr/bin/helloworld

# Actual install
COPY --from=builder /app/build/helloworld-*-linux.deb /tmp
RUN dpkg -i /tmp/helloworld-*-linux.deb
RUN rm -f   /tmp/helloworld-*-linux.deb
