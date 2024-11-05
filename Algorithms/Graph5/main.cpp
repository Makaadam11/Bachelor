#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

list<int> *adj2;
int path = 0 ;

struct Edge {
    int src, dest, weight;
};


struct Graph {

    int V, E;

    struct Edge* edge;

    bool get_path(int s, int d);
    void addEdge2(int v, int w);
    bool path_bool(bool x);

};

struct Graph* createGraph(int V, int E)
{
    adj2 = new list<int>[V];
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printArr(int dist[], int n)
{
    printf("\nMap (Vertex,Distance from Source)");
    for (int i = 0; i < n; ++i)
        cout<< "\n("<<i<<", "<< dist[i]<<")";

}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "\nFALSE\n";
            printf("Graph contains negative weight cycle");
            return;
        }
    }

    cout << "\nTURE\n";

    printArr(dist, V);

    return;
}

std::vector<std::vector<int> > parsedCsv;

void parseCSV(string name) {
    std::ifstream data(name);
    std::string line;
    int i = 0;

    while (getline(data, line)) {

        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> parsedRow;
        while (std::getline(lineStream, cell, ',')) {
            parsedRow.push_back(stoi(cell));
        }
        i++;
        parsedCsv.push_back(parsedRow);
    }

}

bool Graph::get_path(int s, int d)
{
    if (s == d)
        return true;


    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);


    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();
        path++;


        for (i = adj2[s].begin(); i != adj2[s].end(); ++i)
        {

            if (*i == d){

                return true;
            }

            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}
int main()
{

    // Create a graph given in the above diagram
    string name, line;
    cout << "Podaj nazwe pliku \"nazwa.csv\": \n";
    cin >> name;

    parseCSV(name);


     int S;
    int number_of_lines = 0;

    ifstream data(name);
    while (std::getline(data, line))
        ++number_of_lines;


    int size =0;

    if(parsedCsv[0][0] < 0){
        size = parsedCsv[number_of_lines-1][0] - parsedCsv[number_of_lines-1][0];
    }
    if (parsedCsv[0][0]==0){
        size = parsedCsv[number_of_lines-1][0] +1;
    }
    if (parsedCsv[0][0]>0){
        size = parsedCsv[number_of_lines-1][0];
    }

    struct Graph* graph = createGraph(size, number_of_lines);


    for (int i = 0; i < number_of_lines; i++) {
        graph->edge[i].src = parsedCsv[i][0];
        graph->edge[i].dest = parsedCsv[i][1];
        graph->edge[i].weight = parsedCsv[i][2];

    }

    cout << "Podaj wierzcholek startowy: \n";
    cin >> S;

    pair<int,int> pair1;
    list <pair<int,int>> result;

    BellmanFord(graph, S);

    cout << "\n\nMap (Vertex,Predecessor): \n";

    for (int i = 0; i < number_of_lines; i++) {

        (graph->get_path(S, graph->edge[i].src));

        pair1.first=graph->edge[i].dest;
        pair1.second= graph->edge[i].src;

        result.push_back(pair1);

        path = 0;

    }

    result.sort();

    for ( const auto& token : result )
        std::cout <<"(" <<token.first << ", " << token.second << ")\n";


    return 0;
}