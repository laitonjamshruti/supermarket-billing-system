#include <iostream>
#include <iomanip> // for setw formatting
using namespace std;

int main() {
    // Supermarket items
    string items[] = {"Apple", "Banana", "Milk", "Bread", "Eggs","Biscuits","Shampoo", "Toothpaste ","Sunscreen"};
    int prices[] = {50, 20, 30, 25, 10, 20, 120, 35, 250};
    int n = 9; // number of items

    // Cart details
    int cart[9] = {0}; // quantity of each item in the cart

    int choice, quantity;
    bool shopping = true;

    cout << "====================================\n";
    cout << "     Welcome to Supermarket Billing  \n";
    cout << "====================================\n";

    while (shopping) {
        cout << "\n--------- MAIN MENU ---------\n";
        cout << "1. Show Items\n";
        cout << "2. Add Item to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {

                cout << "\nAvailable Items:\n";
                cout << left << setw(5) << "No." << setw(10) << "Item" << "Price (Rs.)\n";
                for (int i = 0; i < n; i++) {
                    cout << left << setw(5) << i + 1 
                         << setw(10) << items[i] 
                         << prices[i] << endl;
                }
                break;
            }
            case 2: {
                int itemNo;
                cout << "\nEnter item number to add: ";
                cin >> itemNo;
                if (itemNo >= 1 && itemNo <= n) {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    cart[itemNo - 1] += quantity;
                    cout << quantity << " x " << items[itemNo - 1] << " added to cart.\n";
                } else {
                    cout << "Invalid item number!\n";
                }
                break;
            }
            case 3: {
                cout << "\n------ Your Cart ------\n";
                int total = 0;
                cout << left << setw(10) << "Item" 
                     << setw(10) << "Qty" 
                     << setw(10) << "Price" 
                     << setw(10) << "Total\n";
                for (int i = 0; i < n; i++) {
                    if (cart[i] > 0) {
                        int cost = cart[i] * prices[i];
                        cout << left << setw(10) << items[i] 
                             << setw(10) << cart[i] 
                             << setw(10) << prices[i] 
                             << setw(10) << cost << endl;
                        total += cost;
                    }
                }
                cout << "-----------------------------\n";
                cout << "Cart Total: Rs." << total << endl;
                break;
            }
            case 4: {
                cout << "\n===== FINAL BILL =====\n";
                int total = 0;
                cout << left << setw(10) << "  Item" 
                     << setw(10) << "  Qty" 
                     << setw(10) << "  Price" 
                     << setw(10) << "  Total\n";
                for (int i = 0; i < n; i++) {
                    if (cart[i] > 0) {
                        int cost = cart[i] * prices[i];
                        cout << left << setw(10) << items[i] 
                             << setw(10) << cart[i] 
                             << setw(10) << prices[i] 
                             << setw(10) << cost << endl;
                        total += cost;
                    }
                }
                cout << "-----------------------------\n";
                cout << "Grand Total: Rs." << total << endl;
                cout << "Thank you for shopping with us!\n";
                shopping = false; // exit after checkout
                break;
            }
            case 5: {
                cout << "Exiting... Thank you!\n";
                shopping = false;
                break;
            }
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
