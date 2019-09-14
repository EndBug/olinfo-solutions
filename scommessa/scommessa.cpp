#include <iostream>
#include <stdio.h>
#include <assert.h>

#define MAXN 200

using namespace std;

int C[MAXN];

void solve(FILE *fw, int N, int C[]) {
    int FN = 0, FC[MAXN];
    for (int i = 0; i < N; i++) {
        int le = 0, lo = 0, re = 0, ro = 0;
        for (int j = 0; j < i; j++) if (C[j] % 2) lo++; else le++;
        for (int j = i+1; j < N; j++) if (C[j] % 2) ro++; else re++;
        if (le == lo && re == ro) {
            FC[FN] = C[i];
            FN++;
        }
    }
    fprintf(fw, "%d\n", FN);
    for (int i = 0; i < FN; i++) {
        fprintf(fw, "%d", FC[i]);
        if (i != FN-1) fprintf(fw, " ");
    }
    fprintf(fw, "\n");
}

int main()
{
    FILE *fr, *fw;
    int N;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for (int j = 0; j < N; j++) {
        assert(1 == fscanf(fr, "%d ", &C[j]));
    }
    solve(fw, N, C);
}
