//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
          if(head->next==NULL)return head;
        vector<int> v;
        Node* a = head;
        while(a!=NULL)
        {
            v.push_back(a->data);
            a=a->next;
        }
        vector<int> st;
        for(int i=0;i<v.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                st.push_back(v[i]);
            }
        }
        
        Node* ans = new Node(st[0]);
        Node* b = ans;
        for(int i=1;i<st.size();i++)
        {
            b->next  = new Node(st[i]);
            b=b->next;
        }
        return ans;
        // yo
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends
