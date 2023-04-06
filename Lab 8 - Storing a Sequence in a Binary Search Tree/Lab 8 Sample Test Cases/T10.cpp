#include <vector>
#include <cstdlib>

#include "bstSequence.h"

int main()
{
  int N = 10; // this should run quickly even for very large N!
  Node *S = order_n_teams(N);
  for (int i=0; i<N-1; i++) {
    Node *x = select(S, i);
    Node *y = select(S, i+1);
    //ASSERT_EQ(did_x_beat_y(x->key, y->key), true);
    if (did_x_beat_y(x->key, y->key) != true)
    {
      std::cout << "Team x: " << i << ", Team y: " << i+1 << ", expected/correct value for did_x_beat_y(x->key, y->key) is true, actual value when testing is false.\n";
      return 1;
    }
  }
  std::cout << "Passed" << std::endl;
  return 0;
}