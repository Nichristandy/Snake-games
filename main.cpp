#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int gd,gm, x[200], y[200], d, dir = 1, rx = 200, ry= 200;
int g = 1, chk = 700, length = 1;


int endfunc(int e, int a);

int snakeyandfood ()
{
	
	
		setfillstyle(1,0);
		bar(0,0,640,480);
		setfillstyle(1,6);
		bar(0,0,640,10);
		bar(0,0,10,480);
		bar(630,10,640,480);
		bar(0,480,640,470);
		
		
		//food taken 
		if (x[0] == rx && y[0]==ry)
		{
		
		length += 1;
		g = g+1;
		setfillstyle(1,0);
		bar(rx,ry,rx + 10, ry+10);
		
		// food spawn
		do
		{
		 rx = (1 + rand() % 620);
		 ry = ( 1 + rand() % 460);	
		 
		 
		}while(getpixel(rx,ry) != 0 && rx > 10 && ry > 10);
		rx = rx/10;
		rx = rx*10;
		ry = ry/10;
		ry = ry*10;
		setfillstyle(1,7);
	
	    }
		bar(rx,ry,rx+10,ry+10);
		// snake 
	if(GetAsyncKeyState(VK_RIGHT))
	{d=1;}
    else if(GetAsyncKeyState(VK_LEFT))
	{ d=2;}
    else if(GetAsyncKeyState(VK_UP))
	{ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) 
	{d=4;}
    else
	{d=0;}
    
		switch(d)
		{
			case 0:
				if(dir == 1) 
				{x[0]=x[0]+10;}
				else if (dir == 2)
				{x[0]=x[0]-10;}
				else if (dir == 3)
				{y[0]=y[0]-10;}
				else if (dir == 4)
				{y[0]=y[0]+10;}
				else 
				{d = 0;}
				break;
				
			case 1:
				x[0] = x[0] +10;
				dir = 1;
				break;
			case 2:
				x[0] = x[0] - 10;
				dir = 2;
				break;
			case 3:
				y[0] = y[0] - 10; 
				dir = 3;
				break;
			case 4:
				dir = 4;
				y[0] = y[0] + 10;
				break;
		}
		for (int i=0; i < length; i++)
		{
			bar(x[i],y[i],x[i]+10,y[i]+10);
		}
		for (int i = 199; i> 0 ; i--)
		{
			x[i] = x[i-1];
			y[i] = y[i-1];
		}
	
		
		delay (100);
		
		if(x[0]>=640 || x[0] <= 0 || y[0] <= 0 || y[0] >=480)
		{
			endfunc(g,0);
		}
		for (int i =2; i < length; i++)
		{
			if(x[0] == x[i] && y[0] == y[i])
			{
				chk = i;
			}
		}
		if(x[0]==x[chk] && y[0] == y[chk])
		{
			endfunc(g, 1);
			return 1;
		}
	
return snakeyandfood();
}	

int main ()
{
	
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm, "");
	
	// direction
	for(int i=0; i<200; i++)
	{
		x[i] = 0;
		y[i] = 0;
	}
	//food eaten 
    setfillstyle(1,1);  
	x[0] = 200;
	y[0] = 200;
	d=1;
	
	
	// border
	snakeyandfood();
	
}

int endfunc(int e, int a)
{
	setfillstyle(1,5);
	e = e -2;
	bar(0,0,640,460);
	system("cls");
	
	if (a==0)
	{
	printf("YOU DIED OUTSIDE THE ZONE\n");
    }
	else if (a==1)
	{
		printf("YOU EAT YOURSELF, AND DIED !!!\n");
	}
	printf("Your Score is: %d\n", e);
	getch();
	return 0;
}




