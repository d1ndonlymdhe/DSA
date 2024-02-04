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

void shell(int *arr, int size, int h)
{
    if (h == 1)
    {
        insertSort(arr, size);
        return;
    }
    for (int i = 0; i < size / h; i++)
    {
        int c = 0;
        int *sublist = (int*)calloc(h,sizeof(int));
        for (int j = i; j < size; j += h)
        {
            sublist[c] = arr[j];
            c++;
        }
        insertSort(sublist, c);
        c = 0;
        for (int j = i; j < size; j += h)
        {
            arr[j] = sublist[c];
            c++;
        }
    }
    shell(arr, size, h / 2);
}

int main()
{
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    int arrSize = sizeof arr / sizeof(int);
    shell(arr, arrSize, 4);
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}