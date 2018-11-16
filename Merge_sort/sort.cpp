// This implements the recursive function to sort an array of integers using the merge-sort algorithm
// It calls the merge function which runs in O(N) time. 

#include <vector>
#include "merge.h"
#include <iostream>

std::vector<int> sort(std::vector<int> array)
{
    int size_array = array.size();

    if(size_array <= 1)
    {
        return array;
    }
    else
    {
        std::vector<int> sorted_left;
        std::vector<int> sorted_right;

        // Split the array at half length (for odd length arrays, one is longer than the other)
        std::size_t const half_size = array.size() / 2;
        std::vector<int> left_half(array.begin(), array.begin() + half_size);
        std::vector<int> right_half(array.begin() + half_size, array.end());

        // Recursively sort each half
        sorted_left = sort(left_half);
        sorted_right = sort(right_half);

        // Merge the sorted halves
        return merge(sorted_left, sorted_right);
    }
}