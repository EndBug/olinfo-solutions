#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>

using namespace std;

void yodizza(char S[], char Y[]) {
    // Per calcolare la lunghezza si puo' fare cosi'
    int l = strlen(S);

    // Mettete qui il codice della soluzione
    vector <int> spaces;
    spaces.push_back(-1);
    for (int i = 0; i < l; i++) if (S[i] == ' ') spaces.push_back(i);
    spaces.push_back(l);

    for (int i = spaces.size()-1; i > 0; i--) {
        int ind = spaces[i-1]+1;
        while (ind < spaces[i]) {
            if (S[ind] != '\n') {
                int p = strlen(Y);
                Y[p] = S[ind];
            }
            ind++;
        }
        Y[strlen(Y)] = ' ';
    }

    /*int i;
    for (i = 0; i < l; i++) {
         Y[i] = S[i];
    }*/
}


#define MAXS 100000

char S[MAXS + 1], Y[MAXS + 10];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(NULL != fgets(S, MAXS + 1, fr));

    yodizza(S, Y);

    fprintf(fw, "%s\n", Y);
    fclose(fr);
    fclose(fw);
    return 0;
}
