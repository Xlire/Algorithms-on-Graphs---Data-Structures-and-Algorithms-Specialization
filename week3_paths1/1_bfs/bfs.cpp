#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> dis(adj.size(), -1);
  //FIFO
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
    {
      if (dis[v] == -1)
      {
        dis[v] = dis[u] + 1;
        q.push(v);
        if (v == t)
          return dis[v];
      }
    }
  }
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t) << std::endl;
  std::cin.ignore();
  std::cin.get();
}
