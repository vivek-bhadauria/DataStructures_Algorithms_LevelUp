#include<iostream>
using namespace std;

/*intuition: problem turns to count number of bits in n*/
int earthLevel(int n)
{
    int c=0;
    while(n!=0){
        cout<<n<<"<--";
        c++;
        n=n&(n-1);
    }
    cout<<n<<endl;
    return c;
}

int main(){

    int n;
    cin>>n;
    int res = earthLevel(n);
    cout<<"Result = "<<res<<endl;
}