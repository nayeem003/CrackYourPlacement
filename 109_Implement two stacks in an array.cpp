//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends



class twoStacks
{
    public:
        int i;
        int j;
        int *arr;
        
        twoStacks(){
            i=-1;
            j=99;
            arr=new int[200];
        }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        i++;
        arr[i]=x;
        return;    
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       j++;
       arr[j]=x;
       return;    
        
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(i==-1)
            return(-1);
        return(arr[i--]);
        
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(j==99)
        return(-1);
       return(arr[j--]);    
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends
