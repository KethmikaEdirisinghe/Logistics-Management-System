#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
#define MAX_RECORDS 50
#define MAX_DATA 13

void vehicleManagement(int vehiclesData[MAX_VEHICLES][4],int userVehicle,char vehicles[MAX_VEHICLES][10]);

void cityManagement();

int currentCityCount;
char cities[MAX_CITIES][MAX_LENGTH];
int userVehicle;
int  vehiclesData[MAX_VEHICLES][4] = {
  {1000,20,60,12},
  {5000,40,50,6},
  {10000,80,45,4}

};
double records[MAX_RECORDS][MAX_DATA];
char vehicles[MAX_VEHICLES][10] = {"Van","Truck","Lorry"};

int main()
{
   int sourse;
   int destination;
   double weight;
   double diliveryCost,estimatedTime,fuelConsumpion,fuelCost,totalCost,profit,finalCost;
   double diliveryRecords[MAX_RECORDS][MAX_DATA];

   int userCommandMainMenu;
   vehicleManagement(vehiclesData,userVehicle,vehicles);
   cityManagement();
/*
  do{

  }while(1);


    return 0;
}*/
