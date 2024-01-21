#include <iostream>
#include <vector>
using namespace std;

struct tower
{
    vector<int> values;
    char name;
    tower(vector<int> values, char name)
    {
        this->values = values;
        this->name = name;
    }
};

void move(vector<int> &src, vector<int> &dest)
{
    dest.push_back(src[src.size() - 1]);
    src.pop_back();
}

void printTowers(vector<tower> towers)
{
    vector<int> A, B, C;
    for (tower t : towers)
    {
        if (t.name == 'A')
        {
            A = t.values;
        }
        if (t.name == 'B')
        {
            B = t.values;
        }
        if (t.name == 'C')
        {
            C = t.values;
        }
    }
    int largest = C.size();
    if (A.size() > C.size() && A.size() > B.size())
    {
        largest = A.size();
    }
    else if (B.size() > C.size() && B.size() > A.size())
    {
        largest = B.size();
    }

    cout << "------" << endl;
    for (int i = largest; i > 0; i--)
    {
        for (vector<int> t : {A, B, C})
        {
            if (t.size() >= i)
            {
                cout << t[i-1] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "A B C" << endl;
    cout << "------" << endl;
}

void hanoi(tower &src, tower &dest, tower &pivot, int n)
{
    if (n == 0)
    {
        return;
    }
    hanoi(src, pivot, dest, n - 1);
    move(src.values, dest.values);
    printTowers({src, dest, pivot});
    hanoi(pivot, dest, src, n - 1);
}

int main()
{
    int n = 5;
    vector<int> initValues = {};
    for (int i = n; i > 0; i--)
    {
        initValues.push_back(i);
    }
    tower towerA = tower(initValues, 'A');
    tower towerB = tower({}, 'B');
    tower towerC = tower({}, 'C');
    hanoi(towerA, towerC, towerB, n);
}
