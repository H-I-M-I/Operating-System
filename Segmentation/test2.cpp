#include <bits/stdc++.h>
#define max 10000
using namespace std;

int base[max], limit[max];

struct Point
{
    int p, bd, lm;
} point[max];

int main()
{
    char ch;
    int n, i, j, ix, s, v, k;
    int limit[10000];

    cout << "Enter number of segments: "<< " ";
    cout << endl;
    cin >> n;
    cout << endl;
    printf("Enter Base Address && Base Address Limit: ");
    for (i = 0; i < n; i++)
    {
        cin >> base[i] >> limit[i];
        point[i].p = i;
        point[i].bd = base[i];
        point[i].lm = limit[i];
    }

    cout << endl;
    cout << "SEGMENT TABLE:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cout << "Segment no: " << point[i].p << " :--| " << point[i].bd << " <____> " << point[i].bd + point[i].lm << " |" << endl;
            cout << endl;
        }
    }

    cout << "Enter Segment no && Offset : " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> s >> v;
        k = base[s];

        if (v > limit[s])
            cout << "Trapped! Excess Of Limit" << endl;

        else
            cout << "Physical Address is: " << k + v << endl;
    }

    return 0;
}