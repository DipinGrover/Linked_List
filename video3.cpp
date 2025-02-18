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

int main()
{
    vector<int> arr = {2,5,1,7,4};

    Node* head = array_to_dll(arr);

    traversal_in_dll(head);

    // // deletion of head in dll
    // head = delete_head_of_dll(head);
    // cout << endl;
    // traversal_in_dll(head);









    // deletion of tail in dll
    head = delete_tail_of_dll(head);
    cout << endl;
    traversal_in_dll(head);
}