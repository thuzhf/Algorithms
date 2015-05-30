#ifndef MATRIX_POW_HPP_
#define MATRIX_POW_HPP_

#include "../defs.hpp"
#include "../matrix_multiply/matrix_multiply.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>

namespace zf {
	// time complexity: O(log(exp))
	template <class T>
	std::vector<std::vector<T> > matrix_pow(const std::vector<std::vector<T> > &m, unsigned exp) {
		// m should be a square matrix
		// exp should be nonnegative
		if (exp < 0) {
			throw std::invalid_argument( \
				"The exponent should be nonnegative." \
			);
		}

		using vvT_st = typename std::vector<std::vector<T> >::size_type;
		using vT_st = typename std::vector<T>::size_type;
		vvT_st order = m.size();
		vT_st order2 = m[0].size();
		if (order != order2) {
			throw std::invalid_argument( \
				"The input matrix is not a square matrix." \
			);
		}

		std::vector<std::vector<T> > ret;
		// if exp == 0, return an identity matrix with the same order as m
		if (0 == exp) {
			for (vvT_st i = 0; i < order; ++i) {
				std::vector<T> tmp;
				for (vvT_st j = 0; j < order; ++j) {
					tmp.push_back(j == i ? 1 : 0);
				}
				ret.push_back(tmp);
			}
			return ret;
		}

		// if exp > 0
		std::vector<bool> odd;
		bool tmp_odd;
		ret = m;
		for (unsigned i = exp; i > 1; i /= 2) {
			if (1 == i % 2) {
				tmp_odd = true;
			} else {
				tmp_odd = false;
			}
			odd.push_back(tmp_odd);
		}
		
		for (std::vector<bool>::size_type i = odd.size(); i-- != 0; ) {
			if (odd[i]) {
				ret = zf::matrix_multiply(zf::matrix_multiply(ret, ret), m);
			} else {
				ret = zf::matrix_multiply(ret, ret);
			}
		}
		
		return ret;
	}
}

#endif // MATRIX_POW_HPP_
