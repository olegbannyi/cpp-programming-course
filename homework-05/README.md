# CPP PRO: Home Work \#5

## Build and run

### Thread unsafe version

Build and run thread unsafe version

```bash
$ make BUILD=unsafe
```

### Thread safe version

Build and run thread safe version

```bash
$ make
```
or
```bash
$ make BUILD=safe
```

## Input parameters

```
Initial account balance: 1000.00
Number of cachiers: 5
Number of tranaction per cachier: 100
Random deposit amount: 50.00 - 500.00
Random withdraw amount: 10.00 - 200.00
```

## Example of results

### Thread unsafe version

Console output:
```
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 42006.57
Total transactions: 484
Total transaction amount: 94906.65
All cashiers completed work unsafely!
```
Transaction records are stored in log files:
```
build/cachier-unsafe-{1..5}.log
```

### Thread safe version

Console output:
```
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 42629.91
Total transactions: 500
Total transaction amount: 94975.94
All cashiers completed work safely!
```

Transaction records are stored in log files:
```
build/cachier-safe-{1..5}.log
```

## Reference mode
To verify app correctness, run it in reference mode. Deposit and withdraw always have constant value: 100 \
As a result:
 - initial balance should be equal to final balance: 1000.00
 - the result should be equal to the product of the number of cachiers and number of transactions and their value: 5 * 100 * 100.00 = 50'000.00 \
Run in reference mode

### Thread unsafe version
```bash
$ make BUILD=unsafe,ref
```
or compiled app
```bash
$ ./build/banking-unsafe.exe --ref
```
Console output:
```
=== Bank Simulation Results (Unsafe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 491
Total transaction amount: 49100.00
All cashiers completed work unsafely!
```

### Thread safe version
```bash
$ make BUILD=ref
```
or
```bash
$ make BUILD=safe,ref
```
or compiled app
```bash
$ ./build/banking-safe.exe --ref
```
Console output:
```
=== Bank Simulation Results (Safe) ===
Initial balance: 1000.00
Final balance: 1000.00
Total transactions: 500
Total transaction amount: 50000.00
All cashiers completed work safely!
```
