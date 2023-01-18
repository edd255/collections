template <typename T>
class Collection
{
    public:
        /**
         * Adds all elements to the collection.
         */
        virtual bool add_all(Collection<T> elements) = 0;

        /**
         * Performs binary search for the specified key.
         */
        virtual int binary_search(T key) = 0;

        /**
         * Copies all elements to the destination collection.
         */
        virtual void copy(Collection<T> destination) = 0;

        /**
         * Return true if the collections have no elements in common.
         */
        virtual bool is_disjoint_with(Collection<T> other) = 0;

        /**
         * Replaces all elements with the specified element.
         */
        virtual void fill(T element) = 0;

        /**
         * Returns how often an element appears in a collection.
         */
        virtual int frequency(T element) = 0;

        /**
         * Replaces all old values with a new value.
         */
        virtual void replace_all(T old_value, T new_value) = 0;
};
