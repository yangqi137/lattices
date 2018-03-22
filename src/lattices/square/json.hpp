#ifndef LATTICES_SQUARE_JSON_IO_HPP
#define LATTICES_SQUARE_JSON_IO_HPP

#include "lattice.hpp"
#include <nlohmann/json.hpp>

namespace lattices {
  namespace square {
    template <typename S>
    void to_json(nlohmann::json& j, const Lattice<S>& lattice) {
      j["lx"] = lattice.lx;
      j["ly"] = lattice.ly;
    }

    template <typename S>
    void from_json(const nlohmann::json& j, Lattice<S>& lattice) {
      lattice.lx = j["lx"];
      lattice.ly = j["ly"];
    }
  }
}
#endif
