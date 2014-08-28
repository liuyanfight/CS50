//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//
// hacker edition 11.
// Lastly, amaze us by integrating at least two (2) of the following features into your game:
// Implement God Mode whereby, if the program is run with ./breakout GOD, the game ignores the user’s mouse movements 
//  and instead moves the paddle itself in perfect lockstep with the ball along its (horizontal) x-axis so that the ball never misses the paddle.
// Implement a shrinking-paddle mechanism whereby the paddle’s width decreases as bricks are broken; we leave it to you to decide on a formula.
// Implement a variable-scoring mechanism whereby bricks higher in the game’s grid are worth more points than are bricks lower in the game’s grid;
//  we leave it to you to decide on a formula.
// Implement a variable-velocity mechanism whereby the ball’s velocity (along one or both axes) increases as bricks are broken;
//  we leave it to you to decide on a formula.
// Implement lasers, whereby clicking the mouse button during gameplay results in the paddle shooting one or two laser beams upward toward bricks,
//  whereby those beams can destroy them just like the ball can. However, if a beam strikes the ball itself, gameplay must end.

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(int argc,char *argv[])
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    waitForClick();
    // initial velocity
    double vx = 2.0;
    double vy = drand48() * 5;;
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
        // if it's God mode, set autorun.
        if (argc == 2 && strcmp("GOD",argv[1]) == 0)
        {
            // ensure paddle folloes top ball
            double horizontal = getX(ball) - getWidth(paddle) / 2 + getWidth(ball) / 2;
            // bounce off edge of window
            if (horizontal < 0)
            {
                horizontal = 0;
            }
            else if (horizontal > (WIDTH - getWidth(paddle)))
            {
                horizontal = WIDTH - getWidth(paddle);
            }
            setLocation(paddle, horizontal, getY(paddle));
        }
        else
        {
            // check for mouse event
            GEvent event = getNextEvent(MOUSE_EVENT);
        
            // if we heard one
            if (event != NULL)
            {
                // if the event was movement
                if (getEventType(event) == MOUSE_MOVED)
                {
                    // ensure circle follows top cursor
                    double x = getX(event) - getWidth(paddle) / 2;
                    // bounce off left edge of window
                    if (x < 0) 
                    {
                        x = 0;
                    }
                    // bounce off right edge of window
                    else if (x > (WIDTH - getWidth(paddle)))
                    {
                        x = WIDTH - getWidth(paddle);
                    }
                    setLocation(paddle, x, getY(paddle));
                }
            }
        }
        
        move(ball, vx, vy);      
        // Implement lasers?
            
        GObject object = detectCollision(window, ball);
        if (object == paddle)
        {
            vy = -vy;
        }
        // be careful with object != NULL !!!
        else if (object != NULL && strcmp(getType(object), "GRect") == 0)
        {
            // TODO
            vy = -vy;
            // variable-scoring mechanism,1 layer 3 point ,2,3 layer 2 point,4,5 1 point 
            string color = getColorGObject(object);
            if (strcmp(color,"RED") == 0)
            {
                points = points + 3;
            }
            else if (strcmp(color,"YELLOW") == 0 || strcmp(color,"ORANGE") == 0)
            {
                points = points + 2;
            }
            else
            {
                points++;
            }
            removeGWindow(window, object);
            // convert i from int to string
            char s[3];
            sprintf(s, "%i", points);
            setLabel(label, s);
            --bricks;
            // shrinking-paddle mechanism
            setSize(paddle,getWidth(paddle) - 1,getHeight(paddle));
            // variable-velocity mechanism
            vy = vy + 0.05;
        }
        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= WIDTH)
        {
            vx = -vx;
        }
        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            vx = -vx;
        }
        // bounce off down edge of window
        else if (getY(ball) + getHeight(ball) >= HEIGHT)
        {
            lives -= 1;
            removeGWindow(window, ball);
            ball = initBall(window);
            waitForClick();
        }
        // bounce off up edge of window
        else if (getY(ball) <= 0)
        {
            vy = -vy;
        }
        // linger before moving again
        pause(10);
    }
    
    removeGWindow(window, ball);
    ball = initBall(window);
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // 34.5 = (WIDTH - 5 * (COLS + 1)) / COLS
            GRect rect = newGRect(5 + 39.5 * j,50 +  i * 10 + 5 * i,34.5, 10);
            switch(i)
            {
                case 0:
                    setColor(rect, "RED");break;
                case 1:
                    setColor(rect, "ORANGE");break;
                case 2:
                    setColor(rect, "YELLOW");break;
                case 3:
                    setColor(rect, "GREEN");break;
                case 4:
                    setColor(rect, "CYAN");break;
                default:
                    setColor(rect, "BLACK");break;
            }
            setFilled(rect, true);
            add(window, rect);
        }
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS, 2 * RADIUS, 2 * RADIUS);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect((WIDTH - 70) / 2, HEIGHT - 50, 70, 10);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif -45");
    setColor(label, "GRAY");
    double x = (WIDTH - getWidth(label)) / 2;
    double y = (HEIGHT - getHeight(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}