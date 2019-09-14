#include <iostream>
#include <fstream>
#include <vector>

#define MAXR 2000
using namespace std;

int N, R = MAXR;
vector <int> V, P;

void solve(int rem, vector <int> rv, int cost) {
    for (int i = 0; i < rv.size(); i++) {
        vector <int> tv = rv;
        int current = tv[rv.size()-1-i], trem = rem - current, tcost = cost;
        if (current == 2) tcost += P[0]; else if (current == 4) tcost += P[1]; else if (current == 5) tcost += P[2]; else tcost += P[3];
        for (int j = 0; j < i+1; j++) tv.pop_back();
        solve(trem, tv, tcost);
    }
    if (rem <= 0 && R > cost) R = cost;
}

int main()
{
    //init
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for (int i = 0; i < 4; i++) {
        int c, d, p;
        if (i == 0) c = 2; else if (i == 1) c = 4; else if (i == 2) c = 5; else if (i == 3) c = 7;
        in >> d;
        for (int j = 0; j < d; j++) V.push_back(c);
        in >> p;
        P.push_back(p);
    }
    solve(N, V, 0);

    out << R;
    return 0;
}
