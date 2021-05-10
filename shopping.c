#include<stdio.h>
#include <stdlib.h>
#include "shopping.h"
#include <math.h>

//250201092 Aynur Atış

// This code compiled with gcc version 10.2.0

typedef struct{   // product struct

  char *productName;
  double price;
  int quantity;

}productInfos;

productInfos productInfosArray[10]; // the array is created for products to assign it
productInfos shoppingBasket[10];
int shoppingIndex = 0;

void getProductInfos(){         // assigns the all products to productInfosArray

  productInfos product_1;   // creates the first product
  product_1.productName = (char *)malloc(sizeof(char)*6);  // creates a space for productName in productName pointer
  product_1.productName = "Bread";
  product_1.price = 3.5;
  product_1.quantity = 10;
  productInfosArray[0] = product_1;   // first product assigns to productInfosArray[0]
  productInfos product_2;   // creates the second product
  product_2.productName = (char *)malloc(sizeof(char)*4); // creates a space for productName in productName pointer
  product_2.productName = "Egg";
  product_2.price = 2.82;
  product_2.quantity = 30;
  productInfosArray[1] = product_2; // second product assigns to productInfosArray[1]
  productInfos product_3;   // creates the third product
  product_3.productName = (char *)malloc(sizeof(char)*6); // creates a space for productName in productName pointer
  product_3.productName = "Pasta";
  product_3.price = 2.79;
  product_3.quantity = 15;
  productInfosArray[2] = product_3;   // third product assigns to productInfosArray[2]
  productInfos product_4;   // creates the fourth product
  product_4.productName = (char *)malloc(sizeof(char)*5);   // creates a space for productName in productName pointer
  product_4.productName = "Fish";
  product_4.price = 15.98;
  product_4.quantity = 25;
  productInfosArray[3] = product_4; // fourth product assigns to productInfosArray[3]
  productInfos product_5;   // creates the fifth product
  product_5.productName = (char *)malloc(sizeof(char)*5);   // creates a space for productName in productName pointer
  product_5.productName = "Milk";
  product_5.price = 10.26;
  product_5.quantity = 10;
  productInfosArray[4] = product_5; // fifth product assigns to productInfosArray[4]
  productInfos product_6;   // creates the sixth product
  product_6.productName = (char *)malloc(sizeof(char)*12);    // creates a space for productName in productName pointer
  product_6.productName = "Water Small";
  product_6.price = 1.55;
  product_6.quantity = 35;
  productInfosArray[5] = product_6;   // sixth product assigns to productInfosArray[5]
  productInfos product_7;   // creates the seventh product
  product_7.productName = (char *)malloc(sizeof(char)*15);    // creates a space for productName in productName pointer
  product_7.productName = "Hand Sanitizer";
  product_7.price = 20.55;
  product_7.quantity = 20;
  productInfosArray[6] = product_7;   // seventh product assigns to productInfosArray[6]
  productInfos product_8;   // creates the eighth product
  product_8.productName = (char *)malloc(sizeof(char)*11);    // creates a space for productName in productName pointer
  product_8.productName = "Toothpaste";
  product_8.price = 10.83;
  product_8.quantity = 15;
  productInfosArray[7] = product_8; // eightth product assigns to productInfosArray[7]
  productInfos product_9; // creates the nineth product
  product_9.productName = (char *)malloc(sizeof(char)*6);
  product_9.productName = "Pizza";
  product_9.price = 15.30;
  product_9.quantity = 10;
  productInfosArray[8] = product_9;   // n,neth product assigns to productInfosArray[8]
  productInfos product_10;    // creates the tenth product
  product_10.productName = (char *)malloc(sizeof(char)*10);
  product_10.productName = "Chocolate";
  product_10.price = 5.21;
  product_10.quantity = 40;
  productInfosArray[9] = product_10;  // tenth product assigns to productInfosArray[9]

}


int charSize(char productName[])  // calculates the char size
{
  int i=0;
  while(productName[i]!='\0')
  {
    i++;
  }
  return i;
}

