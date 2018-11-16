// This function merges two arrays of integers and runs in O(N) time

#include <vector>
#include "merge.h"

std::vector<int> merge(std::vector<int> array_a, std::vector<int> array_b)
{
    // counters
    int counter_a = 0;
    int counter_b = 0;

    // result
    int size_a = array_a.size();
    int size_b = array_b.size();
    
    std::vector<int> result;
    result.resize(size_a+size_b);

    // merging
    for(int i=0; i<(size_a+size_b); i++)
    {
        if(counter_a == size_a)
        {
            result[i] = array_b[counter_b];
            counter_b++;
        } else if (counter_b == size_b)
        {
            result[i] = array_a[counter_a];
            counter_a++;
        } else 
        {
            if(array_a[counter_a] <= array_b[counter_b])
            {
                result[i] = array_a[counter_a];
                counter_a++;
            } else {
                result[i] = array_b[counter_b];
                counter_b++;
            }
        }
    }

    return result;
}