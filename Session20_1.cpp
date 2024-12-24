#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char bookName[100];
    char author[50];
    long long price;
    char category[50];
} Book;
void inputBook(Book book[], int *n);
void printBook(Book book[], int n);
void addBook(Book book[], int *n);
void deleteBook(Book book[], int *n);
void updateBook(Book book[], int n);
void findBook(Book book[], int n);

int main() {
    Book books[50];
    int n = 0; 
    int choice;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Tim kiem sach theo ten sach\n");
        printf("7. Thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBook(books, &n);
                break;
            case 2:
                printBook(books, n);
                break;
            case 3:
                addBook(books, &n);
                break;
            case 4:
                deleteBook(books, &n);
                break;
            case 5:
                updateBook(books, n);
                break;
            case 6:
                findBook(books, n);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 7);

    return 0;
}
void inputBook(Book book[], int *n) {
    printf("Nhap so luong sach muon them: \n");
    scanf("%d", n);
    getchar(); 
    for (int i = 0; i < *n; i++) {
        book[i].id = i + 1;
        printf("Moi ban nhap vao ten sach: \n");
        fgets(book[i].bookName, 100, stdin);
        book[i].bookName[strcspn(book[i].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: \n");
        fgets(book[i].author, 50, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: \n");
        scanf("%lld", &book[i].price);
        getchar();
        printf("Moi ban nhap vao the loai: \n");
        fgets(book[i].category, 50, stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
    }
}
void printBook(Book book[], int n) {
    printf("In toan bo cac sach: \n");
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %d\n", book[i].id);
        printf("Ten sach: %s\n", book[i].bookName);
        printf("Gia tien: %lld\n", book[i].price);
        printf("Tac gia: %s\n", book[i].author);
        printf("The loai: %s\n", book[i].category);
    }
    printf("\n");
}
void addBook(Book book[], int *n) {
    getchar();
    book[*n].id = *n + 1;
    printf("Moi ban nhap vao ten sach: \n");
    fgets(book[*n].bookName, 100, stdin);
    book[*n].bookName[strcspn(book[*n].bookName, "\n")] = '\0';
    printf("Moi ban nhap vao ten tac gia: \n");
    fgets(book[*n].author, 50, stdin);
    book[*n].author[strcspn(book[*n].author, "\n")] = '\0';
    printf("Moi ban nhap vao gia tien: \n");
    scanf("%lld", &book[*n].price);
    getchar();
    printf("Moi ban nhap vao the loai: \n");
    fgets(book[*n].category, 50, stdin);
    book[*n].category[strcspn(book[*n].category, "\n")] = '\0';
    (*n)++;
}
void deleteBook(Book book[], int *n) {
    int position;
    printf("Moi ban nhap vao ma sach muon xoa: ");
    scanf("%d", &position);
    int findIndex = -1;
    for (int i = 0; i < *n; i++) {
        if (book[i].id == position) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("Khong tim thay sach de xoa\n");
    } else {
        for (int i = findIndex; i < *n - 1; i++) {
            book[i] = book[i + 1];
        }
        (*n)--;
    }
}
void updateBook(Book book[], int n) {
    int position;
    printf("Moi ban nhap vao ma sach muon cap nhat: ");
    scanf("%d", &position);
    int findIndex = -1;
    for (int i = 0; i < n; i++) {
        if (book[i].id == position) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("Khong tim thay sach de cap nhat\n");
    } else {
        getchar();
        printf("Moi ban nhap vao ten sach: \n");
        fgets(book[findIndex].bookName, 100, stdin);
        book[findIndex].bookName[strcspn(book[findIndex].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: \n");
        fgets(book[findIndex].author, 50, stdin);
        book[findIndex].author[strcspn(book[findIndex].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: \n");
        scanf("%lld", &book[findIndex].price);
        getchar();
        printf("Moi ban nhap vao the loai: \n");
        fgets(book[findIndex].category, 50, stdin);
        book[findIndex].category[strcspn(book[findIndex].category, "\n")] = '\0';
    }
}
void findBook(Book book[], int n) {
    char searchName[100];
    getchar();
    printf("Nhap ten sach can tim: \n");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(book[i].bookName, searchName) == 0) {
            printf("\nSach duoc tim thay:\n");
            printf("Ma sach: %d\n", book[i].id);
            printf("Ten sach: %s\n", book[i].bookName);
            printf("Gia tien: %lld\n", book[i].price);
            printf("Tac gia: %s\n", book[i].author);
            printf("The loai: %s\n", book[i].category);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach voi ten: %s\n", searchName);
    }
}


