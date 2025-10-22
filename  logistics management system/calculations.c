#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3

extern int userVehicle;


void Calculations(
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
                  double distances[MAX_CITIES][MAX_CITIES]){
    double fuelPrice = 310.00;
    distance = distances[*sourseCity][*destinationCity];
    *diliveryCost = distance*(vehiclesData[userVehicle-1][1])*(1+(*packageWeight/10000));
    *estimatedTime = distance/vehiclesData[userVehicle-1][2];
    *fuelConsumpion = distance/vehiclesData[userVehicle-1][3];
    *fuelCost = *fuelConsumpion*fuelPrice;
    *totalCost = *diliveryCost + *fuelCost;
    *profit = *totalCost*0.25;
    *finalCost = *totalCost + *profit;
}

