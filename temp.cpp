#include <iostream>
using namespace std;
class stack
{
    public:
    char * arr;
    int size, top;

    stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }
    void push(int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack Overflow!!!"<<endl;
        }
    }
    void pop()
    {
        if(top>=0 && top<size)
        {
            cout<<arr[top]<<" has been poped up."<<endl;
            top--;
        }
        else
        {
            cout<<"Stack underflow"<<endl;
        }
    }
    int peek() //abcde-^fgh*+i
    {
        if(top>=0 && top<size)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack underflow!!"<<endl;
            return -1;
        }
    }
    bool isEmpty()//abcde-^fgh*+i-^*+
    {
        if(top==-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    
};
int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}
void infixTOpostfix(string s,int n)
{
    stack st(n);
    string result;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z')|| (c>='0' && c<='9'))
        {
            result+= c;
        }//abcde-^fgh*+i-^*+
        else if(c=='(')
        {
            st.push('(');
        }
        else if(c==')')
        {
            while(st.peek()!='(')
            {
                result+= st.peek();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.isEmpty()&& precedence(c)<=precedence(st.peek()))
            {
                if(c=='^' && st.peek()=='^')
                {
                    break;
                }
                else
                {
                    result += st.peek();
                    st.pop();
                }
               
            }
            st.push(c);
        }
    }
    while(!st.isEmpty())
    {
         result += st.peek();
        st.pop();
    }
    cout<<result<<endl;
}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    int n;
    n = exp.size();

    cout<<n<<endl;
    infixTOpostfix(exp,n);

    return 0;
}