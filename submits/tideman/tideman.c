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
void swap(int a*, int b*);
void add_pairs(void);
void sort_pairs(void);
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
            }
        }
        record_preferences(ranks);

        printf("\n");
    }
    for (int p = 0; p < candidate_count; p++)
    {
        for (int r = 0; r < candidate_count; r++)
        {
            printf("%i, ", preferences[p][r]);
        }
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
        for (int j = i +1; j < candidate_count; j++)
        {
            x = preferences[i][j];
            z = preferences[j][i];
            if (x < z)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
            }
            else if (x > z)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
            }
            pair_count++; //im using pair_count in here so that it wont 'restart' in the next iteration of i-loop
        }
    }
    return;
}

void swap(int a*, int b*)
{
    int tmp = *a;
    *a = *b
    *b = tmp;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int lenght = MAX * (MAX - 1) / 2;
    for (int i = 0; i < lenght - 1; i++)
    {
        int max_pos = i //index of the max element
        for (int j = i + 1; j < lenght; j++)
        {
            if (pairs[j].winner > pairs[max_pos].winner)
            {
                max_pos = j;
            }
        }
        if (max_pos != i)
        {
            swap(&pairs[i].winner, &pairs[max_pos].winner);
            swap(&pairs[i].loser, &pairs[max_pos].loser);
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}