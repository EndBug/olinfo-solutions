#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, diff = 0;
vector <int> Q;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        in >> temp;
        Q.push_back(temp);
    }

    for (int i = 0; i < N-1; i++) {
        int current = abs(Q[i] - Q[i+1]);
        if (current > diff) diff = current;
    }
    out << diff;

    return 0;
}
