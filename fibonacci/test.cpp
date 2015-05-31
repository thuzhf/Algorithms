#include "fibonacci.hpp"

#include <iostream>

using namespace std;

int main()
{
	zf::ull input;
	cin >> input;
	zf::ull s = zf::fibonacci<zf::ull>(input, 1, 2, 1, 1);
	cout << s << endl;

	return 0;
}
