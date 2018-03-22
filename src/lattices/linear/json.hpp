#ifndef LATTICES_LINEAR_JSON_IO_HPP
#define LATTICES_LINEAR_JSON_IO_HPP

#include "lattice.hpp"
#include <nlohmann/json.hpp>

namespace lattices {
  namespace linear {
    template <typename S>
    void to_json(nlohmann::json& j, const Lattice<S>& lattice) {
      j["l"] = lattice.l;
    }

    template <typename S>
    void from_json(const nlohmann::json& j, Lattice<S>& lattice) {
      lattice.l = j["l"];
    }
  }
}
#endif
