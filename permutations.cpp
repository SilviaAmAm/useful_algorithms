// This algorithms prints out all the permutations of a string.
// It runs in O(N^2 N!) time

#include <string>
#include <iostream>
using namespace std;

// Headers
void permutation(string str, string prefix);

// Main
int main()
{
    string str = "cat";
    permutation(str, "");
}

// Function
void permutation(string str, string prefix)
{
    if (str.length() == 0)
    {
       cout << prefix << "\n";
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string rem = str.substr(0, i) + str.substr(i+1);
            permutation(rem, prefix+str[i]);
        }
    }
}