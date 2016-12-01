#ifndef LATTICES_CUBIC_LATTICE_HPP
#define LATTICES_CUBIC_LATTICE_HPP

#include "../bravias3d/lattice.hpp"
#include "tag.hpp"

namespace lattices {
  namespace cubic {
    template <typename S>
    using Lattice = bravias3d::Lattice<LatticeTag, S>;
    template <typename S>
    using Vertex = bravias3d::Vertex<LatticeTag, S>;
    template <typename S>
    using LatticeCat = bravias3d::LatticeCat<LatticeTag, S>;
  }
}

#endif
