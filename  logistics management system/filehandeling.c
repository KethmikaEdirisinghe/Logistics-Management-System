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

