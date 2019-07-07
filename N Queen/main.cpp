//
//  main.cpp
//  N Queen
//
//  Created by wbb on 2018/5/14.
//  Copyright © 2018年 Wangh7. All rights reserved.
//

#include <iostream>
//#define MAX 500
using namespace std;

class Queen{
    friend int N_Queen(int);
private:
    bool Place(int k);
    void Backtrack(int t);
    int n,*x;
    int sum;
};

bool Queen::Place(int k){
    for(int j=1;j<k;j++)
        if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
            return false;
    return true;
}

void Queen::Backtrack(int t){
    if(t>n)
        sum++;
    else
        for(int i=1;i<=n;i++){
            x[t]=i;
            if(Place(t))
                Backtrack(t+1);
        }
}

int N_Queen(int n){
    Queen N;
    N.n=n;
    N.sum=0;
    int *p=new int [n+1];
    for(int i=0;i<=n;i++)
        p[i]=0;
    N.x=p;
    N.Backtrack(1);
    delete []p;
    return N.sum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=N_Queen(a[i]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}
