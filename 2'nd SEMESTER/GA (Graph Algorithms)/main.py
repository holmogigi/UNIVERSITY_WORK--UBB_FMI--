from graph import *
from UI import *
from Services import *
from exceptions import *

def main():
    graph = Graph()
    graph_copy = Graph()
    print(" '1' to LOAD GRAPH FROM TEXT FILE")
    print(" '2' to GENERATE RANDOM GRAPH")
    inp=input(">> ")

    if inp=='1':
        file_name=input("filename: ")
        graph=read_graph(file_name)
    else:
        vertices=int(input("Number of vertices: "))
        edges=int(input("Number of edges: "))
        graph=create_random_graph(vertices,edges)

    while True:
        try:
            print_menu()
            n=input(">> ");

            if n=='0':
                print("\n        Exiting...")
                exit()

            elif n=='1':
                print('Vertices: ' +str(graph.get_nr_vertices()))

            elif n=='2':
                vertices=graph.vertices_iterator()
                for v in vertices:
                    print(v)

            elif n=='3':
                start=int(input("Start vertex: "))
                end=int(input("End vertex: "))
                if graph.check_between_edge(start,end):
                    print('Edge from: ' + str(start) + ' to ' + str(end))
                else:
                    print('NO edge from: ' + str(start) + ' to ' + str(end))

            elif n=='4':
                vertex=int(input("Vertex: "))
                in_deg=graph.get_in_degree(vertex)
                out_deg=graph.get_out_degree(vertex)
                print('In degree of ' + str(vertex) + ' is: ' + str(in_deg))
                print('Out degree of ' + str(vertex) + ' is: ' + str(out_deg))


            elif n=='5':
                vertex=int(input("Vertex: "))
                vertices=graph.get_outbound_edges(vertex)
                print('Outbound edges from: ' + str(vertex) + ':')
                for v in vertices:
                    cost=graph.get_cost(vertex, v)
                    print('Edge from: ' + str(vertex) + ' to ' + str(v) + ' Cost: ' + str(cost))

            elif n=='6':
                vertex = int(input("Vertex: "))
                vertices = graph.get_inbound_edges(vertex)
                print('Inbound edges from: ' + str(vertex) + ':')
                for v in vertices:
                    cost = graph.get_cost(v, vertex)
                    print('Edge from: ' + str(vertex) + ' to ' + str(v) + ' Cost: ' + str(cost))

            elif n=='7':
                start=int(input("Start vertex: "))
                end=int(input("End vertex: "))
                cost=graph.get_cost(start,end)
                print('The cost of the edge is: ' + str(cost))

            elif n=='8':
                start = int(input("Start vertex: "))
                end = int(input("End vertex: "))
                new_cost=int(input("New cost: "))
                graph.set_cost(start,end,new_cost)

            elif n=='9':
                start = int(input("Start vertex: "))
                end = int(input("End vertex: "))
                cost = int(input("Cost: "))
                graph.add_edge(start,end,cost)

            elif n=='10':
                start = int(input("Start vertex: "))
                end = int(input("End vertex: "))
                graph.remove_edge(start,end)

            elif n=='11':
                graph.add_vertex()

            elif n=='12':
                vertex=int(input("Vertex: "))
                graph.remove_vertex(vertex)

            elif n=='13':
                graph_copy.append(deepcopy(graph))

            elif n=='14':
                graph=graph_copy.pop(-1)

            elif n=='15':
                write_graph_to_file(graph,'graph.txt')

            elif n=='16':
                edges=graph.edges_iterator()
                for edge in edges:
                    print(edge)

            elif n=='17':
                startVertex = int(input("Start vertex: "))
                endVertex = int(input("End vertex: "))
                pathAndDistance = graph.getShortestBackwardsBFSPath(startVertex, endVertex)
                print("Path: " + ("-".join(str(e) for e in pathAndDistance[0])))
                print("Length: " + str(pathAndDistance[1]))

            elif n=='18':
                startVertex = int(input("Start vertex: "))
                endVertex = int(input("End vertex: "))

                distance, path = graph.getShortestCostPathFORD(startVertex, endVertex)
                path.reverse()
                print("Path: " + ("-".join(str(e) for e in path)))
                print("Cost: " + str(distance))

            elif n=='19':
                sorted_DAG=graph.DAG()
                if sorted_DAG==0:
                    raise GraphNotDAG
                else:
                    print("!Graph is DAG!\n")
                    startver=int(input("Start vertex: "))
                    endver=int(input("End vertex: "))


        except InvalidVertexError:
            print("\n!ERROR! The vertex is invalid!\n")
        except InvalidStartVertexError:
            print("\n!ERROR! The start vertex is invalid!\n")
        except InvalidEndVertexError:
            print("\n!ERROR! The end vertex is invalid!\n")
        except ZeroInboundEdgesError:
            print("\n!ERROR! No inbound edges found!\n")
        except ZeroOutboundEdgesError:
            print("\n!ERROR! No outbound edges found!\n")
        except EdgeAlreadyExistsError:
            print("\n!ERROR! This edge already exists!\n")
        except EdgeDoesNotExistError:
            print("\n!ERROR! This edge already exists!\n")
        except InvalidNrVerEdgError:
            print("\n!ERROR! Invalid number of edges/vertices!\n")
        except InvalidLineError:
            print("\n!ERROR! Invalid line in file!\n")
        except NeativeCycleError:
            print("\n!ERROR! Graph contains a negative cost cycle!\n")
        except GraphNotDAG:
            print("\n!ERROR! Graph is not DAG!\n")

main()