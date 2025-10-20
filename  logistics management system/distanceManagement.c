#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100

extern int currentCityCount;

void AddDistances(double distances[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_LENGTH],int currentCityCount){
  int i,j;
  double userDistance;

  if(currentCityCount<2){
    printf("Need at least two cities for make distances!\n");
    return;
   }


 for(i=0;i<currentCityCount;i++){
  for(j=i+1;j<currentCityCount;j++){
      printf("Distance from %s to %s (km): ",cities[i],cities[j]);
      scanf("%lf",&userDistance);

      if(userDistance<0){
       printf("Distance cannot be negative!");
       return;
      }
      distances[i][j] = userDistance;
      distances[j][i] = userDistance;

     }
   }

   for(i=0;i<currentCityCount;i++){
       distances[i][i] = 0;
   }



}

void displayDistance(double distances[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_LENGTH],int currentCityCount){
  int i,j;

  printf("%-12s"," From\\To ");

  for(i=0;i<currentCityCount;i++){
    printf("| %-10s |",cities[i]);
  }
  printf("|\n");

  for(i=0;i<currentCityCount;i++){
    printf(" %-10s |",cities[i]);

   for(j=0;j<currentCityCount;j++){
    printf(" %-10.2f | ",distances[i][j]);
    }
    printf("\n");
  }
}

void displayIndex(double distances[MAX_CITIES][MAX_CITIES],int currentCityCount){
    printf("\n\tIndex Structure Of the table\n");
    int row,col;
    for(col = 0;col<currentCityCount;col++){
       printf(" [%d] ",col);
    }
    printf("\n");
    for(row = 0;row<currentCityCount;row++){
       printf("[%d]",row);

    for(col=0;col<currentCityCount;col++){
       printf(" %6.2f ",distances[row][col]);
       }

       printf("\n");
    }

}

void editDistances(double distances[MAX_CITIES][MAX_CITIES],char cities[MAX_CITIES][MAX_LENGTH],int currentCityCount){

    printf("Your entered Data\n");
    displayDistance(distances, cities, currentCityCount);
    printf("\n");
    displayIndex(distances,currentCityCount);


    int editRow,editCol;
    double newVal;
    printf("Enter the index of the distance to edit: ");
    printf("Enter row: ");
    scanf("%d",&editRow);
    printf("Enter coloumn: ");
    scanf("%d",&editCol);

    if(editRow<0 || editRow>=currentCityCount || editCol<0 || editCol>=currentCityCount){
       printf("Invalid Coordinates!Please enter values between 0 and %d.\n",currentCityCount-1);
       return;
    }


   if(editRow == editCol){
       printf("Distance from a city to itself must be 0!\n");
       return;
   }

    printf("Enter the new Value: ");
    scanf("%lf",&newVal);

    if(newVal<0){
       printf("Distance cannot be negative!\n");
       return;
    }

    distances[editRow][editCol] = newVal;
    distances[editCol][editRow] = newVal;



}

void interfaceDistanceManagement(){
       printf("\t\t---Distance Management Section---\n");
       printf("\n");
       //printf("Select your option:\n");
       printf("1: Add Distances.\n");
       printf("2: Edit Distances.\n");
       printf("3: View Distances.\n");
       printf("4: Exit to Main Menu.\n");
}
