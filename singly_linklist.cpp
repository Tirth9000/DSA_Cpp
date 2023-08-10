#include <iostream>
using namespace std;

class Node
{
private:
    int data;

public:
    Node *next;

    Node() {}
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    friend class Linklist;
};

class Linklist
{
public:
//to insert at head
    void insertAtHead(Node *&head, int a)
    {
        if (head == NULL)
        {
            Node *newnode = new Node(a);
            head = newnode;
        }
        else
        {
            Node *newnode = new Node(a);
            newnode->next = head;
            head = newnode;
        }
    }

//to insert at tail
    void insertAtLast(Node *&head, int data)
    {
        if (head == NULL)
        {
            Node *newnode = new Node(data);
            head = newnode;
        }
        else
        {
            Node *ptr = head;

            Node *newnode = new Node(data);
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = newnode;
            newnode->next = NULL;
        }
    }

//to insert at any position
    void insertAtPosition(Node* &head, int pos, int data)
    {
        Node *newnode = new Node(data);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *ptr = head;

            for (int i = 0; i < pos - 2; i++)
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "Error: you don't have enough elements in the list." << endl;
            }
            else if (ptr->next == NULL)
            {
                cout << "Error: you are at last node in the list." << endl;
            }
            else
            {
                newnode->next = ptr->next;
                ptr->next = newnode;
            }
        }
    }

//to delete the node from the head
    void deleteFromHead(Node* &head)
    {
        Node* ptr = head->next;
        head->next = NULL;
        head = ptr;
    }

//delete the node from the tail
    void deleteFromTail(Node* head)
    {
        Node* ptr = head->next;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            head = head->next;
        }
        head->next = NULL;
    }

//delete the node from any position 
    void deleteFromPosition(Node* head, int pos)
    {
        Node* ptr = head->next;

        for(int i=0;i<pos-2;i++)
        {
            ptr = ptr->next;
            head = head->next;
        }
        head->next = ptr->next;
        ptr->next = NULL;
    }

//display the list
    void display(Node *head)
    {
        cout << "The LinkedLists elements are:" << endl;
        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "X" << endl;
    }
};

int main()
{
    Linklist l1;

    Node *head = NULL;

    l1.insertAtHead(head, 5);
    l1.insertAtHead(head, 9);
    l1.insertAtHead(head, 8);
    l1.insertAtHead(head, 6);
    l1.insertAtHead(head, 4);
    l1.display(head);

    l1.insertAtLast(head, 12);
    l1.insertAtLast(head, 14);
    l1.insertAtLast(head, 17);
    l1.insertAtLast(head, 15);
    l1.display(head);

    l1.insertAtPosition(head, 3, 87);
    l1.display(head);

    l1.deleteFromPosition(head,3);
    l1.deleteFromHead(head);
    l1.deleteFromTail(head);
    l1.display(head);
}