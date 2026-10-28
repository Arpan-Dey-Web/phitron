// Multiply Them!
// Time Limit: 15 Seconds

// Memory Limit: 2.93 MB

// Description
// You have two numbers, but they are lost in such a way that you can only take them as input. Your task is to calculate the Multiplication of these two numbers and display the result as output.

// Statement
// You have two numbers, but they are lost in such a way that you can only take them as input. Your task is to calculate the Multiplication of these two numbers and display the result as output.

// Constraints
// 1 <= N <= 100 

// Input format
// The first line contains an integer A.
// The second line contains an integer B.
// Output Format
// A single integer representing the sum AxB.
// Sample Input 1
// 5
// 2
// Sample Output 1
// 10
// Explanation 1
// 5 x 2 = 10


// #include <stdio.h>
// int main()
// {
//     int a, b;
//     scanf("%d %d", &a, &b );
//     int multiplication = a*b;
//     printf("%d", multiplication);
//   return 0;
// }



// The Highest Score
// Time Limit: 15 Seconds

// Memory Limit: 2.93 MB

// Statement
// Rafi is a student who participated in a programming contest at his university. A total of 𝑁 students participated in the contest, and each student received a score. Rafi's teacher wants to know the highest score achieved by any student in the contest. Given the scores of all N students, help Rafi find and print the highest score.

// Constraints
// 1≤ N ≤1000
// 0≤ Ai  ≤100
// Input format
// The first line contains an integer N, the number of students.
// The second line contains N space-separated integers representing the scores of the students.
// Output Format
// Print a single integer representing the highest score achieved by any student.





// Sample Input 1
// 5
// 45 78 92 65 81
// Sample Output 1
// 92

// #include <stdio.h>
// int main()
// {
//     int n;
//     scanf("%d", &n );
//     int maxNumber = 0; 
//     for(int i=1; i<=n; i++)
//     {
//       int newNumber;
//       scanf("%d", &newNumber );
//       if(newNumber > maxNumber){
//         maxNumber = newNumber;
//       }
//     }
//     printf("%d" , maxNumber);
//   return 0;
// }



// The Longest Winning Streak
// Time Limit: 15 Seconds

// Memory Limit: 2.93 MB

// Description
// Two or more wins belong to the same winning streak only if they occur consecutively.

// For example, if the results are:

// 1 1 0 1 1 1 0 1
// Rafi's winning streaks are:

// First streak: 2 consecutive wins
// Second streak: 3 consecutive wins
// Third streak: 1 consecutive win
// Therefore, the longest winning streak is 3. If Rafi does not win any round, print 0.

// Statement
// Rafi is participating in a gaming competition where he plays N rounds. In each round, he either wins or loses. The results are represented by a sequence of integers, where 1 means Rafi won a round and 0 means he lost. Rafi wants to know the maximum number of consecutive rounds he won. Your task is to help Rafi calculate the length of his longest winning streak.

// Constraints
// 1≤N≤1000
// Each result is either 0 or 1.
// Input format
// The first line contains an integer N, the number of rounds.
// The second line contains N space-separated integers representing the results of the rounds.
// Output Format
// Print a single integer representing the maximum number of consecutive wins.



// Sample Input 1
// 8
// 1 1 0 1 1 1 0 1
// Sample Output 1
// 3



// #include <stdio.h>
// int main()
// {
//     int n;
//     scanf("%d", &n );
//     int currentStreak=0, highestStreak=0;

//       for(int i =1; i<=n; i++)
//       {
//         int x;
//         scanf("%d" , &x);
      
//         if(x==0)
//         {
//           currentStreak=0;
//         }

//         if(x==1)
//         {
//           currentStreak+=1;
//         }
//         if(currentStreak > highestStreak){
//           highestStreak =currentStreak;
//         }  
     
//       }

//    printf("%d", highestStreak);
//   return 0;
// }





// The Kingdoms Royal Selection
// Time Limit: 15 Seconds

// Memory Limit: 2.93 MB

// Statement
// In the Kingdom of CodeLand, the king is searching for a new royal commander. Thousands of candidates have applied, but only one candidate can be selected. The king has established a strict selection policy based on each candidate's age, intelligence score, physical strength, and military experience.



// A candidate is eligible for selection if they satisfy all of the following conditions:

// The candidate must be at least 21 years old and at most 35 years old.
// The intelligence score must be at least 80 out of 100.
// The physical strength score must be at least 70 out of 100.
// The candidate must have at least 2 years of military experience.


// However, the kingdom has a special rule: candidates who are at least 30 years old can compensate for insufficient military experience if their intelligence score is at least 95 and their physical strength score is at least 90. Even if a candidate satisfies the selection criteria, they will be rejected if their age or any score is outside the valid input range. Your task is to determine whether a candidate is selected as the royal commander.



// Special Rules

// The candidate is selected if either of these conditions is satisfied:

// Standard selection: The candidate meets all four standard eligibility requirements.
// Exceptional selection: The candidate is at least 30 years old, has an intelligence score of at least 95, and has a physical strength score of at least 90. Under this rule, military experience is not required.


// A candidate must still satisfy the age range of 21 to 35 years and have valid scores and experience values.





// Constraints
// 1≤A≤100
// 0≤I≤100
// 0≤P≤100
// 0≤E≤50
// Values outside these ranges must be treated as invalid.





// Input format
// The input contains four integers, each on a separate line:
// The first line contains an integer A, representing the candidate's age.
// The second line contains an integer I, representing the intelligence score.
// The third line contains an integer P, representing the physical strength score.
// The fourth line contains an integer E, representing the years of military experience.
// Output Format
// Print exactly one of the following:

// Selected — if the candidate qualifies.
// Rejected — if the candidate does not qualify or any input is invalid.
// Sample Input 1
// 32
// 96
// 92
// 0
// Sample Output 1
// Selected
// Explanation 1
// The candidate does not have military experience, but qualifies under the exceptional selection rule.

// Sample Input 2
// 28
// 95
// 90
// 1
// Sample Output 2
// Rejected
// Explanation 2
// The candidate does not meet the standard military experience requirement and is younger than 30, so the exceptional rule does not apply.

// Sample Input 3
// 25
// 85
// 75
// 3
// Sample Output 3
// Selected
// Explanation 3
// The candidate meets all standard selection requirements.




#include <stdio.h>

int main() {
    int a, i, p, e;

    scanf("%d", &a);
    scanf("%d", &i);
    scanf("%d", &p);
    scanf("%d", &e);

    if (a < 1 || a > 100 || i < 0 || i > 100 || p < 0 || p > 100 || e < 0 || e > 50) 
    {
        printf("Rejected\n");
    }
    else if (a < 21 || a > 35) {
        printf("Rejected\n");
    }
    else if ((i >= 80 && p >= 70 && e >= 2) || (a >= 30 && i >= 95 && p >= 90)) {
        printf("Selected\n");
    }
    else {
        printf("Rejected\n");
    }

    return 0;
}
