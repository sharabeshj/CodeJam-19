#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;

#define MAX_SIZE 1000

int T, N, L;
int A[MAX_SIZE], O[MAX_SIZE];
map<int,char> Alphabets;


int HCF(int a, int b){
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return HCF(a-b, b); 
    return HCF(a, b-a); 
}

string solve(){
    int hcf = 0, k = 0, n, l = MAX_SIZE;
    char initial = 'A';
    string OUTPUT;
    map<int, char>::iterator itr;
    for(int i=0;i<L-1;i++){
        hcf = HCF(A[i], A[i+1]);
        O[k++] = A[i]/hcf;
        O[k++] = hcf;
        O[k++] = A[i+1]/hcf;
    }
    n = sizeof(O)/sizeof(O[0]);

    sort(O, O+n);

    for(int j=0;j<L+1;j++, initial++){
        if(O[j] != l){
            Alphabets.insert(pair<int, char>(O[j], initial));
            l = O[j];
        }
    }

    for(int j = 0;j < L+1;j++){
        OUTPUT[j] = Alphabets.find(O[j])->second;
    }
    
    return OUTPUT;
}

int main(){
    string O;
    cin>>T;
    for(int k=0,i=0;k<T;k++){
        cin>>N>>L;
        
        while(i<L && scanf("%d",&A[i++]) == 1);
        
        cout<<solve();
    }
    
    return 0;
}