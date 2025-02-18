#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1 , Node* next1 , Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* array_to_dll(vector<int> & arr)
{
    Node* head = new Node(arr[0]);

    Node* temp = head;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* front = new Node(arr[i]);

        temp->next = front;

        front -> prev = temp;

        temp = front;
    }

    return head;
}

void traversal_in_dll(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp -> next;
    }

}

Node* delete_head_of_dll(Node* head)
{
    if(head == NULL)
    {
        // empty LL
        return NULL;
    }

    if(head->next == NULL)
    {
        // single element LL
        delete head;

        return NULL;
    }

    Node* temp = head;

    temp = temp->next;

    temp->prev = nullptr;

    head->next = nullptr;

    delete(head);

    return temp;
}

Node* delete_tail_of_dll(Node* head)
{
    if(head == NULL)
    {
        // empty LL
        return NULL;
    }
    else if(head->next == NULL)
    {
        // single node Linked List head will be tail
        delete head;
        return NULL;
    }
    Node* temp = head;

    while(temp->next->next != NULL)
    {
        // move
        temp = temp->next;
    }

    Node* next_one = temp->next;

    temp->next = nullptr;

    next_one->prev = nullptr;

    delete next_one;

    return head;
}

Node* delete_kth_node(Node* head , int k)
{
    if(head == NULL)
    {
        // empty ll
        return NULL;
    }

    if(head->next == NULL)
    {
        // single node ll
        if(k==1)
        {
            delete head;
            return NULL;
        }
        else
        {
            return NULL; // only one node is there but we want to delete 3or 4th node maybe 
        }
    }
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        // for traversal

        cnt ++;

        if(cnt == k)
        {
            if(temp->prev == NULL)
            {
                return delete_head_of_dll(head);
            }
            if(temp->next == NULL)
            {
                return delete_tail_of_dll(head);
            }
            else{
                Node* back_node = temp->prev;
                Node* next_node = temp->next;
                temp->next = nullptr;
                temp->prev = nullptr;
                back_node->next = next_node;
                next_node->prev = back_node;
                break;
            }
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2,7,1,3,5};

    Node* head = array_to_dll(arr);

    traversal_in_dll(head);

    // // deletion of head in dll
    // head = delete_head_of_dll(head);
    // cout << endl;
    // traversal_in_dll(head);









    // // deletion of tail in dll
    // head = delete_tail_of_dll(head);
    // cout << endl;
    // traversal_in_dll(head);









    // delete kth node
    head = delete_kth_node(head , 5);
    cout << endl;
    traversal_in_dll(head);
}