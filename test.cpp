#include <iostream>
#include "vector.h"

int main()
{
    MyVector<int> vec = {1, 0, 1, 1, 0, 1, 0, 1};
	vec.push_back(0);
    vec[8] = vec[0];
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;

    return 0;
}
