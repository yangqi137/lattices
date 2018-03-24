#ifndef LATTICES_HYPERCUBIC_NEAREST_NEIGHBOR_HPP
#define LATTICES_HYPERCUBIC_NEAREST_NEIGHBOR_HPP

#include "lattice.hpp"
#include "offset.hpp"
#include <type_traits>

namespace lattices {
  namespace hypercubic {
    template <unsigned D, typename SIZE_TYPE>
    struct NearestNeighborCat {
      typedef SIZE_TYPE VSize;
      typedef LatticeCat<D, VSize> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;

      typedef OffsetCat<D, VSize> OffsetCat;
      typedef typename OffsetCat::Offset Offset;

      typedef std::integral_constant<unsigned char, 2*D>
      coordinationNumber;

      static Vertex neighbor(const Vertex& v0, unsigned char i, const Lattice& lattice) {
        Vertex v1 = v0;
        OffsetCat::offset_rewind(v1.x[i/2], (i%2==0)?1:-1,
          LatticeCat::length(i/2, lattice));
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
