#include<iostream>
using namespace std;

long long multiplyModulo(int a, int b, long p){
    return ((a%p)*(b%p))%p;
}

long long int powerModulo(int a, int b){
    long p = 1000000007;
    if(b==0){
        return 1;
    }
    long long x = powerModulo(a,b/2) % p;
    long long res = multiplyModulo(x,x,p);
    if(b&1){
        return multiplyModulo(a,res,p);
    }
    return res%p;
}

int main(){

    int a,b;
    cin>>a;
    cin>>b;
    long long res = powerModulo(a,b);
    cout<<"Result = "<<res<<endl;
}