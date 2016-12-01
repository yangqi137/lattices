#ifndef LATTICES_CUBIC_OFFSET_HPP
#define LATTICES_CUBIC_OFFSET_HPP

#include "../bravias3d/offset.hpp"
#include "tag.hpp"

namespace lattices {
  namespace cubic {
    template <typename S>
    using OffsetCat = bravias3d::OffsetCat<LatticeTag, S>;
  }
}

#endif
