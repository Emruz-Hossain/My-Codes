#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    vector<int> places;
    for (int i = 51; i <= 500; i++)
        places.push_back(i);
    shuffle(places.begin(), places.end());

    cout << "T-Shirt Random Winners:";
    for (int i = 0; i < 50; i++)
        cout << " " << places[i]<<endl;
    cout << endl;
}
