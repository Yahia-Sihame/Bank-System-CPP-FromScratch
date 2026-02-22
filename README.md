# 🏦 Bank Management System (OOP Evolution)
### Developed by **Yahia Sihame** 🚀

## 📖 Project Concept
This is a comprehensive **Bank Management System** built entirely from the ground up using **C++**. Unlike standard projects that rely on high-level built-in libraries, this system demonstrates a deep understanding of **Software Engineering** by implementing custom fundamental libraries before building the application logic.

This project was a journey of transforming theoretical **Object-Oriented Programming (OOP)** principles into a scalable, real-world banking solution, following the methodology of **Dr. Abu Hadhoud**.

---

## 🏗️ System Architecture
The project follows a clean and modular structure for better maintainability:

📂 Bank-System-OOP

 ┣ 📁 include/        # Custom Libraries (String, Date, Validation) & Class Headers
 
 ┣ 📁 data/           # Flat-file Database (Text files with custom separators)
 
 ┣ 📁 output/         # Compiled binaries and build objects
 
 ┣ 📜 .gitignore      # Keeping the repository clean
 
 ┗ 📜 Main.cpp        # Application Entry Point
 
---

Login Screen

 <img width="1005" height="238" alt="Screenshot 2026-02-22 at 00 15 45" src="https://github.com/user-attachments/assets/9ce56ef8-e45f-41de-8efc-65efa755a150" />



Main Menu

 <img width="786" height="402" alt="image" src="https://github.com/user-attachments/assets/b8fe4184-8f32-440a-ac33-74ac56509dd8" />



Show Client List

 <img width="1030" height="521" alt="image" src="https://github.com/user-attachments/assets/4d9941e2-6477-4ee5-92a4-ef0b0f972014" />



Add new Client

 <img width="1039" height="525" alt="image" src="https://github.com/user-attachments/assets/f7226212-83a9-4582-b57b-a0d44d21297f" />



Transactions Screen

 <img width="941" height="431" alt="image" src="https://github.com/user-attachments/assets/504452f1-4822-4474-847f-c726d6c8554c" />



Login Register List Screen

 <img width="941" height="431" alt="image" src="https://github.com/user-attachments/assets/8ca5bd8f-fc03-4bc5-b51f-be617c9c3eca" />



Currency Exchange Menue

 <img width="692" height="302" alt="image" src="https://github.com/user-attachments/assets/614f8382-74d8-4a9b-b8e2-021d0b4c8ca0" />



Currency Calculator

 <img width="855" height="584" alt="image" src="https://github.com/user-attachments/assets/40359c0a-c869-4603-bf9b-7e6bfb7722af" />



Manage Users Menue

 <img width="734" height="330" alt="image" src="https://github.com/user-attachments/assets/be267d12-7e5d-4b8e-bab4-a2fc611b4527" />




## 🛠️ Technical Highlights

### 1. Custom Foundations (From Scratch)
I built my own core utilities to handle the system's basic needs without external dependencies:
* **Custom String Library**: Handling complex `Split`, `Join`, and string formatting operations.
* **Custom Date/Time Library**: Managing timestamps for bank transactions and system audit logs.
* **Input Validation Layer**: A robust utility to ensure data integrity and prevent system crashes.

### 2. OOP Pillars in Action
* **Inheritance**: Implemented a hierarchy starting from `clsPerson` to derive `clsUser` and `clsBankClient`.
* **Encapsulation**: Securing financial data and restricting unauthorized access to user permissions.
* **Abstraction**: Simplifying banking operations like Transfers or Withdrawals into clean, reusable class methods.

### 3. Data Persistence (Flat-File DB)
* **Custom Database Logic**: Instead of using SQL, I designed a **Flat-file Database** system.
* **Data Parsing**: Developed logic to read/write objects to `.txt` files using custom record separators.

---

## 🚀 Key Features
* **Secure Login System**: Protects the system with a 3-attempt lock mechanism.
* **Role-Based Permissions (RBAC)**: Distinguishes between Admin and Regular User access.
* **Full CRUD Operations**: Manage clients and users (Create, Read, Update, Delete).
* **Financial Engine**: Robust handling of Deposits, Withdrawals, and Transfers with automated logging.
* **Audit Trail**: Tracking and recording every login move for full accountability.

---

## 💻 How to Compile & Run
To compile the project, use the following command in your terminal:

```bash
g++ -I include/ Main.cpp include/*.cpp -o BankSystem
./BankSystem
