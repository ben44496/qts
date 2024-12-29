cmake_minimum_required(VERSION 3.25)

# Set the project name
project(QTS)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the fmt library
find_package(fmt REQUIRED)

# Find the Boost library
find_package(Boost REQUIRED)

# Find the UUID library
find_package(libuuid REQUIRED)

# Add the eventpp library
find_package(eventpp CONFIG REQUIRED)

# Add spdlog
find_package(spdlog REQUIRED)

# Add the executable
add_executable(QTS_exe src/main.cpp)

# Link libraries
target_link_libraries(QTS_exe PRIVATE fmt::fmt Boost::boost spdlog::spdlog)
# Add the library for header files
add_library(qtslib SHARED src/order_types.cpp src/strategy.cpp src/order_management_system.cpp)

# Specify the include directories for the header files
target_include_directories(qtslib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(QTS_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link the header library with the executable
target_link_libraries(qtslib PRIVATE fmt::fmt Boost::boost libuuid::libuuid eventpp::eventpp spdlog::spdlog)

target_link_libraries(QTS_exe PRIVATE qtslib)