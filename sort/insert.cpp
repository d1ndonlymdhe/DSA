#include <iostream>
#include <vector>
using namespace std;

void insertSort(int *list, int size)
{
    if (size < 1)
    {
        return;
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[j] > list[i])
            {
                int small = list[i];
                for (int k = i; k > j; k--)
                {
                    list[k] = list[k - 1];
                }
                list[j] = small;
            }
        }
    }
    return;
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