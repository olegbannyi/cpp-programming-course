# Курс програмування на C++ [👈](../README.md)

## ДЗ №6: Налаштування Git та GitHub [🇬🇧👈](./README-EN.md)

### Задання

#### Частина 1: Налаштування Git та GitHub

1) Встановіть Git (якщо ще не встановлено):
    - Windows: завантажте з git-scm.com
    - Linux: sudo apt install git або sudo yum install git
    - macOS: brew install git
2) Налаштуйте Git:

```bash
git config --global user.name "Ваше Прізвище Ім'я"
git config --global user.email "ваше-email@example.com"
```

3) Створіть акаунт на GitHub (якщо немає): github.com
4) Створіть новий репозиторій на GitHub:
    - Назва: cpp-programming-course або programming-basics-cpp
    - Зробіть його публічним

#### Частина 2: Ініціалізація локального репозиторію

Створіть папку для проекту:

```bash
mkdir cpp-programming-course
cd cpp-programming-course
```

Ініціалізуйте Git репозиторій:

```bash
git init
```

Підключіть віддалений репозиторій:

```bash
git remote add origin https://github.com/ваш-username/cpp-programming-course.git
```

#### Частина 3: Створення .gitignore файлу

Додайте файл .gitignore

Додайте .gitignore до репозиторію:

```bash
git add .gitignore
git commit -m "Додав .gitignore для C++ проекту"
```

#### Частина 4: Перенесення домашніх завдань

Для кожного з ваших попередніх домашніх завдань виконайте наступні кроки:

1) Створіть папку для першого завдання:
2) Скопіюйте ваші файли (.cpp, .h) до цієї папки
3) Додайте README.md файл з описом завдання
4) Зафіксуйте зміни
