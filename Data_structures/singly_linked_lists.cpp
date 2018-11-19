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

        void add_node_end(int an_element)
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
                tail -> next = tmp;     // The currently last node needs to point to tmp
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
            std::cout << "\n";
        }

        // Adding a node at the beginning
        void add_node_beginning(int new_element)
        {
            Node *tmp = new Node;

            tmp -> element = new_element;
            tmp -> next = head;

            head = tmp;

        }

        // Adding a node at a certain position
        void add_node_position(int new_element, int position)
        {
            // Creating a new node and assigning the value of the element
            Node *new_node = new Node;
            new_node -> element = new_element;
            Node *tmp = head;

            // Moving to the right position
            for (int i = 0; i < position-2; i++)
            {
                tmp = tmp->next;
            }

            // Updating the pointers
            new_node -> next = tmp->next;
            tmp -> next = new_node;
        }

        // Deleting the first element that is equal to a key
        void remove_element(int key)
        {
            Node *current_node = head;
            Node *previous_node = new Node;

            while(current_node->next != NULL and current_node->element != key)
            {
                previous_node = current_node;
                current_node = current_node -> next;
            }

            if (current_node == head)
            {
                head = current_node -> next;
                delete current_node;
            }
            else
            {
                previous_node -> next = current_node -> next;
                delete current_node;
            }
            
        }

        // Remove the node at a certain index
        void remove_node(int position)
        {
            Node *tmp_head = head;

            if (position != 0)
            {   
                head = head -> next;
                position--;
                remove_node(position);
            }
            else
            {
                Node *next_node = head -> next;

                head -> element = next_node -> element;
                head -> next = next_node -> next;

                delete(next_node); 
            }

            // resetting the head
            head = tmp_head;
        }

        // Deleting completely a linked list
        void delete_all()
        {
            Node *tmp = head;

            while(tmp -> next != NULL)
            {
                head = tmp -> next;
                free(tmp);
                tmp = head;
            }

            free(head);
            head = NULL;
        }

        int get_element(int position)
        {
            Node *current_node = head;

            for (int i=0; i < position; i++)
            {
                current_node = current_node -> next;
                if ( current_node -> next == NULL)
                {
                    std::cout << "List length shorter than index asked\n";
                    return 0;
                }
            }

            return current_node -> element;

        }
};

int main()
{
    linked_list a;
    a.add_node_end(1);
    a.add_node_end(2);
    a.add_node_end(4);
    // a.print_list();
    
    a.add_node_position(3, 3);
    // a.print_list();

    a.add_node_end(5);
    a.add_node_end(6);
    a.print_list();

    // std::cout << "The element at index 4 is:\n";
    // std::cout << a.get_element(4) << "\n\n";

    a.remove_node(3);
    a.print_list();

    // a.remove_element(4);
    // a.print_list();
    
    // a.delete_all();
    // a.print_list();

    return 0;
}