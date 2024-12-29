ARG BASE_IMAGE=ubuntu:24.04

FROM ${BASE_IMAGE} AS dev
ARG PROJECT_NAME="qts"
# Mount the project directory
WORKDIR /qts

# C++ build clang and conan
RUN apt-get update && apt-get install -y clang cmake make g++ git

# Install python3 and create venv
RUN apt-get install -y python3 python3-pip python3-venv
# RUN python3 -m venv venv
# ENV PATH="/qts/venv/bin:$PATH"

# Install conan
RUN pip install conan --break-system-packages


# FROM dev AS builder
# ARG PROJECT_NAME="qts"
# # Build
# RUN mkdir build
# WORKDIR /qts/build
# RUN conan install ..
# RUN cmake ..
# RUN make

# FROM ${BASE_IMAGE} AS final
# ARG PROJECT_NAME="qts"
# # Copy the binary from the build stage
# COPY --from=dev /qts/build/main /main
# COPY --from=dev /qts/venv /qtsroject/venv

# # Run C++ main
# CMD ["./main"]
