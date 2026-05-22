#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50

// Structure for Books
typedef struct {
    int bookId;
    char title[100];
    char author[100];
    int quantity;
    int availableQuantity;
} Book;

// Structure for Members
typedef struct {
    int memberId;
    char name[100];
    char email[100];
    int booksIssued;
} Member;

// Structure for Issue Record
typedef struct {
    int bookId;
    int memberId;
    char issueDate[20];
    char dueDate[20];
    int isReturned;
} IssueRecord;

Book books[MAX_BOOKS];
Member members[MAX_MEMBERS];
IssueRecord records[MAX_BOOKS * MAX_MEMBERS];

int totalBooks = 0;
int totalMembers = 0;
int totalRecords = 0;

// Function Prototypes
void displayMenu();
void addBook();
void viewAllBooks();
void addMember();
void viewAllMembers();
void issueBook();
void returnBook();
void searchBook();
void searchMember();
void viewIssuedBooks();
void deleteBook();
void deleteMember();

int main() {
    int choice;
    
    printf("Welcome to the library\n");
    printf("Welcome to the library\n");
    printf("Welcome to the library\n");
    printf("Welcome to the library\n");

    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline from input buffer

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewAllBooks();
                break;
            case 3:
                addMember();
                break;
            case 4:
                viewAllMembers();
                break;
            case 5:
                issueBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                searchBook();
                break;
            case 8:
                searchMember();
                break;
            case 9:
                viewIssuedBooks();
                break;
            case 10:
                deleteBook();
                break;
            case 11:
                deleteMember();
                break;
            case 12:
                printf("\n✓ Thank you for using Library Management System!\n");
                exit(0);
            default:
                printf("\n✗ Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           MAIN MENU                 ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ 1.  Add Book                         ║\n");
    printf("║ 2.  View All Books                   ║\n");
    printf("║ 3.  Add Member                       ║\n");
    printf("║ 4.  View All Members                 ║\n");
    printf("║ 5.  Issue Book                       ║\n");
    printf("║ 6.  Return Book                      ║\n");
    printf("║ 7.  Search Book                      ║\n");
    printf("║ 8.  Search Member                    ║\n");
    printf("║ 9.  View Issued Books                ║\n");
    printf("║ 10. Delete Book                      ║\n");
    printf("║ 11. Delete Member                    ║\n");
    printf("║ 12. Exit                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
}

void addBook() {
    if (totalBooks >= MAX_BOOKS) {
        printf("\n✗ Library is full! Cannot add more books.\n");
        return;
    }

    printf("\n━━━━━━━━━━━ ADD BOOK ━━━━━━━━━━━\n");
    
    books[totalBooks].bookId = totalBooks + 1;
    
    printf("Enter Book Title: ");
    fgets(books[totalBooks].title, sizeof(books[totalBooks].title), stdin);
    books[totalBooks].title[strcspn(books[totalBooks].title, "\n")] = 0;
    
    printf("Enter Author Name: ");
    fgets(books[totalBooks].author, sizeof(books[totalBooks].author), stdin);
    books[totalBooks].author[strcspn(books[totalBooks].author, "\n")] = 0;
    
    printf("Enter Quantity: ");
    scanf("%d", &books[totalBooks].quantity);
    
    books[totalBooks].availableQuantity = books[totalBooks].quantity;
    
    totalBooks++;
    printf("\n✓ Book added successfully! (Book ID: %d)\n", books[totalBooks - 1].bookId);
}

void viewAllBooks() {
    if (totalBooks == 0) {
        printf("\n✗ No books in library!\n");
        return;
    }

    printf("\n━━━━━━━━━━━ ALL BOOKS ━━━━━━━━━━━\n");
    printf("\n%-5s %-30s %-20s %-10s %-12s\n", "ID", "Title", "Author", "Total", "Available");
    printf("═════════════════════════════════════════════════════════════════\n");

    for (int i = 0; i < totalBooks; i++) {
        printf("%-5d %-30s %-20s %-10d %-12d\n",
               books[i].bookId,
               books[i].title,
               books[i].author,
               books[i].quantity,
               books[i].availableQuantity);
    }
}

void addMember() {
    if (totalMembers >= MAX_MEMBERS) {
        printf("\n✗ Maximum members reached!\n");
        return;
    }

    printf("\n━━━━━━━━━━━ ADD MEMBER ━━━━━━━━━━━\n");
    
    members[totalMembers].memberId = totalMembers + 1;
    
    printf("Enter Member Name: ");
    fgets(members[totalMembers].name, sizeof(members[totalMembers].name), stdin);
    members[totalMembers].name[strcspn(members[totalMembers].name, "\n")] = 0;
    
    printf("Enter Email: ");
    fgets(members[totalMembers].email, sizeof(members[totalMembers].email), stdin);
    members[totalMembers].email[strcspn(members[totalMembers].email, "\n")] = 0;
    
    members[totalMembers].booksIssued = 0;
    
    totalMembers++;
    printf("\n✓ Member added successfully! (Member ID: %d)\n", members[totalMembers - 1].memberId);
}

void viewAllMembers() {
    if (totalMembers == 0) {
        printf("\n✗ No members in library!\n");
        return;
    }

    printf("\n━━━━━━━━━━━ ALL MEMBERS ━━━━━━━━━━━\n");
    printf("\n%-5s %-25s %-30s %-12s\n", "ID", "Name", "Email", "Books Issued");
    printf("═══════════════════════════════════════════════════════════════\n");

    for (int i = 0; i < totalMembers; i++) {
        printf("%-5d %-25s*");
    }
}