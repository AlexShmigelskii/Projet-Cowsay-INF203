# 🐄 Projet Cowsay — INF203

Ce projet a été réalisé dans le cadre du cours **INF203** à l’Université Grenoble Alpes (L1 IMA).  
L’objectif est de réimplémenter le célèbre programme `cowsay` en **Bash** et **C**, tout en ajoutant des fonctionnalités créatives et interactives.

## 📁 Structure du projet
```bash
.
├── README.md
├── rapport.pdf
├── scripts
│   ├── cow_college.sh
│   ├── cow_highschool.sh
│   ├── cow_kindergarten.sh
│   ├── cow_primaryschool.sh
│   ├── cow_university.sh
│   ├── crazy_cow.sh
│   └── smart_cow.sh
└── src
    ├── fich.cow
    ├── newcow.c
    ├── reading_cow.c
    └── wildcow.c
```

## ✅ Prérequis

Les scripts Bash utilisent `cowsay`. Il faut donc s'assurer qu’il est installé :

- **Sur Ubuntu / Debian / Linux Mint** :
  ```bash
  sudo apt install cowsay
  ```

- **Sur macOS (via Homebrew)**:
  ```bash
  brew install cowsay
  ```
## 🔧 Compilation

Les programmes en C doivent être compilés avec `gcc`. Par exemple :

```bash
gcc -o newcow src/newcow.c
gcc -o wildcow src/wildcow.c
gcc -o reading_cow src/reading_cow.c
```

## 👨‍💻 Auteurs
- Aleksandr Shmigelskii
- Gabriel Mella
