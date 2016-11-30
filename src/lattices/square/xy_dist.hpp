#ifndef LATTICES_SQUARE_XY_DISTANCE_HPP
#define LATTICES_SQUARE_XY_DISTANCE_HPP

#include "lattice.hpp"
#include "tag.hpp"
#include <algorithm>

namespace lattices {
  namespace square {
    template <typename S>
    struct XYDistCat {
      typedef S VSize;
      typedef LatticeTag Tag;
      typedef LatticeCat<VSize> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;
      typedef Vertex XYDistance;

      VSize static dx_max(const Lattice& lattice) 
      { return lattice.lx/2 + 1; }
      VSize static dy_max(const Lattice& lattice) 
      { return lattice.ly/2 + 1; }

      XYDistance static distance(const Vertex& v0, const Vertex& v1,
				 const Lattice& lattice) {
	Vertex dv;
	VSize dx = abs_diff(v0.x, v1.x);
	dv.x = std::min(dx, lattice.lx - dx);
	
	VSize dy = abs_diff(v0.y, v1.y);
	dv.y = std::min(dy, lattice.ly - dy);

	return dv;
      }

      XYDistance static distance(Vid v0, Vid v1, const Lattice& lattice) {
	return distance(LatticeCat::vertex(v0, lattice), 
			LatticeCat::vertex(v1, lattice), lattice);
      }

    private:
      static Vid abs_diff(Vid v1, Vid v2) {
	if (v1 < v2)
	  return v2 - v1;
	else
	  return v1 - v2;
      }
      
    };
  }
}
#endif
