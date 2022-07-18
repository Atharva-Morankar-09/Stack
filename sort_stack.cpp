
#include<bits/stdc++.h>
using namespace std;

class Solution{
   public:
   void solve(stack<int>& st)
   {
        if(st.size()==1)
        {
            return ;
        }
        int temp=st.top();
        st.pop();
        solve(st);
        insert(st,temp);
   }

   void insert(stack<int>& st, int temp)
   {
       if(st.size()==0 || st.top()>=temp)
       {
          st.push(temp);
          return ;
       }
       int val=st.top();
       st.pop();
       insert(st,temp);
       st.push(val);
   }
};

int main()
{
    Solution obj;
    stack<int> st;
    int n,x;
    cout<<"Enter size of stack : ";
    cin>>n;
    cout<<"Enter the elements :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        st.push(x);
    }
    obj.solve(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
   return 0; 
}