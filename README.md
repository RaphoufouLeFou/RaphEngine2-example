# RaphEngine2-example
RaphEngine2 example project

# How to build

## Linux

TODO

## Windows

To build the project, you need to execute these commands in the root directory.
```bash
cmake -B build -G "Visual Studio 17 2022" -DCMAKE_PREFIX_PATH="path/to/librairy"
cmake --build build --config Release
```
DO NOT FORGET TO REPLACE `path/to/librairy` by a path of the RaphEngine library.
By default, it should be `C:/RaphEngine2Install`.
You can aso omit this argument, but will need root privilege to build the engine.

For debug build, replace `--config Release` by `--config Debug` in your project, AND in the RaphEngine build.

To run your project, type `build\Release\RaphEngine2_example.exe`. (replace the `Release` part with `Debug` when building in debug mode).

If you move the executable in an other place, don't forget to also move the `RaphEngine2.dll` file.
