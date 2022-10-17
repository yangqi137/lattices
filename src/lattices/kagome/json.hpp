#ifndef LATTICES_KAGOME_JSON_IO_HPP
#define LATTICES_KAGOME_JSON_IO_HPP

#include "lattice.hpp"
#include "offset_ab.hpp"
#include <nlohmann/json.hpp>

namespace lattices {
  namespace kagome {
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

    template <typename S>
    void to_json(nlohmann::json& j, const OffsetAB<S>& o) {
      j["dx"] = o.dx;
      j["dy"] = o.dy;
      j["a"] = o.a;
      j["b"] = o.b;
    }

    template <typename S>
    void from_json(const nlohmann::json& j, const OffsetAB<S>& o) {
      j.at("dx").get_to(o.dx);
      j.at("dy").get_to(o.dy);
      j.at("a").get_to(o.a);
      j.at("b").get_to(o.b);
    }

  }
}


#endif
