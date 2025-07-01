# C++ programming course [👈](../README.md)

## HW #5: Synchronization and thread safety [🇺🇦👈](./README.md)

### Task

You are developing a system for a bank where multiple tellers (flows) serve customers simultaneously. You need to implement secure transactions with accounts and statistics.

***Requirements:***

Class ***BankAccount*** with methods:

- deposit(amount) - deposit
- withdraw(amount) - withdraw funds (check sufficiency)
- get_balance() - get balance

Class ***BankStatistics*** for collecting statistics:

- record_transaction(amount) - record transaction
- get_total_transactions() - total number
- get_total_amount() - total amount of transactions

Bank simulation:

- 5 cashiers (flows) serve customers simultaneously
- Each cashier makes 100 random transactions
- Transactions: top-up (50-500 UAH) or withdrawal (10-200 UAH)

### Compile and run

#### Thread unsafe version

Compile and run thread unsafe version

```bash
~$ make BUILD=unsafe
```

#### Thread safe version

Compile and run thread safe version

```bash
~$ make
```

or

```bash
~$ make BUILD=safe
```

### Input parameters

```bash
Initial account balance: 1000.00
Number of cachiers: 5
Number of tranaction per cachier: 100
Random deposit amount: 50.00 - 500.00
Random withdraw amount: 10.00 - 200.00
```

### Example of results

#### Thread unsafe version

Console output:

```bash
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 42006.57
Total transactions: 484
Total transaction amount: 94906.65
All cashiers completed work unsafely!
```

Transaction records are stored in log files:

```bash
build/cachier-unsafe-{1..5}.log
```

#### Thread safe version

Console output:

```bash
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 42629.91
Total transactions: 500
Total transaction amount: 94975.94
All cashiers completed work safely!
```

Transaction records are stored in log files:

```bash
build/cachier-safe-{1..5}.log
```

### Reference mode

To verify app correctness, run it in reference mode. Deposit and withdraw always have constant value: 100 \
As a result:

- initial balance should be equal to final balance: 1000.00
- the result should be equal to the product of the number of cachiers and number of transactions and their value: 5 \* 100 \* 100.00 = 50'000.00 \
Run in reference mode

#### Thread unsafe version

```bash
~$ make BUILD=unsafe,ref
```

or compiled app

```bash
~$ ./build/banking-unsafe.exe --ref
```

Console output:

```bash
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 491
Total transaction amount: 49100.00
All cashiers completed work unsafely!
```

#### Thread safe version

```bash
~$ make BUILD=ref
```

or

```bash
~$ make BUILD=safe,ref
```

or compiled app

```bash
~$ ./build/banking-safe.exe --ref
```

Console output:

```bash
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 500
Total transaction amount: 50000.00
All cashiers completed work safely!
```
