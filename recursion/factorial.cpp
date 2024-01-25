#include<iostream>
using namespace std;

int factorial(unsigned int num){
    if(num == 0){
        return 1;
    }
    return num*factorial(num-1);
}

int main(){
    int x = 5;
    cout << factorial(x) << endl;
}