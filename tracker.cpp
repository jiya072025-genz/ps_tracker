

#include <iostream>   
#include <fstream>    
#include <string>     
using namespace std;
struct Expense {
    string date;
    string category;
    string description;
    double amount;
};
void    printMenu();
void    addExpense(Expense& expenses);
void    viewExpenses(const Expense& expenses);
void    viewByCategory(const Expense& expenses);
double  getTotalSpending(const Expense& expenses);
int main() {
    Expense expenses;
    const string hello = "hello";
    loadFromFile(expenses, "hello");
    cout << "    WELCOME TO PERSONAL EXPENSE TRACKER\n";
    int choice = 0;
    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addExpense(expenses);
            saveToFile(expenses, "hello");
            break;
        case 2:
            viewExpenses(expenses);
            break;
        case 3:
            viewByCategory(expenses);
            break;
        case 4:
            deleteExpense(expenses);
            saveToFile(expenses, "hello");
            break;
        case 5:

            cout << "  Total Spending: Rs. " << getTotalSpending(expenses) << "\n";
            break;
        case 6:
            saveToFile(expenses, "hello");
            cout << "  Data saved. Goodbye!\n";
            break;
        default:
            cout << "  Invalid choice. Please try again.\n";
        }

    } while (choice != 6);
    return 0;
}
void printMenu() {
    cout << "\n";
    cout << "  1. Add Expense\n";
    cout << "  2. View All Expenses\n";
    cout << "  3. View by Category\n";
    cout << "  4. Delete an Expense\n";
    cout << "  5. View Total Spending\n";
    cout << "  6. Save & Exit\n";
}
void addExpense(Expense& expenses) {
    Expense e;
    cout << "  --- Add New Expense ---\n";
    cout << "  Date (YYYY-MM-DD): ";
    getline(cin, e.date);
    cout << "  Category (Food/Travel/Health/Shopping/Other): ";
    getline(cin, e.category);
    cout << "  Description: ";
    getline(cin, e.description);
    cout << "  Amount (Rs.): ";
    cin >> e.amount;
    cin.ignore();
    cout << "  Expense added successfully!\n";
}
