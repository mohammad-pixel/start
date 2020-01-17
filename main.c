#include <stdio.h>

#include <ctype.h>

#include <conio.h>

#include <windows.h>

char map[100][100], *MOVE, move;

int x, y, h, v, flag, FLAG, point_place[100][2], count, END, total;

FILE *ptf;

void Map()

{
	
	ptf=fopen("testcase.txt", "r");
	
	if(ptf==NULL)
	
	{
		
		printf("NO map exist!");
	}
	
	else
	
	{
		
		for( h=0; !feof(ptf); h++)
		
		{
			
			fscanf(ptf,"%s",map[h]);
			
		}
		
		v=strlen(map[0]);
		
		
		
		for(int i=0; i<h; i++)
		
		{
			
			for(int j=0; j<v; j++)
			
			{
				
				if(map[i][j]=='*')
				
				{
					
					point_place[count][0]=i;
					
					point_place[count][1]=j;
					
				    count++;
				}
				
				
			}
			
			
		}
		
	}
}

void key()

{
	
	Display();
	
	while(END==0)
	
	{
	
	move=getch();
	
	Move();
	
    }
}

void Move()

{
	
	move=tolower(move);
	
	switch(move)
	
	{
		
		case 'w':
			
			{
				
				y--;
				
				
				if(y<0||(map[y][x]=='#'))
				
				{
					
					if(map[y][x]=='#')
					
					{
						
						FLAG=1;
						
						MOVE="up";
					}
					
					y++;
					
					printf("\a");
				}
				
				
				break;
			}
			
		case 's':
			
			{
				
				y++;
				
				
	            if(y>=h||(map[y][x]=='#'))
	            
	            {
	            	
	            	if(map[y][x]=='#')
					
					{
						
						FLAG=1;
						
						MOVE="down";
					}
	            	
	            	y--;
	            	
	            	printf("\a");
	            	
	            }
				
				
				break;
			}
			
		case 'a':
			
			{
				
				x--;
				
				
				
				if(x<0||(map[y][x]=='#'))
				
				{
					if(map[y][x]=='#')
					
					{
						
						FLAG=1;
						
						MOVE="left";
					}
					
					x++;
					
					printf("\a");
					
					
				}
				
				break;
			}
			
		case 'd':
			
			{
				
				x++;
				
				
				
				if(x>=v||(map[y][x]=='#'))
				
				{
					
					if(map[y][x]=='#')
					
					{
						
						FLAG=1;
						
						MOVE="right";
					}
					
					
					
					x--;
					
					printf("\a");
				}
				
				break;
				
			}
			
		default :
			
			{
				
				puts("pls enter correct key!");
			}
			
	}
	
	if(map[y][x]=='*')
	
	{
		
		flag=1;
	}
	
	system("cls");
	
	Display();
	
    
}

void Display()

{
	
	
	for(int i=0; i<h; i++)
	
	{
		
		for(int j=0; j<v; j++)
		
		{
			
			
			if((i==y&&j==x)||map[i][j]=='O')
			
			{
				
				
				map[i][j]='1';
				
				printf("O");
				
			}
			
			else
			
			{
				
				
				printf("%c", map[i][j]);
			}
		}
		
		printf("\n");
		
	}
	
	
	if(flag)
	
	{
		Beep(1000,500);
		
		total++;
		
		flag=0;
	}
	
	printf("\n\npoint : %d", total);
	
	if(total==count)
	
	{
		
		printf("\n\n\npackman finished eating");
		
		for(int i=0; i<1000; i++)
		
		{
			
			Beep(800,400);
			
			Beep(8000,200);
			
			Beep(2000,200);
			
			Beep(8000,200);
			
			Beep(400,500);
			
			Beep(8000,200);
			
			Beep(800,400);
			
			Beep(8000,200);
			
			Beep(3000,200);
			
			Beep(8000,000);
			
			Beep(400,500);
			
			Beep(8000,200);
			
			Beep(800,400);
			
			Beep(8000,200);
			
			Beep(1000,200);
			
			Beep(8000,200);
			
			Beep(400,500);
			
			Beep(8000,200);
			
			Beep(800,400);
			
			Beep(8000,200);
			
			
		}
		
		END=1;
		
	}
	
	if(FLAG)
	
	{
		
		printf("\n\nYou cant move to %s! There is an obstacl", MOVE);
		
		
		FLAG=0;
					
	}
	
	
		
}

/*void automatic()

{
	Display();
	
    for(int i=0; i<count; i++)
    
    {
    	
    	if()
	}
	
}*/


int main()

{
	
	Map();
	
	key();
	
	//automatic();
	
	fclose(ptf);
	
}
