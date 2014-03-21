#include <iostream>
using namespace std;

int temp[1010];
int n;

int main()
{
    int first = 1;
    while (cin>>n && n) {
        int i, j;
        for (i = 0; i < n; i++)
            cin >> temp[i];

        if (!first) cout << endl;
        first = 0;
        for (i = 3; i < n; i++) {
            int sum = 0;
            for (j = 0; j < 4; j++)
                sum += temp[i-j];
            cout << sum / 4 << endl;
        }
    }
    return 0;
}

