
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    
    void rec(stack<int>& st, int n)
    {
        if(n==1)
        {
            st.pop();
            return ;
        }
        int val=st.top();
        st.pop();
        n-=1;
        rec(st,n);
        st.push(val);
      
    }

    void solve(stack<int>& st)
    {
        if(st.size()==0)
        {
            return ;
        }
        int n=st.size()/2+1;
        rec(st,n);        
    }

};

int main()
{
    Solution obj;
     
    stack<int> st;
    int n,x;
    cout<<"Enter size of stack : ";
    cin>>n;
    cout<<"Enter elements of stack :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        st.push(x);
    }
    obj.solve(st);
    cout<<"Stack after removing middle element : ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
   return 0; 
}
