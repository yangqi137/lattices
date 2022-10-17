#ifndef LATTICES_NONBRAVIAS_OFFSET_AB_HPP
#define LATTICES_NONBRAVIAS_OFFSET_AB_HPP

#include "lattice.hpp"

#include <type_traits>
#include <cassert>
#include <vector>

namespace lattices { namespace nonbravias {
  template <typename TAG, typename SIZE_TYPE>
  struct OffsetAB {
    typename std::make_signed<SIZE_TYPE>::type dx;
    typename std::make_signed<SIZE_TYPE>::type dy;
    unsigned char a;
    unsigned char b;
  };
  template <typename TAG, typename SIZE_TYPE, unsigned char SUBLATTICE_SIZE>
  struct OffsetABCat {
    typedef TAG Tag;
    typedef SIZE_TYPE VSize;
    typedef VSize Vid;
    typedef LatticeCat<Tag, VSize, SUBLATTICE_SIZE> LatticeCat;
    typedef typename LatticeCat::Lattice Lattice;
    typedef typename LatticeCat::Vertex Vertex;

    typedef typename std::make_signed<Vid>::type OffsetType;
    typedef OffsetAB<Tag, VSize> Offset;

      static void offset_rewind(Vid& x, OffsetType dx, Vid l) {
      	assert(dx > -((OffsetType)l));
	      if (dx < 0)
	        dx += l;
	      x += dx;
	      x %= l;
      }

      static bool try_shift(Vertex& v, const Offset& dv, const Lattice& l) {
        if (v.n != dv.a) return false;
        offset_rewind(v.x, dv.dx, l.lx);
        offset_rewind(v.y, dv.dy, l.ly);
        v.n = dv.b;
        return true;
      }

      static bool try_shift(Vid& vid, const Offset& dv, const Lattice& l) {
        Vertex v = LatticeCat::vertex(vid, l);
        if (try_shift(v, dv, l)) {
          vid = LatticeCat::vid(v, l);
          return true;
        }
        else return false;
      }

      static Offset offset(const Vertex& v0, const Vertex& v1) {
        Offset dv;
        dv.dx = v1.x - v0.x;
        dv.dy = v1.y - v0.y;
        dv.a = v0.n;
        dv.b = v1.n;
        return dv;
      }

      static std::vector<Offset> offsets(const Lattice& l) {
        std::vector<Offset> result;
        const unsigned char ns = SUBLATTICE_SIZE;
        result.reserve(l.lx * l.ly * ns * ns);
        for (OffsetType x = 0; x < l.lx; x++)
          for (OffsetType y = 0; y < l.ly; y++)
            for (unsigned char a = 0; a < ns; a++)
              for (unsigned char b = 0; b < ns; b++)
                result.push_back(Offset{x, y, a, b});
        return result;
      }

  };
} }

#endif