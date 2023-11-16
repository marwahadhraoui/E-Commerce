
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

 void  fillUser(USER*,ITEM*,int length,int result[]);
 void  fillOrdre(ORDER*,ITEM*,int length,int result[]);
 void fillItem(ITEM*);
 void displayUser(USER user);
 void displayOrder(ORDER order);
 int getMaxProductPerUser(int t[],ITEM TItem[],int result[]);
 void bestSellingProduct(int results[][100], int length,ITEM TItem[]);
 float getPriceAfterPromotion (USER userTable[],int length, int id ,int pourcentage);
 int findTopBuyingClient(USER tabUser[],int length);
 void listUserProducts(USER userTable[],int length, int id);
 int findMostExpensiveProduct(ITEM* ,int length);
