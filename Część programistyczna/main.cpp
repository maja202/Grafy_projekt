#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int source, int sink, int V, vector<int>& parent, vector<vector<int>>& residualGraph) {
    fill(parent.begin(), parent.end(), -1); // none is visited
    parent[source] = -2;
    queue <pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int path_flow = q.front().second;
        q.pop();
        for (int v=0; v < V; v++) {
            if (u != v && parent[v] == -1 && residualGraph[u][v] != 0) {
                parent[v] = u;
                path_flow = min(path_flow, residualGraph[u][v]);
                if (v == sink) {
                    return path_flow;
                }
                q.push({v, path_flow});
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>>& graph, int source, int sink) {
    vector<int> parent(graph.size(), -1);
    vector<vector<int>> residualGraph = graph; // copy of the graph
    int path_flow = 0, max_flow = 0;
    while (path_flow = BFS(source, sink, sink + 1, parent, residualGraph)) {
        max_flow += path_flow;
        int u = sink;
        while (u != source) {
            int v = parent[u];
            residualGraph[u][v] += path_flow;
            residualGraph[v][u] -= path_flow;
            u = v;
        }
    }
    return max_flow;
}

void add_edge(vector<vector<int>>& graph,
             int u, int v, int capacity)
{
    graph[u][v] = capacity;
}

int main()
{
    string fileName;
    int V = 0;
    int v = 0, u = 0, capacity = 0, choice = 0;

    cout << "Ford-Fulkerson algorithm to calculate maximum flow." << endl;
    cout << "Name of the file to open: ";
    cin >> fileName;
    cout << "Number of the graph vertices: ";
    cin >> V;
    cout << "Read from adjacency matrix(1) or from adjacency list(2)? ";
    cin >> choice;

    vector<vector<int>> graph(V, vector<int> (V, 0));

    fstream file;
    file.open(fileName, ios::in);

    if(!file) {
        cout << endl << "Failed to open the file." << endl;
        cout << "Make sure that passed name of the file matches the name of the file you want to open." << endl;
        cout << "For more information please check the READ ME in GitHub repository." << endl;
        return 0;
    }

    if(choice == 1) {
        vector<vector<int>> adjMatrix(V, vector<int> (V, 0));
        while(file) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    file >> adjMatrix[i][j];
                }
            }
        }



        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adjMatrix[i][j] != 0) {
                    add_edge(graph, i, j, adjMatrix[i][j]);
                }

            }
        }
    }
    else if(choice == 2) {
        vector<vector<int>> adjList(V, vector<int>(V, 0));
        while (file) {
            file >> u >> v >> capacity;
            add_edge(graph, u, v, capacity);
        }
    }
    else {
        cout << endl << "Given value is incorrect.";
        return 0;
    }

    file.close();
    cout << endl << "Maximum Flow: " << ford_fulkerson(graph, 0, V - 1) << endl;
    return 0;
}