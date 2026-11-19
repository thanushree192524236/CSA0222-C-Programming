# C Programming Assignment 3 – CO3

**Student:** Nandana SR  
**Register number:** 1912260059  
**Course:** C Programming (CSA02)  
**Compiler used for sample runs:** GCC 14.2.0  

## Folder contents

Each task folder contains its C source file, `sample_output.txt`, and `output_screenshot.png` showing a sample run. The programs use straightforward variable names, short comments, and basic C constructs so the logic is easier to follow.

| Folder | Topic | Source file |
|---|---|---|
| Task01 | Linear and binary search | `search.c` |
| Task02 | Bubble, selection and insertion sort | `sorting.c` |
| Task03 | Merge two descending merit lists | `merge.c` |
| Task04 | Two-dimensional rainfall array | `rainfall.c` |
| Task05 | Character arrays and string processing | `strings.c` |
| Task06 | Sorting and searching names | `directory.c` |
| Task07 | Election vote counting | `election.c` |

## Compile and run

Open Terminal in the required task folder. For example, for Task01:

```bash
gcc -std=c11 -Wall -Wextra -pedantic search.c -o search
./search
```

Use the same pattern for the other folders, replacing the source and executable names:

- Task02: `sorting.c` → `sorting`
- Task03: `merge.c` → `merge`
- Task04: `rainfall.c` → `rainfall`
- Task05: `strings.c` → `strings`
- Task06: `directory.c` → `directory`
- Task07: `election.c` → `election`

On Windows, run the executable as `search.exe` (or the matching name).

## Notes before submission

- The sample data in each program is included so it can be compiled and tested immediately. Replace or extend it with the input data required by your faculty.
- Task04 uses generated example rainfall values for all 38 districts and 12 months; it is demonstration data, not official rainfall data.
- Task07 uses a small sample vote list that includes invalid entries. You can change the vote array to test other cases, including a tie.
- The screenshots are captured sample outputs from these compiled programs. Run the programs on your own computer and capture fresh screenshots if your faculty expects screenshots from your own terminal.
- The assignment asks for analysis, complexity discussion, measurements/graphs, individual Student A/Student B contributions, and progressive Git commits in addition to code. Those written components are not claimed to be completed by this code pack.
- Review every program and make sure you can explain it before submitting.

## Suggested GitHub repository name

`CSA02-1912260059-Assignment3`
