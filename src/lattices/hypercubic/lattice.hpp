#ifndef LATTICES_HYPERCUBIC_LATTICE_HPP
#define LATTICES_HYPERCUBIC_LATTICE_HPP

#include <type_traits>
#include <initializer_list>
#include <stdexcept>
#include <cassert>
#include <iostream>
namespace lattices {
  namespace hypercubic {
    struct LatticeTag {};
    template <unsigned D, typename SIZE_TYPE>
    struct Lattice {
      typedef LatticeTag Tag;
      typedef std::integral_constant<unsigned, D> Dim;

      Lattice(std::initializer_list<SIZE_TYPE> lengths) {
        if (lengths.size() != Dim::value)
          throw std::length_error("HyperCubicLattice constructor receives wrong number of lengths.");

        SIZE_TYPE lcum_prev = 1;
        unsigned i = 0;
        for (auto& li : lengths) {
          lcum[i] = lcum_prev * li;
          lcum_prev = lcum[i];
          i++;
        }
      }

      Lattice() {
        for (unsigned i = 0; i < Dim::value; i++)
          lcum[i] = 1;
      }

      SIZE_TYPE lcum[D];
      // lcum[0] = l[0]
      // lcum[1] = l[0] * l[1]
      // lcum[i] = l[0] * ... * l[i]
    };

    template <unsigned D, typename SIZE_TYPE>
    struct Vertex {
      typedef LatticeTag Tag;
      typedef std::integral_constant<unsigned, D> Dim;

      SIZE_TYPE x[D];
    };

    template <unsigned D, typename SIZE_TYPE>
    struct LatticeCat {
      typedef LatticeTag Tag;
      typedef SIZE_TYPE VSize;
      typedef std::integral_constant<unsigned, D> Dim;

      typedef Lattice<D, VSize> Lattice;
      typedef Vertex<D, VSize> Vertex;
      typedef VSize Vid;

      static VSize count(const Lattice& l) { return l.lcum[Dim::value - 1]; }

      static Vertex vertex(Vid vid, const Lattice& l) {
        Vertex v;
        Vid rmd = vid;
        for (unsigned i = Dim::value - 1; i != 0 ; i--) {
          v.x[i] = rmd / l.lcum[i-1];
          rmd = rmd % l.lcum[i-1];
        }
        v.x[0] = rmd;
        return v;
      }

      static Vid vid(const Vertex& v, const Lattice& l) {
        Vid vv = 0;
        for (unsigned i = Dim::value - 1; i != 0; i--)
          vv += v.x[i] * l.lcum[i-1];
        vv += v.x[0];
        return vv;
      }

      static Vid length(unsigned i, const Lattice& l) {
        assert( i < Dim::value);
        if (i == 0) return l.lcum[i];
        else return l.lcum[i] / l.lcum[i-1];
      }

      template <typename InputIterator>
      static Lattice createLattice(InputIterator first, InputIterator last) {
        Lattice lattice;
        SIZE_TYPE lcum_prev = 1;
        unsigned i = 0;
        for (auto p = first; p != last; p++) {
          if (i >= Dim::value) throw std::length_error("HyperCubicLattice constructor receives wrong number of lengths.");
          unsigned li = *p;
          std::cout << li << std::endl;
          lattice.lcum[i] = lcum_prev * li;
          lcum_prev = lattice.lcum[i];
          i++;
        }
        if (i != Dim::value) throw std::length_error("HyperCubicLattice constructor receives wrong number of lengths.");
        return lattice;
      }
    };
  }
}
#endif
