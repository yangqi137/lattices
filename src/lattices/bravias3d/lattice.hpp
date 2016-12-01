#ifndef LATTICES_BRAVIAS3D_LATTICE_HPP
#define LATTICES_BRAVIAS3D_LATTICE_HPP

namespace lattices {
  namespace bravias3d {
    template <typename TAG, typename SIZE_TYPE>
    struct Lattice {
      typedef TAG Tag;

      SIZE_TYPE lx;
      SIZE_TYPE ly;
      SIZE_TYPE lz;
    };
    template <typename TAG, typename SIZE_TYPE>
    struct Vertex {
      typedef TAG Tag;

      SIZE_TYPE x;
      SIZE_TYPE y;
      SIZE_TYPE z;
    };

    template <typename TAG, typename SIZE_TYPE>
    struct LatticeCat {
      typedef TAG Tag;
      typedef SIZE_TYPE VSize;
      typedef Lattice<Tag, VSize> Lattice;
      typedef Vertex<Tag, VSize> Vertex;
      typedef VSize Vid;

      static VSize count(const Lattice& l) { return l.lx * l.ly; }
      static Vid vid(const Vertex& v, const Lattice& l) {
        return (v.z * l.ly + v.y) * l.lx + v.x;
      }

      static Vertex vertex(Vid vid, const Lattice& l) {
        Vertex v;
        Vid lxy = l.lx * l.ly;
        v.z = vid / lxy;
        Vid vxy = vid % lxy;
        v.y = vxy / l.lx;
        v.x = vxy % l.lx;
        return v;
      }

      static bool equal(const Vertex& v1, const Vertex& v2) {
        return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
      }

      static Vid center(const Lattice&) { return 0; }

    };
  }
}

#endif
