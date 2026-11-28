/*
  C++ Mid Exam — Problem Set

  Five problems from the mid-term contest. Each problem below is
  written as:
    1. a block comment  -> the statement (Statement, Input, Output, Examples, Note)
    2. a block comment  -> my solution, kept commented out

  All solutions are kept commented out.
  To run one, remove the block-comment markers around its code
  and wrap the others the same way.

  Problems:
    1. Sort It Twice        — print the array ascending, then descending
    2. sort_it()            — read + sort inside a function, return it
    3. Amena's Alphabets     — sort every line with a frequency count
    4. Best Student         — class objects, highest marks, tie by ID
    5. Three Sum            — three distinct indexes adding to S
*/


/*
=====================================================================
  Problem 1 : Sort It Twice
=====================================================================

  Statement
    You are given an array A of size N. Print the array sorted
    in ASCENDING order, then print it sorted in DESCENDING
    order.

  Input
    First line : N (1 <= N <= 10^5)
    Second line: the array A (-10^9 <= A[i] <= 10^9)

  Output
    Two lines: ascending first, descending second.

  Examples
    Input :
      5
      2 4 6 1 3
    Output:
      1 2 3 4 6
      6 4 3 2 1

  Note
    sort(arr, arr + n) sorts ascending; adding
    greater<int>() flips it to descending. Sorting the SAME
    array twice is enough — no second array needed.

    N can be 10^5, so O(N log N) sort is required: a bubble
    sort would be 10^10 steps and time out.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 2 : sort_it()
=====================================================================

  Statement
    Create a function named sort_it() that takes N as its
    parameter. Read the size in main(), call the function, take
    the array input INSIDE that function, sort it in DESCENDING
    order there, and return the array to main(). Print the
    sorted array in main().

  Input
    First line : N (1 <= N <= 10^5)
    Second line: the array A (-10^9 <= A[i] <= 10^9)

  Output
    The array in descending order.

  Examples
    Input :
      5
      1 4 2 3 5
    Output:
      5 4 3 2 1

  Note — why the function returns int*
    A LOCAL array inside sort_it() would die with the function's
    frame (Module 2's rule). So the array is built with
    new int[n] on the HEAP and its address is returned — still
    valid in main(). main() must delete[] it afterwards, which
    the solution does.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int *sort_it(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    return arr;
}

int main()
{
    int n;
    cin >> n;

    int *sorted_arr = sort_it(n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << sorted_arr[i];
    }
    cout << '\n';

    delete[] sorted_arr;
    return 0;
}
*/


/*
=====================================================================
  Problem 3 : Amena's Alphabets
=====================================================================

  Statement
    Amena reads and writes lowercase letters only, and she
    always writes what she sees in alphabetical order — she
    writes "monkey" as "ekmnoy". Her mother gives her some
    lines; print what Amena would write for each line.

    Note: the input is given by EOF (no count, read until the
    input ends).

  Input
    Lines of lowercase letters and spaces (multiple spaces and
    trailing spaces are possible). 1 <= |S| <= 10^5.

  Output
    Each line with its letters sorted a..z (spaces removed).

  Examples
    Input :
      monkey
      i love flower
    Output:
      ekmnoy
      eefilloorvw

  Note — counting sort instead of sorting
    Count how often each letter appears in count[26], then walk
    a..z printing each letter count[i] times. The line order is
    kept because the counter is flushed on every '\\n'.

    Reading: cin.get(ch) reads ONE character at a time,
    INCLUDING the newline — that '\\n' is the signal to flush.
    At EOF the last line is flushed too (the loop after the
    while).
=====================================================================
*/

/*
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count[26] = {0};

    while (cin.get(ch))
    {
        if (ch == '\n')
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < count[i]; j++)
                {
                    cout << char('a' + i);
                }
            }
            cout << endl;

            for (int i = 0; i < 26; i++)
            {
                count[i] = 0;
            }
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            count[ch - 'a']++;
        }
    }

    // flush the last line if the input did not end with '\n'
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << char('a' + i);
        }
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 4 : Best Student
=====================================================================

  Statement
    A student has an ID, name, section and total marks. You are
    given the information of THREE students per test case.
    Print the student with the highest total marks. On a tie,
    print the one with the SMALLER ID.

  Input
    First line : T, number of test cases (1 <= T <= 1000)
    Each test case: 3 lines, each with ID Name Section Marks
      1 <= ID <= 3, name = lowercase letters,
      'A' <= Section <= 'Z', 0 <= Marks <= 100

  Output
    The winning student's line: ID Name Section Marks

  Examples
    Input :
      3
      1 sakib A 50
      2 rakib D 96
      3 akib C 90
      1 sakib A 50
      2 rakib D 96
      3 akib C 96
      1 sakib A 50
      2 rakib D 50
      3 akib C 40
    Output:
      2 rakib D 96
      2 rakib D 96
      1 sakib A 50

  Note — the tie rule in one condition
    Replace best when the current student is strictly better:

        current.marks > best.marks
        OR (marks equal AND current.id < best.id)

    Test case 2 is the tie: rakib and akib both have 96, but
    rakib's ID 2 < akib's ID 3, so rakib wins.

    The class has TWO constructors: a default Student() {}
    (needed because main() starts with nothing) and the
    full one that copies each field with this-> and strcpy.
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int id;
    char name[105];
    char section;
    int marks;

    Student() {}

    Student(int id, char *name, char section, int marks)
    {
        this->id = id;
        strcpy(this->name, name);
        this->section = section;
        this->marks = marks;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int id, marks;
        char name[105];
        char section;

        cin >> id >> name >> section >> marks;
        Student best(id, name, section, marks);

        for (int i = 0; i < 2; i++)
        {
            cin >> id >> name >> section >> marks;
            Student current(id, name, section, marks);

            if (current.marks > best.marks ||
                (current.marks == best.marks && current.id < best.id))
            {
                best = current;
            }
        }

        cout << best.id << " " << best.name << " " << best.section << " "
             << best.marks << "\n";
    }

    return 0;
}
*/


/*
=====================================================================
  Problem 5 : Three Sum
=====================================================================

  Statement
    You are given an array A of size N and a sum S. Decide
    whether THREE DISTINCT INDEXED values from the array add up
    to exactly S.

  Input
    First line : T (1 <= T <= 100), number of test cases
    Each test case:
      one line with N and S (1 <= N <= 100, 1 <= S <= 1000)
      one line with the array (1 <= A[i] <= 1000)

  Output
    YES if such three indexes exist, otherwise NO.

  Examples
    Input :
      5
      5 10
      1 2 3 4 5
      5 6
      4 2 3 5 4
      3 6
      2 2 2
      4 4
      2 8 1 5
      1 3
      1
    Output:
      YES
      NO
      YES
      NO
      NO

    Test 1: 5 + 4 + 1 = 10      -> YES
    Test 3: 2 + 2 + 2 = 6 — three DIFFERENT indexes (values may
            repeat)            -> YES
    Test 4: no three sum to 4  -> NO
    Test 5: N = 1, no three indexes possible -> NO

  Note
    Three nested loops with i < j < k guarantee the indexes are
    distinct and ordered. N <= 100 -> at most ~160,000 triples
    per test case, fine for T <= 100.

    As soon as one triple matches: set found = true and break
    out of all three loops (the if (found) break after each
    level).
=====================================================================
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        int a[105];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool found = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i] + a[j] + a[k] == s)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    break;
                }
            }

            if (found)
            {
                break;
            }
        }

        if (found)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
*/
