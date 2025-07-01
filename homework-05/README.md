# Курс програмування на C++ [👈](../README.md)

## ДЗ №5: Синхронізація та безпека потоків [🇬🇧👈](./README-EN.md)

### Завдання

Ви розробляєте систему для банку, де кілька касирів (потоків) одночасно обслуговують клієнтів. Потрібно реалізувати безпечні операції з рахунками та статистикою.

***Вимоги:***

Клас ***BankAccount*** з методами:

- deposit(amount) - поповнення рахунку
- withdraw(amount) - зняття коштів (перевірити достатність)
- get_balance() - отримання балансу

Клас ***BankStatistics*** для збору статистики:

- record_transaction(amount) - записати транзакцію
- get_total_transactions() - загальна кількість
- get_total_amount() - загальна сума транзакцій

Симуляція роботи банку:

- 5 касирів (потоків) одночасно обслуговують клієнтів
- Кожен касир робить 100 випадкових операцій
- Операції: поповнення (50-500 грн) або зняття (10-200 грн)

### Компіляція та запуск

#### Потоково небезпечна версія

Компіляція та запуск thread unsafe version

```bash
~$ make BUILD=unsafe
```

#### Потоково безпечна версія

Компіляція та запуск thread safe version

```bash
~$ make
```

або

```bash
~$ make BUILD=safe
```

### Вхідні параметри

```bash
Initial account balance: 1000.00
Number of cachiers: 5
Number of tranaction per cachier: 100
Random deposit amount: 50.00 - 500.00
Random withdraw amount: 10.00 - 200.00
```

### Приклад результату

#### Потоково небезпечна версія

Вихід консолі:

```bash
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 42006.57
Total transactions: 484
Total transaction amount: 94906.65
All cashiers completed work unsafely!
```

Записи транзакцій зберігаються у файлах журналів:

```bash
build/cachier-unsafe-{1..5}.log
```

#### Потоково безпечна версія

Вихід консолі:

```bash
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 42629.91
Total transactions: 500
Total transaction amount: 94975.94
All cashiers completed work safely!
```

Записи транзакцій зберігаються у файлах журналів:

```bash
build/cachier-safe-{1..5}.log
```

### Еталонний режим

Щоб перевірити коректність програми, запустіть її в еталонному режимі. Внесення та виведення коштів завжди мають постійне значення: 100 \
В результаті:

- початковий баланс має дорівнювати кінцевому балансу: 1000.00
- результат має дорівнювати добутку кількості касирів та кількості транзакцій на їх значення: 5 \* 100 \* 100.00 = 50'000.00

Запустити в еталонному режимі

#### Потоково небезпечна версія

```bash
~$ make BUILD=unsafe,ref
```

або скомпільована програма

```bash
~$ ./build/banking-unsafe.exe --ref
```

Вихід консолі:

```bash
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 491
Total transaction amount: 49100.00
All cashiers completed work unsafely!
```

#### Потоково безпечна версія

```bash
~$ make BUILD=ref
```

або

```bash
~$ make BUILD=safe,ref
```

або скомпільована програма

```bash
~$ ./build/banking-safe.exe --ref
```

Вихід консолі:

```bash
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 500
Total transaction amount: 50000.00
All cashiers completed work safely!
```
