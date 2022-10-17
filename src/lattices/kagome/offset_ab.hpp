#ifndef LATTICES_KAGOME_OFFSET_AB_HPP
#define LATTICES_KAGOME_OFFSET_AB_HPP

#include "../nonbravias/offset_ab.hpp"
#include "tag.hpp"

namespace lattices {
  namespace kagome {
    template <typename S>
    using  OffsetABCat = nonbravias::OffsetABCat<LatticeTag, S, 3>;
    template <typename S>
    using OffsetAB = nonbravias::OffsetAB<LatticeTag, S>;
  }
}

#endif