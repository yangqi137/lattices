#ifndef LATTICES_KAGOME_NEAREST_NEIGHBOR_HPP
#define LATTICES_KAGOME_NEAREST_NEIGHBOR_HPP

#include "lattice.hpp"
#include "offset_ab.hpp"
#include <type_traits>

namespace lattices { namespace kagome {
  template <typename S>
  struct NearestNeighborCat {
    typedef S VSize;
    typedef LatticeTag Tag;
    typedef LatticeCat<S> LatticeCat;
    typedef typename LatticeCat::Lattice Lattice;
    typedef typename LatticeCat::Vertex Vertex;

    typedef OffsetABCat<S> OffsetABCat;
    typedef typename OffsetABCat::Offset Offset;
    typedef std::integral_constant<unsigned char, 4> coordinationNumber;

    static Vertex neighbor(const Vertex& vo, unsigned char i,
      const Lattice& lattice) {
      static const Offset offsets[][4] = {
        {
          {}
        }
      };
    }
  }
} }

#endif