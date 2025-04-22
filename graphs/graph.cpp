#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
    private:
        unordered_map<string, unordered_set<string>> adjList;

    public:
        bool addVertex(string vertex)
        {
            if(adjList.count(vertex) == 0) // checks if a vertex is present or not in unordered map
            {
                adjList[vertex];
                return true;
            }
            return false;
        }

        bool addEdge( string v1, string v2)
        {
            if(adjList.count(v1) != 0 && adjList.count(v2) != 0)
            {
                adjList.at(v1).insert(v2); // at gives value of unordered map(i.e the unordered set); insert is used to insert value in unordered set
                adjList.at(v2).insert(v1);
                return true;
            }
            return false;
        }

        bool removeEdge(string v1, string v2)
        {
            if(adjList.count(v1) != 0 && adjList.count(v2) != 0)
            {
                adjList.at(v1).erase(v2); // at gives value of unordered map(i.e the unordered set); erase is used to erase value in unordered set
                adjList.at(v2).erase(v1);
                return true;
            }
            return false;
        }

        bool removeVertex(string vertex)
        {
            if(adjList.count(vertex) != 0)
            {
                for(auto otherVertex : adjList.at(vertex))
                {
                    adjList.at(otherVertex).erase(vertex);
                }
                adjList.erase(vertex);
                return true;
            }
            return false;
          
        }

        void printGraph()
        {
            for(auto [vertex, edges] : adjList)
            {
                cout<<vertex<<" : [";
                for (auto edge : edges)
                {
                    cout<<edge<<" ";
                }
                cout<<"]"<<endl;
            }
        }

};

int main()
{
    Graph g; // another way of declarartion using heap Graph* g = new Graph();
    g.addVertex("A"); // g->addVertex("A")
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addEdge("A","B");
    g.addEdge("A","C");
    g.addEdge("A","D");
    g.addEdge("B","D");
    g.addEdge("C","D");

    g.printGraph();

    //g.removeEdge("B","C");
    g.removeVertex("D");
    g.printGraph();

    return 0;
}