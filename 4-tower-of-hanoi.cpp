#include<iostream>
using namespace std;
void towerOfHanoi(int n,char from,char to,char aux)
{
    if(n==0)
    {
        return ;
    }
    towerOfHanoi(n-1,from,aux,to);
    cout<<"Move disc "<<n<<" from "<<from<< " to "<<to<<endl;

    towerOfHanoi(n-1,aux,to,from);
}
int main(){
int n = 4;

towerOfHanoi(n,'A','C','B');
return 0;
}