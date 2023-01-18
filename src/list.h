#include "collection.h"

template <typename T>
class List : public Collection<T>
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

        /**
         * Get the element at the specified index.
         */
        virtual T get(int index) = 0;

        /**
         * Set the element at the specified index.
         */
        virtual void set(T element, int index) = 0;

        /**
         * Insert an element after the specified index.
         */
        virtual void insert(T element, int index) = 0;

        /**
         * Remove an element at the specified index.
         */
        virtual void remove(int index) = 0;

        /**
         * Remove the first occurence of the specified element.
         */
        virtual void remove(T element) = 0;

        /**
         * Remove the all occurences of the specified element.
         */
        virtual void remove_all(T element) = 0;

        /**
         * Push an element to the back of the collection.
         */
        virtual void push_back(T element) = 0;

        /**
         * Remove the element at the back of the collection.
         */
        virtual void pop_back() = 0;

        /**
         * Insert an element at the front of the collection.
         */
        virtual void push_front(T element) = 0;

        /**
         * Remove the element at the front of the collection.
         */
        virtual void pop_front() = 0;

        /**
         * Remove all elements from the collection.
         */
        virtual void clear() = 0;

        /**
         * Returns true if the element is in the list.
         */
        virtual bool contains(T element) = 0;

        /**
         * Returns the index of the specified element.
         */
        virtual int index_of(T element) = 0;

        /**
         * Returns the number of elements in the list.
         */
        virtual int size() = 0;

        /**
         * Swap the elements at index i and j.
         */
        virtual void swap(int i, int j) = 0;
};
