#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_SALES 50

typedef struct {
    int day, month, year;
} Date;

typedef enum { PACKAGED, COOKED, COMBO } ItemType;

typedef struct {
    char name[30];
    float price;
    int stock;
    ItemType type;
    union {
        Date expiry;
        char preparedTime[10];
        int componentIds[3];
    } details;
} Item;

typedef struct {
    int itemId;
    int quantity;
    float revenue;
} Sale;

void showExpiryWarnings(const Item items[], int count, Date today) {
    for (int i = 0; i < count; i++) {
        if (items[i].type == PACKAGED) {
            Date d = items[i].details.expiry;
            int daysLeft = (d.year - today.year) * 365 +
                           (d.month - today.month) * 30 +
                           d.day - today.day;
            if (daysLeft >= 0 && daysLeft <= 2)
                printf("Expiry warning: %s expires within 2 days\n",
                       items[i].name);
        }
    }
}

int recordSale(Item items[], int count, Sale sales[], int *saleCount,
               int itemId, int quantity) {
    if (itemId < 0 || itemId >= count || quantity <= 0) {
        printf("Invalid sale details\n");
        return 0;
    }

    if (items[itemId].stock < quantity) {
        printf("Not enough stock for %s\n", items[itemId].name);
        return 0;
    }

    items[itemId].stock -= quantity;
    sales[*saleCount].itemId = itemId;
    sales[*saleCount].quantity = quantity;
    sales[*saleCount].revenue = items[itemId].price * quantity;
    (*saleCount)++;

    printf("Sale recorded: %s x%d\n", items[itemId].name, quantity);
    return 1;
}

void printSummary(const Sale sales[], int saleCount) {
    Sale sorted[MAX_SALES];

    for (int i = 0; i < saleCount; i++)
        sorted[i] = sales[i];

    for (int i = 0; i < saleCount - 1; i++) {
        for (int j = i + 1; j < saleCount; j++) {
            if (sorted[j].revenue > sorted[i].revenue) {
                Sale temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    printf("\nBill summary (highest revenue first):\n");
    for (int i = 0; i < saleCount; i++)
        printf("Item %d: quantity %d, revenue Rs.%.2f\n",
               sorted[i].itemId, sorted[i].quantity, sorted[i].revenue);
}

int main(void) {
    Item items[3] = {
        {"Juice", 30.0f, 10, PACKAGED, {.expiry = {20, 11, 2026}}},
        {"Sandwich", 50.0f, 5, COOKED, {.preparedTime = "10:30"}},
        {"Combo", 90.0f, 3, COMBO, {.componentIds = {0, 1, -1}}}
    };
    Sale sales[MAX_SALES];
    int saleCount = 0;
    Date today = {19, 11, 2026};

    recordSale(items, 3, sales, &saleCount, 0, 2);
    recordSale(items, 3, sales, &saleCount, 1, 8);
    recordSale(items, 3, sales, &saleCount, 1, 2);

    showExpiryWarnings(items, 3, today);
    printSummary(sales, saleCount);

    printf("\nRemaining stock: Juice=%d, Sandwich=%d\n",
           items[0].stock, items[1].stock);
    return 0;
}
