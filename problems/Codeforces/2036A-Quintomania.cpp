#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> notes(n, 0);
        for (int i = 0; i < n; i++)
            cin >> notes[i];

        bool perfect = true;

        for (int i = 1; i < n; i++)
        {
            if (abs(notes[i] - notes[i - 1]) != 5 && abs(notes[i] - notes[i - 1]) != 7)
            {
                perfect = false;
                break;
            }
        }

        if (!perfect)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}