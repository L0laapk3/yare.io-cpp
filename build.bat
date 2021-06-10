mkdir build

"wasi-sdk/bin/clang++" ^
  -nostartfiles ^
  -fno-exceptions ^
  -Wl,--no-entry ^
  -Wl,--strip-all ^
  -Wl,--export-dynamic ^
  -fvisibility=hidden ^
  -O3 ^
  --sysroot="wasi-sdk/share/wasi-sysroot" ^
  "src/main.cpp" -o "build/bot.wasm"


  
@REM   -Wl,--import-memory ^


node "yare.io-wasm/wasm" "build/bot.wasm"