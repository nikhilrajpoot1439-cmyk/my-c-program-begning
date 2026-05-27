/*
 * ============================================================
 *         LIBRARY MANAGEMENT SYSTEM - C Language
 * ============================================================
 * Features:
 *   - Add, display, search, delete books
 *   - Issue and return books
 *   - Member management
 *   - File-based persistence (books.dat, members.dat)
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ───────────── Constants ───────────── */
#define MAX_BOOKS       100
#define MAX_MEMBERS     50
#define TITLE_LEN       100
#define AUTHOR_LEN      60
#define ISBN_LEN        20
#define NAME_LEN        60
#define ID_LEN          15
#define BOOKS_FILE      "books.dat"
#define MEMBERS_FILE    "members.dat"

/* ───────────── Structures ───────────── */
typedef struct {
    char  isbn[ISBN_LEN];
    char  title[TITLE_LEN];
    char  author[AUTHOR_LEN];
    int   year;
    int   total_copies;
    int   available_copies;
} Book;

typedef struct {
    char member_id[ID_LEN];
    char name[NAME_LEN];
    char issued_isbn[ISBN_LEN];   /* empty string = no book issued */
    char issue_date[20];
} Member;

/* ───────────── Globals ───────────── */
Book   books[MAX_BOOKS];
Member members[MAX_MEMBERS];
int    book_count   = 0;
int    member_count = 0;

/* ═══════════════════════════════════════
 *         FILE I/O
 * ═══════════════════════════════════════ */
void save_books(void) {
    FILE *fp = fopen(BOOKS_FILE, "wb");
    if (!fp) { printf("  [!] Could not save books.\n"); return; }
    fwrite(&book_count, sizeof(int), 1, fp);
    fwrite(books, sizeof(Book), book_count, fp);
    fclose(fp);
}

void load_books(void) {
    FILE *fp = fopen(BOOKS_FILE, "rb");
    if (!fp) return;
    fread(&book_count, sizeof(int), 1, fp);
    fread(books, sizeof(Book), book_count, fp);
    fclose(fp);
}

void save_members(void) {
    FILE *fp = fopen(MEMBERS_FILE, "wb");
    if (!fp) { printf("  [!] Could not save members.\n"); return; }
    fwrite(&member_count, sizeof(int), 1, fp);
    fwrite(members, sizeof(Member), member_count, fp);
    fclose(fp);
}

void load_members(void) {
    FILE *fp = fopen(MEMBERS_FILE, "rb");
    if (!fp) return;
    fread(&member_count, sizeof(int), 1, fp);
    fread(members, sizeof(Member), member_count, fp);
    fclose(fp);
}

/* ═══════════════════════════════════════
 *         UTILITY
 * ═══════════════════════════════════════ */
void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void flush_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_line(char ch, int n) {
    for (int i = 0; i < n; i++) putchar(ch);
    putchar('\n');
}

void get_today(char *buf) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buf, 20, "%Y-%m-%d", tm_info);
}

/* Find book index by ISBN; returns -1 if not found */
int find_book(const char *isbn) {
    for (int i = 0; i < book_count; i++)
        if (strcmp(books[i].isbn, isbn) == 0) return i;
    return -1;
}

/* Find member index by ID; returns -1 if not found */
int find_member(const char *id) {
    for (int i = 0; i < member_count; i++)
        if (strcmp(members[i].member_id, id) == 0) return i;
    return -1;
}

/* ═══════════════════════════════════════
 *         BOOK FUNCTIONS
 * ═══════════════════════════════════════ */
