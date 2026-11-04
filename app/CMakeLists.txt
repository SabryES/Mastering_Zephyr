cmake_minimum_required(VERSION 3.20.0)

# Find the Zephyr package using the environment variable
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(zephyr_course_app)

# Add your source files (using main.cpp since you created a C++ file earlier)
target_sources(app PRIVATE src/main.cpp)
