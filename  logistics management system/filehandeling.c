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
extern double distances[MAX_CITIES][MAX_CITIES];
extern double distance;
extern int  vehiclesData[MAX_VEHICLES][4];
extern double records[MAX_RECORDS][MAX_DATA];

void saveRoutesToFile(){
   FILE *file = fopen("routes.txt","w");
   if(file == NULL){
       printf("Error opening routes.txt for writing!\n");
       return;
   }
   fprintf(file,"=== CITY LIST ====\n");
   fprintf(file,"Total Cities: %d\n\n",currentCityCount);
   int i,j;
   for(i=0;i<currentCityCount;i++){
       fprintf(file,"[%d]%s\n",i+1,cities[i]);
   }
   fprintf(file,"\n==== DISTANCE MATRIX(km) ====\n");

   fprintf(file,"From\\To");
   for(i=0;i<currentCityCount;i++){
       fprintf(file,"%6d ",i+1);
   }
   fprintf(file,"\n");

   for(i=0;i<currentCityCount;i++){
       fprintf(file,"%6d ",i+1);

    for(j=0;j<currentCityCount;j++){
       fprintf(file,"%-6.2lf",distances[i][j]);
    }
     fprintf(file,"\n");
   }
   fclose(file);
   printf("Routes saved to routes.txt.\n");

}

void loadRoutesFromFile(){
  FILE *file = fopen("routes.txt","r");
  if (file == NULL) {
   printf("No saved datain routes.txt\nStarting New.\n");
   return;
  }

 fscanf(file,"==== CITY LIST ====\n");
 fscanf(file,"Total Cities : %d\n\n",&currentCityCount);

  int i,j;
  for(i = 0;i<currentCityCount;i++){
   fscanf(file,"[%*d] %[^\n]\n",cities[i]);
 }
  fscanf(file,"\n=== DISTANCE MATRIX(km)===\n");

  for(i=0;i<currentCityCount;i++){
        fscanf(file,"%d");
       for(j=0;j<currentCityCount;j++){
              fscanf(file,"%lf",&distances[i][j]);

       }
   }
     fclose(file);
     printf("Routes loaded from routes.txt\n");
}


void saveDiliveriesToFile(){

    FILE *file = fopen("deliveries.txt", "w");
    if (file == NULL) {
      printf("Error opening deliveries.txt for writing!\n");
      return;
    }

    fprintf(file,"\t===DILIVERY HISTORY===\n");
    fprintf(file,"Total Diliveries: %d\n\n",recordIndex);

    int i;
    for(i=0;i<recordIndex;i++){

        fprintf(file, "-------------------------------------\n");
        fprintf(file, "Record #%d\n", i + 1);
        fprintf(file, "From City Index: %.0lf\n", records[i][1]);
        fprintf(file, "To City Index: %.0lf\n", records[i][2]);
        fprintf(file, "Distance: %.2lf km\n", records[i][3]);
        fprintf(file, "Vehicle Type: %.0lf\n", records[i][4]);
        fprintf(file, "Package Weight: %.2lf kg\n", records[i][5]);
        fprintf(file, "Delivery Cost: %.2lf LKR\n", records[i][6]);
        fprintf(file, "Fuel Consumption: %.2lf L\n", records[i][7]);
        fprintf(file, "Fuel Cost: %.2lf LKR\n", records[i][8]);
        fprintf(file, "Total Cost: %.2lf LKR\n", records[i][9]);
        fprintf(file, "Profit: %.2lf LKR\n", records[i][10]);
        fprintf(file, "Final Cost: %.2lf LKR\n", records[i][11]);
        fprintf(file, "Estimated Time: %.2lf hrs\n", records[i][12]);
        fprintf(file, "-------------------------------------\n");

    }
    fclose(file);
    printf("Diliveries save to dilivery.txt");

 }

 void loadDiliveriesFromFile() {
    FILE *file = fopen("deliveries.txt", "r");
    if (file == NULL) {
        printf("No saved data in deliveires.txt\nstarting new.\n");
        return;
    }

    fscanf(file, "==== DELIVERY HISTORY ====\n");
    fscanf(file, "Total Deliveries: %d\n\n", &recordIndex);

    for (int i = 0; i < recordIndex; i++) {

        fscanf(file, "-------------------------------------\n");
        fscanf(file, "Record #%*d\n");
        fscanf(file, "From City Index: %lf\n", &records[i][1]);
        fscanf(file, "To City Index: %lf\n", &records[i][2]);
        fscanf(file, "Distance: %lf km\n", &records[i][3]);
        fscanf(file, "Vehicle Type: %lf\n", &records[i][4]);
        fscanf(file, "Package Weight: %lf kg\n", &records[i][5]);
        fscanf(file, "Delivery Cost: %lf LKR\n", &records[i][6]);
        fscanf(file, "Fuel Consumption: %lf L\n", &records[i][7]);
        fscanf(file, "Fuel Cost: %lf LKR\n", &records[i][8]);
        fscanf(file, "Total Cost: %lf LKR\n", &records[i][9]);
        fscanf(file, "Profit: %lf LKR\n", &records[i][10]);
        fscanf(file, "Final Cost: %lf LKR\n", &records[i][11]);
        fscanf(file, "Estimated Time: %lf hrs\n", &records[i][12]);
        fscanf(file, "-------------------------------------\n");
        records[i][0] = i;
    }

    fclose(file);
    printf("Deliveries loaded from deliveries.txt\n");
}
