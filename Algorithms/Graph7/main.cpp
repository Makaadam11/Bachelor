#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits.h>

using namespace std;

void print(std::vector<std::vector<double>> dist, std::vector<std::vector<int>> next, int start, int end) {

    const auto size = next.size();
    for (auto i = start-1; i < size; ++i) {

        for (auto j = end-1; j < size; ++j) {
            if (i != j ) {
                auto u = i+1;
                auto v = j+1;

                std::cout << "(" << u << " -> " << v << ", " << dist[i][j]
                          << ", ";
                std::stringstream path;
                path << u;
                do {
                    u = next[u - 1][v - 1];
                    path << " -> " << u;
                } while (u != v);
                std::cout << path.str() << ")" << std::endl;

                return;
            }
        }

    }
}

void solve(std::vector<std::vector<int>> w_s, const int num_vertices,int start,int end,
                                    int start1,int end1,int start2,int end2) {
    std::vector<std::vector<double>> dist(num_vertices);
    for (auto& dim : dist) {
        for (auto i = 0; i < num_vertices; ++i) {
            dim.push_back(INT_MAX);
        }
    }
    for (auto& w : w_s) {
        dist[w[0] - 1][w[1] - 1] = w[2];
    }
    std::vector<std::vector<int>> next(num_vertices);
    for (auto i = 0; i < num_vertices; ++i) {
        for (auto j = 0; j < num_vertices; ++j) {
            next[i].push_back(0);
        }
        for (auto j = 0; j < num_vertices; ++j) {
            if (i != j) {
                next[i][j] = j + 1;
            }
        }
    }
    for (auto k = 0; k < num_vertices; ++k) {
        for (auto i = 0; i < num_vertices; ++i) {
            for (auto j = 0; j < num_vertices; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    print(dist,next,start,end);
    print(dist,next,start1,end1);
    print(dist,next,start2,end2);
}

std::vector<std::vector<int> > parsedCsv;

void parseCSV(std::string name) {
    std::ifstream data(name);
    std::string line;

    while (getline(data, line)) {

        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> parsedRow;
        while (std::getline(lineStream, cell, ',')) {
            parsedRow.push_back(stoi(cell));
        }
        parsedCsv.push_back(parsedRow);
    }

}

int main() {
    std::vector<std::vector<int>> w ;
    std::vector<int> v;
    std:: string name,line;
    int number_of_lines =0;
    int size =0;

    std::cout << "Podaj nazwe pliku \"nazwa.csv\": \n";
    std:: cin >> name;

    parseCSV(name);



    ifstream data(name);
    while (std::getline(data, line))
        ++number_of_lines;


    for (int i = 0; i < number_of_lines ; ++i) {
        v = { parsedCsv[i][0], parsedCsv[i][1], parsedCsv[i][2]};
        w.push_back(v);
    }

    if(parsedCsv[0][0] < 0){
        size = parsedCsv[number_of_lines-1][0] - parsedCsv[number_of_lines-1][0];
    }
    if (parsedCsv[0][0]==0){
        size = parsedCsv[number_of_lines-1][0] + 1;
    }
    if (parsedCsv[0][0]>0){
        size = parsedCsv[number_of_lines-1][0];
    }

    int S,END,S1,END1,S2,END2;

    cout << "Podaj wierzcholek startowy 1: \n";
    cin >> S;
    cout << "Podaj wierzcholek koncowy 1: \n";
    cin >> END;
    cout << "Podaj wierzcholek startowy 2: \n";
    cin >> S1;
    cout << "Podaj wierzcholek koncowy 2: \n";
    cin >> END1;
    cout << "Podaj wierzcholek startowy 3: \n";
    cin >> S2;
    cout << "Podaj wierzcholek koncowy 3: \n";
    cin >> END2;

    std::cout << "\n (pair, dist, path)" << std::endl;

    solve(w, size,S,END,S1,END1,S2,END2);

    cout << "\n\nwcisnij dowolny przycisk + enter aby zakonczyc ";
    cin >> S;

    return 0;
}