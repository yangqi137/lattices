#ifndef LATTICES_CUBIC_EUCLIDEAN_DISTANCE_HPP
#define LATTICES_CUBIC_EUCLIDEAN_DISTANCE_HPP

#include "lattice.hpp"
#include "tag.hpp"
#include "offset.hpp"
#include <algorithm>

namespace lattices {
  namespace cubic {
    template <typename S>
    struct EuclideanDistanceCat {
      typedef S VSize;
      typedef LatticeTag Tag;
      typedef LatticeCat<VSize> LatticeCat;
      typedef OffsetCat<S> OffsetCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;
      typedef unsigned long NormType;

      static NormType norm(const Vertex& v, const Lattice& lattice) {
        NormType xabs = std::min(v.x, lattice.lx - v.x);
        NormType yabs = std::min(v.y, lattice.ly - v.y);
        NormType zabs = std::min(v.z, lattice.lz - v.z);

        return xabs*xabs + yabs*yabs + zabs*zabs;
      }
    };
  }
}

#endif
