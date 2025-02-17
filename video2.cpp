#include <iostream>
#include <vector>
using namespace std;

class Node
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

Node* array_to_LL(vector<int> & arr)
{
    Node* head = new Node(arr[0]);

    Node* mover = head;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);

        mover->next = temp;

        mover = temp;
    }

    return head;

}

void traversal_in_LL(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int count_nodes_in_LL(Node* head)
{
    Node* temp = head;

    int count = 0;

    while(temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    return count;
}

Node* delete_head_of_LL(Node* head)
{
    if(head == NULL)
    {
        // empty LL
        return head;
    }
    if(head->next == nullptr)
    {
        // single node
        delete head;

        return NULL;
    }
    Node* temp = head;

    head = head->next;

    delete temp;

    return head;

}

Node* delete_tail_of_LL(Node* head)
{
    if(head == NULL)
    {
        // empty LL
        return head;
    }
    if(head->next == NULL)
    {
        delete head;
        return NULL; // a single node that would be head and tail
    }
    Node* temp = head;

    while(temp -> next -> next != NULL)
    {
        // move
        temp = temp->next;
    }

    delete temp->next;

    temp->next = nullptr;

    return head;

    
}

Node* delete_kth_node(Node* head , int k)
{
    // if empty LL
    if(head == NULL)
    {
        return NULL;
    }
    // if k ==1 it means we have to delete head of LL
    if(k==1)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        return head;
    }

    // for rest of cases when we want to delete middle or last node 
    Node* back = nullptr;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) // traversal
    {
        cnt++;
        if(cnt == k)
        {
            back->next = back->next->next;
            delete temp;
            break;
        }
        back = temp;
        temp = temp->next;
    }
    return head;
    
}

Node* delete_given_value_node(Node* head , int value)
{
    if(head == NULL)
    {
        // empty LL
        return NULL;
    }
    if(head->data == value)
    {
        // delete the head node 
        return delete_head_of_LL(head);
    }
    Node* temp = head;
    Node* back = nullptr;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            back->next = temp->next;

            delete temp;

            break;
        }
        back = temp;
        temp = temp->next;
    }
    return head;
}

Node* insert_at_head(Node* head , int element)
{
    if(head == NULL)
    {
        // empty ll
        Node* temp = new Node(element);
        return temp;
    }
    Node* temp = new Node(element , head);

    return temp; // new head
}

Node* insert_at_tail(Node* head , int element)
{
    if(head == NULL)
    {
        Node* temp = new Node(element);
        return temp;
    }
    Node* temp = head;

    while(temp -> next != nullptr)
    {
        // move
        temp = temp->next;
    }

    Node* new_node = new Node(element);
    temp->next = new_node;
    return head;
}

Node* insert_at_kth_position(Node* head , int value , int k)
{
    if(head == NULL)
    {
        // empty LL
        if(k==1)
        {
            Node* temp = new Node(value);
            return temp;
        }
        else
        {
            return NULL; 
        }
    }
    if(k == 1)
    {
        // insert at head
        Node* temp = new Node(value , head);
        return temp; // new head 
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        // for traversal
        cnt++;
        if(cnt == k-1)
        {
            Node* new_node = new Node(value);
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insert_before_given_value_node(Node* head , int value , int node_val)
{
    if(head == NULL)
    {
        // empty LL
        // cannot insert before some node with given value
        return NULL;
    }
    if(head->data == node_val)
    {
        // insert before head

        Node* new_one = new Node(value);

        new_one -> next = head;

        return new_one;
    }
    Node* back = nullptr;
    Node* temp = head;
    while(temp != NULL)
    {
        // traversal
        if(temp->data == node_val)
        {
            Node* new_one = new Node(value);
            back->next = new_one;
            new_one->next = temp;
            break;
        }
        back = temp;
        temp = temp->next;
    }
    return head;


}

int main()
{
    vector<int> arr = {7,1,3,5,2,4};

    Node* head = array_to_LL(arr);

    
    
    
    
    // // traversal in LL 
    // traversal_in_LL(head);









    // // count nodes in LL
    // int cnt = count_nodes_in_LL(head);
    // cout << cnt << " ";











    // // delete Head of LL
    // traversal_in_LL(head);
    // cout << endl;
    // head = delete_head_of_LL(head);
    // traversal_in_LL(head);










    // // delete tail of LL
    // traversal_in_LL(head);
    // cout << endl;
    // delete_tail_of_LL(head);
    // traversal_in_LL(head);









    // // delete kth node
    // traversal_in_LL(head);
    // cout << endl;
    // head = delete_kth_node(head , 4);
    // traversal_in_LL(head);









    // // delete kth node
    // traversal_in_LL(head);
    // cout << endl;
    // head = delete_given_value_node(head , 3);
    // traversal_in_LL(head);








    // // insert before head
    // traversal_in_LL(head);
    // cout << endl;
    // head = insert_at_head(head , 8);
    // traversal_in_LL(head);










    // // inserting node at last
    // traversal_in_LL(head);
    // cout << endl;
    // head = insert_at_tail(head , 8);
    // traversal_in_LL(head);









    // // inserting at kth position
    // traversal_in_LL(head);
    // cout << endl;
    // head = insert_at_kth_position(head , 8 , 4);
    // traversal_in_LL(head);









    // inserting before a given value node in a LL
    traversal_in_LL(head);
    cout << endl;
    head = insert_before_given_value_node(head , 8 , 5);
    traversal_in_LL(head);

}