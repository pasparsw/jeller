
![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/pasparsw/jeller/windows-release-build.yml?label=Windows%20release%20build) ![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/pasparsw/jeller/linux-release-build.yml?label=Linux%20release%20build) [![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

# Jeller - simple C++ logger
Table of contents:

[What is it?](#what_is_it)<br>
[How to build this project?](#how_to_build_this_project)<br>
[How to integrate with your project?](#how_to_intergate_with_your_project)<br>
&emsp;[As a submodule](#as_a_submodule)<br>
&emsp;[As a release package](#as_a_release_package)<br>
[How to use?](#how_to_use)<br>
&emsp;[Creating a logger](#creating_a_logger)<br>
&emsp;[Logging data](#logging_data)<br>
&emsp;[Setting logging level](#setting_logging_level)<br>
&emsp;[Setting custom default logging callback](#setting_custom_default_logging_callback)<br>
&emsp;[Appending multiple logging callbacks](#appending_multiple_logging_callbacks)<br>


## <a name="what_is_it"></a>What is it?

Jeller is a simple C++ logger which allows you to set up logging in your application with the least possible effort.

## <a name="how_to_build_this_project"></a>How to build this project?

The preffered way of building this project is to use build scripts placed in _scripts_ directory. To build a release version on Windows:
```
build.bat Release
```

To build a release version on Linux:
```
build.sh Release
```
To build a Debug version just omit "Release" argument (Debug build is done by default).

## <a name="how_to_intergate_with_your_project"></a>How to integrate with your project?
### <a name="as_a_submodule"></a>As a submodule

To integrate Jeller as a submodule in your project, first of all add it as a submodule to your repository:
```
git submodule add git@github.com:pasparsw/jeller.git
```
Then in CMakeLists.txt include Jeller to your build by using _add_subdirectory_ command and link it to your target. Example CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.10)
project(YourProject)

# this line is needed only for placing YourProject executable and Jeller library in the same directory without performing
# installation step - most probably you want to customize your installation process
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(jeller)
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Jeller
)
```
Now you can start using Jeller in your project. Please check the examples to learn more details about Jeller usage.

### <a name="as_a_release_package"></a>As a release package

To integrate Jeller using the release package, download the latest version from GitHub. Inside you will find two folders containing Jeller packages for Windows and for Linux, so first of all put the appropriate (Windows or Linux) folder somewhere in your project. Below you can find structures of the individual packages.
Windows:
```
jeller_win
|- Debug
   |- Jeller.dll
   |- Jeller.lib
   |- Jeller.pdb
|- include
   |- jeller
      |- *.hpp files
|- Release
   |- Jeller.dll
   |- Jeller.lib
```

Linux:
```cpp
jeller_linux
|- Debug
   |- libJeller.so
|- include
   |- jeller
      |- *.hpp files
|- Release
   |- libJeller.so
```

Assuming, that you are on Windows and the Jeller package _jeller_win_ has been placed in the root of your project, an example CMakeLists.txt file may look like this:
```cmake
cmake_minimum_required(VERSION 3.10)
project(YourProject)

# make sure that CMAKE_BUILD_TYPE variable is not empty
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(JELLER_RELEASE_PACKAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jeller_win)
set(JELLER_BINARIES_DIR ${JELLER_RELEASE_PACKAGE_DIR}/${CMAKE_BUILD_TYPE})

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${JELLER_RELEASE_PACKAGE_DIR}/include
)
target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)

find_library(JELLER_LIB NAMES Jeller HINTS ${JELLER_BINARIES_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${JELLER_LIB}
)

# install Jeller to the same directory as your application executable
install(FILES ${JELLER_BINARIES_DIR}/Jeller.dll DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
```
Now you can start using Jeller in your project. Please check the examples to learn more details about Jeller usage.

## <a name="how_to_use"></a>How to use

The idea behind Jeller is that you create a dedicated static logger object for each translation unit. In such way, each logger may have its individual name related to the e.g. class name which then may be shown in the logs. Please check the _examples_ folder for detailed sample codes.

### <a name="creating_a_logger"></a>Creating a logger
```cpp
static jeller::Logger logger("ComponentName");
```

### <a name="logging_data"></a>Logging data
There are 5 logging levels which you can use to log data:
```cpp
logger.Fatal("Example fatal error log");
logger.Error("Example error log");
logger.Warning("Example warning log");
logger.Info("Example info log");
logger.Debug("Example debug log");
logger.Verbose("Example verbose log");
```

### <a name="setting_logging_level"></a>Setting logging level
By default, logging level is set to INFO, but you can change this e.g. to DEBUG by calling a static function:
```cpp
jeller::Logger::SetLevel(jeller::LoggingLevel::kDebug);
```

### <a name="setting_custom_default_logging_callback"></a>Setting custom default logging callback
By default, logs on levels :
* VERBOSE, DEBUG, INFO and WARNING are sent to the standard output
* ERROR and FATAL are sent to the standard error
You may want to change this, so there is a method letting user to overload the default logging callback. First of all, you need to define your logging callback compliant with the signature:
```cpp
void YourLoggingCallback(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    // custom data logging code here
}
```
After this you may override the default logging callback by calling:
```cpp
jeller::Logger::SetDefaultLoggingCallback(YourLoggingCallback);
```

### <a name="appending_multiple_logging_callbacks"></a>Appending multiple logging callbacks
It may happen that you want to send logged data to more than one destination, e.g. you may want to save logs on all levels to the temporary file, but save to data base only the most important ERROR and FATAL logs. You can do this by defining your custom logging callbacks:
```cpp
void LogToFile(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    // file logging code here
}

void LogToDatabase(const std::string_view logger_name, const std::string_view logging_level, const std::string_view message)
{
    // database logging code here
}
```

And then by passing them as follows:
```cpp
jeller::Logger::AppendLoggingCallback(LogToFile);
jeller::Logger::AppendLoggingCallback(LogToDatabase);
```

Please note, that in such case the default logging callback is still active, so effectively in such case logs will be sent to three destinations: stdout/stderr, file and database.