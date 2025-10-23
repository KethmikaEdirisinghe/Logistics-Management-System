#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
#define MAX_RECORDS 50
#define MAX_DATA 13

extern int currentCityCount;
extern int recordIndex;
extern int userVehicle;
extern char cities[MAX_CITIES][MAX_LENGTH];
extern char vehicles[MAX_VEHICLES][10];
extern double records[MAX_RECORDS][MAX_DATA];

double findTotal(int recordColumn){
   double total= 0.0;
   int i;
   for(i=0;i<recordIndex;i++){
       total += records[i][recordColumn];

   }
   return total;
}
void longestShortestRoutes(){
  int i;
  int shortestIndex;
  int longestIndex;
  double mindistance = records[0][3];
  double maxdistance = records[0][3];

  for(i=0;i<recordIndex;i++){
   if (records[i][3] < mindistance) {  // shortest
    mindistance = records[i][3];
    shortestIndex = i;
    }
   if (records[i][3] > maxdistance) {  // longest
    maxdistance = records[i][3];
    longestIndex = i;
   }

  }
  printf("\nShortest Route: %.2f km\n", records[shortestIndex][3]);
  printf("  From %s to %s\n",
  cities[(int)records[shortestIndex][1] - 1],
  cities[(int)records[shortestIndex][2] - 1]);

  printf("\nLongest Route: %.2f km\n", records[longestIndex][3]);
  printf("  From %s to %s\n",
  cities[(int)records[longestIndex][1] - 1],
  cities[(int)records[longestIndex][2] - 1]);

}

void performances(){
   printf("\t\tReports\n\n");
   printf("Total Diliveries Completed: %d",recordIndex);
   printf("Total Distance Covered: %.2f",findTotal(3));
   printf("Average Dilivery Time: %.2f",findTotal(3)/findTotal(12));
   printf("Longest and Shortest Routes Completed:\n ");
   longestShortestRoutes();

