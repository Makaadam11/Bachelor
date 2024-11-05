#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // An array of adjacency lists

    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    // The main function that finds and prints strongly connected
    // components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout <<"\'" << v << "\'"<<" ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
    cout << "[ ";
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {

        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {

            gr.DFSUtil(v, visited);

        }

    }
    cout << "]";
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
int main()
{
    // Create a graph given in the above diagram
    string name;
    int number_of_lines = 0;
    string line;
    cout << "Podaj nazwe pliku \"nazwa.csv:\" \n";
    cin >> name;


    ifstream data(name);
    while (std::getline(data, line))
        ++number_of_lines;


    parseCSV(name);


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


    Graph g(size);


    for(int i = 0; i < number_of_lines ; i++){
        g.addEdge(parsedCsv[i][0],parsedCsv[i][1]);
    }

    cout << "\nFollowing are strongly connected components in "
            "given graph \n";
    g.printSCCs();

    return 0;
}