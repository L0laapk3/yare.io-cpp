mkdir build

"wasi-sdk/bin/clang++" ^
  -nostartfiles ^
  -fno-exceptions ^
  -Wl,--no-entry ^
  -Wl,--import-memory ^
  -Wl,--strip-all ^
  -fvisibility=hidden ^
  -Ofast ^
  --sysroot="wasi-sdk/share/wasi-sysroot" ^
  "src/*.cpp" -o "build/bot.wasm"



node "yare.io-wasm/wasm2yareio" "build/bot.wasm"