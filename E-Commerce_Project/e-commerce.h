
struct item {
    int itemCode;
    char label[100];
    float price;
};
typedef struct item ITEM;


struct order {
    int orderNumber;
    char date[20];
    char address[100];
    int promoCode;
    float totalPrice;
    ITEM item[10];
};
typedef struct order ORDER;

struct user {
    char firstname[50];
    char lastname[50];
    char email[100];
    int phoneNumber;
    int id;
    ORDER order;
};

typedef struct user USER;

//Définition des fonctions

 int  fillUser(USER*,ITEM T[],int length);
 int  fillOrdre(ORDER*,ITEM T[],int length);
 void fillItem(ITEM*);
 void displayUser(USER user);
 void displayOrder(ORDER order);
 int bestSellingProduct(int t[],ITEM TItem[]);
