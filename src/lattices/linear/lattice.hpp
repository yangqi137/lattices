#ifndef LATTICES_LINEAR_LATTICE_HPP
#define LATTICES_LINEAR_LATTICE_HPP

namespace lattices {
  namespace linear {
    struct LatticeTag {};
    template <typename S>
    struct Lattice {
      typedef LatticeTag Tag;
      S l;
    };
    template <typename S>
    struct Vertex {
      typedef LatticeTag Tag;

      S x;
    };
    template <typename S>
    struct LatticeCat {
      typedef LatticeTag Tag;
      typedef S VSize;
      typedef S Vid;
      typedef Lattice<S> Lattice;
      typedef Vertex<S> Vertex;

      static VSize count(const Lattice& l) { return l.l; }
      static Vid vid(const Vertex& v, const Lattice& l) {
        return v.x;
      }
      static Vertex vertex(Vid vid, const Lattice& l) {
        Vertex v; v.x = vid;
        return v;
      }
      static bool equal(const Vertex& v1, const Vertex& v2) {
        return v1.x == v2.x;
      }
      static Vid center(const Lattice&) { return 0; }
    };
  }
}

#endif
