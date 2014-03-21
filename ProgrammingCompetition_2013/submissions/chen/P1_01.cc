#include <iostream>
using namespace std;

int temp[1010];
int n;

int main()
{
    while (cin>>n && n) {
        int i, j;
        for (i = 0; i < n; i++)
            cin >> temp[i];

        for (i = 3; i < n; i++) {
            int sum = 0;
            for (j = 0; j < 4; j++)
                sum += temp[i-j];
            cout << sum / 4 << endl;
        }

        cout << endl;
    }
    return 0;
}

