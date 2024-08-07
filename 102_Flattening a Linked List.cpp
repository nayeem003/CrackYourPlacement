//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* l1, Node* l2)
    {
        Node* d1=new Node(-1);
        Node* res=d1;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->data>l2->data)
            {
                d1->bottom=l2;
                l2=l2->bottom;
            }
            else{
                d1->bottom=l1;
                l1=l1->bottom;
            }
            d1->next=NULL;
            d1=d1->bottom;
        }
        if(l1!=NULL)
        {
            d1->bottom=l1;
        }
        if(l2!=NULL)
        {
            d1->bottom=l2;
        }
        return res->bottom;
    }
    Node* mergehead(Node* node)
    {
        if(node==NULL or node->next==NULL)
        {
            return node;
        }
        Node* h=mergehead(node->next);
        return merge(node,h);
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        return mergehead(root);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends
