#ifndef LATTICES_LINEAR_OFFSET_HPP
#define LATTICES_LINEAR_OFFSET_HPP

#include "lattice.hpp"

#include <type_traits>
#include <cassert>
#include <algorithm>

namespace lattices {
  namespace linear {
    template <typename SIZE_TYPE>
    struct OffsetCat {
      typedef LatticeTag Tag;
      typedef SIZE_TYPE VSize;
      typedef LatticeCat<VSize> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;

      typedef typename std::make_signed<Vid>::type OffsetType;
      static void offset_rewind(Vid& x, OffsetType dx, Vid l) {
	      assert(dx > -((OffsetType)l));
	      if (dx < 0)
	        dx += l;
	        x += dx;
	        x %= l;
      }

      struct Offset {
	      OffsetType dx;
      };

      static Vid dx_max(const Lattice& l) { return l.l / 2; }

      static void shift(Vertex& v, const Vertex& dv, const Lattice& l) {
        v.x += dv.x;
        v.x %= l.l;
      }

      static void shift(Vertex& v, const Offset& dv, const Lattice& l) {
	      offset_rewind(v.x, dv.dx, l.l);
      }

      static void shift(Vid& vid, Vid dvid, const Lattice& l) {
	      Vertex v = LatticeCat::vertex(vid, l);
	      Vertex dv = LatticeCat::vertex(dvid, l);
	      shift(v, dv, l);
	      vid = LatticeCat::vid(v, l);
      }

      static Offset offset(const Vertex& v0, const Vertex& v1) {
	      Offset dv = {v1.x - v0.x};
	      return dv;
      }

      static Vid dv2id(const Offset& dv, const Lattice& l) {
	      Vertex v = LatticeCat::vertex(0, l);
	      shift(v, dv, l);
	      return LatticeCat::vid(v, l);
      }

      static Offset reverse_offset(const Offset& dv, const Lattice& l) {
	      Offset dv2 = {-dv.dx};
	      return dv2;
      }

    };
  }
}
#endif
