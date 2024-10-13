#include<bits/stdc++.h>
using namespace std;
//Class for the graph.
class graph
{
    int v;
    //Adjacency list.
    list<int> *adjacencylist;
    //Function to detectcycle.
    bool checkcycle2(int v, bool vertvisited[], bool *recursionst);
    public:
    graph(int v);
    void drawedge(int v, int u);
    bool checkcycle();
};
//Constructor for a graph with v nodes.
graph::graph(int v)
{
    this->v=v;
    adjacencylist= new list<int>[v];
}
//To add edges in the graph.
void graph::drawedge(int v, int u)
{
    adjacencylist[v].push_back(u);
}
//Function to keep track of visited nodes and recursion 
//stack.
bool graph::checkcycle2(int v, bool vertvisited[], bool *recursionst)
{
    if(vertvisited[v]==false)
    {
        //Marking the vertex as visited.
        vertvisited[v]=true;
        recursionst[v]=true;
        //Making recursive calls for the adjacent 
        //vertices and return true if any back edge is 
        //found.
        list<int>::iterator itr;
        for(itr=adjacencylist[v].begin();itr!=adjacencylist[v].end();++itr)
        {
            if(!vertvisited[*itr]&&checkcycle2(*itr, vertvisited, recursionst))
            {
                return true;
            }
            else if(recursionst[*itr])
            {
                return true;
            }
        }
    }
    //Unmark the vertex from recursion stack.
    recursionst[v]=false;
    return false;
}
bool graph::checkcycle()
{
    //Declare and initialise the visited and recursion stack array as false.
    bool *vertvisited=new bool[v];
    bool *recursionst=new bool[v];
    for(int i=0;i<v;i++)
    {
        vertvisited[i]=false;
        recursionst[i]=false;
    }
    //Call the "checkcycle2" function for cycle 
    //detection.
    for(int i=0;i<v;i++)
    {
        if(checkcycle2(i, vertvisited, recursionst))
        {
            return true;
        }
    }
    return false;
}
//Driver function.
int main()
{
    graph g(6);
    g.drawedge(0, 1);
    g.drawedge(1, 5);
    g.drawedge(5, 4);
    g.drawedge(4, 0);
    g.drawedge(4, 3);
    g.drawedge(3, 2);
    g.drawedge(0, 2);
    g.drawedge(0, 2);
    g.drawedge(0, 2);
    g.drawedge(0, 2);
    g.drawedge(0, 2);
    g.drawedge(0, 2);
    g.drawedge(0, 2);
    
    //Function call and print the result.
    if(g.checkcycle())
        cout << "Graph is cyclic";
    else
        cout << "Graph is acyclic";
    return 0;
}