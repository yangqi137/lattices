#ifndef LATTICES_KAGOME_NEAREST_NEIGHBOR_HPP
#define LATTICES_KAGOME_NEAREST_NEIGHBOR_HPP

#include "lattice.hpp"
#include "offset_ab.hpp"
#include <type_traits>
#include <cassert>

namespace lattices { namespace kagome {
  template <typename S>
  struct NearestNeighborCat {
    typedef S VSize;
    typedef LatticeTag Tag;
    typedef LatticeCat<S> LatticeCat;
    typedef typename LatticeCat::Lattice Lattice;
    typedef typename LatticeCat::Vertex Vertex;
    typedef typename LatticeCat::Vid Vid;

    typedef OffsetABCat<S> OffsetCat;
    typedef typename OffsetCat::Offset Offset;
    typedef std::integral_constant<unsigned char, 4> coordinationNumber;

    static Vertex neighbor(const Vertex& v0, unsigned char i,
      const Lattice& lattice) {
      static const Offset offsets[][4] = {
        { {1, 0, 0, 2}, {0, 0, 0, 1}, {0, -1, 0, 1}, {0, -1, 0, 2} },
        { {0, 1, 1, 0}, {0, 0, 1, 2}, {1, 0, 1, 2}, {0, 0, 1, 0} },
        { {-1, 0, 2, 1}, {-1, 0, 2, 0}, {0, 1, 2, 0}, {0, 0, 2, 1} }
      };
      Vertex v1 = v0;
      assert(i < coordinationNumber::value);
      bool rtn = OffsetCat::try_shift(v1, offsets[v0.n][i], lattice);
      assert(rtn);
      return v1;
    }

    static Vid neighbor(Vid v0, unsigned char i, const Lattice& lattice) {
      Vertex vv0 = LatticeCat::vertex(v0, lattice);
      Vertex v1 = neighbor(vv0, i, lattice);
      return LatticeCat::vid(v1, lattice);
    }
  };
} }

#endif