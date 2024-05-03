#include <iostream>

using namespace std;

const int MAX_VERTICES = 26;

class Graph {
    int vertices;
    int adjacency[MAX_VERTICES][MAX_VERTICES];

public:
    Graph() {
        vertices = 0;
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                adjacency[i][j] = 0;
            }
        }
    }

    void add_edge(char u, char v) {
        int index_u = u - 'a';
        int index_v = v - 'a';
        adjacency[index_u][index_v] = 1;
        adjacency[index_v][index_u] = 1; // For undirected graph
        if (index_u >= vertices) vertices = index_u + 1;
        if (index_v >= vertices) vertices = index_v + 1;
    }

    void print() {
        for (int i = 0; i < vertices; i++) {
            cout << (char)('a' + i) << ": ";
            for (int j = 0; j < vertices; j++) {
                if (adjacency[i][j] == 1) {
                    cout << (char)('a' + j) << "->";
                }
            }
            cout << "Null" << endl;
        }
    }
};

int main() {
    Graph g;
    int vert, e;
    char u, v;

    cout << "Enter the number of vertices: ";
    cin >> vert;

    cout << "Enter the number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        g.add_edge(u, v);
    }

    g.print();

    return 0;
}
