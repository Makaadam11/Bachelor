import csv
import numpy 
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.cluster import SpectralClustering

import os
path = os.path.abspath(os.path.dirname(__file__))

number = input("Wybierz numer pliku z danymi do oczytania (0-5): ")
name=""

"""choose dataset
"""
if number == '0':
    name = os.path.join(path, "data_0.csv")
elif number == '1':
    name = os.path.join(path, "data_1.csv")
elif number == '2':
    name = os.path.join(path, "data_2.csv")
elif number == '3':
    name = os.path.join(path, "data_3.csv")
elif number == '4':
    name = os.path.join(path, "data_4.csv")
elif number == '5':
    name = os.path.join(path, "data_5.csv")

"""parsing and saving data from .csv file
"""
parsedCSV = numpy.array(list(csv.reader(open(name, "r"), delimiter=",")))[1:]
points = numpy.array([[float(x), float(y), int(z)] for x, y, z in parsedCSV])
size = (len(parsedCSV)) 

cluster_method =''

"""choose clustering method
"""
cluster_input = input("Wpisz metodę klastrowania: \n1) Funkcja używająca jądra Gaussa (RBF) z odległością euklidesową wpisz: rbf \n2) Funkcja używająca K-macierz łączności najbliższych sąsiadów wpisz: knn\n")

if cluster_input == 'knn':
    cluster_method = 'nearest_neighbors'
if cluster_input == 'rbf':
    cluster_method = 'rbf'    

cluster_number = input("Wpisz ilość klastrów: ")

"""
store result of MTS algorithm
"""
result = []
csv_result = []

def MAX(sets):
    return (max(sets))




model = SpectralClustering(n_clusters=(int)(MAX(cluster_number)), affinity=cluster_method,assign_labels='kmeans')
labels = model.fit_predict(points)

class Graph:

    """initialize graph
    """
    def __init__(self, vertices):
        
        """No. of vertices
        """
        self.V = vertices 

        """default dictionary to store graph
        """
        self.graph = [] 
    """
    function to add an edge to graph
    """
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])
   
    """
    A utility function to find set of an element i (uses path compression technique)
    """
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])
    
    """
    A function that does union of two sets of x and y (uses union by rank)
    """
    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
       
        """
        Attach smaller rank tree under root of high rank tree (Union by Rank)
        """
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
           
            """
            If ranks are same, then make one as root and increment its rank by one
            """
        else:
            parent[yroot] = xroot
            rank[xroot] += 1


    def KruskalMST(self):
        
        """
        Construct Minimum Spanning Tree (MST) using Kruskal's algorithm
        """
        
        """
        An index variable, used for sorted edges
        """
        i = 0
       
        """
        An index variable, used for result[]
        """
        e = 0

        self.graph = sorted(self.graph,
                            key=lambda item: item[2])

        parent = []
        rank = []
        
        """
        Create V subsets with single elements
        """
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
       
        """
        Number of edges to be taken is equal to V-1
        """
        while e < self.V - 1:

            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)

           
            """
            If including this edge doesn't cause cycle, include it in result and 
            increment the indexof result for next edge
            """
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)
            
            """
            Else discard the edge
            """
        arr = numpy.empty(len(result),dtype=float)
        
        
        minimumCost = 0
        iter = 0
        arr = list()

        print ("Edges in the constructed MST")
        for u, v, weight in result:
            
            array2 = [int(u),weight,int(v)]
            csv_result.append(array2)
            arr.append(weight)
            iter += 1
            minimumCost += weight

            print("%d -- %d == %f" % (u, v, weight))
        print('\n')     
        print("Minimum Spanning Tree" , minimumCost)  
        print('\n')  
                               

"""creates a graph object with a given number of vertices.
"""
graph = Graph(size)

"""are nested loops that iterate over the vertices.
"""
for i in range(0,size):

    for j in range(0,size):
        
        if(i!=j):
            
            """calculates the Euclidean distance between the two points represented by the vertices.
            """
            a = numpy.array([parsedCSV[i][0],parsedCSV[i][1]],dtype='f')
            b = numpy.array([parsedCSV[j][0],parsedCSV[j][1]],dtype='f')
            """calculate weight
            """
            weight = numpy.linalg.norm(a-b)
            """add edge
            """
            graph.addEdge(i, j, weight) 
 
"""uses MST algorighm on created graph
"""
graph.KruskalMST() 

csv_result2 = []

csv_result = numpy.asarray(csv_result)

"""
this code saves points and their distances to .csv file by iterating through MST result
"""
with open(str(path)+"\\distances.csv", 'a',newline='' ) as file:
    writer = csv.writer(file)
    
    points_header = ['point 1','distance p1-p2','point 2']
   
    writer.writerow(points_header) 

    for px in range (0,size-1):       
        writer.writerow(csv_result[px]+labels[px])

"""
this code saves points and their clusters to .csv file by iterating through point coordinate
and their clusters
"""
with open(str(path)+"\\clusters.csv", 'a',newline='' ) as file:
    writer = csv.writer(file)
    
    points_header2 = ['cord_x','cord_y','cluster']
   
    for px in range (0,len(points)-1):
        array3 = [points[px,0],points[px,1],labels[px]]
        csv_result2.append(array3)

    writer.writerow(points_header2) 

    for px in range (0,size-1):       
        writer.writerow(csv_result2[px])        
    
"""
plots the scatter plot of the points using x and y coordinates and the cluster labels.
"""
plt.scatter(points[:, 0], points[:, 1], c=labels,s=25, cmap='viridis')


plt.show()     