#ifndef LATTICES_SQUARE_BOND_MAP_HPP
#define LATTICES_SQUARE_BOND_MAP_HPP

#include "lattice.hpp"
#include "nearest_neighbor.hpp"
#include "../nonbravias/lattice.hpp"
#include <type_traits>

namespace lattices {
  namespace square {
		struct SquareNNBondLatticeTag {};
    template <typename S>
    struct BondMapCat {
      typedef LatticeCat<S> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;
			
      typedef nonbravias::LatticeCat<SquareNNBondLatticeTag, S, 2> BondLatticeCat;
      
			typedef typename BondLatticeCat::Lattice BondLattice;
      typedef typename BondLatticeCat::Vertex BondVertex;

      typedef NearestNeighborCat<S> NeighborCat;
      typedef typename NeighborCat::coordinationNumber
      coordinationNumber;

      static BondLattice bondLattice(const Lattice& lattice) {
				BondLattice bl;
				bl.lx = lattice.lx; bl.ly=lattice.ly;
				return bl;
      }

      static BondVertex bond(Vertex v, unsigned char i,
			     const Lattice& lattice) {
				assert(i < coordinationNumber::value);
				static const short offsets[][3] = {
	  			{0, 0, 0}, {0, 0, 1},
	  			{-1, 0, 0}, {0, -1, 1}
				};
				BondVertex vb;
				vb.x = add_rewind(v.x, offsets[i][0], lattice.lx);
				vb.y = add_rewind(v.y, offsets[i][1], lattice.ly);
				vb.n = offsets[i][2];
				return vb;
      }

      static Vid bond(Vid v, unsigned char i, 
		      const Lattice& lattice) {
				Vertex vv = LatticeCat::vertex(v, lattice);
				BondVertex bv = bond(vv, i, lattice);
				return BondLatticeCat::vid(bv, bondLattice(lattice));
      }

    private:
      static Vid add_rewind(Vid x, 
			     typename std::make_signed<Vid>::type dx,
			     Vid l) {
				assert(dx > -((typename std::make_signed<Vid>::type)l));
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
