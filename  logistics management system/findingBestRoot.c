#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
#define MAX_RECORDS 50
#define MAX_DATA 13

extern int currentCityCount;
extern char cities[MAX_CITIES][MAX_LENGTH];
extern double distances[MAX_CITIES][MAX_CITIES];
extern double distance;

void findShortestRouteIterative(int startPoint, int endPoint) {
  double minDistance = 99999; // Start with the largest possible distance
  int bestPath[MAX_CITIES];
  int bestPathLength = 0;
  double currentDistance;

  if (distances[startPoint][endPoint] > 0) {
   minDistance = distances[startPoint][endPoint];
   bestPath[0] = startPoint;
   bestPath[1] = endPoint;
   bestPathLength = 2;
  }


  for (int c1 = 0; c1 < currentCityCount; c1++) {
   if (c1 == startPoint || c1 == endPoint) continue;

   if (distances[startPoint][c1] > 0 && distances[c1][endPoint] > 0) {
            currentDistance = distances[startPoint][c1] + distances[c1][endPoint];
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                bestPathLength= 3;
                bestPath[0] = startPoint; bestPath[1] = c1; bestPath[2] = endPoint;
            }
        }
    }


    for (int c1 = 0; c1 < currentCityCount; c1++) {
     if (c1 == startPoint || c1 == endPoint) continue;
     for (int c2 = 0; c2 < currentCityCount; c2++) {
      if (c2 == startPoint || c2 == endPoint || c2 == c1) continue;

      if (distances[startPoint][c1] > 0 && distances[c1][c2] > 0 && distances[c2][endPoint] > 0) {
        currentDistance= distances[startPoint][c1] + distances[c1][c2] + distances[c2][endPoint];
         if (currentDistance< minDistance) {
          minDistance = currentDistance;
          bestPathLength = 4;
          bestPath[0] = startPoint; bestPath[1] = c1; bestPath[2] = c2; bestPath[3] = endPoint;
         }
       }
    }
  }


  for (int c1 = 0; c1 < currentCityCount; c1++) {
   if (c1 == startPoint || c1 == endPoint) continue;
    for (int c2 = 0; c2 < currentCityCount; c2++) {
     if (c2 == startPoint || c2 == endPoint || c2 == c1) continue;
      for (int c3 = 0; c3 < currentCityCount; c3++) {
       if (c3 == startPoint || c3 == endPoint || c3 == c1 || c3 == c2) continue;

   if (distances[startPoint][c1] > 0 && distances[c1][c2] > 0 && distances[c2][c3] > 0 && distances[c3][endPoint] > 0) {
    currentDistance = distances[startPoint][c1] + distances[c1][c2] + distances[c2][c3] + distances[c3][endPoint];
     if (currentDistance < minDistance) {
       minDistance= currentDistance;
       bestPathLength = 5;
       bestPath[0] = startPoint; bestPath[1] = c1; bestPath[2] = c2; bestPath[3] = c3; bestPath[4] = endPoint;

         }
        }
      }
    }
  }


  for (int c1 = 0; c1 < currentCityCount; c1++) {
   if (c1 == startPoint || c1 == endPoint) continue;
    for (int c2 = 0; c2 < currentCityCount; c2++) {
     if (c2 == startPoint || c2 == endPoint || c2 == c1) continue;
    for (int c3 = 0; c3 < currentCityCount; c3++) {
     if (c3 == startPoint || c3 == endPoint || c3 == c1 || c3 == c2) continue;
    for (int c4 = 0; c4 < currentCityCount; c4++) {
     if (c4 == startPoint || c4 == endPoint || c4 == c1 || c4 == c2 || c4 == c3) continue;

   if(distances[startPoint][c1] > 0 && distances[c1][c2] > 0 && distances[c2][c3] > 0 && distances[c3][c4] > 0 && distances[c4][endPoint] > 0) {
   currentDistance = distances[startPoint][c1] + distances[c1][c2] + distances[c2][c3] + distances[c3][c4] + distances[c4][endPoint];
   if (currentDistance< minDistance) {
   minDistance = currentDistance;
   bestPathLength = 6;
   bestPath[0] = startPoint; bestPath[1] = c1; bestPath[2] = c2; bestPath[3] = c3; bestPath[4] = c4; bestPath[5] = endPoint;

          }
         }
       }
     }
    }
  }


  if (bestPathLength > 0) {

   distance = minDistance;

   printf("\n--- Least-Cost Route Found ---\n");
   printf("Minimum Distance: %.2f km\n", distance);
   printf("Optimal Route: ");
  for (int i = 0; i < bestPathLength; i++) {

    if (i == bestPathLength - 1) {

        printf("%s", cities[bestPath[i]]);
    } else {

        printf("%s -> ", cities[bestPath[i]]);
     }
   }
  }
}
