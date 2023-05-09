#include <iostream>
#include <queue>
using namespace std;

// Definition for a node in the graph
class Node {
public:
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

// Definition for the graph
class Graph {
private:
    int numVertices;
    Node** adjacencyList;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyList = new Node*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyList[i] = nullptr;
        }
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);
        newNode->next = adjacencyList[src];
        adjacencyList[src] = newNode;
    }

    void DFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }
        DFSUtil(startVertex, visited);
    }

    void BFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            Node* temp = adjacencyList[current];
            while (temp != nullptr) {
                if (!visited[temp->value]) {
                    visited[temp->value] = true;
                    q.push(temp->value);
                }
                temp = temp->next;
            }
        }
    }

private:
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";
        Node* temp = adjacencyList[vertex];
        while (temp != nullptr) {
            if (!visited[temp->value]) {
                DFSUtil(temp->value, visited);
            }
            temp = temp->next;
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "DFS: ";
    g.DFS(0);
    cout << endl;

    cout << "BFS: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
