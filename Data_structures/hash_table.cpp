/*
This program implements a very simple hash table.
*/

#include <iostream>

// A new entry for the hash table
class HashEntry 
{
    private:
        int key;
        int value;
    public:
        HashEntry(int a_key, int a_value) 
        {
            this->key = a_key;
            this->value = a_value;
        }
    
        int getKey() const
        {
            return key;
        }
    
        int getValue() const
        {
            return value;
        }
};

class HashMap 
{
    private:
        HashEntry **table;  //Pointer to a pointer to a HashEntry object
        const int table_size = 128;
    public:
        HashMap() 
        {
            table = new HashEntry*[table_size];     // table is now a pointer to an array (of size 128) of pointers
            for (int i = 0; i < table_size; i++)    // The table is empty
                table[i] = NULL;
        }
    
        int get(int key) 
        {
            int hash = (key % table_size);      // hash function
            
            while (table[hash] != NULL && table[hash]->getKey() != key)     
                hash = (hash + 1) % table_size;

            if (table[hash] == NULL)
                return -1;
            else
                return table[hash]->getValue();
        }
    
        // Adding a value to the hash table
        void put(int key, int value) 
        {
            int hash = (key % table_size);  // Transforming the key with the hash function

            // Checking if that place in the table is free, otherwise increase the counter
            while (table[hash] != NULL && table[hash]->getKey() != key)
                hash = (hash + 1) % table_size;
            
            // If that part of the hash table is already filled, replace it with the new value
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
        }     
    
        ~HashMap() {
                for (int i = 0; i < table_size; i++)
                    if (table[i] != NULL)
                            delete table[i];
                delete[] table;
        }
};

int main()
{
    HashMap my_first_map;
    my_first_map.put(1, 7565);
    my_first_map.put(2, 6914);
    my_first_map.put(3, 6912);

    std::cout << my_first_map.get(1) << "\n";
    std::cout << my_first_map.get(2) << "\n";
    std::cout << my_first_map.get(3) << "\n";

}