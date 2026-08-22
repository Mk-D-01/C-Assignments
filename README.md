# C Assignments & Git Quick Guide

Welcome to the **C Assignments** repository! This repository contains weekly C programming assignments, Data Structures lab solutions, and reference code.

---

## 📁 Repository Structure

```text
C Assignments/
├── Yuvraj_Singh/         # Weekly C programming solutions (Week 1 - Week 14)
│   ├── Week1/
│   ├── Week2/
│   └── ...
├── Base/                 # Base templates & reference files
├── README.md             # This README file
└── *.pdf / *.docx       # Lab manuals and formatted documents
```

---

## 🛠️ How to Compile & Run C Code

Using `gcc` (GNU Compiler Collection):

```bash
# Navigate to the specific week directory
cd Yuvraj_Singh/Week1

# Compile a C file
gcc question1.c -o question1

# Run the compiled executable (Linux/macOS)
./question1

# Run the compiled executable (Windows PowerShell)
.\question1.exe
```

---

## 🚀 Git Quick Reference Cheat Sheet

Here are the essential Git commands for daily usage in this repository:

### 1. Check Repository Status
```bash
git status
```

### 2. Stage & Commit Changes
```bash
# Stage a specific file
git add filename.c

# Or stage all changed files
git add .

# Commit changes with a descriptive message
git commit -m "Add solution for Week 1 Question 1"
```

### 3. Syncing with Remote (GitHub / GitLab)
```bash
# Push committed changes to remote repository
git push origin main

# Pull latest changes from remote repository
git pull origin main
```

### 4. Branching Basics
```bash
# Create and switch to a new branch
git checkout -b feature/week-15

# Switch back to main branch
git checkout main

# Merge branch into current branch
git merge feature/week-15
```

### 5. Viewing Commit History
```bash
# View recent commit logs (concise view)
git log --oneline -n 5
```

---

## 📄 License
This repository is maintained for academic and educational purposes.
