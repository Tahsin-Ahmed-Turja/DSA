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
        if (size != capacity){
            a[++tos] = x;
            size++;
        }
    }

    char pop()
    {
        if (!isempty())
        {
            size--;
            return a[tos--];
        }
        
    }

    char top()
    {   
        if(!isempty())
            return a[tos];
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


int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void infixToPostfix(string s)
{

	mystack st = mystack(10000);
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.isempty()
				&& prec(c) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.isempty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

int main()
{
	string exp;
    cin >> exp;
	infixToPostfix(exp);
	return 0;
}
