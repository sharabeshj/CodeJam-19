#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000
int T;
int N[MAX_SIZE];

bool check(int a){
    while(a > 0){
        if(a%10 == 4){
            return false;
        }
        a = a/10;
    }
    return true;
}

void solve(int n,int c){
    int i=1,a,b;
    while(i){
        if(check(n-i)){
           a = n - i;
            b = i; 
            break;
        }
        i++;
    };

    cout<<"Case #"<<c<<": "<<a<<" "<<b<<"\n";
}

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N[i];
    }
    for(int i=0;i<T;i++) solve(N[i], i+1);
    return 0;
}