void add_book(void) {
    if (book_count >= MAX_BOOKS) {
        printf("  [!] Library is full. Cannot add more books.\n");
        return;
    }
    Book b;
    printf("\n  Enter ISBN        : "); scanf("%s", b.isbn); flush_input();
    if (find_book(b.isbn) != -1) {
        printf("  [!] Book with this ISBN already exists.\n");
        return;
    }
    printf("  Enter Title       : "); fgets(b.title,  TITLE_LEN,  stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    printf("  Enter Author      : "); fgets(b.author, AUTHOR_LEN, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("  Enter Year        : "); scanf("%d", &b.year); flush_input();
    printf("  Number of Copies  : "); scanf("%d", &b.total_copies); flush_input();
    b.available_copies = b.total_copies;

    books[book_count++] = b;
    save_books();
    printf("\n  [✓] Book added successfully!\n");
}

void display_all_books(void) {
    if (book_count == 0) { printf("\n  No books in library.\n"); return; }
    printf("\n");
    print_line('=', 82);
    printf("  %-15s %-30s %-20s %-4s  Avail/Total\n",
           "ISBN", "Title", "Author", "Year");
    print_line('-', 82);
    for (int i = 0; i < book_count; i++) {
        printf("  %-15s %-30s %-20s %-4d  %d/%d\n",
               books[i].isbn,
               books[i].title,
               books[i].author,
               books[i].year,
               books[i].available_copies,
               books[i].total_copies);
    }
    print_line('=', 82);
}

void search_book(void) {
    char keyword[TITLE_LEN];
    printf("\n  Search by Title / Author / ISBN: "); fgets(keyword, TITLE_LEN, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title,  keyword) ||
            strstr(books[i].author, keyword) ||
            strstr(books[i].isbn,   keyword)) {
            if (!found) {
                printf("\n  Search Results:\n");
                print_line('-', 70);
            }
            printf("  ISBN    : %s\n",  books[i].isbn);
            printf("  Title   : %s\n",  books[i].title);
            printf("  Author  : %s\n",  books[i].author);
            printf("  Year    : %d\n",  books[i].year);
            printf("  Copies  : %d available / %d total\n",
                   books[i].available_copies, books[i].total_copies);
            print_line('-', 70);
            found = 1;
        }
    }
    if (!found) printf("\n  [!] No books found matching \"%s\".\n", keyword);
}

void delete_book(void) {
    char isbn[ISBN_LEN];
    printf("\n  Enter ISBN of book to delete: "); scanf("%s", isbn); flush_input();
    int idx = find_book(isbn);
    if (idx == -1) { printf("  [!] Book not found.\n"); return; }
    if (books[idx].available_copies != books[idx].total_copies) {
        printf("  [!] Cannot delete — some copies are currently issued.\n");
        return;
    }
    /* Shift left */
    for (int i = idx; i < book_count - 1; i++) books[i] = books[i+1];
    book_count--;
    save_books();
    printf("  [✓] Book deleted.\n");
}

/* ═══════════════════════════════════════
 *         MEMBER FUNCTIONS
 * ═══════════════════════════════════════ */
void add_member(void) {
    if (member_count >= MAX_MEMBERS) {
        printf("  [!] Member limit reached.\n"); return;
    }
    Member m;
    printf("\n  Enter Member ID   : "); scanf("%s", m.member_id); flush_input();
    if (find_member(m.member_id) != -1) {
        printf("  [!] Member ID already exists.\n"); return;
    }
    printf("  Enter Full Name   : "); fgets(m.name, NAME_LEN, stdin);
    m.name[strcspn(m.name, "\n")] = '\0';
    m.issued_isbn[0] = '\0';
    m.issue_date[0]  = '\0';

    members[member_count++] = m;
    save_members();
    printf("\n  [✓] Member registered successfully!\n");
}

void display_all_members(void) {
    if (member_count == 0) { printf("\n  No members registered.\n"); return; }
    printf("\n");
    print_line('=', 70);
    printf("  %-12s %-25s %-18s %s\n", "Member ID", "Name", "Issued ISBN", "Issue Date");
    print_line('-', 70);
    for (int i = 0; i < member_count; i++) {
        printf("  %-12s %-25s %-18s %s\n",
               members[i].member_id,
               members[i].name,
               strlen(members[i].issued_isbn) ? members[i].issued_isbn : "(none)",
               strlen(members[i].issue_date)  ? members[i].issue_date  : "-");
    }
    print_line('=', 70);
}

void delete_member(void) {
    char id[ID_LEN];
    printf("\n  Enter Member ID to delete: "); scanf("%s", id); flush_input();
    int idx = find_member(id);
    if (idx == -1) { printf("  [!] Member not found.\n"); return; }
    if (strlen(members[idx].issued_isbn) > 0) {
        printf("  [!] Cannot delete — member has an issued book. Please return it first.\n");
        return;
    }
    for (int i = idx; i < member_count - 1; i++) members[i] = members[i+1];
    member_count--;
    save_members();
    printf("  [✓] Member deleted.\n");
}

/* ═══════════════════════════════════════
 *         ISSUE / RETURN
 * ═══════════════════════════════════════ */
void issue_book(void) {
    char member_id[ID_LEN], isbn[ISBN_LEN];
    printf("\n  Enter Member ID : "); scanf("%s", member_id); flush_input();
    int mi = find_member(member_id);
    if (mi == -1) { printf("  [!] Member not found.\n"); return; }
    if (strlen(members[mi].issued_isbn) > 0) {
        printf("  [!] Member already has a book issued (ISBN: %s).\n",
               members[mi].issued_isbn);
        return;
    }
    printf("  Enter Book ISBN : "); scanf("%s", isbn); flush_input();
    int bi = find_book(isbn);
    if (bi == -1) { printf("  [!] Book not found.\n"); return; }
    if (books[bi].available_copies == 0) {
        printf("  [!] No available copies of this book.\n"); return;
    }

    books[bi].available_copies--;
    strcpy(members[mi].issued_isbn, isbn);
    get_today(members[mi].issue_date);

    save_books();
    save_members();
    printf("\n  [✓] Book \"%s\" issued to %s on %s.\n",
           books[bi].title, members[mi].name, members[mi].issue_date);
}

