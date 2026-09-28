git clone --recursive https://github.com/onnx/onnx.git
cd onnx
mkdir build
cd build

cmake .. \
  -DONNX_BUILD_TESTS=OFF \
  -DONNX_BUILD_BENCHMARKS=OFF \
  -DONNX_USE_PROTOBUF_SHARED_LIBS=ON \
  -DCMAKE_BUILD_TYPE=Release

cmake --build . -j$(nproc)