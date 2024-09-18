#include <iostream>
#include <graphics.h>
#include <time.h>
#include <stdio.h>

using namespace std;
int main()
{
	int gd = DETECT, gm, key_dir, foodX, foodY, snakeX[200], snakeY[200];
	initgraph(&gd, &gm, (char *)"");
	// INITIALIZATION of VARIABLES.....
	int delayTime = 200;
	int food = 0;
	int body = 500;
	int length = 1;
	int p_dir = 1;
	bool game = true;

	for (int i = 0; i < 200; i++)
	{
		snakeX[i] = 0;
		snakeY[i] = 0;
	}
	snakeX[0] = 200, snakeY[0] = 200;
	foodX = 200, foodY = 200;
	key_dir = 1;

	// DRAWING GAME PANEL.....
	while (game)
	{
		setfillstyle(SOLID_FILL, YELLOW);
		bar(0, 0, 630, 470);
		setfillstyle(SOLID_FILL, BLUE);
		bar(0, 0, 630, 10);
		bar(0, 0, 10, 470);
		bar(0, 470, 630, 460);
		bar(620, 10, 630, 470);  // background............
		// Food...............
		setfillstyle(SOLID_FILL, RED);
		if(snakeX[0] == foodX && snakeY[0] == foodY)
		{
			length++;
			food++;
			delayTime--;
			
			bar(foodX, foodY, foodX + 10, foodY + 10);
			// food position................ 
			do
			{
				foodX = (10 + rand() % 600);
				foodY = (10 + rand() % 450);
			}while(getpixel(foodX, foodY) != 0 && foodX > 10 && foodY > 10);
			
			foodX = foodX / 10;
			foodX = foodX * 10;
			foodY = foodY / 10;
			foodY = foodY * 10;
			
			if(foodX == 10)
			{
				foodX = rand() % 10 + 5;
				foodX = foodX * 10;
			}
			else if(foodY == 10)
			{
				foodY = rand() % 10 + 5;
				foodY = foodY * 10;
			}
			
		}
		// arrow key directions from kekyboard..........
		bar(foodX, foodY, foodX + 10, foodY + 10);
		
		setfillstyle(SOLID_FILL, BLACK);
		if(GetAsyncKeyState(VK_RIGHT))
		{
			key_dir = 1;
		}
		else if(GetAsyncKeyState(VK_LEFT))
		{
			key_dir = 2;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			key_dir = 3;
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			key_dir = 4;
		}
		else
		{
			key_dir = 0;
		}
		
		switch(key_dir)
		{
			case 0:
				{
					if(p_dir == 1)
					{
						snakeX[0] += 10;
					}
					else if(p_dir == 2)
					{
						snakeX[0] -= 10;
					}
					else if(p_dir == 3)
					{
						snakeY[0] -= 10;
					}
					else if(p_dir == 4)
					{
						snakeY[0] += 10;
					}
					else
					{
						key_dir = 0;
					}
					break;
				} 
			case 1:
				{
					snakeX[0] += 10;
					p_dir = 1;
					break;
				}
			case 2:
				{
					snakeX[0] -= 10;
					p_dir = 2;
					break;
				}
			case 3:
				{
					snakeY[0] -= 10;
					p_dir = 3;
					break;
				}
			case 4:
				{
					snakeY[0] += 10;
					p_dir = 4;
					break;
				}
		}
		
		// SNAKE DISPLAY......
		for(int i = 0; i < length; i++)
		{
			bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
		}
		
		// SNAKE BODY......
		for(int i = 199; i > 0; i--)
		{
			snakeX[i] = snakeX[i - 1];
			snakeY[i] = snakeY[i - 1];
		}
		
		// IF SNAKE TOUCHES ITS BODY.......
		for(int i = 2; i < length; i++)
		{
			if(snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
			{
				body = i;
				break;
			}
		}
		delay(delayTime);
		
		// IF SNAKE TOUCHES WALL......
		if(snakeX[0] >= 615 || snakeX[0] <= 5 || snakeY[0] <= 5 || snakeY[0] >= 455)
		{
			cout<<"\t\nSNAKE BUMPED INTO THE WALL !!!"<<endl;
			game = false;
		}
		// IF SNAKE TOUCHES ITSELF......
		if(snakeX[0] == snakeX[body] && snakeY[0] == snakeY[body])
		{
			cout<<"\t\nSNAKE BUMPED INTO ITSELF !!!"<<endl;
			game = false;
		}
		
	}
	
	cout<<"\t\nYour Score is "<<food - 1<<endl;
	cout<<"\t\tG A M E  O V E R  !!!\a"<<endl;
	return 0;
	
}
