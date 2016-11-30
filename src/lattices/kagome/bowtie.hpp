#ifndef LATTICES_KAGOME_BOWTIE_HPP
#define LATTICES_KAGOME_BOWTIE_HPP

#include "lattice.hpp"
#include "offset3.hpp"

namespace lattices {
  namespace kagome {
    template <typename S>
    struct BowtieCat {
      typedef LatticeCat<S> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;

      typedef Offset3Cat<S> Offset3Cat;
      typedef typename Offset3Cat::Offset3 Offset3;

      static void bowtie(Vertex v0, Vertex bt[4],
			 const Lattice& lattice) {
	static Offset3 offsets[3][4] = {
	  {{0, 0, 1}, {0, -1, 1}, {1, 0, 2}, {0, -1, 2}},
	  {{0, 0, 2}, {1, 0, 2}, {0, 1, 0}, {0, 0, 0}},
	  {{-1, 0, 0}, {0, 1, 0}, {-1, 0, 1}, {0, 0, 1}}
	};

	for (int i=0; i<4; i++)
	  bt[i] = Offset3Cat::offset3(v0, offsets[v0.n][i], lattice);
      }

      static void bowtie(Vid v0, Vid bt[4], const Lattice& lattice) {
	Vertex vv0 = LatticeCat::vertex(v0, lattice), vbt[4];
	bowtie(vv0, vbt, lattice);
	for (int i=0; i<4; i++)
	  bt[i] = LatticeCat::vid(vbt[i], lattice);
      }
    };
  }
}

#endif
