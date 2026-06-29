#include "framework.hpp"
#include "drisp.hpp"

neuro::Processor *neuro::Processor::make(const string &name, json &params)
{
  string es;

  if (name != "drisp") {
    es = (string) "Processor::make() called with a name ("
       + name
       + (string) ") not equal to drisp";
    throw std::runtime_error(es);
  }

  return new drisp::Processor(params);
}
