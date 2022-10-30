#ifndef LATTICES_SQUARE_NEAREST_NEIGHBOR_HPP
#define LATTICES_SQUARE_NEAREST_NEIGHBOR_HPP

#include "lattice.hpp"
#include "offset.hpp"
#include <type_traits>

namespace lattices {
  namespace square {
    template <typename S>
    struct NearestNeighborCat {
      typedef S VSize;
      typedef LatticeCat<VSize> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;

      typedef OffsetCat<VSize> OffsetCat;
      typedef typename OffsetCat::Offset Offset;

      typedef std::integral_constant<unsigned char, 4>
      coordinationNumber;

      static Vertex neighbor(const Vertex& v0, unsigned char i,
			     const Lattice& lattice) {
        static const Offset neighborOffsets[] = {
          {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
	      Vertex v1 = v0;
	      OffsetCat::shift(v1, neighborOffsets[i], lattice);
	      return v1;
      }

      static Vid neighbor(Vid v0, unsigned char i,
			  const Lattice& lattice) {
	Vertex vv0 = LatticeCat::vertex(v0, lattice);
	Vertex v1 = neighbor(vv0, i, lattice);
	return LatticeCat::vid(v1, lattice);
      }

    };
  }
}

#endif
