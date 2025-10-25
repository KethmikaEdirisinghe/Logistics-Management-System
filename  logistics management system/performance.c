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


void recordDilivery(
                  int *sourseCity,
                  int *destinationCity,
                  double *packageWeight,
                  double*diliveryCost,
                  double *estimatedTime,
                  double *fuelConsumpion,
                  double *fuelCost,
                  double *totalCost,
                  double *profit,
                  double *finalCost,
                  double distance,
                  int vehiclesData[MAX_VEHICLES][4],
                  double distances[MAX_CITIES][MAX_CITIES]);

void findShortestRouteIterative(int startPoint, int endPoint);

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
  int shortestIndex = 0;
  int longestIndex = 0;

  if(recordIndex == 0){
       printf("No records available yet.\n");
  }
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

void performances() {
    printf("\n====================================================\n");
    printf("\tDELIVERY PERFORMANCE REPORT\n");
    printf("====================================================\n\n");

    if (recordIndex == 0) {
        printf("No delivery records available yet.\n");
        printf("====================================================\n");
        return;
    }


    printf("Total Deliveries Completed : %d\n", recordIndex);
    printf("Total Distance Covered     : %.2f km\n", findTotal(3));

    double totalDistance = findTotal(3);
    double totalTime = findTotal(12);

    if (recordIndex > 0)
        printf("Average Delivery Time       : %.2f hours\n", totalTime / recordIndex);
    else
        printf("Average Delivery Time       : 0.00 hours\n");

    double totalRevenue = findTotal(11);
    double totalProfit = findTotal(10);

    printf("Total Revenue               : %.2f LKR\n", totalRevenue);
    printf("Total Profit                : %.2f LKR\n", totalProfit);

    printf("----------------------------------------------------\n");
    printf("Longest and Shortest Routes Completed:\n");


    int shortestIndex = 0, longestIndex = 0;
    double mindistance = records[0][3];
    double maxdistance = records[0][3];

    for (int i = 1; i < recordIndex; i++) {
        if (records[i][3] < mindistance) {
            mindistance = records[i][3];
            shortestIndex = i;
        }
        if (records[i][3] > maxdistance) {
            maxdistance = records[i][3];
            longestIndex = i;
        }
    }

    printf("\nShortest Route:\n");
    printf("  From %-10s -> To %-10s : %.2f km\n",
           cities[(int)records[shortestIndex][1] - 1],
           cities[(int)records[shortestIndex][2] - 1],
           records[shortestIndex][3]);

    printf("\nLongest Route:\n");
    printf("  From %-10s -> To %-10s : %.2f km\n",
           cities[(int)records[longestIndex][1] - 1],
           cities[(int)records[longestIndex][2] - 1],
           records[longestIndex][3]);

    printf("----------------------------------------------------\n");


    int bestStart = (int)records[shortestIndex][1] - 1;
    int bestEnd = (int)records[shortestIndex][2] - 1;

    printf("\n*** Best Route Optimization (Based on City Network) ***\n");
    findShortestRouteIterative(bestStart, bestEnd);
    printf("\n====================================================\n");
}
