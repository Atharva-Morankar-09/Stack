
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insert(stack<int> &st, int temp)
    {
        if (st.size() == 0)
        {
            st.push(temp);
            return;
        }
        int val = st.top();
        st.pop();
        insert(st, temp);
        st.push(val);
    }

    void reverse(stack<int> &st)
    {
        if (st.size() == 1)
        {
            return;
        }
        int temp = st.top();
        st.pop();
        reverse(st);
        insert(st, temp);
    }
};

int main()
{
    Solution obj;
    stack<int> st;
    int n, x;
    cout << "Enter size of stack : ";
    cin >> n;
    cout << "Enter elements of stack : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.push(x);
    }
    stack<int> sc = st;
    cout << "Orignal Stack : ";
    while (!sc.empty())
    {
        cout << sc.top() << " ";
        sc.pop();
    }
    obj.reverse(st);
    cout << "\nReversed stack is : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}