/***************************************************************************
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3 (Hacker Edition)
 *
 * Yannick Jacobs
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500
 
#include <unistd.h>
#include <string.h>
 
#include "framework.h"
#include "solver.h"
 
 
// constants
#define DIM_MIN     3
#define DIM_MAX     9
#define SET_SEED    NULL
#define MAX_TRIES   20
#define STRUCT_SIZE 128
 
 
// board
int **board; 
 
// dimensions
int d;
 
 
int
main(int argc, char *argv[])
{    
    // allocate board array
    board = malloc(DIM_MAX * sizeof(int *));
    for(int i = 0; i < DIM_MAX; i++)
        board[i] = malloc(DIM_MAX * sizeof(int));
 
 
    // greet user with instructions
    greet();
 
 
    // ensure proper usage
    if(argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
 
 
    // ensure valid dimensions
    d = atoi(argv[1]);
    if(d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
 
 
    // initialize the board
    init(d, board, SET_SEED, MAX_TRIES);
 
 
    // accept moves until game is won
    while(true)
    {
        // clear the screen
        clear();
 
        // draw the current state of the board
        draw(d, board);
 
        // check for win
        if(won(d, board))
        {
            printf("ftw!\n");
            break;
        }
 
        // prompt for move (or GOD)
        printf("Tile to move: ");
        char *input = GetString();        
 
        if(input == NULL)
            return 3;
        else if(strcmp("GOD", input) == 0)
        {
            // make a copy of the startboard for animations sake
            int **startboard = malloc(d * sizeof(int *));
            for(int i = 0; i < d; i++)
                startboard[i] = malloc(d * sizeof(int));
 
            for(int i = 0; i < d; i++)
            {
                for(int j = 0; j < d; j++)
                    startboard[i][j] = board[i][j];
            } 
 
 
            // init array of moves made to solution
            int moves[200];
            for(int i = 0; i < 200; i++)
                moves[i] = -1;
 
 
            // start search and return number of moves made
            printf("God mode enabled! Please wait while I find a solution...\n");
            printf("It can take a couple minutes!\n");
            int result = iterative_deepening(board, d, moves);
 
 
            // animate solution
            for(int i = 0; i < result; i++)
            { 
                // find coordinates of blank tile
                int posBlank = find_tile(0, d, startboard);
                int y = posBlank % d;
                int x = (posBlank - y)/d;  
 
                // make the move
                make_move(startboard, moves[i], x, y);             
 
                // redraw
                clear();
                draw(d, startboard);
                usleep(500000);
            }
 
 
            // final check
            if(won(d, startboard))
            {
                printf("I solved the puzzle in %d moves!\n", result);
                printf("ftw!\n");                
            }
 
 
            // free startboard
            for(int i = 0; i < d; i++)
                free(startboard[i]);
            free(startboard);
 
            break;
        }
        else if (atoi(input) > 0)
        { 
            int tile = atoi(input);
 
            // move if possible, else report illegality
            if(!move(tile, d, board))
            {
                printf("\nIllegal move.\n");
                usleep(500000);
            }
        }
 
        // sleep thread for animation's sake
        usleep(500000);
    }
 
    // free allocated memory   
    for(int i = 0; i < DIM_MAX; i++)
        free(board[i]);
    free(board);
 
    // that's all folks
    return 0;
}
 
 
 
