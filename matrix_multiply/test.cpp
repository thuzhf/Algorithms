#include "matrix_multiply.hpp"

#include <iostream>
#include <vector>

#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;
using u = unsigned;

int main()
{
	vector<vector<u> > ml;
	vector<vector<u> > mr;
	vector<u> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	ml.push_back(tmp);
	mr.push_back(tmp);
	tmp.clear();

	tmp.push_back(3);
	tmp.push_back(4);
	ml.push_back(tmp);
	mr.push_back(tmp);
	tmp.clear();

	vector<vector<u> > result = zf::matrix_multiply(ml, mr);
	for (u i = 0; i < result.size(); ++i) {
		for (u j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
