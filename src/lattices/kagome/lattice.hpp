#ifndef LATTICES_KAGOME_LATTICE_HPP
#define LATTICES_KAGOME_LATTICE_HPP

#include "../nonbravias/lattice.hpp"
#include "tag.hpp"

namespace lattices {
  namespace kagome {
    template <typename S>
    using  Lattice = nonbravias::Lattice<LatticeTag, S>;
    template <typename S>
    using  Vertex = nonbravias::Vertex<LatticeTag, S>;
    template <typename S>
    using  LatticeCat = nonbravias::LatticeCat<LatticeTag, S, 3>;
  }
}

#endif
