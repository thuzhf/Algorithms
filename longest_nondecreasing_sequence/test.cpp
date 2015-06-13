#include "longest_nondecreasing_sequence.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> v {2,1,4,3,6,5,8,7,10,9,12,9.7,9.7,9.7};
	cout << zf::longest_nondecreasing_sequence_length(v) << endl;
	

	return 0;
}
