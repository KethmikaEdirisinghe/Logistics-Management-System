#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
#define MAX_RECORDS 50
#define MAX_DATA 13

extern int userVehicle;
extern char vehicles[MAX_VEHICLES][10];
extern int  vehiclesData[MAX_VEHICLES][4];


void displayVehicleSet(int vehiclesData[MAX_VEHICLES][4],char vehicles[MAX_VEHICLES][10]){
   int i,j,vehicleSelect;

   printf("\n----------------------------------------------------------------------------------------\n");
   printf("Type\tCapacity(kg)\tRate per km(LKR)\tAvg Speed(km\h)\tFuel Efficiency(km/l)\n");

   for(i=0;i<3;i++){

     printf("%-10s\t%-12d\t%-16d\t%-15d\t%-21d\t\n",vehicles[i],vehiclesData[i][0],vehiclesData[i][1],vehiclesData[i][2],vehiclesData[i][3]);

   }
   printf("\n----------------------------------------------------------------------------------------\n");
}

void selectVehicle(int vehiclesData[MAX_VEHICLES][4],char vehicles[MAX_VEHICLES][10],int *userVehicle){
  printf("\n-*-*-*-*-*-*-*-*-\n");
  printf("1-> Van.\n");
  printf("2-> Truck.\n");
  printf("3-> Lorry.\n");
  printf("\n-*-*-*-*-*-*-*-*-\n");
  printf("\n=>Please Select your Vehicle: ");
  scanf("%d",userVehicle);

  if(*userVehicle == 1){
   printf("* You have selected Van.\n");
  }else if(*userVehicle == 2){
   printf("* You have selected Truck.\n");
  }else if(*userVehicle == 3){
   printf("* You have selected Lorry.\n");
  }else{
   printf("Invalid Select!\n");

   }
}

void vehicleManagement(int vehiclesData[MAX_VEHICLES][4],int *userVehicle,char vehicles[MAX_VEHICLES][10]){
  printf("\n--------------------------------------------\n");
  printf("\n\t---Vehicle Management Section---\n");
  printf("\n");
  displayVehicleSet(vehiclesData,vehicles);
  selectVehicle(vehiclesData,vehicles,userVehicle);
  printf("\n--------------------------------------------\n");

}

