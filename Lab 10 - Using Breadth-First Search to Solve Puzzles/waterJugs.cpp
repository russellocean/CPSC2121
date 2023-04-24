/*
 * Name: Russell Welch
 * Date Submitted: 04/24/2023
 * Lab Section: 001
 * Assignment Name: Lab 10 - Using Breadth-First Search to Solve Puzzles
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

void build_graph(void)
{
  // Iterate through all possible states for jug A and jug B
  for (int a = 0; a <= 3; ++a)
  {
    for (int b = 0; b <= 4; ++b)
    {
      // Iterate through all possible actions
      for (int action = 0; action < 6; ++action)
      {
        int new_a = a, new_b = b;
        switch (action)
        {
          case 0: new_a = 3; break; // Fill A
          case 1: new_b = 4; break; // Fill B
          case 2: new_a = 0; break; // Empty A
          case 3: new_b = 0; break; // Empty B
          case 4: // Pour A->B
            new_b = min(a + b, 4);
            new_a = a - (new_b - b);
            break;
          case 5: // Pour B->A
            new_a = min(a + b, 3);
            new_b = b - (new_a - a);
            break;
        }
        // Create a pair representing the new state
        state new_state = make_pair(new_a, new_b);

        // Add the valid neighbor state to the current state's neighbors vector
        nbrs[make_pair(a, b)].push_back(new_state);

        // Add the appropriate edge label for the transition between the two states
        edge_label[make_pair(make_pair(a, b), new_state)] = actions[action];
      }
    }
  }
}


// int main(void)
// {
//   build_graph();

//   state start = make_pair(0,0);
  
//   for (int i=0; i<5; i++)
//     nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
//   search (start);
//   if (visited[make_pair(-1,-1)]) 
//     print_path (start, pred[make_pair(-1,-1)]);
//   else
//     cout << "No path!\n";
  
//   return 0;
// }
