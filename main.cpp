#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Order {
    string name;
    int price;
    int quantity;
};

// Display food and drink menu
void displayMenu() {
    cout << "\n========================================\n";
    cout << "          MINI CASHIER SYSTEM           \n";
    cout << "========================================\n";

    cout << "\nFOOD MENU\n";
    cout << "1. Fried Rice          Rp 15000\n";
    cout << "2. Fried Chicken       Rp 12000\n";
    cout << "3. Fried Noodles       Rp 13000\n";
    cout << "4. Meatball Soup       Rp 10000\n";
    cout << "5. Chicken Noodles     Rp 12000\n";

    cout << "\nDRINK MENU\n";
    cout << "6. Iced Tea            Rp 5000\n";
    cout << "7. Orange Juice        Rp 8000\n";
    cout << "8. Mineral Water       Rp 4000\n";
    cout << "9. Iced Coffee         Rp 10000\n";
    cout << "10. Milk               Rp 7000\n";

    cout << "----------------------------------------\n";
    cout << "0. Finish Ordering\n";
    cout << "========================================\n";
}

// Calculate total price
long long calculateTotal(const vector<Order>& cart) {
    long long total = 0;

    for (const auto& item : cart) {
        total += 1LL * item.price * item.quantity;
    }

    return total;
}

// Display payment receipt
void displayReceipt(const vector<Order>& cart,
                    long long total,
                    long long payment) {

    cout << "\n========================================\n";
    cout << "              SALES RECEIPT             \n";
    cout << "========================================\n";

    cout << left << setw(20) << "Item"
         << right << setw(5) << "Qty"
         << setw(14) << "Subtotal" << endl;

    cout << "----------------------------------------\n";

    for (const auto& item : cart) {
        cout << left << setw(20) << item.name
             << right << setw(5) << item.quantity
             << setw(14) << item.price * item.quantity
             << endl;
    }

    cout << "----------------------------------------\n";
    cout << "Total Price : Rp " << total << endl;
    cout << "Payment     : Rp " << payment << endl;
    cout << "Change      : Rp " << payment - total << endl;

    cout << "========================================\n";
    cout << "       THANK YOU FOR YOUR PURCHASE!     \n";
    cout << "========================================\n";
}

int main() {
    vector<Order> cart;

    int choice, quantity;
    long long total, payment;
    string menuName;
    int price;

    displayMenu();

    while (true) {
        cout << "\nEnter menu number (0 to finish): ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                menuName = "Fried Rice";
                price = 15000;
                break;
            case 2:
                menuName = "Fried Chicken";
                price = 12000;
                break;
            case 3:
                menuName = "Fried Noodles";
                price = 13000;
                break;
            case 4:
                menuName = "Meatball Soup";
                price = 10000;
                break;
            case 5:
                menuName = "Chicken Noodles";
                price = 12000;
                break;
            case 6:
                menuName = "Iced Tea";
                price = 5000;
                break;
            case 7:
                menuName = "Orange Juice";
                price = 8000;
                break;
            case 8:
                menuName = "Mineral Water";
                price = 4000;
                break;
            case 9:
                menuName = "Iced Coffee";
                price = 10000;
                break;
            case 10:
                menuName = "Milk";
                price = 7000;
                break;
            default:
                cout << "Menu not available!\n";
                continue;
        }

        cout << "Selected item: " << menuName << endl;
        cout << "Enter quantity: ";

        if (!(cin >> quantity) || quantity <= 0) {
            cout << "Invalid quantity!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        bool found = false;

        for (auto& item : cart) {
            if (item.name == menuName) {
                item.quantity += quantity;
                found = true;
                break;
            }
        }

        if (!found) {
            cart.push_back({menuName, price, quantity});
        }

        cout << "Item successfully added to cart!\n";
    }

    if (cart.empty()) {
        cout << "\nNo items were ordered.\n";
        return 0;
    }

    total = calculateTotal(cart);

    cout << "\nTotal Payment: Rp " << total << endl;

    while (true) {
        cout << "Enter payment amount: Rp ";

        if (!(cin >> payment) || payment < total) {
            cout << "Insufficient payment or invalid input!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        break;
    }

    displayReceipt(cart, total, payment);

    return 0;
}
