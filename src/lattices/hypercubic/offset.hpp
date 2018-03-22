#ifndef LATTICES_HYPERCUBIC_HPP
#define LATTICES_HYPERCUBIC_HPP

#include "lattice.hpp"

#include <type_traits>
#include <algorithm>

namespace lattices {
  namespace hypercubic {
    template <unsigned D, typename SIZE_TYPE>
    struct OffsetCat {
      typedef LatticeTag Tag;
      typedef SIZE_TYPE VSize;
      typedef LatticeCat<D, VSize> LatticeCat;
      typedef typename LatticeCat::Lattice Lattice;
      typedef typename LatticeCat::Vertex Vertex;
      typedef typename LatticeCat::Vid Vid;
      typedef typename LatticeCat::Dim Dim;

      typedef typename std::make_signed<Vid>::type OffsetType;

      static void offset_rewind(Vid& x, OffsetType dx, Vid l) {
        assert(dx > -((OffsetType)l));
        if (dx < 0)
          dx += l;
        x += dx;
        x %= l;
      }

      struct Offset {
        OffsetType dx[Dim::value];
      };

      static void shift(Vertex& v, const Vertex& dv, const Lattice& l) {
        for (unsigned i = 0; i < Dim::value; i++) {
          v.x[i] += dv.x[i];
          v.x[i] %= LatticeCat::length(i, l);
        }
      }

      static void shift(Vertex& v, const Offset& dv, const Lattice& l) {
        for (unsigned i = 0; i < Dim::value; i++) {
          offset_rewind(v.x[i], dv.dx[i], LatticeCat::length(i, l));
        }
      }

      static void shift(Vid& vid, Vid dvid, const Lattice& l) {
        Vertex v = LatticeCat::vertex(vid, l);
        Vertex dv = LatticeCat::vertex(dvid, l);
        shift(v, dv, l);
        vid = LatticeCat::vid(v, l);
      }

      static Offset offset(const Vertex& v0, const Vertex& v1) {
        Offset dv;
        for (unsigned i = 0; i < Dim::value; i++)
          dv.dx[i] = v1.x[i] - v0.x[i];
        return dv;
      }

      static Vid dv2id(const Offset& dv, const Lattice& l) {
        Vertex v = LatticeCat::vertex(0, l);
        shift(v, dv, l);
        return LatticeCat::vid(v, l);
      }

      static Offset reverse_offset(const Offset& dv, const Lattice& l) {
        Offset dv2;
        for (unsigned i = 0; i < Dim::value; i++)
          dv2.dx[i] = - dv.dx[i];
        return dv2;
      }

      static void minus(Vertex& v, const Lattice& l) {
        for (unsigned i = 0; i < Dim::value; i++) {
          Vid lxi = LatticeCat::length(i, l);
          v.x[i] = (lxi - v.x[i]) % lxi;
        }
      }

      static void minus(Vid& vid, const Lattice& l) {
        Vertex v = LatticeCat::vertex(vid, l);
        minus(v, l);
        vid = LatticeCat::vid(v, l);
      }

    };
  }
}

#endif
