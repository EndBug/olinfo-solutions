#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int A;
    in >> A;
    int P[A][A];
    for (int i = 0; i < A; i++) {
        for (int j = 0; j <= i; j++) in >> P[i][j];
    }

    //int index = 0, S = P[0][0];
    /*for (int i = 1; i < A; i++) {
        int left = 0, right = 0;
        for (int j = 0; j+i < A; j++) {
                left += P[j+i][index];
        }
        for (int j = 0; j+i < A; j++) {
                right += P[j+i][index+j+1];
        }
        if (left < right) index++;
        S += P[i][index];
    }*/

    /*for (int i = 1; i < A; i++) {
        int left = 0, right = 0;
        for (int k = i; k < A; k++) for (int j = index; j <= index + (k-i); j++) left += P[k][j];
        for (int k = i; k < A; k++) for (int j = index+1; j <= index+1 + (k-i); j++) right += P[k][j];
        cout << left << " - " << right << endl;
        if (right > left) index++;
        S += P[i][index];

    }*/

    int index = 0, S = 0;
    vector <vector <int>> paths;
    for (int i = A-1; i >= 0; i--) {
        vector <vector <int>> new_paths;
        if (paths.size() == 0) for (int j = 0; j <= i; j++) {
            vector <int> path;
            path.push_back(P[i][j]);
            new_paths.push_back(path);
        } else {
            for (int j = 0; j <= i; j++) {
                vector <int> path;
                int left_s = 0, right_s = 0;
                for (int k = 0; k < paths[j].size(); k++) left_s += paths[j][k];
                for (int k = 0; k < paths[j+1].size(); k++) right_s += paths[j+1][k];
                if (left_s > right_s) path = paths[j];
                else path = paths[j+1];
                path.insert(path.begin(), P[i][j]);
                new_paths.push_back(path);
            }
        }
        paths = new_paths;
    }
    for (int i = 0; i < paths[0].size(); i++) {
            S += paths[0][i];
            cout << paths[0][i] << endl;
    }

    out << S;
    return 0;
}
