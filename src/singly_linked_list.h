#include "list.h"
#include "singly_linked_item.h"

template <typename T>
class SinglyLinkedList : public List<T>
{
    private:
        SinglyLinkedItem<T> head;
        SinglyLinkedItem<T>* last;
        int current_size;

    public:
        SinglyLinkedList()
        {
            SinglyLinkedItem<T> new_element(nullptr, nullptr);
            head = new_element;
            last = &head;
            current_size = 0;
        }

        ~SinglyLinkedList()
        {
            clear();
        }

        T get(int index)
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                if (count == index) {
                    return (current->data);
                }
                count++;
                current = current->next;
            }
        }

        bool add_all(Collection<T> elements);

        int binary_search(T key);

        void copy(Collection<T> destination);

        bool is_disjoint_with(Collection<T> other)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                if (other.contains(current -> element)) {
                    return false;
                }
                current = current -> next;
            }
            return true;
        }

        void fill(T element)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                current -> element = element;
                current = current->next;
            }
        }

        int frequency(T element)
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                if (current -> element == element) {
                    count++;
                }
                current = current->next;
            }
            return count;
        }

        void replace_all(T old_value, T new_value)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                if (current -> element == old_value) {
                    current -> element = new_value;
                }
                current = current->next;
            }
        }

        void set(T element, int index)
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                if (count == index) {
                    current -> element = element;
                }
                count++;
                current = current->next;
            }
        }

        void insert(T element, int index)
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                if (count == index - 1) {
                    SinglyLinkedItem<T> item(element, nullptr);
                    SinglyLinkedItem<T> old = current -> next;
                    current -> next = item;
                    item -> next = old;
                    if (index == current_size - 1) {
                        last = &item;
                    }
                    current_size++;
                    return;
                }
                count++;
                current = current -> next;
            }
        }

        void remove(int index)
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                if (count == index - 1) {
                    SinglyLinkedItem<T>* successor = current -> next;
                    current -> next = successor -> next;
                    delete(successor);
                    return;
                }
                count++;
                current = current -> next;
            }
        }

        void remove(T element)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                SinglyLinkedItem<T>* successor = current -> next;
                if (successor == nullptr) {
                    return;
                }
                if (successor -> element == element) {
                    current -> next = successor -> next;
                    if (successor -> next == nullptr) {
                        last = &(current -> next);
                    }
                    delete(successor);
                    return;
                }
                current = current -> next;
            }
        }

        void remove_all(T element)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                SinglyLinkedItem<T>* successor = current -> next;
                if (successor == nullptr) {
                    return;
                }
                if (successor -> element == element) {
                    current -> next = successor -> next;
                    if (successor -> next == nullptr) {
                        last = &(current -> next);
                    }
                    delete(successor);
                }
                current = current -> next;
            }
        }

        void push_back(T element)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                if (current -> next == nullptr) {
                    SinglyLinkedItem<T> new_element(element, nullptr);
                    current -> next = new_element;
                    last = &new_element;
                }
                current = current -> next;
            }
        }

        T pop_back()
        {
            SinglyLinkedItem<T>* current = head;
            if (current == last) {
                delete(current);
                head = nullptr;
                last = nullptr;
                return last;
            }
            while (current != nullptr) {
                if (current -> next == last) {
                    T temp = current -> next;
                    last = current;
                    return temp;
                }
                current = current -> next;
            }
        }

        void push_front(T element)
        {
            SinglyLinkedItem<T> new_element(element, head);
            head = element;
        }

        T pop_front()
        {
            SinglyLinkedItem<T>* temp = head;
            T element = temp -> element;
            head = temp -> next;
            delete(temp);
            return element;
        }

        void clear()
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                SinglyLinkedItem<T>* old = current;
                current = current -> next;
                delete(old);
            }
        }

        bool contains(T element)
        {
            SinglyLinkedItem<T>* current = head;
            while (current != nullptr) {
                if (current -> element == element) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }

        int index_of(T element)
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                if (current -> element == element) {
                    return count;
                }
                count++;
                current = current->next;
            }
        }

        int size()
        {
            SinglyLinkedItem<T>* current = head;
            int count = 0;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }

        void swap(int i, int j);
};
