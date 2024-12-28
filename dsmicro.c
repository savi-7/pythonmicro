#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense details
struct Expense {
    char description[50];
    float amount;
};

// Function prototypes
void addExpense(struct Expense expenses[], int *count);
void displayExpenses(struct Expense expenses[], int count);
float calculateTotal(struct Expense expenses[], int count);

int main() {
    struct Expense expenses[100]; // Array to store up to 100 expenses
    int count = 0; // Number of expenses added
    int choice;

    do {
        // Display menu
        printf("\nExpense Tracker Menu\n");
        printf("1. Add an Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count); // Add a new expense
                break;
            case 2:
                displayExpenses(expenses, count); // Display all expenses
                break;
            case 3:
                printf("Total Expenses: %.2f\n", calculateTotal(expenses, count)); // Display total
                break;
            case 4:
                printf("Exiting the Expense Tracker...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add an expense
void addExpense(struct Expense expenses[], int *count) {
    printf("Enter expense description: ");
    getchar(); // To consume the newline character left by scanf
    fgets(expenses[*count].description, sizeof(expenses[*count].description), stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = '\0'; // Remove newline character

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++; // Increment the expense count
    printf("Expense added successfully.\n");
}

// Function to display all expenses
void displayExpenses(struct Expense expenses[], int count) {
    int i;
    if (count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    printf("\n--- All Expenses ---\n");
    for ( i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

// Function to calculate total expenses
float calculateTotal(struct Expense expenses[], int count) {
    float total = 0;
    int i;
    for (i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}