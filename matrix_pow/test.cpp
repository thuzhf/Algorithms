#include "matrix_pow.hpp"

#include <iostream>

using namespace std;

int main()
{
	vector<vector<zf::ull> > m;
	vector<zf::ull> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	m.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(4);
	m.push_back(tmp);
	tmp.clear();

	unsigned exp = 33;
	vector<vector<zf::ull> > result = zf::matrix_pow(m, exp);
	for (unsigned i = 0; i < result.size(); ++i) {
		for (unsigned j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
