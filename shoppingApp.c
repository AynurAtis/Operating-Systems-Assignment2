#include<stdio.h>
#include<stdlib.h>
#include "shopping.h"

// 250201092 Aynur Atış

// This code compiled with gcc version 10.2.0

int main(){

  getProductInfos();
  int option;
  printf("WELCOME TO SHOPPING APP!\n\n");

  while(1){
    printf("------MAIN MENU-------\n");
    printf("1- Buy a product\n");
    printf("2- List all products\n");
    printf("3- Shopping summary\n");
    printf("4- Exit\n");
    printf("-------------------------\n");
    printf("Enter the choice: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
      buyAProduct();
      break;
      case 2:
        allProducts();
        break;
      case 3:
      shoppingSummary();
        break;
      case 4:
        printf("Good Bye!\n");
        exit(EXIT_SUCCESS);
        break;
      default:
        printf("Invalid Option!\n");
        break;
    }
 }
}
