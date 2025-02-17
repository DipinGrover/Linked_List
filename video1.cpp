#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convert_array_to_ll(vector<int> &arr)
{
    Node* head = new Node(arr[0]); // head is the first node of LL
    // head points to 0th index element of array
    Node* mover = head; // mover points to head

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]); // temp points from arr[1] to all elements of array
        mover->next = temp; // mover next is temp
        mover = temp; // move the mover
    }
    return head; // return head of LL
}

void traversal_in_ll(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int length_of_ll(Node* head)
{
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

bool is_this_element_present(Node* head , int value)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> arr = {13,4,7,1,3,5};

    // Node* y = new Node(arr[2]);

    // cout << y->data;




    // for converting array to LL
    Node* head = convert_array_to_ll(arr);
    // cout << head->data;







    // function for traversal in LL
    // traversal_in_ll(head);







    // // function to print length of LL
    // int length = length_of_ll(head);
    // cout << length << " "; // printing extra space at last







    // search an element in LL
    bool is_present = is_this_element_present(head , 1);

    cout << is_present << " ";
    
}