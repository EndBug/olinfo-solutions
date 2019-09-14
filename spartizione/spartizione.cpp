#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int G, P, T = 0, times = 1;
    in >> G >> P;
    P--;
    while (G > 0) {
        if (G >= times) T += times;
        else T += G;
        G -= times;
        G -= P;
        times++;
    }
    out << T;
    return 0;
}
