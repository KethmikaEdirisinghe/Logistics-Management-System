#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3


int  vehiclesData[MAX_VEHICLES][4] = {
  {1000,20,60,12},
  {5000,40,50,6},
  {10000,80,45,4} }

char vehicles[MAX_VEHICLES][10] = {"Van","Truck","Lorry"};
int userVehicle;

void displayVehicleSet(int vehiclesData[MAX_VEHICLES][4],char vehicles[MAX_VEHICLES][10]){
   int i,j,vehicleSelect;

   printf("Type\tCapacity(kg)\tRate per km(LKR)\tAvg Speed(km\h)\tFuel Efficiency(km/l)\n");

   for(i=0;i<3;i++){

     printf("%-10s\t%-12d\t%-16d\t%-15d\t%-21d\t\n",vehicles[i],vehiclesData[i][0],vehiclesData[i][1],vehiclesData[i][2],vehiclesData[i][3]);

   }

}

void selectVehicle(int vehiclesData[MAX_VEHICLES][4],char vehicles[MAX_VEHICLES][10],int userVehicle){

  printf("1-> Van\n ");
  printf("2-> Truck.\n");
  printf("3-> Lorry.\n");
  printf("Please Select your Vehicle: \n");
  scanf("%d",&userVehicle);

  if(userVehicle == 1){
   printf("You have selected Van.\n");
  }else if(userVehicle == 2){
   printf("You have selected Truck.\n");
  }else if(userVehicle == 3){
   printf("You have selected Lorry.\n");
  }else{
   printf("Invalid Select!\n");

   }
}

void vehicleManagement(int vehiclesData[MAX_VEHICLES][4],int userVehicle,char vehicles[MAX_VEHICLES][10]){
  printf("\n\tVehicle Management Section\n");
  displayVehicleSet(vehiclesData,vehicles);
  selectVehicle(vehiclesData,vehicles,userVehicle);

}
