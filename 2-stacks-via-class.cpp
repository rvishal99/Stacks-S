#include <iostream>
using namespace std;
class stack
{
    // properties
public:
    int *arr, top, size; // here top is index of top element in stack

    // behaviour
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
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
        if (top >= 0)
        {
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
};

int main()
{
    stack st(5); // here 5 is size of the stack
    st.push(22);
    st.push(42);
    st.push(62);
    st.push(100);
    // st.push(200); it will cause stack overflow
    cout << "Top of st is " << st.peek() << endl;

    st.pop();
    cout << "Top of st is " << st.peek() << endl;
    st.pop();
    cout << "Top of st is " << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is empty " << endl;
    }
    else
    {
        cout << "Stack is not empty " << endl;
    }
    return 0;
}