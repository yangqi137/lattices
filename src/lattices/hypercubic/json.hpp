#ifndef LATTICES_HYPERCUBIC_JSON_IO_HPP
#define LATTICES_HYPERCUBIC_JSON_IO_HPP

#include "lattice.hpp"
#include <nlohmann/json.hpp>

namespace lattices {
  namespace hypercubic {
    template <unsigned D, typename S>
    void to_json(nlohmann::json& j, const Lattice<D, S>& lattice) {
      for (unsigned i = 0; i < D; i++)
        j[i] = LatticeCat<D, S>::length(i, lattice);
    }

    template <unsigned D, typename S>
    void from_json(const nlohmann::json& j, Lattice<D, S>& lattice) {
      lattice = LatticeCat<D, S>::createLattice(j.begin(), j.end());
    }
  }
}
#endif
