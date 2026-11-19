# CSA02 – C Programming – Assignment 5

**Student:** Nandana SR  
**Register Number:** 1912260059  
**Course:** C Programming  
**Course Outcome:** CO5

## Compiler
GCC (GNU Compiler Collection). Check your installed version with:

```bash
gcc --version
```

## Folder structure
- `Task01_Recursion/` – linear power, fast power and digital root
- `Task02_Input_Safety/` – safe input using `fgets()` and file error handling
- `Task03_Text_Binary/` – writes and reads donor records in text and binary formats
- `Task04_Dynamic_Memory/` – growable donor list using `realloc()`
- `screenshots/` – terminal-output screenshots for the programs

## Compile and run

Run these commands from the main assignment folder:

```bash
gcc -Wall -Wextra -std=c11 Task01_Recursion/power_recursion.c -o task1
./task1

gcc -Wall -Wextra -std=c11 Task02_Input_Safety/safe_input.c -o task2
./task2

gcc -Wall -Wextra -std=c11 Task03_Text_Binary/text_binary_compare.c -o task3
./task3

gcc -Wall -Wextra -std=c11 Task04_Dynamic_Memory/donor_list.c -o task4
./task4
```

On Windows, run the generated `.exe` files instead of using `./`.

## Task results
1. **Recursion:** The linear version calculates 2^30 in 31 calls. The halving version calculates the same result in 6 calls. The digital-root example returns 2 for 9875.
2. **Input safety:** `fgets()` reads within the size of the name array. If the sample data file is missing, `perror()` displays the reason.
3. **Text and binary files:** Both formats are used to store and read 1,000 donor records. The program prints the record counts and write time. File sizes can be checked with `ls -l` (Mac/Linux) or File Explorer.
4. **Dynamic memory:** The donor list starts with capacity 2 and doubles as more records are added. The allocated memory is released with `free()`.

## Notes
- The screenshots show sample runs from the included source code.
- Task B2 asks for additional adversarial tests (long input, invalid command-line arguments, and memory checking). Those tests should be run and recorded on the machine used for submission.
- The timing printed by Task 3 depends on the computer and may vary between runs.
- Commit each task separately to GitHub as required by the assignment. Add your GitHub repository link to the report.
