// This shows how a singly linked list works

#include <iostream>

// Each node contains an element and a pointer to another node
struct Node
{
    int element;
    struct Node *next;
};

// The list has no elements when it is instantiated
class linked_list
{
    private:
        struct Node *head, *tail;
    public:
        linked_list()
        {
            head = NULL;
            tail = NULL;
        }

        void add_node(int an_element)
        {
            Node *tmp = new Node;   // tmp is a pointer to a new Node
            tmp -> element = an_element;    // the element of the new node is now "an_element"
            tmp -> next = NULL;

            if (head==NULL)
            {
                head = tmp;     // if the head is pointing to nothing, both head and tail will point to the new node
                tail = tmp;
            }
            else
            {
                tail -> next = tmp;     // Now the last node points to the new node
                tail = tmp;             // The new node becomes the last node

            }
        }

        // Function to print the entire list
        void print_list()
        {
            Node *n = head;

            while( n != NULL)
            {
                std::cout << n -> element << "\n";
                n = n -> next;
            }
        }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(4);

    a.print_list();

    return 0;
}