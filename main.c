#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"


#define DIM 400000

int Min(int a, int b);

int MinimumNoOperations(char rule[DIM], char code_fragment[DIM], int dp[DIM][DIM], int n, int m)
{
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=i;
    }
    for(int j=0; j<=m; j++)
    {
        dp[0][j]=j;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(rule[i]==code_fragment[j])
                dp[i+1][j+1]=dp[i][j];
            else
            {
                int insert_cost=dp[i+1][j]+1;
                int delete_cost=dp[i][j+1]+1;
                int replace_cost=dp[i][j]+1;

                if(rule[i-1]==code_fragment[j] && rule[i]==code_fragment[j-1])
                {
                    int swap_cost=dp[i-1][j-1]+1; // bonus operation compared to the original "Edit Distance" problem
                    replace_cost=Min(replace_cost,swap_cost);
                }

                dp[i+1][j+1]=Min(Min(insert_cost,delete_cost), replace_cost);
            }
        }
    }
    return dp[n][m];
}

int dp[DIM][DIM];
char input[DIM], rule[DIM];

/*
fnuc(myFuncion
func(myFunction)
*/


int main()
{
    fgets(rule, DIM, stdin);
    rule[strlen(rule)-1]=0;

    fgets(input, DIM, stdin);
    input[strlen(input)-1]=0;

    int len_input = strlen(input);
    int len_rule = strlen(rule);

    int distance = MinimumNoOperations(rule, input, dp, len_rule, len_input);

    printf("Minimum number of operations required: %d\n", distance);


    printf("\nNow let's try with random inputs!\n");
    strcpy(rule,"");
    strcpy(input,"");
    srand(time(NULL));

    int random_length1=rand()%20;
    char *randrule, *randinput;
    randrule= random_string(random_length1);
    int random_length2=rand()%20;
    randinput = random_string(random_length2);

    printf("Rule: %s\nInput: %s\n",randrule, randinput);

    distance = MinimumNoOperations(randrule, randinput, dp, random_length1,random_length2);

    printf("Minimum number of operations required: %d\n", distance);



    return 0;
}

int Min(int a, int b)
{
    return a > b ? b : a;
}

