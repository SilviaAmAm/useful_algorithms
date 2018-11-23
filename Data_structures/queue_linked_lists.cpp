#include <iostream>

struct Node
{
    int val;
    struct Node * next;
};

class Queue_list
{
    private:
        Node * front_node, * rear_node;
        int n_elements;
    public:
        Queue_list()
        {
            front_node = new Node;
            rear_node = new Node;
            n_elements = 0;
        }

        void enqueue(int element)
        {
            if(n_elements == 0)
            {
                front_node = rear_node;
                rear_node -> val = element;
                rear_node -> next = NULL;
                n_elements++;
            }
            else
            {
                Node * tmp = new Node;
                tmp -> val = element;
                tmp -> next = NULL;
                rear_node -> next = tmp;
                rear_node = tmp;
                n_elements++;
            }
        }

        int dequeue()
        {
            if (n_elements == 0)
            {
                std::cout << "The queue is empty.\n";
                return 0;
            }

            Node * tmp = front_node;
            front_node = front_node -> next;
            n_elements--;

            return tmp->val;
        }

        void print_queue()
        {
            Node * tmp = front_node;

            while(tmp != NULL)
            {
                std::cout << tmp->val << "\t";
                tmp = tmp -> next;
            }

            std::cout << "\n";
        }
};

int main()
{
    Queue_list q;
    q.enqueue(1);
    q.enqueue(10);
    q.enqueue(32);
    q.enqueue(14);

    q.print_queue();

    q.dequeue();
    q.print_queue();

    q.enqueue(16);
    q.enqueue(12);
    q.print_queue();

    for(int i = 0; i < 6; i++)
    {
        q.dequeue();
        q.print_queue();
    }
    
    q.print_queue();
    q.enqueue(10);
    q.print_queue();
}