#include <vector>
#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int a[11] = {2,4,6,8,10,1,3,5,7,9,11};

    std::vector<int> array_a(a, a+11);
    std::vector<int> result;

    result = sort(array_a);

    for (int i=0; i<result.size();i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}