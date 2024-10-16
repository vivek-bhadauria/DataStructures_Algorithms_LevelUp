#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isBalanced(string s){
    stack<char> stk;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            stk.push(s[i]);
        }else{
            if(stk.empty()){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

void printBracketsNaive(int n, string &s){
    if(n==0){
        if(isBalanced(s)){
            cout<<s<<endl;
        }
        return;
    }

    /* pick '(' */
    s.push_back('(');
    printBracketsNaive(n-1,s);
    s.pop_back();

    /* pick ')' */
    s.push_back(')');
    printBracketsNaive(n-1,s);
    s.pop_back();
}

void printBracketsRefined(int totalOpen, int totalClose, int open, int close, string s){

    if(totalOpen==0 and totalClose == 0 and open == close){
        cout<<s<<endl;
        return;
    }

   
    /* pick '(' */
    if(totalOpen > 0){
        s.push_back('(');
        printBracketsRefined(totalOpen-1, totalClose, open+1, close, s);
        s.pop_back();
    }

    /* pick ')' */
    if(totalClose > 0 and close<open){
        s.push_back(')');
        printBracketsRefined(totalOpen, totalClose-1, open, close+1, s);
        s.pop_back();
    }
}

int main(){
    int n;
    string s;
    cin>>n;
    printBracketsRefined(n,n,0,0,s);
}