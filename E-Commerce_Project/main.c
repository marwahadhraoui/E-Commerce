#include <stdio.h>
#include <stdlib.h>
#include "e-commerce.h"

int main()
{
    const percent=20;
    USER user;
    ORDER order;
    ITEM* itemTable;
    USER* userTable;
    int idMostExpensiveItem,idUser,topBuyingClient;
    ITEM* p;
    USER* u;
    float priceAfterPromo;
    p=&itemTable;
    u=&userTable;
    int i,itemTableSize,userTableSize;
    printf("Enter Item table size : \n");
    scanf("%d",&itemTableSize);
    printf("Enter User table size : \n");
    scanf("%d",&userTableSize);
    int result[userTableSize][userTableSize];
    itemTable=(ITEM*)malloc(itemTableSize*sizeof(ITEM));
    userTable=(USER*)malloc(userTableSize*sizeof(USER));

    for (i =0; i<itemTableSize; i++)
    {
        fillItem(p+i);
    }
    //call the dislpay
    for (i =0; i<itemTableSize; i++)
    {
        displayItem(*(p+i));
    }
    // Call the fillUser function to fill in user information
    for(i=0; i<userTableSize; i++)
    {
        fillUser(u+i,&itemTable,itemTableSize,result[i]);
    }
    bestSellingProduct(result,userTableSize,&itemTable);
    printf("\n----------------------------------\n");
    idMostExpensiveItem=findMostExpensiveProduct(&itemTable,itemTableSize);
    printf("The name of the Most expensive item is %s \n",itemTable[idMostExpensiveItem].label);
    printf("\n----------------------------------\n");
    printf("Enter the ID of the user you wish to see its lists of products");
    scanf("%d",&idUser);
    listUserProducts(userTable,userTableSize,idUser);
    printf("\n----------------------------------\n");
    printf("Enter user's ID you wish to calculate their total price for.");
    scanf("%d",&idUser);
    priceAfterPromo = getPriceAfterPromotion(userTable,userTableSize,idUser,percent);
    printf("\n----------------------------------\n");
    printf("After promotion, the total price is %2.f \n",priceAfterPromo);
    topBuyingClient =findTopBuyingClient(userTable,userTableSize);
    printf("\n-----------------------------\n");
    printf("Top buying Client is :\n");
    displayUser(userTable[topBuyingClient]);
    return 0;
}
