#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool cycle_check(int winner, int loser);
void lock_pairs(void);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];


        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int x;
    int z;
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        for (int j = i +1; j < candidate_count; j++)
        {
            x = ranks[i];
            z = ranks[j];
            preferences[x][z] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int x;
    int z;
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            x = preferences[i][j];
            z = preferences[j][i];
            if (x < z)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            else if (x > z)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }

        }
    }
    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int lenght = pair_count;
    for (int i = 0; i < lenght - 1; i++)
    {
        int max_pos = i; //index of the max element
        for (int j = i + 1; j < lenght; j++)
        {
            int a = pairs[j].winner;
            int b = pairs[j].loser;
            int d = pairs[max_pos].winner;
            int e = pairs[max_pos].loser;
            if (preferences[a][b] > preferences[d][e])
            {
                max_pos = j;
            }
        }
        if (max_pos != i)
        {
            int temp = pairs[i].winner;
            pairs[i].winner = pairs[max_pos].winner;
            pairs[max_pos].winner = temp;

            int temp_sec = pairs[i].loser;
            pairs[i].loser = pairs[max_pos].loser;
            pairs[max_pos].loser = temp_sec;
        }
    }

    return;
}

bool cycle_check(int winner, int loser)
{
    while ( winner != -1 && winner != loser)
    {
        bool cycle = false;
        for (int i = 0; i < candidate_count; i++)
        {
            if(locked[i][winner])
            {
                cycle = true;
                winner = i;
            }
        }

        if(!cycle)
        {
            winner = -1;
        }
    }

    if (winner == loser)
    {
        return true;
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle_check(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int count;
    int winner;
    for (int i = 0; i < MAX; i++ )
    {
        for (int j = 0; j < MAX; j++)
        {
            winner = j;
            count = 0;
            if (locked[j][i] == false)
            {
                count += 1;
            }
        }
        if (count == MAX)
        {
            printf("%s\n", candidates[winner]);
            return;
        }
    }
    return;
}