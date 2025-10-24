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

   for(i=0;i<currentCityCount;i++){
    for(j=0;j<currentCityCount;j++){
       fprintf(file,"%-8.2lf",distances[i][j]);
    }
     fprintf(file,"\n");
   }
   fclose(file);
   printf("Routes saved to routes.txt.\n");

}

void loadRoutesFromFile(){
  FILE *file = fopen("routes.txt\n","r");
  if (file == NULL) {
   printf("No routes.txt found — starting new.\n");
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
    printf("Diliveries save to dilivery.txt;");

 }
