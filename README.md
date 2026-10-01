# Payment-Gateway-Stimulator

A modular **C++ payment gateway simulation system** developed as a 3rd-semester Object-Oriented Programming project. The application demonstrates how different payment methods can be modeled and processed using core OOP principles such as **abstraction, encapsulation, inheritance, and runtime polymorphism**.

> **Academic Project · C++ · Object-Oriented Programming**

---

## Overview

The **Payment Gateway Simulator** models the core workflow of a digital payment system without connecting to any real financial service.

The system provides a common payment interface while allowing different payment methods to implement their own transaction-processing logic. This architecture demonstrates how OOP can be used to design a system that is **modular, extensible, and maintainable**.

The project is intended for educational purposes and focuses primarily on **object-oriented design and implementation** rather than real-world payment processing.

---

## Key Features

* Multiple payment methods
* Common payment interface for different payment types
* User and transaction management
* Payment amount handling
* Transaction ID generation
* Payment status handling
* Runtime polymorphism
* Modular class-based architecture
* Input validation and transaction flow
* Console-based user interface

### Supported Payment Methods

* **UPI**
* **Card Payment**
* **Net Banking**

---
## Project Structure

The project follows a modular C++ structure that separates **interface definitions, implementations, and program execution**. This makes the codebase easier to understand, maintain, and extend.

```text
Payment-Gateway-Simulator/
│
├── include/                         # Header files
│   ├── Payment.h                    # Abstract base payment class
│   ├── User.h                       # User information and operations
│   ├── UPIPayment.h                 # UPI payment implementation
│   ├── CardPayment.h                # Card payment implementation
│   └── NetBankingPayment.h          # Net banking implementation
│
├── src/                             # Source file implementations
│   ├── Payment.cpp                  # Payment class implementation
│   ├── User.cpp                     # User class implementation
│   ├── UPIPayment.cpp               # UPI payment logic
│   ├── CardPayment.cpp               # Card payment logic
│   └── NetBankingPayment.cpp         # Net banking logic
│
├── main.cpp                         # Program entry point
│
├── README.md                        # Project documentation
│
└── .gitignore                       # Files excluded from Git
```




```

---
### Class Relationship

The payment classes follow an inheritance-based design:

```text
                         ┌─────────────────┐
                         │     Payment     │
                         │  Abstract Base  │
                         └────────┬────────┘
                                  │
                 ┌────────────────┼────────────────┐
                 │                │                │
                 ▼                ▼                ▼
        ┌────────────────┐ ┌───────────────┐ ┌────────────────────┐
        │  UPIPayment    │ │  CardPayment  │ │ NetBankingPayment  │
        └────────────────┘ └───────────────┘ └────────────────────┘
```

The `Payment` class defines the common interface, while each derived class provides its own implementation of the payment process.

### Program Flow

```text
                    ┌──────────────┐
                    │    main()    │
                    └──────┬───────┘
                           │
                           ▼
                    ┌──────────────┐
                    │ Create User  │
                    └──────┬───────┘
                           │
                           ▼
                    ┌──────────────┐
                    │ Select Mode  │
                    └──────┬───────┘
                           │
             ┌─────────────┼─────────────┐
             ▼             ▼             ▼
           UPI           Card       Net Banking
             │             │             │
             └─────────────┼─────────────┘
                           ▼
                  ┌─────────────────┐
                  │ Process Payment  │
                  └────────┬────────┘
                           │
                           ▼
                  ┌─────────────────┐
                  │ Transaction     │
                  │ Result          │
                  └─────────────────┘
```

This structure keeps **class declarations, implementations, and application logic separated**, following a clean and maintainable C++ project organization.



## Transaction Flow

```text
Start
  │
  ▼
Enter User Details
  │
  ▼
Enter Payment Amount
  │
  ▼
Select Payment Method
  │
  ├── UPI
  ├── Card
  └── Net Banking
  │
  ▼
Create Payment Object
  │
  ▼
Process Transaction
  │
  ▼
Generate Transaction ID
  │
  ▼
Display Transaction Status
  │
  ▼
End
```

---

## Example

```text
========================================
       PAYMENT GATEWAY SIMULATOR
========================================

User: Samikhya
Amount: ₹1500

Select Payment Method:

1. UPI
2. Card
3. Net Banking

Enter choice: 1

Enter UPI ID: user@upi

Processing transaction...

----------------------------------------
Transaction ID : TXN10234
Payment Method : UPI
Amount         : ₹1500
Status         : SUCCESS
----------------------------------------

Payment processed successfully.
```


## How to Run

### 1. Clone the repository

```bash
git clone <repository-url>
cd Payment-Gateway-Simulator
```

### 2. Compile

If the project uses separate source and header directories:

```bash
g++ main.cpp src/*.cpp -Iinclude -o payment_gateway
```

### 3. Run

**Windows:**

```bash
payment_gateway.exe
```

**Linux/macOS:**

```bash
./payment_gateway
```

> The exact compilation command may vary depending on the final project structure.

---

## Design Goals

The project focuses on demonstrating how a real-world system can be broken down into independent classes with clearly defined responsibilities.

### The design aims to provide:

* **Modularity** — Each payment method is implemented independently.
* **Reusability** — Common functionality is maintained in base classes.
* **Extensibility** — New payment methods can be added with minimal changes.
* **Maintainability** — Responsibilities are separated across classes.
* **OOP Implementation** — Core concepts are demonstrated through a practical use case.

---



## Limitations

This application is a **simulation** and does not process real financial transactions.

It does not connect to:

* Banks
* UPI networks
* Credit/debit card networks
* Payment processors
* Real financial accounts

All transactions are simulated locally for academic purposes.


## Academic Information

**Project:** Payment Gateway Simulator
**Course:** Object-Oriented Programming
**Semester:** 3rd Semester
**Program:** B.Tech — Computer Science & Engineering
**Language:** C++

---

## Author

**Samikhya Das**

B.Tech — Computer Science & Engineering

---

## Disclaimer

This project is developed **strictly for academic and educational purposes**. It is not intended for processing actual payments or handling real financial information.

