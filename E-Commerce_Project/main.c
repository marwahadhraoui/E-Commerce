#include <stdio.h>
#include <stdlib.h>
#include "e-commerce.h"

int main()
{
      USER user;
    ORDER order;
    ITEM itemTable[2];
    USER userTable[2];
    ITEM* p;
    USER* u;
    int BestSellProduct,tMax[];

    p=&itemTable;
    u=&userTable;


    int i;
    //fill T table of items
    int length = sizeof(itemTable) / sizeof(itemTable[0]);

    for (i =0;i<length;i++){
        fillItem(p+i);
    }
    //call the dislpay
     for (i =0;i<length;i++){
        displayItem(*(p+i));
    }

    for(i=0;i<length;i++){
    // Call the fillUser function to fill in user information
        tMax[i]= fillUser(u+i,itemTable,length);

    }


      BestSellProduct = bestSellingProduct(tMax,itemTable);

      printf("The id of best selling product is %d",BestSellProduct);
    // Call the display functions to print user and order information
    //displayUser(user);


    return 0;
}
