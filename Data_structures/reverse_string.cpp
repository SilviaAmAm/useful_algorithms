// This program takes a string and reverses it using a stack
#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::string the_string = "GeeksQuiz";
    std::string reversed_string;
    std::stack <char> the_stack;

    reversed_string.resize(the_string.length()); 

    for (int i = 0; i < the_string.length(); i++)
    {
        the_stack.push(the_string[i]);
    }

    for (int i = 0; i < the_string.length(); i++)
    {
        reversed_string[i] = the_stack.top();
        the_stack.pop();
    }

    std::cout << reversed_string << "\n";
    
}