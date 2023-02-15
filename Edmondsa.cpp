#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_NODES = 100;
const int INF = 1e9;

int graph[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];
int nodes, edges;

bool bfs(int source, int sink) {
    for (int i = 0; i < nodes; i++) {
        parent[i] = -1;
    }

    queue<int> q;
    q.push(source);
    parent[source] = -2;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < nodes; v++) {
            if (parent[v] == -1 && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;

                if (v == sink) {
                    return true;
                }
            }
        }
    }

    return false;
}

int edmondsKarp(int source, int sink) {
    int maxFlow = 0;

    while (bfs(source, sink)) {
        int pathFlow = INF;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

void readGraph(const string& filename) {
    ifstream file(filename);
    string line;
    int i = 0;
    int j = 0;
    while (getline(file, line)) {
        int pos = 0;
        int value;
        while (pos != string::npos) {
            pos = line.find(";");
            value = stoi(line.substr(0, pos));
            graph[i][j++] = value;
            line = line.substr(pos + 1);
        }
        i++;
        j = 0;
    }
    nodes = i;
    edges = j;
}

int main() {
    readGraph("data.csv");

    steady_clock::time_point start = steady_clock::now();
    int maxFlow = edmondsKarp(0, nodes - 1);
    steady_clock::time_point stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Max flow: " << maxFlow << endl;
    cout << "Time complexity: " << duration.count() << " microseconds" << endl;

    return 0;
}
