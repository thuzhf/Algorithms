#ifndef LONGEST_NONDECREASING_SEQUENCE_HPP_
#define LONGEST_NONDECREASING_SEQUENCE_HPP_

#include <vector>
#include <functional>
#include <tuple>

namespace zf {
	// use DP and a few optimizations
	template<typename T>
	auto longest_nondecreasing_sequence_length(const std::vector<T>& v) -> typename std::vector<T>::size_type {
		auto v_size = v.size();
		using vTst = typename std::vector<T>::size_type;
		std::vector<vTst> longest (v_size, 0); // if it has non-zero value, its value must be longest for it.
		longest[0] = 1;
		std::function<vTst (vTst)> DP; // use fully specified declaration because we need recursion.
		DP = [&] (vTst k) -> vTst { // k: [0, v_size); v[k] is the last element.
			if (longest[k] != 0)  return longest[k];

			vTst tmp_longest = 0; // longest length found so far.
			T tmp_max;
			bool tmp_max_initialized = false;
			std::vector<std::tuple<T, vTst> > qualified;
			for (vTst i = 0; i <= k - 1; ++i)
				if (v[i] <= v[k])
					qualified.push_back(std::forward_as_tuple(v[i], i));

			for (auto i = qualified.size() - 1; i != -1; --i) { // at first, i != -1.
				while (i - 1 != -1 && std::get<0>(qualified[i - 1]) > std::get<0>(qualified[i]))
					--i;
				if (tmp_max_initialized && std::get<0>(qualified[i]) <= tmp_max)
					continue;
				else {
					tmp_max = std::get<0>(qualified[i]);
					tmp_max_initialized = true;
				}
				vTst tmp = DP(std::get<1>(qualified[i]));
				if (tmp > tmp_longest)
					tmp_longest = tmp;
			}
			longest[k] = tmp_longest + 1;
			return longest[k];
		};
		
		vTst tmp_longest = 0;
		T tmp_max;
		bool tmp_max_initialized = false;
		for (vTst i = v_size - 1; i != -1; --i) {
			while (i - 1 != -1 && v[i - 1] > v[i])
				--i;
			if (tmp_max_initialized && v[i] <= tmp_max)
				continue;
			else {
				tmp_max = v[i];
				tmp_max_initialized = true;
			}
			vTst tmp = DP(i);
			if (tmp > tmp_longest)
				tmp_longest = tmp;
		}
		return tmp_longest;
	}
}

#endif // LONGEST_NONDECREASING_SEQUENCE_HPP_
