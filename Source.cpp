#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;
int win(char ch);
void board(int emh);

char jadval[11][11];
int l;
int emh=7;
int i,j,c,n12=1,k;
int main(void)
{

/*
jadval[6][0]='X';
jadval[6][1]='X';
jadval[6][2]='X';
jadval[6][3]='X';
*/
cout<<"1 - easy \n";
cout <<"2 - medium \n";
cout <<"3 - hard \n";
cin >> c;
if(c==1)
	emh=7;
if(c==2)
	emh=9;
if(c==3)
	emh=11;

do
{
board(emh);
cin >> c;
for(i=emh-1;i>-1;i--)
{
	if(jadval[i][c]=='\0')
	{
		k=i;
		break;
	}
}

if (n12==1){
	jadval[k][c]='O';
   n12=2;
   if(win('O')==4)
   {
   	board(emh);
   	cout << "O is win";
      getch();
      c=-1;
   }
}else{
	jadval[k][c]='X';
   n12=1;
   if(win('X')==4)
   {
   	board(emh);
   	cout << "X is win";
      getch();
      c=-1;
   }
}

}while(c!=-1);

//getch();

}

int win(char ch)
{
   int cc;
	for(i=0;i<emh-3;i++)
   {
   	for(j=0;j<emh-3;j++)
      {
      	cc=0;
      	for(k=0;k<emh-3;k++)
         {
         	if(jadval[i+k][j+k]==ch)
            {
            	cc++;
            }
         }
         if(cc==4)
         {
         	return cc;
         }
      	cc=0;
      	for(k=0;k<4;k++)
         {
         	if(jadval[i+k][j-k]==ch)
            {
            	cc++;
            }
         }
         if(cc==4)
         {
         	return cc;
         }

      	cc=0;
      	for(k=0;k<4;k++)
         {
         	if(jadval[i+j][k+i]==ch)
            {
            	cc++;
            }
         }
         if(cc==4)
         {
         	return cc;
         }

		   cc=0;
      	for(k=0;k<4;k++)
         {
         	if(jadval[k+i][i+j]==ch)
            {
            	cc++;
            }
         }
         if(cc==4)
         {
         	return cc;
         }
		}
   }

return cc;
}

void board(int emh)
{
//clrscr();
for(i=0;i<emh;i++)
{
	for(l=0;l<=(emh*2);l++)
   	cout <<"-";
	cout <<"\n";
	for(j=0;j<emh;j++)
   {
		//jadval[i][j]=' ';
		cout <<"|"<<jadval[i][j];
	}
	cout <<"|\n";
}
for(l=0;l<=(emh*2);l++)
	cout <<"-";
cout <<"\n";
for(l=0;l<emh;l++)
	cout << " " << l;
cout <<"\n\n\n";

}

