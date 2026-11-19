# C Programming – Assignment 4 (CO4)

**Student:** Nandana SR  
**Register Number:** 1912260059  
**Course:** C Programming (CSA02)  
**Programme:** B.Tech Electronics and Communication Engineering

## Compiler
GCC (GNU Compiler Collection). Compile using `gcc -Wall -Wextra`.

## Folder guide
- `Task01` – Patient register using nested structures and a structure pointer.
- `Task02` – Nested parcel structures, pointer access and selection sort.
- `Task03` – Tagged union for weather-station readings.
- `Task04` – Correct structure-pointer handling for account interest.
- `Task05` – Static, automatic, extern and register examples (three source files).
- `Task06` – Canteen inventory, sales, expiry warning and revenue summary.
- Each task has an `output.png` screenshot of its sample run.

## Compile and run
Open Terminal in the assignment folder and run the command for the required task:

```bash
gcc -Wall -Wextra Task01/task1.c -o task1 && ./task1
gcc -Wall -Wextra Task02/task2.c -o task2 && ./task2
gcc -Wall -Wextra Task03/task3.c -o task3 && ./task3
gcc -Wall -Wextra Task04/task4.c -o task4 && ./task4
gcc -Wall -Wextra Task05/main.c Task05/token.c Task05/shared.c -o task5 && ./task5
gcc -Wall -Wextra Task06/task6.c -o task6 && ./task6
```

## Notes
The programs use simple variable names, comments and straightforward logic for easy explanation during the viva. Output screenshots show sample executions. Task 6 uses a simple day-count estimate for the two-day expiry demonstration; a production system should use full calendar-date validation.
