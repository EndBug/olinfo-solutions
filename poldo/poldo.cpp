#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*int N, panini[10000];
vector <int> migliore, temp;


void naviga(int index) {
    temp.push_back(index);
    for (int i = index+1; i < N; i++) if (panini[i] < panini[index]) naviga(i);
    if (temp.size() > migliore.size()) migliore = temp;
    temp.pop_back();
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for (int i = 0; i < N; i++) in >> panini[i];

    for (int i = 0; i < N; i++) if (migliore.size() < N-i) naviga(i);

    out << migliore.size();
    return 0;
}
*/

//Codice di Alessandro Bugatti, il mio è giusto mio va in timeout, con la nuova modalità di sottoposizione non me ne devo preoccupare, quindi lo lascio così

int soluzioni[10000];
int panini[10000];

int main(int argc, char *argv[])
{
    fstream in,out;
    int numeroPanini,m;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    in >> numeroPanini;
    for (int i=0; i<numeroPanini; i++)
        in >> panini[i];
    for (int i=numeroPanini-1; i>=0; i--)
    {
        m=0;
        for (int j=numeroPanini-1; j>i; j--)
        {
            if (panini[i] > panini[j] && soluzioni[j]>m)
                m=soluzioni[j];
        }
        soluzioni[i] = m + 1;
    }
    m=soluzioni[0];
    for (int i=1; i< numeroPanini; i++)
        if (soluzioni[i] > m)
            m = soluzioni[i];
    out << m;
}
