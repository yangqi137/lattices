#ifndef LATTICES_TRIANGULAR_OFFSET_HPP
#define LATTICES_TRIANGULAR_OFFSET_HPP

#include "../bravias/offset.hpp"
#include "tag.hpp"

namespace lattices {
  namespace triangular {
    template <typename S>
    using OffsetCat = bravias::OffsetCat<LatticeTag, S>;
  }
}

#endif
