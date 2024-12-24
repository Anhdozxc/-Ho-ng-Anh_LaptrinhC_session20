#include <stdio.h>
#include <string.h>
struct Product {
    char id[20];
    char name[50];
    float import_price;
    float sell_price;
    int quantity;
};
void inputProducts(Product products[], int *size, float *revenue);
void displayProducts(Product products[], int size);
void importProduct(Product products[], int size, float *revenue);
void updateProduct(Product products[], int size);
void sortProducts(Product products[], int size);
void searchProduct(Product products[], int size);
void sellProduct(Product products[], int size, float *revenue);
void displayRevenue(float revenue);

int main() {
    Product products[100];
    int size = 0;
    float revenue = 0;
    int choice;

    do {
        printf("\n========MENU========\n");
        printf("1. Nhap thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputProducts(products, &size, &revenue);
                break;
            case 2:
                displayProducts(products, size);
                break;
            case 3:
                importProduct(products, size, &revenue);
                break;
            case 4:
                updateProduct(products, size);
                break;
            case 5:
                sortProducts(products, size);
                break;
            case 6:
                searchProduct(products, size);
                break;
            case 7:
                sellProduct(products, size, &revenue);
                break;
            case 8:
                displayRevenue(revenue);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 9);

    return 0;
}
void inputProducts(Product products[], int *size, float *revenue) {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%s", products[*size].id);
        printf("Ten san pham: ");
        scanf("%s", products[*size].name);
        printf("Gia nhap: ");
        scanf("%f", &products[*size].import_price);
        printf("Gia ban: ");
        scanf("%f", &products[*size].sell_price);
        printf("So luong: ");
        scanf("%d", &products[*size].quantity);
        *revenue -= products[*size].import_price * products[*size].quantity;
        (*size)++;
    }
}
void displayProducts(Product products[], int size) {
    if (size == 0) {
        printf("Danh sach san pham rong.\n");
        return;
    }
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < size; i++) {
        printf("Ma: %s, Ten: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
               products[i].id, products[i].name, products[i].import_price,
               products[i].sell_price, products[i].quantity);
    }
}
void importProduct(Product products[], int size, float *revenue) {
    char id[20];
    int quantity;
    printf("Nhap ma san pham: ");
    scanf("%s", id);
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Nhap so luong: ");
            scanf("%d", &quantity);
            products[i].quantity += quantity;
            *revenue -= products[i].import_price * quantity;
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}
void updateProduct(Product products[], int size) {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", id);
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Cap nhat thong tin moi:\n");
            printf("Ten san pham: ");
            scanf("%s", products[i].name);
            printf("Gia nhap: ");
            scanf("%f", &products[i].import_price);
            printf("Gia ban: ");
            scanf("%f", &products[i].sell_price);
            printf("So luong: ");
            scanf("%d", &products[i].quantity);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}
void sortProducts(Product products[], int size) {
    int choice;
    printf("Sap xep theo gia: 1. Tang 2. Giam\n");
    printf("Lua chon: ");
    scanf("%d", &choice);

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((choice == 1 && products[i].sell_price > products[j].sell_price) ||
                (choice == 2 && products[i].sell_price < products[j].sell_price)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach san pham.\n");
}
void searchProduct(Product products[], int size) {
    char id[20];
    printf("Nhap ma san pham can tim: ");
    scanf("%s", id);
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Ma: %s, Ten: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
                   products[i].id, products[i].name, products[i].import_price,
                   products[i].sell_price, products[i].quantity);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}
void sellProduct(Product products[], int size, float *revenue) {
    char id[20];
    int quantity;
    printf("Nhap ma san pham: ");
    scanf("%s", id);
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].id, id) == 0) {
            if (products[i].quantity == 0) {
                printf("Het hang.\n");
                return;
            }
            printf("Nhap so luong can ban: ");
            scanf("%d", &quantity);
            if (quantity > products[i].quantity) {
                printf("Khong con du hang.\n");
            } else {
                products[i].quantity -= quantity;
                *revenue += products[i].sell_price * quantity;
                printf("Ban thanh cong.\n");
            }
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}
void displayRevenue(float revenue) {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}


