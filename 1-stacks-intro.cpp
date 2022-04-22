#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creation of stack
    // stack is LIFO data structure 
    // last in first out
    stack<int>s;

    //push operation
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout<<"Printing top element "<<s.top()<<endl; 
    if(s.empty())
    {
        cout<<"Stack is empty "<<endl;
    }
    else
    {
        cout<<"Stack is not empty "<<endl;
    }

    cout<<"Size of stack is "<<s.size()<<endl;
    return 0;
}