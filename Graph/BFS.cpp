#include <bits/stdc++.h>

using namespace std;

class Graph
{
  int V;

  list<int> *adj;

public:
  Graph(int V)
  {
    this->V = V;
    adj = new list<int>[V];
  }
  void addEdge(int v, int w)
  {
    adj[v].push_back(w); // Add w to v’s list.
  }
  void BFS(int s);
};

void Graph::BFS(int s)
{
  // Mark all the vertices as not visited
  vector<bool> visited(V, false);

  // Create a queue for BFS
  list<int> queue;

  // Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);

  while (!queue.empty())
  {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    cout << s << " ";
    queue.pop_front();

    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
    {
      if (!visited[*i])
      {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Breadth First Traversal "
       << "(starting from vertex 2) \n";
  g.BFS(0);

  return 0;
}
