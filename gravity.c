#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <stdlib.h>
#include "C:\gbdk\include\gb\malloc.h"

static struct GameBoardBoundary
{
	UINT8 minX, minY;
	UINT8 maxX, maxY;
	UINT8 width, height;
	UINT8 gap;
} gbb;

typedef struct
{
	UINT8 x, y;
	UINT8 radius;
} GameCircle, *GameCirclePtr;

/*GameCirclePtr gameCircleNew(UINT8 xIn, UINT8 yIn, UINT8 r)
{
	GameCirclePtr ret = (GameCirclePtr)malloc(sizeof(GameCircle));

	// validate input coord and radius fits in boundary.
	if ((xIn - r) < gbb.minX || (xIn + r) > gbb.maxX ||
		(yIn - r) < gbb.minY || (yIn + r) > gbb.maxY)
	{
		ret.x = gbb.minX + gbb.gap; 
		ret.y = gbb.minY + gbb.gap;
		ret.radius = 0;
		return ret;
	}

	ret.x = xIn;
	ret.y = yIn;
	ret.radius = r;
	return ret;
}

void initBoard()
{
	// boundary gaps determined aesthetically.
	gbb.gap = 5;
	gbb.minX = gbb.gap;
	gbb.minY = gbb.gap;
	gbb.maxX = SCREENWIDTH - 2*gbb.gap;
	gbb.maxY = SCREENWIDTH - 5*gbb.gap;
	gbb.width = gbb.maxX - gbb.minX;
	gbb.height = gbb.maxY - gbb.minY;
	box(gbb.minX-1, gbb.minY-1, gbb.maxX+1, gbb.maxY+1, M_NOFILL);

	GameCircle startPos = gameCircleNew(30, 50, 5);
	circle(startPos->x, startPos->y, startPos->radius, M_FILL);

	free(startPos);
}*/

void welcomeScreen()
{
    printf("Welcome to Glavity");
    printf("\nPress Start");
    waitpad(J_START);
}

//#define DYNAMIC_MEMORY_SIZE 0x2000
//unsigned char xdata dynamic_memory_pool[DYNAMIC_MEMORY_SIZE];
//unsigned char xdata * current_buffer; 
struct Stupid
{
	UINT8 s;
};
void GetStupidMallocWorking()
{
	//init_dynamic_memory(dynamic_memory_pool,DYNAMIC_MEMORY_SIZE);
	//current_buffer = malloc(0x100);


	//struct Stupid* stup;
	//stup = (struct Stupid*)malloc(sizeof(struct Stupid));
	//free(stup);
}

void main()
{
    welcomeScreen();
    GetStupidMallocWorking();
    //initBoard();       
}

/*Before C89, no structures could be passed as values ​​(and thus 
also not used as a return value of functions), too 
direct assignments were not possible:*/


/*#define SCREENWIDTH  0xA0U
Height of the visible screen in pixels.
#define SCREENHEIGHT 0x90U
#define MINWNDPOSX   0x07U
#define MINWNDPOSY   0x00U
#define MAXWNDPOSX   0xA6U
#define MAXWNDPOSY   0x8FU
#define GRAPHICS_WIDTH	160
#define GRAPHICS_HEIGHT 144

Prints the character 'chr' in the default font at the current position 
void wrtchr(char chr);

Sets the current text position to (x,y).  Note that x and y have units
   of cells (8 pixels) 
void gotogxy(UINT8 x, UINT8 y);

Draw a line in the current drawing mode and colour from (x1,y1) to (x2,y2) 
void line(UINT8 x1, UINT8 y1, UINT8 x2, UINT8 y2);

Draw a box (rectangle) with corners (x1,y1) and (x2,y2) using fill mode
   'style' (one of NOFILL or FILL 
void box(UINT8 x1, UINT8 y1, UINT8 x2, UINT8 y2, UINT8 style);

Draw a circle with centre at (x,y) and radius 'radius'.  'style' sets
   the fill mode 
void circle(UINT8 x, UINT8 y, UINT8 radius, UINT8 style);

Plot a point in the current drawing mode and colour at (x,y)
void plot_point(UINT8 x, UINT8 y);

Delays the given number of milliseconds.
    Uses no timers or interrupts, and can be called with 
    interrupts disabled (why nobody knows :)
void delay(UINT16 d);

Reads and returns the current state of the joypad.
    Follows Nintendo's guidelines for reading the pad.
    Return value is an OR of J_*
UINT8 joypad(void);

Waits until all the keys given in mask are pressed.
    Normally only used for checking one key, but it will
    support many, even J_LEFT at the same time as J_RIGHT :)
UINT8 waitpad(UINT8 mask);*/