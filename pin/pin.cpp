#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int N, K;

map <string, int> pins;
pair <string, int> best;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N >> K;
    best.second = 0;
    char D[N];
    for (int i = 0; i < N; i++) in >> D[i];

    for (int i = 0; i < N-K+1; i++) {
        string p;
        for (int j = 0; j < K; j++) p.push_back(D[i+j]);

        if (pins[p]) pins[p]++;
        else pins[p] = 1;
    }

    map<string,int>::iterator it;
    for (it = pins.begin(); it != pins.end(); it++) {
        if (it->second > best.second) {
            best.first = it->first;
            best.second = it->second;
        }
    }

    for (int i = 0; i < K; i++) {
        out << best.first[i];
        if (i < K-1) out << " ";
    }
}