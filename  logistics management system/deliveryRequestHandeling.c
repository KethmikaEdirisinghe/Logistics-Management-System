#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
#define MAX_RECORDS 50
#define MAX_DATA 13
extern int currentCityCount;
extern int userVehicle;
extern char vehicles[MAX_VEHICLES][10];
extern double distances[MAX_CITIES][MAX_CITIES];
extern void vehicleManagement(int vehiclesData[MAX_VEHICLES][4],int *userVehicle,char vehicles[MAX_VEHICLES][10]);

extern void recordDilivery(
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

extern void Calculations(
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


void diliveryRequestSection(
                            char cities[MAX_CITIES][MAX_LENGTH],
                            int vehiclesData[MAX_VEHICLES][4],
                            int *sourseCity,
                            int *destinationCity,
                            double *packageWeight,
                            double distance,
                            double*diliveryCost,
                            double *estimatedTime,
                            double *fuelConsumpion,
                            double *fuelCost,
                            double *totalCost,
                            double *profit,
                            double *finalCost,
                            double diliveryRecords[MAX_RECORDS][MAX_DATA]){
   //int i,*sourseCity,*destinationCity;
   //double packageWeight = 0.0;
   int i;
   for(i=0;i<currentCityCount;i++){
       printf("%d. %s\n",i+1,cities[i]);
   }

   do{
   printf("\nEnter where you put your package: ");
   scanf("%d",sourseCity);

   printf("Enter where you want to send your package: ");
   scanf("%d",destinationCity);

   if(*sourseCity == *destinationCity){
       printf("Invalid Destionation Selection!");
     }
   }while(*sourseCity == *destinationCity);

   printf("Your Package will be transfered from %s -------(to)-----> %s \n",cities[*sourseCity-1],cities[*destinationCity-1]);

   printf("Enter the weight of the package: ");
   scanf("%lf",packageWeight);

   vehicleManagement(vehiclesData,&userVehicle,vehicles);

   if(vehiclesData[userVehicle-1][0]<*packageWeight){
       printf("Package Weight is higher than maximum capacity of your selected Vehicle!\n");
   }

recordDilivery(sourseCity, destinationCity, packageWeight,
               diliveryCost, estimatedTime, fuelConsumpion,
               fuelCost, totalCost, profit, finalCost,
               distance, vehiclesData, distances);


}
