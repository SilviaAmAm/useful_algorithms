// This program implements a hash table using linked lists to avoid conflicts
#include <iostream>

class HashEntry
{
    private:
        int key;
        int value;
        HashEntry *next;

    public:
        HashEntry(int a_key, int a_value)
        {
            key = a_key;
            value = a_value;
            next = NULL;
        }

        void set_key(int a_key)
        {
            key = a_key;
        }

        void set_value(int a_value)
        {
            value = a_value;
        }

        void set_next(HashEntry *the_next)
        {
            next = the_next;
        }

        int get_key()
        {
            return key;
        }

        int get_value()
        {
            return value;
        }

        HashEntry *get_next()
        {
            return next;
        }
};

class HashTable
{
    private:
        HashEntry **table;
    public:
        HashTable()
        {
            table = new HashEntry*[1000];

            //Initialising the empty table
            for(int i=0; i<1000; i++)
            {
                table[i] = NULL;
            }
        }

        // This finds an empty entry for a key,value pair or if key is already present replaces the value
        void put(int a_key, int a_value)
        {
            // Finding the hash
            int hash = a_key % 1000;

            // If the table is empty at that location
            if(table[hash] == NULL)
            {
                HashEntry *new_entry = new HashEntry(a_key, a_value);
                table[hash] = new_entry;
            }
            else
            {
                // If there are entries, avoid collisions
                HashEntry *ptr_entry = table[hash]; 
                HashEntry *previous_entry = table[hash];

                while(ptr_entry != NULL)
                {
                    if(ptr_entry -> get_key() == a_key )
                    {
                        ptr_entry -> set_value(a_value);
                        return;
                    }
                    else
                    {
                        previous_entry = ptr_entry;
                        ptr_entry = ptr_entry -> get_next();
                    }
                }

                HashEntry *new_entry = new HashEntry(a_key, a_value);
                previous_entry -> set_next(new_entry);
            }            
        }

        // This retrieves the value corresponding to a key
        int get(int a_key)
        {
            //Finding the Hash index
            int hash = a_key % 1000;

            //Looking in the table
            HashEntry *current_entry = table[hash];

            if(current_entry == NULL)
            {
                return -1;
            }
            else
            {
                while(current_entry != NULL and current_entry->get_key() != a_key)
                {
                    current_entry = current_entry -> get_next();
                }

                if(current_entry == NULL)
                {
                    return -1;
                }
                else
                {
                    return current_entry->get_value();
                }
            }
        }

        // This removes an entry with a certain key if it exists
        void remove(int a_key)
        {
            // find the hash index
            int hash = a_key % 1000;

            if (table[hash] == NULL) return;

            if (table[hash]->get_key() == a_key)
            {
                table[hash] = table[hash]->get_next();
            }
            else
            {
                HashEntry *current_entry = table[hash];
                HashEntry *prev_entry = table[hash];

                while(current_entry != NULL and current_entry -> get_key() != a_key)
                {
                    prev_entry = current_entry;
                    current_entry = current_entry->get_next();
                }

                if(current_entry != NULL)
                {
                    prev_entry->set_next(current_entry -> get_next());
                }
            }
        }
};

int main()
{
    HashTable a_magnificent_table;

    // a_magnificent_table.put(10, 35);
    // a_magnificent_table.put(1010, 45);
    // a_magnificent_table.put(2010, 55);
    // a_magnificent_table.put(1010, 15);

    // std::cout << a_magnificent_table.get(10) << "\n";
    // std::cout << a_magnificent_table.get(1010) << "\n";
    // std::cout << a_magnificent_table.get(2010) << "\n";
    // std::cout << a_magnificent_table.get(3) << "\n";

    // a_magnificent_table.remove(1010);

    // std::cout << a_magnificent_table.get(10) << "\n";
    // std::cout << a_magnificent_table.get(1010) << "\n";
    // std::cout << a_magnificent_table.get(2010) << "\n";

    a_magnificent_table.put(1, 1);
    a_magnificent_table.put(2, 2);

    std::cout << a_magnificent_table.get(1) << "\n";
    std::cout << a_magnificent_table.get(3) << "\n";

    a_magnificent_table.put(2, 1);

   std::cout << a_magnificent_table.get(2) << "\n";

    a_magnificent_table.remove(2);

    std::cout << a_magnificent_table.get(2) << "\n";

}