/*
 * Name: Russell Welch
 * Date Submitted: 05/01/2023
 * Lab Section: 001
 * Assignment Name: Lab 11 - Iterative Refinement and the Traveling Salesman Problem
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <random>

using namespace std;

const int N = 14; //Number of cities in cities.txt
typedef pair<double,double> Point; //<latitude,longitude> of a city
vector<Point> P(N), best; //P - current solution, best - best solution
map<Point, int> cities; //Point (latitude,longitude) -> index of city in cities.txt order
string cityNames[] = {"New York City",
                      "Chicago",
                      "Los Angeles",
                      "Toronto",
                      "Houston",
                      "Montreal",
                      "Mexico City",
                      "Vancouver",
                      "Atlanta",
                      "Denver",
                      "San Juan",
                      "New Orleans",
                      "Miami",
                      "Kansas City"}; //Index of a city -> city name

//Calculates "distance"
//Units are lat./long. "degrees" on an x-y plane
//to simplify calculations (not mi/km on globe)
double dist(int i, int j)
{
  double dx = P[(i+N)%N].first - P[(j+N)%N].first;
  double dy = P[(i+N)%N].second - P[(j+N)%N].second;
  return sqrt(dx*dx + dy*dy);
}


bool refine(double &len)
{
  bool improved = false;
  for (int i = 0; i < N; ++i)
  {
    for (int j = i + 2; j < N; ++j)
    {
      double old_dist = dist(i, i + 1) + dist(j, (j + 1) % N);
      double new_dist = dist(i, j) + dist(i + 1, (j + 1) % N);
      double decrease = old_dist - new_dist;

      if (decrease > 0.0001)
      {
        reverse(P.begin() + i + 1, P.begin() + j + 1);
        len -= decrease;
        improved = true;
      }
    }
  }
  return improved;
}


double tspRefine()
{
  double best_len = 999999999;
  ifstream fin("cities.txt");
  for (int i = 0; i < N; i++)
  {
    fin >> P[i].first >> P[i].second;
    cities[P[i]] = i;
  }

  random_device rd;
  mt19937 g(rd());

  int iterations = 100; // Adjust the number of iterations if needed
  for (int iter = 0; iter < iterations; ++iter)
  {
    shuffle(P.begin(), P.end(), g);

    double len = 0.0;
    for (int i = 0; i < N; ++i)
      len += dist(i, (i + 1) % N);

    while (refine(len));

    if (len < best_len)
    {
      best_len = len;
      best = P;
    }
  }

  for (auto p : best) cout << cityNames[cities[p]] << endl;
  cout << "\nTotal length: " << best_len << "\n";
  return best_len;
}

// int main(void)
// {
//   double best_len = 999999999;
//   best_len=tspRefine();
//   return 0;
// }
