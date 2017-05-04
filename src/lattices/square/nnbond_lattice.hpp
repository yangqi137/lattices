#ifndef LATTICES_SQUARE_NEARESTNEIGHBOR_BOND_LATTICE
#define LATTICES_SQUARE_NEARESTNEIGHBOR_BOND_LATTICE

#include <array>
#include "../nonbravias/lattice.hpp"
#include "lattice.hpp"
#include "offset.hpp"

namespace lattices {
  namespace square {
    template <typename S>
    struct NNBondLatticeMapCat {
      struct NNBondLatticeTag {};
      typedef LatticeCat<S> VLatticeCat;
      typedef nonbravias::LatticeCat<NNBondLatticeTag, S, 2> BLatticeCat;
      typedef typename VLatticeCat::Lattice VLattice;
      typedef typename BLatticeCat::Lattice BLattice;
      typedef typename VLatticeCat::Vertex Vertex;
      typedef typename BLatticeCat::Vertex Bond;
      typedef S Vid;
      typedef S VSize;

      typedef OffsetCat<S> OffsetCat;
      typedef typename OffsetCat::Offset Offset;

      static const unsigned char BOND_X = 0;
      static const unsigned char BOND_Y = 1;

      static BLattice bondLattice(const VLattice& vl) {
        BLattice bl;
        bl.lx = vl.lx;
        bl.ly = vl.ly;
        return bl;
      }

      static std::array<Bond, 4> bondsOfVertex(const Vertex& v, const VLattice& vl) {
        Bond bx1 = {v.x, v.y, BOND_X}, by1 = {v.x, v.y, BOND_Y};

        Vertex vx = v;
        OffsetCat::shift(vx, Offset{-1, 0}, vl);
        Bond bx2 = {vx.x, vx.y, BOND_X};

        Vertex vy = v;
        OffsetCat::shift(vy, Offset{0, -1}, vl);
        Bond by2 = {vy.x, vy.y, BOND_Y};

        return {bx1, by1, bx2, by2};
      }

      static std::array<Vertex, 2> verticesOfBond(const Bond& b, const VLattice& vl) {
        Vertex v1 = {b.x, b.y};
        Vertex v2 = v1;
        if (b.n == BOND_X)
          OffsetCat::shift(v2, Offset{1, 0}, vl);
        else
          OffsetCat::shift(v2, Offset{0, 1}, vl);
        return {v1, v2};
      }

      static std::array<Vid, 4> bondsOfVertex(Vid v, const VLattice& vl, const BLattice& bl) {
        Vertex vv = VLatticeCat::vertex(v, vl);
        auto bonds = bondsOfVertex(vv, vl);
        std::array<Vid, 4> result;
        for (unsigned i = 0; i < 4; i++)
          result[i] = BLatticeCat::vid(bonds[i], bl);
        return result;
      }

      static std::array<Vid, 2> verticesOfBond(Vid b, const VLattice& vl, const BLattice& bl) {
        Bond bb = BLatticeCat::vertex(b, bl);
        auto vertices = verticesOfBond(bb, vl);
        return {VLatticeCat::vid(vertices[0], vl),
                VLatticeCat::vid(vertices[1], vl)};
      }

      static Bond bond(const Vertex& v, unsigned char n) {
        Bond b = {v.x, v.y, n};
        return b;
      }

      static bool check_bond(const Vertex& v1, const Vertex& v2, const Bond& b, const VLattice& vl) {
        auto v12 = verticesOfBond(b, vl);
        return (VLatticeCat::equal(v1, v12[0])
                 && VLatticeCat::equal(v2, v12[1]))
                 || (VLatticeCat::equal(v1, v12[1])
                 && VLatticeCat::equal(v2, v12[0]));
      }
    };
  }
}
#endif
