#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> vec = {1, 2, 3, 4, 5, 6};
    Vector<int>::Iterator it = vec.begin() + 2;

    vec.erase(it, it + 2);

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << ' ';
	}
    std::cout << std::endl;

    return 0;
}
