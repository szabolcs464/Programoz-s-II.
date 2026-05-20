#include <iostream>
#include <vector>

using namespace std;

const int n = 100;
vector<int> adjList[n+1]; // Szomszédsági lista
int color[n+1]; // 0:fehér, 1:szürke, 2: fekete

// Mélységi bejárás (DFS)
void dfs(int u) {
    color[u] = 1;
    cout << u << " ";

    for (int i = 0; i < adjList[u].size(); ++i) {
        int v = adjList[u][i];
        if (color[v] == 0) {
            dfs(v);
        }
    }
    color[u] = 2;
}

int main() {
    int csomopontok_szama, elek_szama;
    cout << "Add meg a csomopontok es az elek szamat: ";
    cin >> csomopontok_szama >> elek_szama;

    cout << "Add meg az eleket (x y formatumban):" << endl;
    for(int i = 0; i < elek_szama; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x); // Irányítatlan gráf esetén
    }

    int start_node;
    cout << "Add meg a bejaras kezdopontjat: ";
    cin >> start_node;

    cout << "DFS bejaras eredmenye (pre-sorrend): ";
    dfs(start_node);
    cout << endl;

    return 0;
}