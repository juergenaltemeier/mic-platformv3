# mic-renamer-hub

This is a modular Qt Quick application for renaming images.

## Installation

### macOS (with Homebrew)

1.  **Install Prerequisites:**
    ```bash
    brew install qt@6 cmake
    ```

2.  **Set Environment Variables:**
    Add the following lines to your shell profile (e.g., `~/.zshrc` or `~/.bash_profile`) to make Qt available to CMake.
    ```bash
    export PATH="/opt/homebrew/opt/qt@6/bin:$PATH"
    export LDFLAGS="-L/opt/homebrew/opt/qt@6/lib"
    export CPPFLAGS="-I/opt/homebrew/opt/qt@6/include"
    ```
    Remember to source your profile (`source ~/.zshrc`) or open a new terminal for the changes to take effect.

### Windows

1.  **Install Prerequisites:**
    -   **CMake:** Download and install from the [official CMake website](https://cmake.org/download/).
    -   **Qt 6:** Download the [Qt Online Installer](https://www.qt.io/download-qt-installer) from the Qt website. During installation, select a `MinGW` kit and `CMake` from the developer tools. brew install qt@6
    -   **Compiler:** Ensure you have a C++ compiler. The `Build Tools for Visual Studio` or the `MinGW` compiler (which can be installed with Qt) are good options.

2.  **Set Environment Variables:**
    Add the paths to your Qt `bin` directory (e.g., `C:\Qt\6.x.x\mingw_64\bin`) and CMake `bin` directory to your system's `PATH` environment variable.

## Build Instructions

1.  **Create a build directory:**
    ```bash
    mkdir build
    cd build
    ```

2.  **Configure the project with CMake:**
    ```bash
    cmake ..
    ```
    *Note: On Windows, you might need to specify the generator, e.g., `cmake .. -G "MinGW Makefiles"`.*

3.  **Build the project:**
    ```bash
    cmake --build .
    ```

## Running the Application

After a successful build, you can run the application from the `build` directory:

-   **Linux/macOS:**
    ```bash
    ./mic-renamer-hub
    ```
-   **Windows:**
    ```bash
    mic-renamer-hub.exe
    ```

## Project Structure

-   `src/`: C++ source code, including modules.
-   `qml/`: QML source code for the user interface.
-   `CMakeLists.txt`: Main project build configuration.