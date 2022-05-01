/* C++ implementation to convert
infix expression to postfix*/

#include <iostream>
#include <string.h>
using namespace std;
class stack
{
    // properties
public:
    char * arr; 
    int top, size; // here top is index of top element in stack

    // behaviour
    stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }
    void push(int element)
    {
        // checking space availabilty
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow " << endl;
        }
    }
    void pop()
    {
        if (top >= 0&& top<size)
        {
            cout << arr[top] << " has been poped up." << endl;
            top--;
        }
        else
        {
            cout << "Stack Underflow " << endl;
        }
    }
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty " << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Function to return precedence of operators
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

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s,int n)
{

    // For stack operations, we are using
                    // C++ built in stack
    stack st(n);
    
    string result;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');
              

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.peek() != '(')
            {
                result += st.peek();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.isEmpty() && prec(s[i]) <= prec(st.peek()))
            {
                if (c == '^' && st.peek() == '^')
                    break;
                else
                {
                    result += st.peek();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.isEmpty())
    {
        result += st.peek();
        st.pop();
    }

    cout << result << endl;
}

// Driver program to test above functions
int main()
{

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    int n;
    n = exp.size();

    cout<<n<<endl;
    infixToPostfix(exp,n);
    return 0;
}
