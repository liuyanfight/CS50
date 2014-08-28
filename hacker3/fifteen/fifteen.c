/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 *
 *ANSI Escape Sequences
 *echo -e '\033[1;32mCheers\033[0m'
 *颜色表示法：
 *一、以4开头的背景色;以3开头的前景色m    
 *二、或者不要背景色：
 *0;前景色m 
 *1;前景色m
 *0和1这两种有略微的差别。
 *口诀：0黑 1红 2绿 3棕 4蓝 5紫 6青 7灰
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
int generate(int x, int y);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("\n\n\n\n\n\n");
    printf("\e[35m  ( \\/\\/ )(  _)(  )  / _)/  \\(  \\/  )(  _)  (_  _)/  \\   (_  _)( )( )(  _)\e[0m\n");
    printf("\e[35m   \\    /  ) _) )(__( (_( () ))    (  ) _)    )( ( () )    )(   )__(  ) _)\e[0m\n");
    printf("\e[35m    \\/\\/  (___)(____)\\__)\\__/(_/\\/\\_)(___)   (__) \\__/    (__) (_)(_)(___)\e[0m\n");
    printf("\e[35m    __   __   __  __  ___     __  ___    ___  __  ___  ____  ___  ___  _  _\e[0m\n"); 
    printf("\e[35m   / _) (  ) (  \\/  )(  _)   /  \\(  _)  (  _)(  )(  _)(_  _)(  _)(  _)( \\( )\e[0m\n");
    printf("\e[35m  ( (/\\ /__\\  )    (  ) _)  ( () )) _)   ) _) )(  ) _)  )(   ) _) ) _) )  ( \e[0m\n");
    printf("\e[35m   \\__/(_)(_)(_/\\/\\_)(___)   \\__/(_)    (_)  (__)(_)   (__) (___)(___)(_)\\_)\e[0m\n");

    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // TODO 
    /*To be clear, whereas the standard edition of this problem set requires 
     *that the board be initialized to a specific configuration, 
     *this Hacker Edition requires that it be initialized to a pseudorandom 
     *but still solvable configuration.*/
    
    // the seed will generate  random
    srand((unsigned int) time(NULL));
    for (int i = 0;i < d;i++)
    {
        for(int j = 0;j < d;j++)
        {
            board[i][j] = generate(i, j);
        }
    }
    // if number of tiles is odd,swap 2 and 1(e.g 4*4)
    if (d % 2 == 0)
    {
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp;
    }
}
//generate random between 0 ~ d * d
int generate(int x, int y)
{
    if (x == d - 1 && y == d - 1)
        return 0;
    int random = rand() % (d * d);
    for (int i = 0;i < d;i++)
    {
        for(int j = 0;j < d;j++)
        {
            if (board[i][j] == random || random == 0)
                return generate(x, y);
        }
    }
    return random;
}
// remeber the position of 0
int zeroi = 0,zeroj = 0;

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    printf("\n\n");
    int k = 0;
    for (int i = 0;i < (5 * d - 15) / 2;i++)
        printf(" ");
    printf("\e[1;41mGame of Fifteen!\e[0m\n");
    for (int i = 0;i < d;i++)
    {
        for (int m = 0;m < d;m++)
            printf("\e[34m=====\e[0m");
        printf("\e[34m=\e[0m\n");
        for (int j = 0;j < d;j++)
        {
            k++;
            printf("\e[34m|\e[0m");
            // print blank space instead of 0
            if (board[i][j] == 0)
            {
                printf("    ");
                zeroi = i;
                zeroj = j;
            }
            else
            {
                if (board[i][j] == k)
                    printf("\e[32m%3d \e[0m",board[i][j]);
                else
                    printf("%3d ",board[i][j]);
            }
        }
        printf("\e[34m|\e[0m\n");
     }
    for (int m = 0;m < d;m++)
        printf("\e[34m=====\e[0m");
    printf("\e[34m=\e[0m\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    for (int i = 0;i < d;i++)
    {
        for(int j = 0;j < d;j++)
        {
            //find tile position
            if (board[i][j] == tile)
            {
                // on the right,left,top,down
                if ((i == zeroi && j == zeroj + 1) ||
                    (i == zeroi && j == zeroj - 1) ||
                    (i == zeroi - 1 && j == zeroj) ||
                    (i == zeroi + 1 && j == zeroj))
                {
                    int temp = board[i][j];
                    board[i][j] = 0;
                    board[zeroi][zeroj] = temp;
                    return true;
                }
                return false;
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    // check is 0 in the last number to save time
    if (zeroi == d - 1 && zeroj == d - 1)
    {
        int k = 0;
        for (int i = 0;i < d;i++)
        {
            for (int j = 0;j < d;j++)
            {
                if (board[i][j] != ++k && k < d * d)
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
