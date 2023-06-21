
# Fractions

## Table of Contents
  - [Description](#description)
    - [Example](#example)
    - [Notes](#notes)
  - [Installation](#installation)
    - [Download Executables](#download-executables)
    - [Building the Console Application](#building-the-console-application)
    - [Building the Android Application](#building-the-android-application)
  - [Using the Core Library in Your Projects](#using-the-core-library-in-your-projects)
  - [Documentation](#documentation)
  - [Screenshots](#screenshots)

## Description
Fractions is an application that takes operations on fractions as input and produces a fractional result. 

### Example
Example usage (where '?' represents the command prompt):

? 1/2 * 3&3/4  
= 1&7/8

### Notes
- Supported operators are `*`, `/`, `+`, `-` (multiply, divide, add, subtract).
- Operands and operators must be separated by one or more spaces.
- Mixed numbers should be represented in the form `whole&numerator/denominator`. For example, "3&1/4", "-1&7/8".
- Improper fractions, whole numbers, and negative numbers are allowed as operands.

## Installation

### Download Executables
If you don't want to compile the application yourself, you can download the latest release. The release includes a Console Application, an Android Application, and the core library built for Windows and Android.  
You can download the latest release of the project [here](https://github.com/bodaiboka/fractions/releases/latest).

- The Console Application can be launched by double-clicking on it or typing its name in a terminal.
- To install the Android Application, copy the `.apk` file to your device and install it by tapping on it. Note: You might need to enable installation from unknown sources in your settings.

### Building the Console Application
To build the Console Application, follow these steps:
1. Install `cmake`.
2. Add `cmake` to the PATH environment variable.
3. Install `MinGW`.
4. Add `MinGW` to the PATH environment variable.
5. Build the fractions library located in the `libFractional` directory by running the `build_windows_release.bat` script. It will create the required static library for the Console Application.
6. Build the Console Application in the `app/windows` directory by running the `build.bat` batch file.
7. After successful compilation, the executable should appear in the `app/windows` directory as `app.exe`.  

__Note:__ As an alternative, if you don't intend to modify the library code, you can download the latest release and copy `libfractional.a` into the `app/windows` directory. Then compile the Console Application. Make sure to update the library path in the build.bat file before compiling the Console Application.

### Building the Android Application
To build the Android Application, follow these steps:
1. Install Android NDK.
2. Create an environment variable named `ANDROID_NDK`, and set its value to the path of the Android NDK.
3. Install `cmake`.
4. Add `cmake` to the PATH environment variable.
5. Install `MinGW`.
6. Add `MinGW` to the PATH environment variable.
7. Build the fractions library located in the `libFractional` directory by running the `build_android_release.bat` script. This will create the required shared library and copy it into the Android project.
8. Open the Android Project located in `app/android` with Android Studio and build the application.

__Note:__ Alternatively, if you don't plan to modify the library code, you can simply download the latest release, and copy the `jniLibs` directory into `app/android/app/src/main`. Then, compile the Android Application using Android Studio.

## Using the core library in Your Projects
If you wish to incorporate the core library into your own projects, first build the library for either Windows or Android by utilizing the appropriate script file within the libFractional directory.

The core functionality of this library can be accessed through the std::string produce_fractional_result(std::string input) function. This function accepts an input string consisting of a fractional expression and returns the resultant fraction as a string.

### Note for Android Projects
When integrating the core library into an Android project, a custom JNI (Java Native Interface) wrapper will be required. Ensure that the JNI wrapper is tailored to suit your package name and the specific class where the library is loaded. This is essential for establishing the connection between the Java code and the native library functions.

## Documentation

The `docs` directory contains supplementary documentation and resources for the project.
- Flowchart: A flowchart depicting the structure and flow of the Console Application is available as an HTML file named `flowchart.html`. You can also view the flowchart online by clicking [here](https://bodaiboka.github.io/fractions/flowchart.html).
- Screenshots: Screenshots showcasing the Android Application can be found in the `docs/android/screenshots` directory. These images provide visual insight into the features and interface of the app.

## Screenshots
<p align="center">
<img src="./docs/android/screenshots/enter_expression_1.png" alt="Screenshot of the app" height="500"/>
<img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsQAAA7EAZUrDhsAAAANSURBVBhXYzh8+PB/AAffA0nNPuCLAAAAAElFTkSuQmCC" width="40"/>
<img src="./docs/android/screenshots/enter_expression_2.png" alt="Screenshot of the app" height="500"/>
<img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsQAAA7EAZUrDhsAAAANSURBVBhXYzh8+PB/AAffA0nNPuCLAAAAAElFTkSuQmCC" width="40"/>
<img src="./docs/android/screenshots/enter_expression_3.png" alt="Screenshot of the app" height="500"/>
</p>


