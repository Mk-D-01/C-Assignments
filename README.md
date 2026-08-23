# 💻 C Programming & Data Structures (DSA) Lab Assignments

A comprehensive academic repository featuring 14 weeks of C programming assignments, Data Structures and Algorithms (DSA) lab solutions, reference code templates, and an automated lab report generator.

---

## 📌 Project Overview (In a Gist)

This repository serves as a practical codebase for learning **C Programming** and **Data Structures & Algorithms (DSA)**. It includes weekly structured implementations created by **Yuvraj Singh** (B.Tech CSE - AI & ML), spanning foundational C concepts up to advanced graph space complexity analysis.

In addition to source code, the project includes an interactive **Web Platform & Document Generator (`index.html`)** that dynamically generates complete `.docx` lab files personalized with student profile information and customized terminal execution outputs.

### Key Highlights
- **14 Weeks of Lab Solutions:** Progressive curriculum covering basic I/O, control flow, arrays, strings, pointers, dynamic memory allocation, linked lists (singly/doubly/circular), stacks, queues, trees, and graph representations.
- **Automated `.docx` Report Generator:** An interactive web dashboard (`index.html`) that creates personalized lab files named `DSA_Lab_File_<Student_Name>.docx` with custom name comments and dynamic terminal execution outputs.
- **Reference Templates & Documentation:** Includes reusable C templates (`linked_list.c`) and official lab manuals (`DS Lab Manual.pdf`, lab report templates).
- **Practical Implementations:** Real-world problem solving, memory comparison algorithms (e.g., Adjacency Matrix vs. Adjacency List), and data structure operations.

---

## 📁 Repository Structure

```text
C Assignments/
├── Yuvraj_Singh/              # Weekly assignment solutions (Week 1 – Week 14)
│   ├── Week1/                 # Fundamentals: Basics, Variables & Operators
│   ├── Week2 - Week6/         # Arrays, Strings, Functions & Pointers
│   ├── Week7 - Week9/         # Linked Lists (Singly, Doubly, Circular)
│   ├── Week10 - Week13/       # Stacks, Queues, Trees & Searching/Sorting
│   └── Week14/                # Advanced DSA: Graph Memory & Adjacency Analysis
├── Base/                      # Reusable C code templates (e.g., linked_list.c)
├── index.html                 # Interactive Web Platform & .docx Lab File Generator
├── DS Lab Manual.pdf          # Official Data Structures lab reference manual
├── *.docx                     # Generated & formatted lab files (e.g., DSA_Lab_File_Yuvraj_Singh.docx)
└── README.md                  # Project overview and guide
```

---

## 📄 Automated Lab File & Document Generator (`index.html`)

The repository includes a web-based utility (`index.html`) designed to automate lab file creation:

1. **Student Profile Customization:** Accepts custom inputs for **Name**, **Roll Number**, **Section**, **Course**, and **Branch**.
2. **Dynamic Header & Code Formatting:** Automatically updates the student comment block header at the top of every code snippet in the document.
3. **Dynamic Terminal Output Updates:** Adjusts simulated terminal execution displays (e.g., terminal folder paths like `Yuvraj_Singh/`) to reflect individual student profiles.
4. **Auto-Named `.docx` Export:** Generates and downloads a ready-to-submit Word document formatted as:
   ```text
   DSA_Lab_File_<Student_Name>.docx
   ```
   *(e.g., `DSA_Lab_File_Yuvraj_Singh.docx`)*

---

## 📚 Curriculum Breakdown

| Phase | Topics Covered | Key Concepts |
| :--- | :--- | :--- |
| **Weeks 1 – 4** | Basic C Syntax & Control Flow | Input/Output, Loops, Conditionals, Functions |
| **Weeks 5 – 7** | Pointers & Memory Allocation | Dynamic memory (`malloc`/`free`), Arrays, Singly Linked Lists |
| **Weeks 8 – 9** | Advanced Linked Lists | Doubly Linked Lists, Circular Linked Lists, Fast/Slow Pointers |
| **Weeks 10 – 12** | Stacks & Queues | Array/List implementations, Expression evaluation, FIFO/LIFO |
| **Weeks 13 – 14** | Trees & Graphs | Binary Trees, Graph representations (Matrix vs. List space analysis) |

---

## 🛠️ How to Compile & Run

### Prerequisites
Make sure you have `gcc` (GNU Compiler Collection) or any standard C compiler installed.

```bash
# Verify gcc installation
gcc --version
```

### Execution Steps

1. **Navigate to the desired week directory:**
   ```bash
   cd Yuvraj_Singh/Week1
   ```

2. **Compile the C program:**
   ```bash
   gcc question1.c -o question1
   ```

3. **Run the executable:**
   - **Windows (PowerShell / Command Prompt):**
     ```powershell
     .\question1.exe
     ```
   - **Linux / macOS:**
     ```bash
     ./question1
     ```

---

## 🚀 Git Cheat Sheet

Quick commands for managing and pushing work to the repository:

```bash
# Check modified files
git status

# Stage all changes
git add .

# Commit with a message
git commit -m "Add solution for Week 14 Graph Analysis"

# Push to remote repository
git push origin main
```

---

## 📄 License & Attribution

Maintained for academic, learning, and reference purposes by **Yuvraj Singh** (B.Tech CSE - AI & ML).


