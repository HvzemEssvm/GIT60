# This is a Git Repo for *AMIT ALEX60 Embedded Course* 👋
# Student Database (SDB)

A command-line application implemented in C for managing student records using a hash table with linear probing for efficient data storage and retrieval.

---

## 📚 Project Overview

The Simple Student Database (SDB) is an API designed to demonstrate fundamental data structure concepts, specifically a hash table, for managing student information. It provides a set of core functionalities to interact with student records based on AMIT requirements, including adding, deleting, reading, and listing student data.

---

## ✨ Features

* **Add Entry:** Insert new student records with unique IDs, academic year, and three course details (ID and grade).
* **Get Used Size:** Retrieve the current number of student entries in the database.
* **Read Student Data:** Display all details for a specific student using their ID.
* **Get All Student IDs:** List all student IDs currently stored in the database.
* **Check ID Existence:** Verify if a student ID already exists in the database.
* **Delete Student Data:** Remove a student record from the database by ID, with a confirmation prompt.
* **Check Database Fullness:** Determine if the database has reached its maximum capacity.
* **Error Handling:** Provides informative error messages for invalid inputs, full database, non-existent entries, and memory allocation issues.
* **Variable Sized Database:** you could change `#define MAX_SIZE`, `#define MIN_SIZE` & `#define HT_SIZE` but keep in mind that *HT_SIZE must be bigger than or equal to MAX_SIZE*
---

## 📁 Project Structure

The project is organized into several C source and header files:

* `main.c`: The entry point of the application, which calls the main database application loop.
* `SDB.h`: Defines the `student` structure and declares the public functions for database operations.
* `SDB.c`: Contains the core implementation of the hash table logic and the student database operations. This is where students are added, deleted, read, and managed.
* `SDBAPP.c`: Implements the `SDB_APP()` function, which provides the interactive command-line menu and handles user choices by calling the appropriate SDB functions.
* `PRIV_LIB.h`: Contains declarations for utility private methods (like `fetch_str`, `isUInt`, `Fetch_Validate_Uint`) and defines various error macros used throughout the project.
* `STD.h`: Defines standard types such as `uint8`, `uint16`, `uint32`, `int8`, `int16`, `int32`, and a `bool` enum for portability and clarity.

---

## 🛠️ How to Build and Run

To compile and run this project, you will need a C compiler (like GCC).

1.  **Clone the repository (if applicable):**
    ```cli
    git clone <your-repository-url>
    cd <your-project-directory>
    ```

2.  **Compile the source files:**
    Open your terminal or command prompt in the project directory and run the following commands:
    ```cli
    gcc *.c -o main.exe.
    ```

3.  **Run the application:**
    ```cli
    .\main.exe
    ```

---

## 📝 Usage

Once the application is running, you will be presented with a menu of options. Enter the corresponding number to perform an action:
1. Add student entry with unique ID
2. Fetch used size in the database
3. Read student's information
4. Get a list of all IDs
5. Check if a certain ID exists
6. Delete an entry **(Only if database size will be bigger than the minimum pre-defined size)**
7. Check if database is full
8. Exit the program

---

## 🎥 [Illustrative Demo](https://drive.google.com/file/d/1ojDALOhpzsowH8P3CC6VmXS8UVAfoVlB/view?usp=sharing)
