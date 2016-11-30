#ifndef LATTICES_KAGOME_LATTICE_HPP
#define LATTICES_KAGOME_LATTICE_HPP

#include "../nonbravias/lattice.hpp"
#include "tag.hpp"

namespace lattices {
  namespace kagome {
    template <typename S>
    using nonbravias::Lattice<LatticeTag, S> Lattice;
    template <typename S>
    using nonbravias::Vertex<LatticeTag, S> Vertex;
    template <typename S>
    using nonbravias::LatticeCat<LatticeTag, S, 3> LatticeCat;
  }
}

#endif
