#include <iostream>
#include <fstream>

using namespace std;

long long int N, A, B;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    A = N/2;
    B = N - A;
    out << (A+1)*(B+1);
    return 0;
}
