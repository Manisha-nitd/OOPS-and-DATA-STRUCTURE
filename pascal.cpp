#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int rows;
    cout << "Enter the number of rows : ";
    cin >> rows;
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        int val = 1;
        cout<<setw(2*rows-i);
        for (int k = 0; k <= i; k++)
        {
            cout << " " << val;
            val = val * (i - k) / (k + 1);
        }
        cout << endl << endl;
    }
    cout << endl;
    return 0;
}
