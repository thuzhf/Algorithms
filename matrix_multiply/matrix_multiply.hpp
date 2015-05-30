#ifndef MATRIX_MULTIPLY_HPP_
#define MATRIX_MULTIPLY_HPP_

#include <stdexcept>
#include <iostream>
#include <vector>

namespace zf {
	template <class T>
	std::vector<std::vector<T> > matrix_multiply( \
			const std::vector<std::vector<T> > &ml, \
			const std::vector<std::vector<T> > &mr) {
		unsigned ml_row_n = ml.size();
		unsigned ml_col_n = ml[0].size();
		unsigned mr_row_n = mr.size();
		unsigned mr_col_n = mr[0].size();
		if (ml_col_n != mr_row_n) {
			throw std::invalid_argument( \
				"The first matrix's column's dimension didn't match the second matrix's row's dimension." \
			);
		} else if (0 == ml_row_n || 0 == ml_col_n || 0 == mr_row_n || 0 == mr_col_n) {
			throw std::invalid_argument( \
				"Input matrix's dimensions should both be positive." \
			);
		}
		
		unsigned ret_row_n = ml_row_n;
		unsigned ret_col_n = mr_col_n;
		unsigned inter_n = ml_col_n;
		std::vector<std::vector<T> > ret;
		T tmp;
		for (unsigned i = 0; i < ret_row_n; ++i) {
			std::vector<T> one_row;
			for (unsigned j = 0; j < ret_col_n; ++j) {
				tmp = 0;
				for (unsigned k = 0; k < inter_n; ++k) {
					tmp += ml[i][k] * mr[k][j];
				}
				one_row.push_back(tmp);
			}
			ret.push_back(one_row);
		}

		return ret;
	}
}

#endif // MATRIX_MULTIPLY_HPP_
