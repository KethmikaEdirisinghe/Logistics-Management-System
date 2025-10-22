#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3

void vehicleManagement(int vehiclesData[MAX_VEHICLES][4],int userVehicle,char vehicles[MAX_VEHICLES][10]);

int currentCityCount;
char cities[MAX_CITIES][MAX_LENGTH];
int userVehicle;




int main()
{
   int userCommandMainMenu;
   vehicleManagement(vehiclesData,userVehicle,vehicles);
/*
  do{

  }while(1);


    return 0;
}*/
