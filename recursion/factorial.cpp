#include<iostream>
using namespace std;

int fibo(unsigned int num){
    if(num == 0){
        return 1;
    }
    if(num == 1){
        return 1;
    }
    return num*fibo(num-1);
}

int main(){
    int x = 5;
    cout << fibo(x) << endl;
}