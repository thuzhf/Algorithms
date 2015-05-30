#include "../defs.hpp"
#include "../matrix_pow/matrix_pow.hpp"
#include "../matrix_multiply/matrix_multiply.hpp"

#include <vector>

namespace zf {
	template <class T>
	T fibonacci(unsigned n, T x1 = 1, T x2 = 1, T a = 1, T b = 1) {
		// f(n+2) = a * f(n + 1) + b * f(n)
		T ret = 0;
		if (0 == n) {
			return 0;
		} else if (1 == n) {
			return x1;
		} else if (2 == n) {
			return x2;
		}

		// this is the coefficient matrix for iteration
		std::vector<std::vector<T> > m;
		std::vector<T> tmp;
		tmp.push_back(a);
		tmp.push_back(b);
		m.push_back(tmp);
		tmp.clear();
		tmp.push_back(1);
		tmp.push_back(0);
		m.push_back(tmp);
		tmp.clear();

		std::vector<std::vector<T> > init;
		init.push_back(std::vector<T>(1, x1));
		init.push_back(std::vector<T>(1, x2));

		std::vector<std::vector<T> > final_m = zf::matrix_pow(m, n - 2);
		ret = zf::matrix_multiply(final_m, init)[0][0];

		return ret;
	}
}