int checkAllCharacter(char *a, char *b, int size) // check all characters of product_name is the same user input(ProductInput)
{
  int counter =0;
  for(int i=0; i<size; i++)
  {
    if(a[i] == b[i])
    {
      counter++;
    }
  }
  if(counter == size)
  {
    return 1;
  }
  else {
    return 0;
  }
}


void buyAProduct(){   // Buy a product method

  char *product_name; // product_name created as pointer
  int product_quantity; // product_quantity created
  product_name = (char *)malloc(sizeof(char) * 5);  // memory allocated for product name
  int product_name_size = 5;  // size of product_name that is created firstly
  char productInput[50];  // user input for product name

  printf("Name of product: ");
  scanf("%s", productInput);
  int char_size = charSize(productInput); // calling the charSize method for calculating the user input's size

  while(char_size>product_name_size)  // if the size of product_name that is created firstly is smaller than user input size, product_name size increase twice
  {
    product_name = (char *)malloc(sizeof(char) * product_name_size * 2);
    product_name_size = product_name_size * 2;
  }
  int k=0;
  while(productInput[k]!='\0') // copy the user input(productInput) to product_name
  {
    product_name[k] = productInput[k];
    k++;
  }
  int flag = 0; // check the product name is exist
  int sameProduct = 0;  // check the shopping basket, if the user want to buy the same product
  int checkCharacter = 0;
  int checkShoppingBasket = 0;
  for(int s=0; s<10; s++)
  {
    checkCharacter = checkAllCharacter(product_name,productInfosArray[s].productName, char_size); // check all characters of product_name
    if(checkCharacter == 1)
    {
      flag = 1;
      int quantity ;
      printf("Enter the quantity : ");
      scanf("%d", &quantity);
      if(quantity > productInfosArray[s].quantity) // check the enough product is exist
      {
        printf("There is not enough %s!\n", productInfosArray[s].productName);
      }
      else{
          for(int t=0; t<shoppingIndex; t++)
          {
            checkShoppingBasket = checkAllCharacter(product_name, shoppingBasket[t].productName, char_size); // check all characters of product_name
            if(checkShoppingBasket == 1) // if user want to buy same product
            {
              sameProduct = 1;
              shoppingBasket[t].quantity += quantity; // product quantity is incresed
              productInfosArray[s].quantity -= quantity; // total product is decreased
              break;
            }
          }
        if(sameProduct == 0){ // if the user want to different product
          productInfos prdct;
          prdct.productName = productInfosArray[s].productName;
          prdct.quantity = quantity;
          prdct.price = productInfosArray[s].price;
          shoppingBasket[shoppingIndex] = prdct;  // the product that the user wants to buy added to shoppingBasket
          shoppingIndex ++; // shoppingBasket array index
          productInfosArray[s].quantity -= quantity;  // total product is decreased
        }
        printf("You bought %d %s\n\n", quantity, productInfosArray[s].productName);
      }
    }
  }
  if(flag == 0){
    printf("Product not found\n\n!");
  }
}


void shoppingSummary()  // shopping summary method
{
  float totalPrice = 0;
  printf("-----------------------------Shopping Summary------------------------------\n" );
  for(int i=0; i<shoppingIndex; i++)
  {
      printf("Product name: %s,  Unit Price : %.2f,  Quantity : %d\n", shoppingBasket[i].productName, shoppingBasket[i].price, shoppingBasket[i].quantity);
      totalPrice += (shoppingBasket[i].price * shoppingBasket[i].quantity);
  }
  printf("----------------------------------------------------------------------------\n" );
  printf("Total Price: %.2f\n\n", totalPrice);
}


void allProducts(){ // list of all products

  //getProductInfos();
  printf("\n----------------------------Product List-----------------------------------\n" );
  for(int i=0; i<10;i++)
  {
    printf("Product Name: %s,  Unit Price: %.2f,  Quantity: %d\n", productInfosArray[i].productName, productInfosArray[i].price, productInfosArray[i].quantity);
  }
  printf("\n");
}
