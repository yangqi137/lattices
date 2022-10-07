#ifndef LATTICES_TRIANGULAR_JSON_IO_HPP
#define LATTICES_TRIANGULAR_JSON_IO_HPP

#include "lattice.hpp"
#include <nlohmann/json.hpp>

namespace lattices {
  namespace triangular {
    template <typename S>
    void to_json(nlohmann::json& j, const Lattice<S>& lattice) {
      j["lx"] = lattice.lx;
      j["ly"] = lattice.ly;
    }

    template <typename S>
    void from_json(const nlohmann::json& j, Lattice<S>& lattice) {
      j.at("lx").get_to(lattice.lx);
      j.at("ly").get_to(lattice.ly);
    }
  }
}
#endif
