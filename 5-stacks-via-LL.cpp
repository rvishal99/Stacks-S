#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node * next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
node * top = NULL;
bool isEmpty()
{
    if(top==NULL)
    {
        return true;
    }
    else{
        return false;
    }
}
void push(int d)
{
    node * ptr = new node(d);
    ptr->next = top;
    top = ptr;
}
void pop()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty" <<endl;
    }
    else{
        cout<<"The popped element is: "<<top->data<<endl;
        
        top = top->next;

    }
}
void lltraversal()
{
    node * ptr = top;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }cout<<endl;
}
int main(){
    push(1);
    push(2);
    push(3);

    pop();

return 0;
}