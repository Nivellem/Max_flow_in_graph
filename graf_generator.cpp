#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

using namespace std;

const int N = 6;
const int MAX_WEIGHT = 20;
const int NUM_GRAPHS = 1;

vector<vector<int>> graph(N, vector<int>(N, 0));

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
}

void saveGraph(int graphNum) {
    string filename = "graphs.csv";
    ofstream outFile;
    outFile.open(filename, ios::app);

    outFile << "Graph " << graphNum << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            outFile << graph[i][j];
            if (j < N - 1) {
                outFile << ";";
            }
        }
        outFile << endl;
    }

    outFile.close();
}

int main() {
    // Seed with a real random value, if available
    random_device rd;

    // Choose a random mean between 1 and MAX_WEIGHT
    mt19937 e2(rd());
    uniform_int_distribution<int> dist(1, MAX_WEIGHT);

    for (int graphNum = 1; graphNum <= NUM_GRAPHS; graphNum++) {
        // Generate random edges and add to the graph
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int weight = dist(e2);
                addEdge(i, j, weight);
                addEdge(j, i, weight);
            }
        }

        saveGraph(graphNum);
    }

    return 0;
}
