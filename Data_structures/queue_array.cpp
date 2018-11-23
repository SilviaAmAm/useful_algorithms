#include <iostream>
#include <vector>

class Queue_array
{
    private:
        int size;
        int * queue;
        int idx_front, n_elements;
    public:
        Queue_array(int queue_size)
        {
            idx_front = 0;
            n_elements = 0;
            size = queue_size;

            int queue[size];

        }

        void enqueue(int element)
        {
            // Checking if the queue is full
            if (n_elements == size)
            {
                std::cout << "The queue is full. \n";
            }
            else
            {
                int idx_new = idx_front + n_elements;
                // Updating the indices in a circular matter
                if (idx_new >= size)
                {
                    idx_new -= size;
                }

                queue[idx_new] = element;
                n_elements++;
            }
        }

        int dequeue()
        {
            int dequeued_element = queue[idx_front];

            idx_front++;
            n_elements--;

            if (idx_front >= size)
            {
                idx_front -= size;
            }

            return dequeued_element;
        }

        void print_queue()
        {
            int counter = idx_front;
            for(int i = 0; i < n_elements; i++)
            {
                std::cout << queue[counter] << "\t";
                counter++;

                // Update counter in circular matter
                if(counter >= size)
                {
                    counter = 0;
                }
            }

            std::cout <<  "\n";
        }
};


int main()
{
    Queue_array q(5);
    q.enqueue(1);
    q.enqueue(10);
    q.enqueue(32);
    q.enqueue(14);

    q.print_queue();

    q.dequeue();
    q.print_queue();

}