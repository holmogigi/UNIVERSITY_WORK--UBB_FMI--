from queue import *
import math
from copy import deepcopy
from exceptions import *
#Problem 2 for assig 2
#Problem 5 for assig 3
#Problem 4 for assig 4

class Graph:
    def __init__(self,n=0):
        self._inbound={}
        self._outbound={}
        self._costs={}
        for i in range(n):
            self._inbound[i]=[]
            self._outbound[i]=[]

    # Number of vertices getter
    def get_nr_vertices(self):
        return len(self._outbound.keys())

    # Number of edges getter
    def get_nr_edges(self):
        return len(self._outbound.keys())

    # Costs getter
    def get_costs(self):
        return self._costs

    # Checks if a vertex is valid
    def check_vertex(self, vertex):
        return 0<=vertex<self.get_nr_vertices()

    # Getter for the in degree of given vertex
    def get_in_degree(self, vertex):
        if not self.check_vertex(vertex):
            raise InvalidVertexError

        return len(self._inbound[vertex])

    # Getter for the out degree of given vertex
    def get_out_degree(self, vertex):
        if not self.check_vertex(vertex):
            raise InvalidVertexError

        return len(self._outbound[vertex])

    # Getter for inbound edges of given vertex
    def get_inbound_edges(self,vertex):
        if not self.check_vertex(vertex):
            raise InvalidVertexError
        for edges in self._inbound[vertex]:
            yield edges

    # Getter for outbound edges of given vertex
    def get_outbound_edges(self, vertex):
        if not self.check_vertex(vertex):
            raise InvalidVertexError
        for edges in self._outbound[vertex]:
            yield edges

    # Getter for the cost of the edges starting from a given vertex to another
    def get_cost(self, start, end):
        if not self.check_vertex(start):
            raise InvalidStartVertexError
        if not self.check_vertex(end):
            raise InvalidEndVertexError

        return self._costs[(start,end)]

    # Setter for the cost of the edge of start and end vertex
    def set_cost(self, start, end, new_cost):
        if not self.check_vertex(start):
            raise InvalidStartVertexError
        if not self.check_vertex(end):
            raise InvalidEndVertexError

        self._costs[(start,end)]=new_cost

    # yield is used to return the generator that passes the edges
    def edges_iterator(self):
        for edges in self._costs.keys():
            yield edges

    # yield is used to return the generator that passes the vertices
    def vertices_iterator(self):
        ver_nr= self.get_nr_vertices()
        for vertex in range(ver_nr):
            yield vertex

    # Checks if there is an edge betweeen 2 given vertices
    def check_between_edge(self, start, end):
        if not self.check_vertex(start):
            raise InvalidStartVertexError
        if not self.check_vertex(end):
            raise InvalidEndVertexError

        return end in self._outbound[start]

    # Function that adds an edge to the graph
    def add_edge(self, start, end, cost=0):
        if not self.check_vertex(start):
            raise InvalidStartVertexError
        if not self.check_vertex(end):
            raise InvalidEndVertexError
        if (start,end) in self._costs.keys():
            raise EdgeAlreadyExistsError

        self._outbound[start].append(end)
        self._inbound[end].append(start)
        self._costs[(start,end)]=cost

    # Function that removes an edge of the graph
    def remove_edge(self,start,end):
        if not self.check_vertex(start):
            raise InvalidStartVertexError
        if not self.check_vertex(end):
            raise InvalidEndVertexError
        if (start,end) not in self._costs.keys():
            raise EdgeDoesNotExistError

        del self._costs[(start,end)]
        self._inbound[end].remove(start)
        self._outbound[start].remove(end)

    # Funcion that adds a vertex to the graph
    def add_vertex(self):
        vertex=self.get_nr_vertices()
        self._inbound[vertex]=[]
        self._outbound[vertex]=[]

    # Function that modifies the neighbour, needed for the remove vertex function
    def modify_neighbours(self, i, new_in, new_out):
        self._inbound[i]=new_in[:]
        self._outbound[i]=new_out[:]

    # Function that removes a given vertex from the graph
    def remove_vertex(self, vertex):
        if not self.check_vertex(vertex):
            raise InvalidVertexError

        # Delete the vertex from inbound/outbound of oubound/inbound neighbours
        for n in self._inbound[vertex]:
            self._outbound[n].remove(vertex)
        for n in self._outbound[vertex]:
            self._inbound[n].remove(vertex)
        del self._inbound[vertex]
        del self._outbound[vertex]
        remove_keys=[]
        for i in self._costs.keys():
            if vertex in i:
                remove_keys.append(i)
        for j in remove_keys:
            del self._costs[j]

        # Re-numbering the vertices
        vertices_nr=self.get_nr_vertices()
        for i in range(vertex,vertices_nr):
            self.modify_neighbours(i, self._inbound[i+1], self._outbound[i+1])
        if vertex!=vertices_nr:
            del self._inbound[vertices_nr]
            del self._outbound[vertices_nr]

        # Decreasing(1) the index of all vertices > than the removed vertex
        for i in self._inbound.keys():
            lenght=len(self._inbound[i])
            for j in range(lenght):
                if self._inbound[i][j]>vertex:
                    self._inbound[i][j]-=1
        for i in self._outbound.keys():
            lenght=len(self._outbound[i])
            for j in range(lenght):
                if self._outbound[i][j]>vertex:
                    self._outbound[i][j]-=1

        # Updating the costs
        new_cost={}
        for start,end in self._costs:
            cost=self._costs[(start,end)]
            if start>vertex:
                start-=1
            if end>vertex:
                end-=1
            new_cost[(start,end)]=cost
        self.set_cost(cost)

    # Function that searches for the shortest path between 2 vertices using a backwards Breadth-first search sorting algo
    def getShortestBackwardsBFSPath(self, startIndex, endIndex):
        queue = [endIndex]
        next = {}
        distances = {}
        visited = []
        distances[endIndex] = 0
        while len(queue) != 0:
            currentVertex = queue.pop(0)
            for neighbor in self._inbound[currentVertex]:
                if not (neighbor in visited):
                    queue.append(neighbor)
                    visited.append(neighbor)
                    distances[neighbor] = distances[currentVertex] + 1
                    next[neighbor] = currentVertex
                    if neighbor == startIndex:
                        path = []
                        index = startIndex
                        while index != endIndex:
                            path.append(index)
                            index = next[index]
                        path.append(endIndex)
                        return (path, distances[startIndex])

    # Function that finds a lowest cost walk between the given vertices
    # || prints a message if there are negative cost cycles using Ford's algo
    def getShortestCostPathFORD(self, start, end):
        distance={}
        previous={}
        inf =float('inf')

        # Init the distance to all vertices to infinit
        for vertex in self.vertices_iterator():
            distance[vertex]=inf
            previous[vertex]=-1
        distance[start]=0

        # Loop that goes through all edges and checks if the cost is minimum, if True add it to the previous dict and compute the distance
        ok=True
        while ok:
            ok=False
            for (x, y) in self._costs.keys():
                if distance[y] > distance[x] + self._costs[(x,y)] and distance[x]!=inf:
                    distance[y]=distance[x] + self._costs[(x,y)]
                    previous[y]=x
                    ok=True
        # Stops when all edges are checked and all distances from the start vertex are minimum

        # Check for negative cost cycles if there are any we will find a shorter path
        for (x, y) in self._costs.keys():
            if distance[y] >distance[x] + self._costs[(x,y)] and distance[x]!=inf:
                raise NeativeCycleError

        # Create the path from the end vertex to the start vertex
        path=[]
        vertex=end
        path.append(vertex)
        while previous[vertex]!=-1:
            path.append(previous[vertex])
            vertex=previous[vertex]
        return distance[end], path


    # Function that sorts the vertices topologically
    def topo_sort_predecessor(self):
        sorted=[]
        q=Queue()
        count={}

        for each in self._inbound:
            count[each]= len(self._inbound[each])
            if count[each]==0:
                q.put(each)

        while not q.empty():
            current=q.get()
            sorted.append(current)
            for each in self.get_outbound_edges(current):
                count[each]-=1
                if count[each]==0:
                    q.put(each)
        if len(sorted) < len(self._inbound):
            sorted=[]
        return sorted


    # Function that checks if the given graph is DAG
    def DAG(self):
        sorted=self.topo_sort_predecessor()
        if sorted==[]:
            return 0
        return 1

    # Function that calculates the highest cost path between 2 given vertices
    def highest_cost_path(self, start, end):
        topo_sorted=self.topo_sort_predecessor()
        distance={}
        previous={}
        inf=float('-inf')

        for vertex in topo_sorted:
            distance[vertex]=inf
            previous[vertex]=-1
        distance[start]=0

        for vertex in topo_sorted:
            if vertex==end:
                break
            for vertex2 in self.get_outbound_edges(vertex):
                if distance[vertex2] < distance[vertex] + self._costs[(vertex,vertex2)]:
                    distance[vertex2]=distance[vertex]+self._costs[(vertex,vertex2)]
                    previous[vertex2]=vertex

        return distance[end], previous
