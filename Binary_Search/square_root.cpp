#include<iostream>
using namespace std;

float squareRoot(float n, int p){
    float root=0;
    int s=0;
    int e=n;
    int m=-1;

    /* finding the part before decimal */
    while(s<=e){
        m=(s+e)>>1;
        if(m*m == n){
            return m;
        }else if(m*m > n){
                e=m-1;
        }else {
            root=m;
            s=m+1;
        }
    }

    /* finding parts after decimal*/
    float j=0.1;
    float i=j;
    while(p>0){
       
        while( (root+i)*(root+i) <= n){
            root = root + i;
            i = i + j;  
        }
        j=j/10;
        i=j;
        p--;
    }

    return root;
}

int main(){

    int n,p;
    cin>>n;
    cin>>p;
    float res = squareRoot(n,p);
    cout<<"Result = "<<res<<endl;
}