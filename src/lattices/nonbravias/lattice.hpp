#ifndef LATTICES_NONBRAVIAS_LATTICE_HPP
#define LATTICES_NONBRAVIAS_LATTICE_HPP

namespace lattices {
  namespace nonbravias {
    template <typename TAG, typename SIZE_TYPE>
    struct Lattice {
      SIZE_TYPE lx;
      SIZE_TYPE ly;
    };
    template <typename TAG, typename SIZE_TYPE>
    struct Vertex {
      SIZE_TYPE x;
      SIZE_TYPE y;
      unsigned char n;
    };

    template <typename TAG, typename SIZE_TYPE, unsigned char SUBLATTICE_SIZE>
    struct LatticeCat {
      typedef TAG Tag;
      typedef SIZE_TYPE VSize;
      typedef std::integral_constant<unsigned char, SUBLATTICE_SIZE>
      SublatticeSize;
      typedef Lattice<Tag, VSize> Lattice;
      typedef Vertex<Tag, VSize> Vertex;
      typedef VSize Vid;

      static VSize count(const Lattice& lattice)
      { return lattice.lx * lattice.ly * SublatticeSize::value; }

      static Vid vid(const Vertex& v, const Lattice& l) {
	return (v.y * l.lx + v.x) * SublatticeSize::value + v.n;
      }

      static Vertex vertex(Vid vid, const Lattice& l) {
	Vertex v;
	v.n = vid % SublatticeSize::value;
	VSize vxy = vid / SublatticeSize::value;
	v.x = vxy % l.lx;
	v.y = vxy / l.lx;
	return v;
      }

      static bool equal(const Vertex& v1, const Vertex& v2) {
	return v1.x == v2.x && v1.y == v2.y && v1.n == v2.n;
      }

      static Vid center(const Lattice&) { return 0; }

    };
  }
}
#endif
