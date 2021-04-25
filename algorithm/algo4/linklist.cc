

class MyLinkedList
{

public:
    struct linklist_t
    {
        int val;
        linklist_t *next;
        linklist_t(int _val) : val(_val), next(nullptr) {}
    };

private:
    linklist_t *dummy_head;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        dummy_head = new linklist_t(0);
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        linklist_t *p_node = dummy_head->next;
        while (index--)
        {
            p_node = p_node->next;
        }
        return p_node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {

        linklist_t *p_node = new linklist_t(val);
        p_node->next = dummy_head->next;
        dummy_head->next = p_node;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {

        linklist_t *p_node = dummy_head;
        while (p_node->next != nullptr)
        {
            p_node = p_node->next;
        }
        linklist_t *p_new_node = new linklist_t(val);
        p_node->next = p_new_node;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }

        linklist_t *p_node = dummy_head;
        while (index--)
        {
            p_node = p_node->next;
        }

        linklist_t *p_new_node = new linklist_t(val);
        p_new_node->next = p_node->next;
        p_node->next = p_new_node;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        linklist_t *p_node = dummy_head;
        while (index--)
        {
            p_node = p_node->next;
        }
        linklist_t *p_del_node = p_node->next;

        p_node->next = p_del_node->next;

        delete p_del_node;
        size--;
    }
};
