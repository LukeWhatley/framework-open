#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_json.hpp"
#include "framework.hpp"
#include "nlohmann/json.hpp"

#include "drisp.hpp" 

namespace py = pybind11;

PYBIND11_MODULE(drisp, m) {
  m.doc() = "drisp";
  py::module::import("neuro");

  py::class_<drisp::Processor, neuro::Processor>(m, "Processor", py::multiple_inheritance())
    .def(py::init<nlohmann::json&>());
}
