from graph import *
from random import *
from exceptions import *

# Creates a random graph
def create_random_graph(vertices, edges):
    graph=Graph(vertices)
    edges_nr=0
    while edges_nr<edges:
        x=randint(0, vertices-1)
        y=randint(0, vertices-1)
        if not graph.check_between_edge(x,y):
            graph.add_edge(x,y,randint(0,1000))
            edges_nr+=1
    return deepcopy(graph)

# Write a given graph to a file
def write_graph_to_file(graph, file_name):
    file=open(file_name, "w")
    file.write(str(graph.get_nr_vertices()) + ' ' + str(graph.get_nr_edges()) + '\n')
    costs=graph.get_costs()
    for vertex1,vertex2 in costs:
        file.write(str(vertex1) + ' ' + str(vertex2) + ' ' + str(costs[(vertex1,vertex2)]) + '\n')
    file.close()

# Read a graph from a given file
def read_graph(file_name):
    file=open(file_name, "r")
    line=file.readline()
    line=line.strip('\n')
    line=line.split(' ')
    if len(line)!=2:
        raise InvalidNrVerEdgError
    vertices=int(line[0])
    edge=int(line[1])
    graph=Graph(vertices)
    for i in range(edge):
        edge=file.readline()
        edge=edge.strip('\n')
        edge=edge.split(' ')
        if len(edge)!=3:
            raise InvalidLineError
        start_vertex=int(edge[0])
        end_vertex=int(edge[1])
        cost=int(edge[2])
        graph.add_edge(start_vertex,end_vertex,cost)
    file.close()
    return deepcopy(graph)