#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;   // 0 = Available, 1 = Issued
};

void addBook() {
    struct Book b;
    FILE *fp = fopen("library.txt", "ab");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    b.issued = 0;

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book Added Successfully!\n");
}

void issueBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.txt", "rb+");

    printf("Enter Book ID to Issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            if (b.issued == 0) {
                b.issued = 1;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book Issued Successfully!\n");
            } else {
                printf("Book Already Issued!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book Not Found!\n");

    fclose(fp);
}

void returnBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.txt", "rb+");

    printf("Enter Book ID to Return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            if (b.issued == 1) {
                b.issued = 0;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book Returned Successfully!\n");
            } else {
                printf("Book was not issued!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book Not Found!\n");

    fclose(fp);
}

void displayBooks() {
    struct Book b;
    FILE *fp = fopen("library.txt", "rb");

    printf("\n===== Book List =====\n");

    while (fread(&b, sizeof(b), 1, fp)) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n\n",
               b.id, b.title, b.author,
               b.issued ? "Issued" : "Available");
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: displayBooks(); break;
            case 5: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}