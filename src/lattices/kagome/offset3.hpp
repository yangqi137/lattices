#ifndef LATTICES_KAGOME_OFFSET3_HPP
#define LATTICES_KAGOME_OFFSET3_HPP

#include "lattice.hpp"
#include <type_traits>

namespace lattices {
  namespace kagome {
    template <typename S>
    struct Offset3Cat {
      typedef S VSize;
      typedef LatticeCat<S> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;

      typedef typename std::make_signed<VSize>::type OffsetType;
      struct Offset3 {
	OffsetType dx;
	OffsetType dy;
	unsigned char n;
      };

      static Vertex offset3(Vertex v0, Offset3 dv,
			    const Lattice& lattice) {
	Vertex v1;
	v1.x = add_rewind(v0.x, dv.dx, lattice.lx);
	v1.y = add_rewind(v0.y, dv.dy, lattice.ly);
	v1.n = dv.n;

	return v1;
      }

      static Vid offset3(Vid v0, Offset3 dv,
			 const Lattice& lattice) {
	Vertex v1 = offset3(LatticeCat::vid(v0, lattice),
			    dv, lattice);
	return LatticeCat::vid(v1);
      }

    private:
      static Vid add_rewind(Vid x, OffsetType dx, Vid l) {
	assert(dx > -((OffsetType)l));
	if (dx < 0)
	  dx += l;
	Vid y = x + dx;
	y %= l;
	return y;
      }

    };
  }
}

#endif
