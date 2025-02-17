Node* delete_kth_node(Node* head , int k)
{
    if(head == NULL)
    {
        // empty LL
        return head;
    }
    if(k==1)
    {
        // delete head of LL
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* back = NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) // traversal
    {
        cnt++;
        if(cnt == k)
        {
            // delete this temp node
            back->next = back->next->next;
            delete temp;
            break;
        }
        back = temp;
        temp = temp->next;
    }
    return head;
}