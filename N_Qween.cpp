#include <bits\stdc++.h>

int a[50],counter = 0;

using namespace std;

int place(int pos){
    int i;
    for (i = 1; i < pos; i++){
        if((a[i]==a[pos])||((abs(a[i] - a[pos])==abs(i-pos))))
            return 0;
    }
    return 1;
    
}

void print_sol(int n){
    int i,j;
    counter ++;
    cout<<"\n\nSoluton #"<<counter<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==j){
                cout<<"Q\t";
            }
            else{
                cout<<"*\t";
            }
        }
        cout<<"\n";
    }
    
}

void queen(int n){
    int k = 1;
    a[k] = 0;
    while (k!=0){
        do{
            a[k]++;
        }while ((a[k]<=n) &&! place(k));
        if(a[k]<=n){
            if(k==n)
                print_sol(n);
            else{
                k++;
                a[k]=0;
            }
        }
        else
            k--;
        
    }
     
}

int main(){
    int n;
    cout<<"Enter the number of Queen's :\t";
    cin>>n;
    queen(n);
    cout<<"\nTotal solution "<< counter;
}