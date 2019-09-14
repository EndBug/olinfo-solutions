#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int C[MAXN];
double m = 1;
bool btc = true;

double solve(int N, double E, int C[]) {
    // insert your code here
    for (int i = 0; i <= N; i++) {
        if (((E > E + C[i] && btc) || (E < E + C[i] && !btc)) && i != N) {
            if (btc) m *= E;
            else m /= E;
            btc = !btc;
        };
        if (i == N && btc) {
            m *= E;
            btc = false;
        }
        E += C[i];
    }
    return m;
}

int main() {
    FILE *fr, *fw;
    int N, E, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &E));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));

    fprintf(fw, "%.8f\n", solve(N, E, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
