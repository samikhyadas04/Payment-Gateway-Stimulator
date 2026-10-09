#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <iomanip>

#include "include/User.h"
#include "include/Payment.h"
#include "include/UPIPayment.h"
#include "include/CardPayment.h"
#include "include/NetBankingPayment.h"

using namespace std;

// Reads a complete line from the terminal.
// getline() allows input containing spaces.
string readLine(const string& prompt) {
    string value;

    cout << prompt;
    getline(cin, value);

    return value;
}

// Reads an integer and handles invalid input safely.
int readInt(const string& prompt) {
    while (true) {
        string input = readLine(prompt);

        try {
            size_t position;
            int value = stoi(input, &position);

            // Reject extra characters after the integer.
            if (input.find_first_not_of(" \t\r\n", position)
                == string::npos) {
                return value;
            }
        }
        catch (const exception&) {
            // stoi() throws an exception for invalid input.
        }

        cout << "Invalid input. Please enter a number.\n";
    }
}

// Reads a non-negative monetary amount.
double readBalance(const string& prompt) {
    while (true) {
        string input = readLine(prompt);

        try {
            size_t position;
            double value = stod(input, &position);

            // Check for extra characters and invalid amounts.
            if (input.find_first_not_of(" \t\r\n", position)
                    == string::npos &&
                value >= 0 &&
                value <= numeric_limits<double>::max() / 1000) {
                return value;
            }
        }
        catch (const exception&) {
            // stod() throws an exception for invalid input.
        }

        cout << "Enter a valid non-negative amount.\n";
    }
}

// Searches for a registered user using their username.
// Returns a pointer to the user if found, otherwise nullptr.
User* findUser(vector<User>& users,
               const string& username) {
    for (User& user : users) {
        if (user.getUsername() == username) {
            return &user;
        }
    }

    return nullptr;
}

// Handles account registration.
void createAccount(vector<User>& users) {
    cout << "\n========== CREATE ACCOUNT ==========\n";

    // Collect the user's basic information.
    string name = readLine("Enter your name: ");

    string username;

    // Ensure the username is not empty or already registered.
    while (true) {
        username = readLine("Enter username/email: ");

        if (username.empty()) {
            cout << "Username cannot be empty.\n";
        }
        else if (findUser(users, username) != nullptr) {
            cout << "Username already exists. Try another.\n";
        }
        else {
            break;
        }
    }

    // Ask the user to create a password.
    string password;

    while (true) {
        password = readLine("Create password: ");

        if (password.empty()) {
            cout << "Password cannot be empty.\n";
        }
        else {
            break;
        }
    }

    // Set the initial simulated account balance.
    double balance = readBalance("Enter initial balance (Rs.): ");

    // Construct a User object and store it in the vector.
    users.emplace_back(name, username, password, balance);

    cout << "\nAccount created successfully!\n";
    cout << "Please log in from the main menu.\n";
}

// Verifies login credentials against registered user details.
User* login(vector<User>& users) {
    cout << "\n========== LOGIN ==========\n";

    string username = readLine("Enter username/email: ");
    string password = readLine("Enter password: ");

    // Find the account and check its password.
    User* user = findUser(users, username);

    if (user != nullptr && user->checkPassword(password)) {
        cout << "\nLogin successful!\n";
        cout << "Welcome, " << user->getName() << "!\n";

        return user;
    }

    // Display an error when either credential is incorrect.
    cout << "\nInvalid username or password.\n";
    return nullptr;
}

// Handles all payment methods through a common base-class pointer.
void makePayment(User& user) {
    cout << "\n========== MAKE PAYMENT ==========\n";
    cout << "1. Credit/Debit Card\n";
    cout << "2. UPI\n";
    cout << "3. Net Banking\n";

    int choice = readInt("Select payment method: ");

    // Runtime polymorphism: each derived class provides
    // its own implementation of the Payment functions.
    unique_ptr<Payment> payment;

    switch (choice) {
        case 1:
            payment = make_unique<CardPayment>();
            break;

        case 2:
            payment = make_unique<UPIPayment>();
            break;

        case 3:
            payment = make_unique<NetBankingPayment>();
            break;

        default:
            cout << "Invalid payment method.\n";
            return;
    }

    // Repeat input until the payment details are valid.
    while (true) {
        payment->collectDetails();

        if (payment->validateDetails()) {
            break;
        }

        cout << "Invalid payment details. Please try again.\n";
    }

    // Collect the amount to be paid.
    double amount = readBalance("Enter payment amount (Rs.): ");

    if (amount == 0) {
        cout << "Payment amount must be greater than zero.\n";
        return;
    }

    // Process the transaction and handle amount-related errors.
    try {
        payment->processPayment(user, amount);
    }
    catch (const invalid_argument& error) {
        cout << "Payment error: " << error.what() << '\n';
    }
}

// Displays the current balance of the logged-in user.
void checkBalance(const User& user) {
    cout << "\n========== ACCOUNT BALANCE ==========\n";

    cout << "Available Balance: Rs. "
         << fixed << setprecision(2)
         << user.getBalance() << '\n';
}

// Displays the user menu until the user chooses to log out.
void userMenu(User& user) {
    bool loggedIn = true;

    while (loggedIn) {
        cout << "\n========== USER MENU ==========\n";
        cout << "1. Make Payment\n";
        cout << "2. View Transactions\n";
        cout << "3. Check Balance\n";
        cout << "4. Logout\n";

        int choice = readInt("Enter your choice: ");

        // Execute the selected user operation.
        switch (choice) {
            case 1:
                makePayment(user);
                break;

            case 2:
                user.displayTransactions();
                break;

            case 3:
                checkBalance(user);
                break;

            case 4:
                cout << "\nLogout successful!\n";
                loggedIn = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Entry point of the program.
int main() {

    // Stores registered users for the current program session.
    vector<User> users;

    bool running = true;

    cout << "========================================\n";
    cout << "       PAYMENT GATEWAY SIMULATOR\n";
    cout << "========================================\n";

    // Keep displaying the main menu until Exit is selected.
    while (running) {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        int choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                // Register a new user, then return to the main menu.
                createAccount(users);
                break;

            case 2: {
                // Open the user menu only after successful login.
                User* user = login(users);

                if (user != nullptr) {
                    userMenu(*user);
                }

                break;
            }

            case 3:
                // End the program.
                cout << "\nThank you for using the "
                     << "Payment Gateway Simulator!\n";

                running = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}