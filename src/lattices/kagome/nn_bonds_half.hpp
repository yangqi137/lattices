#ifndef LATTICES_KAGOME_NEAREST_NEIGHBOR_BONDS_HALF_HPP
#define LATTICES_KAGOME_NEAREST_NEIGHBOR_BONDS_HALF_HPP

#include "bondset.hpp"

namespace lattices {
  namespace kagome {
    struct NNHSBCData {
      static constexpr unsigned nBonds = 2;
      static constexpr unsigned nSublattices = 3;
      
      static int offsetsp[][][]() {
	static int data[nSublattices][nBonds][nSublattices]
	  = {{{0, 0, 1}, {0, 0, 2}},
	     {{1, 0, 0}, {0, 0, 2}},
	     {{0, 1, 0}, (-1, 1, 1}}};
	return data;
      }
				     
    };


    template <typename S>
    using NNBondsHalf = BondSet<NNHSBCData, S>;
  }
}

#endif
