#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3

extern int currentCityCount;
extern double records[MAX_RECORDS][MAX_DATA];
void diliveryRecords(
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
                  //double records[MAX_RECORDS][MAX_DATA]){

  distance = distances[*sourseCity][*destinationCity];
  records[recordIndex][0] = (double)recordIndex;
  records[recordIndex][1] = (double)*sourseCity;
  records[recordIndex][2] = (double)*destinationCity;
  records[recordIndex][3] = distance;
  records[recordIndex][4] = (double)userVehicle;
  records[recordIndex][5] = *packageWeight;
  records[recordIndex][6] = *diliveryCost;
  records[recordIndex][7] = *fuelConsumpion;
  records[recordIndex][8] = *fuelCost;
  records[recordIndex][9] = *totalCost;
  records[recordIndex][10] = *profit;
  records[recordIndex][11] = *finalCost;
  records[recordIndex][12] = *estimatedTime;
  recordIndex++;

 }
