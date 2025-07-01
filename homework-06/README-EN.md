# C++ programming course [👈](../README-EN.md)

## HW #6: Git and GitHub setup [🇺🇦👈](./README.md)

### Task

#### Part 1: Git and GitHub setup

1) Install Git (if not already installed):
    - Windows: download from git-scm.com
    - Linux: sudo apt install git or sudo yum install git
    - macOS: brew install git
2) Configure Git:

```bash
git config --global user.name "Your full name"
git config --global user.email "your-email@example.com"
```

3) Create a GitHub account (if you don't have one): github.com
4) Create a new repository on GitHub:
    - Name: cpp-programming-course or programming-basics-cpp
    - Make it public

#### Part 2: Initializing the local repository

Create a directory for the project:

```bash
mkdir cpp-programming-course
cd cpp-programming-course
```

Initialize the Git repository:

```bash
git init
```

Connect the remote repository:

```bash
git remote add origin https://github.com/your-username/cpp-programming-course.git
```

#### Part 3: Creating a .gitignore file

Add a .gitignore file

Add a .gitignore to the repository:

```bash
git add .gitignore
git commit -m "Added .gitignore into C++ project"
```

#### Part 4: Transferring Homeworks

For each of your previous homeworks, follow these steps:

1) Create a direcotry for the homework:
2) Copy your files (.cpp, .h) into this direcotry
3) Add a README.md file with the homework description
4) Commit the changes
