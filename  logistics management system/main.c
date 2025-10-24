#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
#define MAX_RECORDS 50
#define MAX_DATA 13

int currentCityCount;
int recordIndex=0;
int userVehicle;
char cities[MAX_CITIES][MAX_LENGTH];
double distances[MAX_CITIES][MAX_CITIES];
double distance;
int  vehiclesData[MAX_VEHICLES][4] = {
  {1000,20,60,12},
  {5000,40,50,6},
  {10000,80,45,4}

};
char vehicles[MAX_VEHICLES][10] = {"Van","Truck","Lorry"};
double records[MAX_RECORDS][MAX_DATA];

void cityManagement();
void performances();
void interfaceMainMenu();
void saveRoutesToFile();
void loadRoutesFromFile();
void loadDiliveriesFromFile();
void saveDiliveriesToFile();
void vehicleManagement(int vehiclesData[MAX_VEHICLES][4],int *userVehicle,char vehicles[MAX_VEHICLES][10]);
void distanceManagement(double distances[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_LENGTH]);

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
                            double diliveryRecords[MAX_RECORDS][MAX_DATA]);

void distanceManagement(double distances[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_LENGTH]);

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
                  double distances[MAX_CITIES][MAX_CITIES]);



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


int main()
{


   int sourse;
   int destination;
   double weight;
   double diliveryCost,estimatedTime,fuelConsumpion,fuelCost,totalCost,profit,finalCost;
   double diliveryRecords[MAX_RECORDS][MAX_DATA];


  loadRoutesFromFile();
  loadDiliveriesFromFile();


  //vehicleManagement(vehiclesData,userVehicle);
  //distanceManagement(distances,cities,currentCityCount);

  // diliveryRequestSection(cities,vehiclesData,&sourse,&destination,&weight,diliveryRecords);
  //Calculations(&sourse,&destination,&weight,&diliveryCost,&estimatedTime,&fuelConsumpion,&fuelCost,&totalCost,&profit,&finalCost,distance,vehiclesData,distances);
  int userCommandMainMenu;

  do{

   interfaceMainMenu();
   printf("Select what you want to do: ");
   scanf("%d",&userCommandMainMenu);

   while (getchar() != '\n' && getchar() != EOF);

   switch(userCommandMainMenu){

   case 1:{
   cityManagement();

   }break;

   case 2:{
   distanceManagement(distances,cities);
   }break;

   case 3:{
   diliveryRequestSection(cities,vehiclesData,&sourse,&destination,&weight,distance,&diliveryCost,&estimatedTime,&fuelConsumpion,&fuelCost,&totalCost,
   &profit,&finalCost,diliveryRecords);
   //Calculations( &sourse,&destination,&weight,&diliveryCost,&estimatedTime,&fuelConsumpion,&fuelCost,&totalCost,&profit,&finalCost,distance,vehiclesData,distances);
   //recordDilivery(&sourse, &destination, &weight,&diliveryCost, &estimatedTime, &fuelConsumpion,&fuelCost, &totalCost, &profit, &finalCost,distance, vehiclesData, distances);
   }break;

   case 4:{
   performances();
   }break;

   case 5:{
   printf("Thank You for Using our system.\n");
   printf("Exit Completed...\n");
   saveRoutesToFile();
   saveDiliveriesToFile();

   return 0;

   }break;

   default:
    printf("Invalid Input!Please check the Main Menu.\n");
    break;
 }


  }while(userCommandMainMenu != 5);

    return 0;
}
