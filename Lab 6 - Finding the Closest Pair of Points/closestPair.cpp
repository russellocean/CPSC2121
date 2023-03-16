/*
 * Name: Russell Welch
 * Date Submitted: 03/13/23
 * Lab Section: 001
 * Assignment Name: Lab 6 - Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

// Calculates the minimum distance between a point in the current cell and the points in the compare cell,
// excluding the point itself and points that have already been compared.
double getMinimumDistance(const int k, const std::vector<point>& currentCell, const std::vector<point>& compareCell, double minimum) {
    for (size_t i = 0; i < compareCell.size(); i++) {
        // If the point being compared is the same as the point in the current cell or has already been compared,
        // skip it to avoid unnecessary comparisons.
        if (i >= k && currentCell[k].x == compareCell[i].x && currentCell[k].y == compareCell[i].y) {
            break;
        }

        // Calculate the Euclidean distance between the point in the current cell and the point in the compare cell.
        double distance = std::sqrt(std::pow(currentCell[k].x - compareCell[i].x, 2) + std::pow(currentCell[k].y - compareCell[i].y, 2));

        // If the calculated distance is less than the current minimum, update the minimum.
        if (distance < minimum) {
            minimum = distance;
        }
    }

    // Return the updated minimum distance.
    return minimum;
}

/*
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Uses "spatial hashing" where the #of cells scales with the #of points
  and finds the distance between the closest pair of points returned
  as a double type value
*/
double closestPair(string filename) {
    // Open the file and read in the number of points
    // Return 0 if the file cannot be opened
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        return 0;
    }
    int numPoints;
    inputFile >> numPoints;

    // Create 2D vector of cells to hold the points using b to scale size
    // b = sqrt(numPoints) because the number of cells should scale with the number of points
    const int numCells = static_cast<int>(std::sqrt(numPoints));
    std::vector<std::vector<std::vector<point>>> cellTable(numCells, std::vector<std::vector<point>>(numCells));

    // Read in the points and put them in the cell table
    for (int i = 0; i < numPoints; i++) {
        point p;
        inputFile >> p.y >> p.x;
        cellTable[static_cast<int>(p.y * numCells)][static_cast<int>(p.x * numCells)].push_back(p);
    }

    // Close the file
    inputFile.close();

    // Set the minimum to the maximum possible distance
    double minimum = std::sqrt(2);

    // Iterate through the cells in the cell table
    for (size_t i = 0; i < numCells; i++) {
        for (size_t j = 0; j < numCells; j++) {
            // Get the current cell
            std::vector<point>& currentCell = cellTable[i][j];

            // Iterate through the points in the current cell
            for (size_t k = 0; k < currentCell.size(); k++) {
                // Check the needed cells, do not need to compare to previous surrounding cells
                // Current cell
                minimum = getMinimumDistance(k, currentCell, currentCell, minimum);

                // Right cell
                if (j + 1 < numCells) {
                    minimum = getMinimumDistance(k, currentCell, cellTable[i][j + 1], minimum);
                }

                // Bottom cell
                if (i + 1 < numCells) {
                    minimum = getMinimumDistance(k, currentCell, cellTable[i + 1][j], minimum);
                }

                // Bottom right cell
                if (i + 1 < numCells && j + 1 < numCells) {
                    minimum = getMinimumDistance(k, currentCell, cellTable[i + 1][j + 1], minimum);
                }

                // Bottom left cell
                if (i + 1 < numCells && j > 0) {
                    minimum = getMinimumDistance(k, currentCell, cellTable[i + 1][j - 1], minimum);
                }
            }
        }
    }

    // Return the minimum distance between two points
    return minimum;
}

// int main()
// {
//     double min;
//     string filename;
//     cout << "File with list of points within unit square: ";
//     cin >> filename;
//     min = closestPair(filename);
//     cout << setprecision(16);
//     cout << "Distance between closest pair of points: " << min << endl;
//     return 0;
// }