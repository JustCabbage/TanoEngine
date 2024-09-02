# TanoEngine

Tano is a C++23 game engine built on top of SFML. It is currently in its early stages of development.

## Build

> To build Tano, you will need to have CMake installed on your system. If you don't have CMake installed, you can download it from the official [CMake website](https://cmake.org/download/) and follow the installation instructions for your operating system.

Once you have CMake, you can follow these steps:

1. Clone the repository: `git clone --recursive https://github.com/JustCabbage/TanoEngine.git`
2. Navigate to the project directory: `cd TanoEngine`
3. Create a build directory: `mkdir build && cd build`
4. Generate the build files: `cmake ..`
5. Build the project: `cmake --build .`

If you would like to compile the project in Debug mode, use `cmake --build . --config Debug` instead.

By default, Tano's build system should clone all its relevant dependencies for you while CMake generates the build files.

**Please ensure you have the necessary build tools installed for your system. If you are using Windows, you may need to have Visual Studio installed with the C++ workload. For Linux, make sure you have the build-essential package installed.**

> If you encounter any issues or have any questions, please feel free to [open an issue](https://github.com/JustCabbage/TanoEngine/issues).

## License

TanoEngine is currently licensed under the [MIT License](https://github.com/JustCabbage/TanoEngine/blob/master/LICENSE).

