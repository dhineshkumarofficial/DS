#include <stdio.h>
#include <string.h>
#define MAX 100
struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
};
struct Book lib[MAX];
int n = 0;
void addBook() {
    if (n >= MAX) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &lib[n].id);
    printf("Enter Title: ");
    scanf(" %[^\n]", lib[n].title);
    printf("Enter Author: ");
    scanf(" %[^\n]", lib[n].author);
    lib[n].issued = 0;
    n++;
    printf("Book added successfully!\n");
}
void display() {
    int i;
    if (n == 0) {
        printf("No books available.\n");
        return;
    }
    printf("\n%-6s %-22s %-20s %s\n", "ID", "Title", "Author", "Status");
    for (i = 0; i < n; i++) {
        printf("%-6d %-22s %-20s %s\n", lib[i].id, lib[i].title,
        lib[i].author, lib[i].issued ? "Issued" : "Available");
    }
}
int find(int id) {
    int i;
    for (i = 0; i < n; i++) {
        if (lib[i].id == id)
        return i;
    }
    return -1;
}
void searchBook() {
    int id, p;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    p = find(id);
    if (p == -1)
    printf("Book not found!\n");
    else
    printf("Found: %s by %s [%s]\n", lib[p].title, lib[p].author,
    lib[p].issued ? "Issued" : "Available");
}
void issueBook() {
    int id, p;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    p = find(id);
    if (p == -1)
    printf("Book not found!\n");
    else if (lib[p].issued)
    printf("Book is already issued.\n");
    else {
        lib[p].issued = 1;
        printf("Book issued successfully!\n");
    }
}
void returnBook() {
    int id, p;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    p = find(id);
    if (p == -1)
    printf("Book not found!\n");
    else if (!lib[p].issued)
    printf("Book was not issued.\n");
    else {
        lib[p].issued = 0;
        printf("Book returned successfully!\n");
    }
}
int main() {
    int ch;
    do {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1.Add Book  2.Display  3.Search\n");
        printf("4.Issue Book  5.Return Book  6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addBook();    break;
            case 2: display();    break;
            case 3: searchBook(); break;
            case 4: issueBook();  break;
            case 5: returnBook(); break;
            case 6: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 6);
    return 0;
}
