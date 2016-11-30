#ifndef LATTICES_SQUARE_LATTICE_HPP
#define LATTICES_SQUARE_LATTICE_HPP

#include "../bravias/lattice.hpp"
#include "tag.hpp"

namespace lattices {
  namespace square {
    template <typename S>
    using Lattice = bravias::Lattice<LatticeTag, S>;
    template <typename S>
    using Vertex = bravias::Vertex<LatticeTag, S>;
    template <typename S>
    using LatticeCat = bravias::LatticeCat<LatticeTag, S>;
  }
}

#endif
