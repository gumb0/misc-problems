// https://code.google.com/codejam/contest/4314486/dashboard#s=p0

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T = 0;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int N = 0;
        cin >> N;

        vector<int> parties;
        copy_n(istream_iterator<int>(cin), N, back_inserter(parties));

        cout << "Case #" << (i + 1) << ": ";

        int max = *max_element(parties.begin(), parties.end());
        while (max > 0)
        {
            vector<int> maxElems;
            for (int i = 0; i < parties.size(); ++i)
            {
                if (parties[i] == max)
                    maxElems.push_back(i);
            }

            if (maxElems.size() % 2)
            {
                cout << static_cast<char>('A' + maxElems[0]) << ' ';
                --parties[maxElems[0]];
            }

            for (int i = maxElems.size() % 2 ? 1 : 0; i < maxElems.size(); i += 2)
            {
                cout << static_cast<char>('A' + maxElems[i]) << static_cast<char>('A' + maxElems[i + 1]) << ' ';
                --parties[maxElems[i]];
                --parties[maxElems[i + 1]];
            }

            max = *max_element(parties.begin(), parties.end());
        }

        cout << '\n';
    }

    return 0;
}

