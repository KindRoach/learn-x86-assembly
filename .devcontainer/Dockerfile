FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    ninja-build \
    nasm

# install vtune
WORKDIR /vtune
RUN apt-get update && apt-get install -y wget
RUN wget https://registrationcenter-download.intel.com/akdlm/IRC_NAS/15ddff8e-7875-4973-9120-fa2e18759fba/intel-vtune-2025.8.0.9_offline.sh
RUN bash intel-vtune-2025.8.0.9_offline.sh -a -s --eula accept

# setup metrics-discovery for vtune
RUN apt-get update && apt-get install -y libdrm-dev cmake build-essential git
WORKDIR /metrics-discovery
RUN git clone https://github.com/intel/metrics-discovery.git .
RUN cmake -S . -B build && cmake --build build -j && cmake --install build
