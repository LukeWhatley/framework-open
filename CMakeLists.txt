cmake_minimum_required(VERSION 3.22)
project(neuro LANGUAGES CXX)

include(FetchContent)

execute_process(
    COMMAND python3 -c "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

find_package(pybind11 REQUIRED CONFIG)

set(SOURCES_FRAMEWORK src/framework.cpp
                      src/properties.cpp
                      src/processor_help.cpp
                      include/utils/MOA.hpp
                      include/utils/json_helpers.hpp)

add_library(framework STATIC ${SOURCES_FRAMEWORK})
target_include_directories(framework PUBLIC ./include ./bindings)
set_target_properties(framework PROPERTIES POSITION_INDEPENDENT_CODE ON)

set(SOURCES_NEURO bindings/framework.cpp
                  bindings/processor_help.cpp
                  bindings/processor.cpp
                  bindings/network.cpp
                  bindings/pybind_json.hpp
				  bindings/moa.cpp)

pybind11_add_module(neuro ${SOURCES_NEURO})

target_link_libraries(neuro PRIVATE framework)

set(SOURCES_RISP bindings/risp.cpp
                 bindings/pybind_json.hpp
                 src/risp.cpp
                 src/risp_static.cpp)

pybind11_add_module(risp ${SOURCES_RISP})

target_link_libraries(risp PRIVATE framework)

FetchContent_Declare(eons
    SOURCE_DIR /home/null/Documents/Research/eons
)
FetchContent_MakeAvailable(eons)

install(TARGETS neuro risp LIBRARY DESTINATION .)
