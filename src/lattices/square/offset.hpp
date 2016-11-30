#ifndef LATTICES_SQUARE_OFFSET_HPP
#define LATTICES_SQUARE_OFFSET_HPP

#include "../bravias/offset.hpp"
#include "tag.hpp"

namespace lattices {
  namespace square {
    template <typename S>
    using OffsetCat = bravias::OffsetCat<LatticeTag, S>;
  }
}

#endif