void return_book(void) {
    char member_id[ID_LEN];
    printf("\n  Enter Member ID : "); scanf("%s", member_id); flush_input();
    int mi = find_member(member_id);
    if (mi == -1) { printf("  [!] Member not found.\n"); return; }
    if (strlen(members[mi].issued_isbn) == 0) {
        printf("  [!] This member has no issued book.\n"); return;
    }

    int bi = find_book(members[mi].issued_isbn);
    if (bi != -1) books[bi].available_copies++;

    printf("\n  [✓] Book (ISBN: %s) returned by %s.\n",
           members[mi].issued_isbn, members[mi].name);

    members[mi].issued_isbn[0] = '\0';
    members[mi].issue_date[0]  = '\0';

    save_books();
    save_members();
}

/* ═══════════════════════════════════════
 *         MENUS
 * ═══════════════════════════════════════ */
void book_menu(void) {
    int choice;
    do {
        printf("\n  ╔══════════════════════════╗\n");
        printf("  ║      BOOK MANAGEMENT     ║\n");
        printf("  ╠══════════════════════════╣\n");
        printf("  ║  1. Add Book             ║\n");
        printf("  ║  2. Display All Books    ║\n");
        printf("  ║  3. Search Book          ║\n");
        printf("  ║  4. Delete Book          ║\n");
        printf("  ║  0. Back                 ║\n");
        printf("  ╚══════════════════════════╝\n");
        printf("  Choice: "); scanf("%d", &choice); flush_input();
        switch (choice) {
            case 1: add_book();          break;
            case 2: display_all_books(); break;
            case 3: search_book();       break;
            case 4: delete_book();       break;
            case 0: break;
            default: printf("  [!] Invalid option.\n");
        }
    } while (choice != 0);
}

void member_menu(void) {
    int choice;
    do {
        printf("\n  ╔══════════════════════════╗\n");
        printf("  ║    MEMBER MANAGEMENT     ║\n");
        printf("  ╠══════════════════════════╣\n");
        printf("  ║  1. Add Member           ║\n");
        printf("  ║  2. Display All Members  ║\n");
        printf("  ║  3. Delete Member        ║\n");
        printf("  ║  0. Back                 ║\n");
        printf("  ╚══════════════════════════╝\n");
        printf("  Choice: "); scanf("%d", &choice); flush_input();
        switch (choice) {
            case 1: add_member();          break;
            case 2: display_all_members(); break;
            case 3: delete_member();       break;
            case 0: break;
            default: printf("  [!] Invalid option.\n");
        }
    } while (choice != 0);
}

void transaction_menu(void) {
    int choice;
    do {
        printf("\n  ╔══════════════════════════╗\n");
        printf("  ║     ISSUE / RETURN       ║\n");
        printf("  ╠══════════════════════════╣\n");
        printf("  ║  1. Issue Book           ║\n");
        printf("  ║  2. Return Book          ║\n");
        printf("  ║  0. Back                 ║\n");
        printf("  ╚══════════════════════════╝\n");
        printf("  Choice: "); scanf("%d", &choice); flush_input();
        switch (choice) {
            case 1: issue_book();  break;
            case 2: return_book(); break;
            case 0: break;
            default: printf("  [!] Invalid option.\n");
        }
    } while (choice != 0);
}

/* ═══════════════════════════════════════
 *         MAIN
 * ═══════════════════════════════════════ */
int main(void) {
    load_books();
    load_members();

    int choice;
    do {
        printf("\n");
        print_line('=', 34);
        printf("   LIBRARY MANAGEMENT SYSTEM\n");
        print_line('=', 34);
        printf("  Books: %-4d  Members: %d\n", book_count, member_count);
        print_line('-', 34);
        printf("  1. Book Management\n");
        printf("  2. Member Management\n");
        printf("  3. Issue / Return Book\n");
        printf("  0. Exit\n");
        print_line('-', 34);
        printf("  Choice: "); scanf("%d", &choice); flush_input();

        switch (choice) {
            case 1: book_menu();        break;
            case 2: member_menu();      break;
            case 3: transaction_menu(); break;
            case 0: printf("\n  Goodbye!\n\n"); break;
            default: printf("  [!] Invalid option.\n");
        }
    } while (choice != 0);

    return 0;
}