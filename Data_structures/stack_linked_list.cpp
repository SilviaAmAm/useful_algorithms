// This implements a stack using C++ linked lists
#include <iostream>

// The node of a linked list
struct Node
{
    int val;
    struct Node * next;
};

class Stack_linked
{
    private:
        int size;
        Node * top_node;
        Node * head;

    public:
        Stack_linked()
        {
            size = 0;
            top_node = new Node;
            top_node -> next = NULL;
        }

        void push(int element)
        {
            if(size == 0)
            {
                Node *a_first_node = new Node;
                a_first_node -> val = element;
                a_first_node -> next = NULL;

                top_node = a_first_node;
                size++;
            }
            else
            {
                Node *a_new_node = new Node;
                Node *tmp = top_node;

                a_new_node -> val = element;
                a_new_node -> next = tmp;

                top_node = a_new_node;
                size++;
            }
        }

        void pop()
        {
            if (size == 0)
            {
                std::cout << "The stack is empty.\n";
            }
            else
            {
                top_node = top_node -> next;
                size--;
            }
            
        }

        void showstack()
        {
            Node *current_node = top_node;

            while(current_node -> next != NULL)
            {
                std::cout << current_node -> val << "\t";
                current_node = current_node -> next;
            }

            std::cout << current_node -> val << "\t";

            std::cout <<  "\n";
        }

        int get_size()
        {
            return size;
        }

        int get_top()
        {
            return top_node->val;
        }
            
};

int main()
{
    Stack_linked s;
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
    s.pop();
    s.showstack(); 

    std::cout << "\ns.size() : " << s.get_size(); 
    std::cout << "\ns.top() : " << s.get_top();


}