#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

enum tipo {BLEAH, SLURP};

struct Nodo {
    list <int> nodi_collegati;
    int tipo;
    int passaggi = 0;
};

Nodo nodi[30];
list <int> soluzione;
bool finito;

void init() {
    soluzione.clear();
    finito = false;
    soluzione.push_back(0);
    for (int i = 0; i < 30; i++) {
        nodi[i].passaggi = 0;
        nodi[i].nodi_collegati.clear();
    }
}

void naviga(int i) {
    for (auto n: nodi[i].nodi_collegati) {
            for (auto x: soluzione) cout << x << " ";
    cout << endl;

        if (nodi[n].passaggi == 0 || (nodi[n].passaggi == 1 && nodi[i].tipo == nodi[n].tipo)) {
            if (n == 0 && nodi[i].tipo == BLEAH) {
                finito = true;
                return;
            }
            soluzione.push_back(n);
            nodi[n].passaggi++;
            if (nodi[i].tipo == BLEAH) nodi[n].tipo = SLURP;
            else nodi[n].tipo = BLEAH;
            naviga(n);
            if (finito) return;
            soluzione.pop_back();
            nodi[n].passaggi--;
            if (nodi[i].tipo == BLEAH) nodi[n].tipo = SLURP;
            else nodi[n].tipo = BLEAH;

        }
    }
}

int main()
{
    int N, M;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        int inizio, fine;
        in >> inizio >> fine;
        nodi[inizio].nodi_collegati.push_back(fine);
        nodi[fine].nodi_collegati.push_back(inizio);
    }
    naviga(0);
    out << soluzione.size() << endl;
    for (auto i: soluzione) out << i << " ";
    out << "0" << endl;
    return 0;
}
