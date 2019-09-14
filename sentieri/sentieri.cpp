#include <iostream>
#include <fstream>
#include <vector>

/*struct edge { int to, length; };

int dijkstra(const vector< vector<edge> > &graph, int source, int target) {
    vector<int> min_distance( graph.size(), INT_MAX );
    min_distance[ source ] = 0;
    set< pair<int,int> > active_vertices;
    active_vertices.insert( {0,source} );

    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (auto ed : graph[where])
            if (min_distance[ed.to] > min_distance[where] + ed.length) {
                active_vertices.erase( { min_distance[ed.to], ed.to } );
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert( { min_distance[ed.to], ed.to } );
            }
    }
    return INT_MAX;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    vector <vector <edge>> graph;
    int N, A, B;
    in >> N >> A >> B;
    for (int i = 0; i < A; i++) {
        int X, Y;
        in >> X >> Y;
        edge ex, ey;
        ex.to = Y;
        ex.length = 0;
        graph[X][Y] = ex;
        ey.to = X;
        ey.length = 0;
        graph[Y][X] = ey;
    }
    for (int i = 0; i < B; i++) {
        int X, Y;
        in >> X >> Y;
        edge ex, ey;
        ex.to = Y;
        ex.length = 1;
        graph[X][Y] = ex;
        ey.to = X;
        ey.length = 1;
        graph[Y][X] = ey;
    }
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) cout << graph[i][j];
        cout << endl;
    }

}
*/

#include<bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> mii;

struct step{ //step dell'algoritmo
    int curr, //nodo corrente
        dist; //distanza da source

    step(){}
    step(int c, int d)
    : curr(c), dist(d) {}

    bool operator<(const step& s) //operator< per la coda di priorit�
    const { return dist>s.dist; }
};

int v, a, b;
mii adj;

int dijkstra(mii& graph, int source, int target)
{
    vector<int> distance(graph.size(),oo); //distanze da source
    priority_queue<step> pq; //coda di priorit�
    step head;
    pq.push({source,0}); //inserisco il primo step
    int sent = 0;

    while(!pq.empty()){
        head = pq.top(); //prendo lo step alla distanza minore
        pq.pop();

        if(distance[head.curr]==oo){ //se non ho gi� chiuso questo nodo
            distance[head.curr]=head.dist; //aggiorno la distanza

            if(head.curr==target) return head.dist; //se � il mio target termino

            for(auto x : graph[head.curr]) //per ogni nodo adiacente
                if(distance[x.first]>head.dist+x.second) {//se per raggiungerlo migliorer� il risultato
                    if (distance[x.first]>head.dist+x.second  == 1) sent++;
                    pq.push({x.first,head.dist+x.second}); //lo aggiungo alla coda
                }
        }
    }
    //return distance[target];
    return sent;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

    in >> v >> a >> b;
    adj.resize(v+1);
    for(int x=0, i, j; x < a; ++x){
        in >> i >> j;
        adj[i].push_back({j,0}); // i->j di peso w
        adj[j].push_back({i,0}); // j->i di peso w
    }
    for(int x=0, i, j; x < b; ++x){
        in >> i >> j;
        adj[i].push_back({j,1}); // i->j di peso w
        adj[j].push_back({i,1}); // j->i di peso w
    }

    out << dijkstra(adj,1,v) << "\n";

	return 0;
}
