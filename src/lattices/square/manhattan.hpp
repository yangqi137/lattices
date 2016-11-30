#ifndef LATTICES_SQUARE_MANHATTAN_HPP
#define LATTICES_SQUARE_MANHATTAN_HPP

#include "xy_dist.hpp"
#include "lattice.hpp"
#include "tag.hpp"

namespace lattices {
  namespace square {
    template <typename S>
    struct ManhattanCat {
      typedef S VSize;
      typedef LatticeTag Tag;
      typedef LatticeCat<VSize> LatticeCat;
      typedef XYDistCat<S> XYDistCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;

      VSize static max(const Lattice& lattice) {
	return XYDistCat::dx_max(lattice) + XYDistCat::dy_max(lattice);
      }
      
      static VSize manhattanDistance(const Vertex& v1, const Vertex& v2,
				     const Lattice& l) {
	auto dv = XYDistCat::distance(v1, v2, l);
	return dv.x + dv.y;
      }
      
      static VSize manhattanDistance(Vid v1, Vid v2, const Lattice& l) {
	Vertex vv1 = LatticeCat::vertex(v1, l);
	Vertex vv2 = LatticeCat::vertex(v2, l);
	return manhattanDistance(vv1, vv2, l);
      }
      
    };
  }
}

#endif
