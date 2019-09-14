#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector <int> seq;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    seq.push_back(N);

    while (N != 1) {
        if (N % 2) {
            N *= 3;
            N++;
        } else N /= 2;
        seq.push_back(N);
    }

    out << seq.size();

    return 0;
}
