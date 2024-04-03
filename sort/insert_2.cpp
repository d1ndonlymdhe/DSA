#include <iostream>
using namespace std;

void insertSort(int *list,int size){
    for(int i=1;i<=size-1;i++){
        int temp = list[i];
        int j = i-1;
        while(j>=0 && temp < list[j]){
            list[j+1] = list[j];
            j = j-1;
        }
    list[j+1] = temp;
        cout << "------" << endl;
        //list all
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << endl;
        }
        cout << "--------" << endl;
    }
}

int main()
{
    int list[] = {70, 80, 30, 10, 20, 5, 3, 100, 99, 50,-50};
    int arrSize = (sizeof list)/(sizeof(int));
    insertSort(list, arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        cout << list[i] << endl;
    }
}