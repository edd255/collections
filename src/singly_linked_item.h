template <typename T>
class SinglyLinkedItem
{
    private:
        T element;
        T* next;

    public:
        SinglyLinkedItem(T element, SinglyLinkedItem<T>* next)
        {
            this -> element = element;
            this -> next = next;
        }

        ~SinglyLinkedItem()
        {
            delete element;
        }
};
