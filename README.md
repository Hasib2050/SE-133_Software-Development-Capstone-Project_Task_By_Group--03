# Employee Management System in C

A simple **Employee Management System** developed using the C programming language to demonstrate CRUD operations (Create, Read, Update, Delete) using both text files and binary files.

This project demonstrates how employee records can be stored, retrieved, modified, and deleted using file handling in C.

## Group Information

**Group: 03**

| Member | Name | ID |
|---|---|---|
| Member 1 | MD. HASIBUL HASAN HASIB | 253-35-645 |
| Member 2 | Abir Hasan Khan | 253-35-313 |
| Member 3 | Syed Mehedi Hasan Iran | 253-35-529 |

## Project Features

The system provides four basic CRUD operations:

- **Create:** Add new employee records.
- **Read:** Display all stored employee records.
- **Update:** Modify employee information using Employee ID.
- **Delete:** Remove an employee record using Employee ID.

## Project Versions

This project contains two implementations:

### 1. Text File Handling

Employee information is stored in a human-readable text file named `employees.txt`.

**File Handling Functions:**
- `fopen()` – Opens the file.
- `fprintf()` – Writes employee records.
- `fscanf()` – Reads employee records.
- `fclose()` – Closes the file.
- `remove()` – Removes the original file.
- `rename()` – Renames the temporary file.

**File Modes:**

| Mode | Purpose |
|---|---|
| `"a"` | Append employee records |
| `"r"` | Read employee records |
| `"w"` | Write into a temporary file |

### 2. Binary File Handling

Employee information is stored in binary format in a file named `employees.dat`.

**File Handling Functions:**
- `fopen()` – Opens the binary file.
- `fwrite()` – Writes employee structures.
- `fread()` – Reads employee structures.
- `fclose()` – Closes the file.
- `remove()` – Removes the original file.
- `rename()` – Renames the temporary file.

**File Modes:**

| Mode | Purpose |
|---|---|
| `"ab"` | Append binary records |
| `"rb"` | Read binary records |
| `"wb"` | Write binary records |

## Employee Structure

The project uses `typedef struct` to define employee information.

```c
typedef struct Employee
{
    int id;
    char name[50];
    float salary;
} EMP;
```

Each employee record contains:

- Employee ID
- Employee Name
- Employee Salary

## How to Run the Project

**Requirements:**
- C Compiler (GCC recommended)
- Code::Blocks or Visual Studio Code

**Steps:**

1. Clone the repository:

```bash
git clone YOUR_REPOSITORY_URL
```

2. Open the project folder.

3. Compile the text file version:

```bash
gcc text_crud.c -o text_crud
```

4. Run:

```bash
./text_crud
```

5. Compile the binary file version:

```bash
gcc binary_crud.c -o binary_crud
```

6. Run:

```bash
./binary_crud
```

*Note: On Windows, run the generated `.exe` files instead of using `./`.*

## Example Employee Records

| ID | Name | Salary |
|---|---|---:|
| 101 | Hasibul Hasan | 35000 |
| 102 | Rahim Ahmed | 28000 |
| 103 | Karim Hossain | 32000 |
| 104 | Sakib Khan | 40000 |
| 105 | Nusrat Jahan | 45000 |

## Learning Objectives

Through this project, we aim to understand:

- File handling in C.
- Text file and binary file operations.
- Reading and writing structure data.
- Using `typedef struct`.
- Implementing CRUD operations.
- Working with temporary files.
- Using `fread()` and `fwrite()`.
- Understanding file modes and file pointers.

## Conclusion

This project provides practical experience with file handling in C by implementing an Employee Management System using both text and binary files. It helps demonstrate the differences between text-based and binary-based data storage while applying fundamental programming concepts.

---

