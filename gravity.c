#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>

#define true 1
#define false 0

typedef UINT8 bool;

typedef enum BoardObjectType
{
	CIRCLE, BOX, IMAGE
} BoardObjectType;

typedef struct Point
{
	UINT8 x, y;
} Point, *PointPtr;

typedef struct Color
{
	UINT8 cfore, cback, cmode;
} Color, *ColorPtr;

typedef struct BoardCircle
{
	Point pos;
	UINT8 radius;
	Color color;
} BoardCircle, *BoardCirclePtr;


void welcomeScreen();
void initSimpleBoard(BoardObjectType t, BoardCirclePtr c);
void drawBoardCircle(BoardCirclePtr c);


void main(void)
{
	UINT8 key;
	bool gamePlaying = true;
	BoardCircle player;
	BoardObjectType playerType = CIRCLE;

	welcomeScreen();
    initSimpleBoard(playerType, &player);  

	waitpadup();
	do {
    	wait_vbl_done();
    	key = joypad();
    	if (key & J_UP)
    	{
    		player.pos.y++;
    	}
    	else if (key & J_DOWN)
    	{
    		player.pos.y--;
    	}
    	else if (key & J_LEFT)
    	{
    		player.pos.x--;
    	}
    	else if (key & J_RIGHT)
    	{
    		player.pos.x++;
    	}    	
    	drawBoardCircle(&player);    	
    } while (gamePlaying);
    waitpadup();
}

void welcomeScreen()
{
    printf("Welcome to Glavity");
    printf("\nPress Start");
    waitpad(J_START);
}

void initSimpleBoard(BoardObjectType type, BoardCirclePtr player)
{
	if (player == NULL)
	{
		return;
	}

	switch (type)
	{
		case CIRCLE:
			(*player).pos.x = 140;
			(*player).pos.y = 20;
			(*player).radius = 30;
			drawBoardCircle(player);
			break;

		default:
			printf("boom");
	}
}

void drawBoardCircle(BoardCirclePtr obj)
{
	UINT8 x, y, r;
	if (obj == NULL)
	{
		return;
	}

	x = (*obj).pos.x;
	y = (*obj).pos.y;
	r = (*obj).radius;

	// small circle
    color(LTGREY, WHITE, SOLID);
    circle(x, y, r-15, M_FILL);
	// large circle
	color(DKGREY, WHITE, XOR);
	circle(x-20, y+20, r, M_FILL);	
	// outline large circle
	color(BLACK, WHITE, SOLID);
	circle(x-20, y+20, r, M_NOFILL); 	
}