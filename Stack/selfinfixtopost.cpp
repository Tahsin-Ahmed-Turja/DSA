#include <bits/stdc++.h>
using namespace std;

class mystack
{
public:
    char *a;
    int size;
    int capacity;
    int tos;

    mystack(int cap)
    {
        a = new char[cap];
        capacity = cap;
        tos = -1;
        size = 0;
    }

    void push(char x)
    {
        if (size != capacity)
        {
            a[++tos] = x;
            size++;
        }
    }

    char pop()
    {
        if(!isempty()){
            size--;
            return a[tos--];
        }
    }

    char top()
    {
        if(!isempty()){
            return a[tos];
        }
    }

    bool isempty()
    {
        return size == 0;
    }
    bool isfull()
    {
        return size == capacity;
    }
    int getsize()
    {
        return size;
    }
};

int p(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

string infixtopost(string s)
{
    mystack st = mystack(10000);
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') && (s[i] >= '0' && s[i] <= '9'))
        {
            result += s[i];
        }
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            int v = p(s[i]);
            if (v == 0)
                continue;
            while (!st.isempty() && p(st.top()) >= v)
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.isempty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    string ans = infixtopost(s);
    cout << ans << endl;
}
