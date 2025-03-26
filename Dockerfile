# Use an official Ubuntu as a base image
FROM gcc:latest
# Install dependencies: build-essential for g++ and cmake
RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake

# Set working directory inside the container
WORKDIR /workspace

# Copy the local code to the container
COPY . /workspace

# Set the default C++ standard to C++11
ENV CXXFLAGS="-std=c++11"

# Define the default command (you can override this during the container run)
CMD ["bash"]