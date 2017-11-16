#ifndef LATTICES_CUBIC_JSON_IO_HPP
#define LATTICES_CUBIC_JSON_IO_HPP

#include "lattice.hpp"
#include <json.hpp>

namespace lattices {
  namespace cubic {
    template <typename S>
    void to_json(nlohmann::json& j, const Lattice<S>& lattice) {
      j["lx"] = lattice.lx;
      j["ly"] = lattice.ly;
      j["lz"] = lattice.lz;
    }

    template <typename S>
    void from_json(const nlohmann::json& j, Lattice<S>& lattice) {
      lattice.lx = j.at("lx");
      lattice.ly = j.at("ly");
      lattice.lz = j.at("lz");
    }
  }
}
#endif
