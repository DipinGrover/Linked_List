#include <iostream>
#include <vector>
using namespace std;
// change 1
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

int main()
{
    vector<int> arr = {2,5,1,7,4};

    Node* head = array_to_dll(arr);

    traversal_in_dll(head);
}