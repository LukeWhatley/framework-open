cmake_minimum_required(VERSION 3.22)
project(neuro LANGUAGES CXX)

execute_process(
    COMMAND python3 -c "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

find_package(pybind11 REQUIRED CONFIG)

set(SOURCES_NEURO bindings/framework.cpp
                  bindings/processor_help.cpp
                  bindings/processor.cpp
                  bindings/network.cpp
                  bindings/pybind_json.hpp
				  bindings/moa.cpp
                  src/framework.cpp
                  src/properties.cpp
                  src/processor_help.cpp
			  	  include/utils/MOA.hpp
			  	  include/utils/json_helpers.hpp)

pybind11_add_module(neuro ${SOURCES_NEURO})

target_include_directories(neuro PRIVATE ./include ./bindings)

set(SOURCES_RISP bindings/risp.cpp
                 bindings/pybind_json.hpp
                 src/risp.cpp
                 src/risp_static.cpp
                 src/framework.cpp
                 src/properties.cpp
                 src/processor_help.cpp
			  	 include/utils/MOA.hpp
			 	 include/utils/json_helpers.hpp)

pybind11_add_module(risp ${SOURCES_RISP})

target_include_directories(risp PRIVATE ./include ./bindings)

install(TARGETS neuro risp LIBRARY DESTINATION .)

