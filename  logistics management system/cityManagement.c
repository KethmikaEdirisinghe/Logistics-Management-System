#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_LENGTH 100

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
