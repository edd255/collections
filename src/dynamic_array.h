#include <iostream>

template <typename T>
class DynamicArray
{
    private:
        int current_size;
        int max_size;
        T* array;

    public:
        void reallocate()
        {
            max_size = 2 * current_size;
            T new_array = new T[max_size];
            for (int i = 0; i < array; i++) {
                new_array[i] = array[i];
            }
            free(array);
            array = new_array;
        }

        void push_back(T element)
        {
            if (current_size == max_size) {
                reallocate();
            }
            array[current_size] = element;
            current_size++;
        }

        void pop_back()
        {
            current_size--;
            if (current_size == max_size / 4 && current_size > 0) {
                reallocate();
            }
        }

        T get(int index)
        {
            if (index < 0 || index >= max_size) {
                return NULL;
            }
            return array[index];
        }

        DynamicArray(int max_size)
        {
            this -> array        = new T[max_size];
            this -> max_size     = max_size;
            this -> current_size = 0;
        }

        ~DynamicArray()
        {
            delete[] array;
        }
};
