#include<stdio.h>
#include"e-commerce.h"
#include <stdbool.h>

void fillUser(USER* user, ITEM* tItem ,int  length,int result[])
{
    printf("****** USER Info ******\n");
    printf("Enter id : ");
    scanf("%d",&user->id);

    printf("Enter Firstname : ");
    scanf("%s",&user->firstname);

    printf("\nEnter Lastname : ");
    scanf("%s",&user->lastname);

    printf("\nEnter Email : ");
    scanf("%s",&user->email);

    printf("\nEnter phone number : ");
    scanf("%d",&user->phoneNumber);
    printf("\nEnter your order informations : \n");
    fillOrder(&user->order,tItem,length,result);
    printf("-----------------------------------------------------\n");


}

void fillOrder(ORDER* order, ITEM* tItem , int length,int result[] )
{
    int i,code,quantity,tabIndexMax[length],max,j=0;
    // Initialize tabIndexMax to zero
    for (i = 0; i <= length; i++) ////////////////////////////////////////////
    {
        tabIndexMax[i] = 0;
    }
    printf("****** Odrer Info ******");
    printf("\nEnter Order Number: ");
    scanf("%d", &order->orderNumber);

    printf("Enter Date: ");
    scanf("%s", &order->date);

    printf("Enter Address: ");
    scanf("%s", &order->address);

    printf("Enter Promo Code: ");
    scanf("%d", &order->promoCode);

    printf("Select an item by taping it's code (1 or 2) or 0 to exit \n");
    scanf("%d",&code);
    while (code != 0){
        i=0;
        while (i < length){
            if(code == tItem[i].itemCode){
                order->item[j]=tItem[i];
                j++;
                printf("How many item? ");
                scanf("%d",&quantity);
                tabIndexMax[tItem[i].itemCode] += quantity;
                order->totalPrice=order->totalPrice+(quantity*tItem[i].price);
            }
            i++;}

        printf("Select another Item or Press 0 to exit: \n");
        scanf("%d",&code);
    }
    printf("-----------------------------------------------------\n");
    getMaxProductPerUser(tabIndexMax,tItem,result);
}
void fillItem(ITEM* item)
{
    printf("Enter Item code : ");
    scanf("%d", &item->itemCode);

    printf("Enter Label: ");
    scanf("%s", &item->label);

    printf("Enter Price: ");
    scanf("%f", &item->price);

    printf("-----------------------------------------------------\n");

}

void displayUser(USER user)
{
    printf("User Information:\n");
    printf("First Name: %s\n", user.firstname);
    printf("Last Name: %s\n", user.lastname);
    printf("Email: %s\n", user.email);
    printf("Phone Number: %d\n", user.phoneNumber);
    printf("User ID: %d\n", user.id);
    printf("-----------------------------------------------------\n");
}

void displayOrder(ORDER order)
{
    printf("Order Information:\n");
    printf("Order Number: %d\n", order.orderNumber);
    printf("Date: %s\n", order.date);
    printf("Address: %s\n", order.address);
    printf("Promo Code: %d\n", order.promoCode);

    printf("Total Price: %.2f\n", order.totalPrice);
    printf("-----------------------------------------------------\n");

}
void displayItem (ITEM item)
{
    printf("Item code : %d\n",item.itemCode);
    printf("Item label : %s\n",item.label);
    printf("Item price: %.2f\n",item.price);
    printf("*****************************************************\n");

}
int getMaxProductPerUser(int tabIndexMax[],ITEM tItem[],int result[])
{

    result[0] = 0; // index
    result[1] = 0; // max quantity

    for (int i = 0; i < 2; i++)
    {
        if (tabIndexMax[tItem[i].itemCode] > result[1])
        {
            result[1] = tabIndexMax[tItem[i].itemCode];
            result[0] = tItem[i].itemCode; // update index
        }
    }
}

void bestSellingProduct(int results[][100], int length,ITEM TItem[])
{

    int i,index, maxQuantity= results[0][1];
    index = results[0][0];
    for(i=0; i<length; i++)
    {
        if (results[i][1] > maxQuantity)
        {
            maxQuantity = results[i][1];
            index=results[i][0];
        }
    }

    for(i=0; i<=length; i++)
    {
        if(TItem[i].itemCode == index)
        {
            printf("The Best Selling product is :\n");
            displayItem(TItem[i]);

        }
    }
}

    int findTopBuyingClient(USER tabUser[], int length)
    {

        int lengthItems,lengthNonEmpty,max=-1,indiceUser=0;
        for (int i =0 ; i<length ; i++)
        {
            lengthNonEmpty=0;
            lengthItems=sizeof(tabUser[i].order.item) / sizeof(tabUser[i].order.item[0]);
            printf("the size of items %d ",lengthItems);
            for (int j =0 ; j<lengthItems ; j++)
            {

                if(strlen(tabUser[i].order.item[j].label)>3)
                {
                    lengthNonEmpty=lengthNonEmpty+1;
                }
            }
            printf("the size of items  %d \n",lengthNonEmpty);
            if(lengthNonEmpty>max)
            {
                max = lengthNonEmpty;
                indiceUser=i;
            }
        }
        return indiceUser;
    }

    float getPriceAfterPromotion (USER userTable[],int length,int id ,int pourcentage){
    float priceAfterPromo=0;


    for (int i =0 ; i<length ;i++)
    {
        if(userTable[i].id ==id)

        {
             if(userTable[i].order.promoCode!=0)
        {
             priceAfterPromo=(userTable[i].order.totalPrice*pourcentage)/100;
        }
        else{
             priceAfterPromo=userTable[i].order.totalPrice;
        }

        }
    }
    return priceAfterPromo;

}

void listUserProducts(USER userTable[],int length, int id){
  int lengthItems=0;

  printf("The list of products buyed by this user is : \n");
    for (int i =0 ;i<length;i++)
    {

        if(userTable[i].id==id)
        {
             lengthItems=sizeof(userTable[i].order.item) / sizeof(userTable[i].order.item[0]);
             printf("%d",lengthItems);
             for(int j=0;j<lengthItems;j++)
             {


                          printf("The name of product is %s \n ",userTable[i].order.item[j].label);

             }
        }
    }
}

int findMostExpensiveProduct(ITEM* itemTable,int length){
float highPrice=0;
int indice=0;
 for (int i =0 ;i<length;i++)
    {
        if(itemTable[i].price>highPrice)
        {
            highPrice=itemTable[i].price;
            indice =i;
        }
    }
    return indice;
}


