#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in >> N;
    //Fibonacci
    vector <int> F;
    int a = 0, b = 0, c = 1;
    for (int i = 0; c <= N; i++) {
        F.push_back(c);
        a = b;
        b = c;
        c = a + b;
    }

    //Sum
    int rem = N;
    vector <int> S;
    for (int i = F.size() - 1; i >= 0; i--) {
        if (rem >= F[i]) {
            S.push_back(F[i]);
            rem -= F[i];
        }
    }
    //Final String
    string s = "";
    for (int i = 0; i < F.size(); i++) {
        bool found = false;
        for (int j = 0; j < S.size(); j++) {
            if (F[i] == S[j]) {
                    found = true;
                    S[j] = 0;
                    break;
            }
        }
        if (found) s += "1";
        else s += "0";
    }
    while (s.back() == '0') s.pop_back();
    out << s;
    return 0;
}
