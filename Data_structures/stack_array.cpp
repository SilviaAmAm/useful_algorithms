// This program shows a stack in C++ implemented using arrays
#include <iostream>

class Stack_array
{
    private:
        int size, top_idx;
        int *the_stack;
    public:
        Stack_array(int the_size)
        {
            size = the_size;
            int the_stack[size];
            top_idx = 0;
        }

        void push(int element)
        {
            if (top_idx >= size)
            {
                std::cout << "The stack is currently full. \n";
            }
            else
            {
                the_stack[top_idx] = element;
                top_idx++;
            }
        }

        void pop()
        {
            if(top_idx == 0)
            {
                std::cout << "The stack is currently empty. \n";
            }
            else
            {
                top_idx--;
            }
        }

        void showstack()
        {
            for(int i = 0; i < top_idx; i++)
            {
                std::cout << the_stack[i] << "\t";
            }

            std::cout << "\n";
        }

        // return the total size of the stack (not how many elements in it)
        int get_size()
        {
            return size;   
        }

        // return the last element
        int get_top()
        {
            return the_stack[top_idx-1];
        }


};


int main () 
{ 
    Stack_array s(5); 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    std::cout << "The stack is : "; 
    s.showstack(); 
  
    std::cout << "\ns.size() : " << s.get_size(); 
    std::cout << "\ns.top() : " << s.get_top(); 
  
  
    std::cout << "\ns.pop() : "; 
    s.pop(); 
    s.showstack(); 
  
    return 0; 
} 