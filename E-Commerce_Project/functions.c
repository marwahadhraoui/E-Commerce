#include<stdio.h>
#include"e-commerce.h"
#include <stdbool.h>

int fillUser(USER* user, ITEM tItem [],int  length)
{
    int max;
    printf("****** USER Info ******\n");
    printf("Enter id : ");
    scanf("%d",&user->id);

    printf("Enter Firstname : ");
    scanf("%s",user->firstname);

    printf("\nEnter Lastname : ");
    scanf("%s",&user->lastname);

    printf("\nEnter Email : ");
    scanf("%s",&user->email);

    printf("\nEnter phone number : ");
    scanf("%d",&user->phoneNumber);
    printf("\nEnter your order informations : \n");
    max = fillOrder(&user->order,tItem,length);
    printf("-----------------------------------------------------\n");
    return max;

}

int fillOrder(ORDER* order, ITEM tItem [], int length )
{
    bool quit = true;
    int i,code,quantity,tabIndexMax[length],max;
    char x;


    printf("****** Odrer Info ******");
    printf("Enter Order Number: ");
    scanf("%d", &order->orderNumber);

    printf("Enter Date: ");
    scanf("%s", &order->date);

    printf("Enter Address: ");
    scanf("%s", &order->address);

    printf("Enter Promo Code: ");
    scanf("%d", &order->promoCode);

    printf("Select an item \n");
    scanf("%s",&x);
    while (x !='x')
    {

        i=0;
        while (i<length)
        {

            if(code == tItem[i].itemCode)
            {

                order->item[i]=tItem[i];
                printf("ordre %d",order->item[0].itemCode);
                printf("How many item? ");
                scanf("%d",&quantity);
                tabIndexMax[x]+= quantity;
                order->totalPrice=order->totalPrice+(quantity*tItem[i].price);
            }
            i++;
        }

        printf("Select another Item or Press x to exit: \n");
        scanf("%s",&x);
    }

    printf("-----------------------------------------------------\n");
    max = bestSellingProduct(tabIndexMax,tItem);
    return max;

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
int bestSellingProduct(int tabIndexMax[],ITEM tItem[])
{

int i,max=0,index=0;

for(i=0;i<2;i++){
    if(tabIndexMax[i]>max){
        max= tabIndexMax[i];
        index=i;
    }
return max;

}


}
