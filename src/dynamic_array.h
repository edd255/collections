template <typename T>
class DynamicArray
{
        public:
                void reallocate();
                void push_back(T element);
                void pop_back();
                T get(int index);
                DynamicArray(int max_size);
                ~DynamicArray();

        private:
                int current_size;
                int max_size;
                T* array;
};
