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

//double records[MAX_RECORDS][MAX_DATA];
void Calculations(int *sourseCity,int *destinationCity,double *packageWeight,double*diliveryCost,
 double *estimatedTime,double *fuelConsumpion,double *fuelCost,double *totalCost,double *profit,
 double *finalCost,double distance,int vehiclesData[MAX_VEHICLES][4],double distances[MAX_CITIES][MAX_CITIES]);

void diliveryRequestSection(char cities[MAX_CITIES][MAX_LENGTH],int vehiclesData[MAX_VEHICLES][4],
int *sourseCity,int *destinationCity,double *packageWeight,double records[MAX_RECORDS][MAX_DATA]);

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
                  double distances[MAX_CITIES][MAX_CITIES]){
                  //double records[MAX_RECORDS][MAX_DATA]){

 //diliveryRequestSection(cities,vehiclesData,sourseCity,destinationCity,packageWeight,records);
 distance = distances[*sourseCity-1][*destinationCity-1];

 Calculations(sourseCity,destinationCity,packageWeight,diliveryCost,estimatedTime,fuelConsumpion,fuelCost,totalCost,profit,
              finalCost,distance,vehiclesData,distances);


  //distance = distances[*sourseCity][*destinationCity];
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
