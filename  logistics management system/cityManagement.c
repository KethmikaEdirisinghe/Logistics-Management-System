#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100
#define MAX_VEHICLES 3
extern int currentCityCount;
extern char cities[MAX_CITIES][MAX_LENGTH];

void addCities(char cities[MAX_CITIES][MAX_LENGTH],int *currentCityCount){
   char citynames[MAX_LENGTH];
   char addMore;

do{
   if(*currentCityCount>=MAX_CITIES){
    printf("City Limit Reached!.Cannot Add More.\n");
    return;
   }
   printf("Enter the name of the city: ");
   scanf("%s",citynames);


   strcpy(cities[*currentCityCount],citynames);
   (*currentCityCount)++;

   printf("Do you want to add another City?(y/N): ");
   scanf(" %c",&addMore);

  }while(addMore == 'Y' || addMore == 'y');

}

void renameInput(char cities[MAX_CITIES][MAX_LENGTH],int currentCityCount){
  int userIndexrename;
  char newCityName[MAX_LENGTH];

  printf("Enter the index of the city(0 -%d): ",currentCityCount-1);
  scanf("%d",&userIndexrename);

  if(userIndexrename<0 || userIndexrename>= currentCityCount){
    printf("Invalid City Index!\n");
    return;
  }

  printf("Enter the new name of the city: ");
  scanf("%s",newCityName);

  strcpy(cities[userIndexrename],newCityName);

}

void removeName(char cities[MAX_CITIES][MAX_LENGTH],int *currentCityCount){
  int userIndexremove;
  int i;

  printf("Enter the index of city you need to remove: ");
  scanf("%d",&userIndexremove);

  if(userIndexremove<0 || userIndexremove>= *currentCityCount){
   printf("Invalid City Index!\n");
   return;
  }

  for(i=userIndexremove;i<=*currentCityCount-1;i++){
     strcpy(cities[i],cities[i+1]);
  }
  (*currentCityCount)--;
   printf("City removed successfully.\n");
}

void cityManagement(){
  int userCommandCityManagement;
  char addMore = 'Y';

  do{
   interfaceCityManagement();
   printf("Select what you want to do: ");
   scanf("%d",&userCommandCityManagement);

   switch(userCommandCityManagement){
     case 1:{
       printf("------------------------------------------------------------------------------\n");
       printf("\n\t----Add cities-----\n");
       addCities(cities,&currentCityCount);
       printf("------------------------------------------------------------------------------\n");
     }break;

     case 2:{
       printf("------------------------------------------------------------------------------\n");
       printf("\n\t----Rename City ----\n");
       renameInput(cities, currentCityCount);
       printf("------------------------------------------------------------------------------\n");
     }break;

     case 3:{
       printf("------------------------------------------------------------------------------\n");
       printf("\n\t----Remove City ----\n");
       removeName(cities, &currentCityCount);
       printf("------------------------------------------------------------------------------\n");

     }break;

     case 4:{
      printf("Return to Main Menu.\n");
      return;
     }break;

     default:
      printf("Invalid Option! Try again.\n");
   }

  }while(1); // until return called

}

