/* DO NOT DELETE THIS COMMENT.
This cpp file is an exclusive part of the graphics project titled "SOKOBAN" for 6th sem and is not meant for any other purpose.
This is a handwritten genuine code.
Any resemblance to any code found anywhere else is purely a coincidence.
Credits:
1.Utkarsh Deep - 1MV14CS115
2.Shubham Sinha - 1MV14CS101


*/


#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "test.h"
#include"compute.h"
#include<GL/glut.h>
#include "lodepng.h"
#include "lodepng.cpp"
#include <vector>
//

std::vector <unsigned char> box3;
std::vector <unsigned char> box5;
std::vector <unsigned char> box4;
std::vector <unsigned char> box6;
std::vector <unsigned char> box7;
std::vector <unsigned char> box8;
std::vector <unsigned char> logo;
std::vector <unsigned char> chotaBachha;
std::vector <unsigned char> logo3;
std::vector <unsigned char> logo4;
std::vector <unsigned char> logo5;
std::vector <unsigned char> logo6;
std::vector <unsigned char> logo7;
std::vector <unsigned char> logo8;
unsigned int logoWidth=150;
unsigned int logoHeight=150;
unsigned int logoWidth3=150;
unsigned int logoHeight3=150;
unsigned int logoWidth4=150;
unsigned int logoHeight4=150;
unsigned int logoWidth5=150;
unsigned int logoHeight5=150;
unsigned int logoWidthBachha=150;
unsigned int logoHeightBachha=150;
unsigned int logoWidthBox3=150;
unsigned int logoHeightBox3=150;
unsigned int logoWidthBox4=150;
unsigned int logoHeightBox4=150;
unsigned int logoWidthBox5=150;
unsigned int logoHeightBox5=150;
unsigned int logoWidthBox6=150;
unsigned int logoHeightBox6=150;
unsigned int logoWidth6=150;
unsigned int logoHeight6=150;
unsigned int logoWidth7=150;
unsigned int logoHeight7=150;
unsigned int logoWidthBox7=150;
unsigned int logoHeightBox7=150;
unsigned int logoWidth8=150;
unsigned int logoHeight8=150;
unsigned int logoWidthBox8=150;
unsigned int logoHeightBox8=150;
//unsigned int logoWidth1;
//unsigned int logoHeight1;
int dx;
int flag=0;
int dy;
int playerPush=0;
char grid[500][500];
char duplicate[500][500];
char sample[4][4]={{'D','.','.','.'},{'.','X','B','.'},{'X','X','S','.'},{'.','.','.','.'}};
int m=4;
int n;
int sx,sy,bx,by,desx,desy;
void makeBox(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
void makeSokoban(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
void update() {
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++) {
        if(grid[i][j]=='B'||grid[i][j]=='S') {
            duplicate[i][j]='.';
        }
        else
            duplicate[i][j]=grid[i][j];
    }
    if(sx==desx&&sy==desy) {
        duplicate[sx][sy]='L';
        duplicate[bx][by]='B';
    }
    else {
    duplicate[sx][sy]='S';
    duplicate[bx][by]='B';
    }
    //printf("duplicate array: \n");
    //printf("sx=%d sy=%d",sx,sy);
    /*for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
        printf("%c ",duplicate[i][j]);
        }
        printf("\n");
    }*/

}

void drawStrokeText(char str[250],int x,int y,int z,float p1,float p2)
{
      int i;
	  glPushMatrix();
	  glTranslatef(x, y,z);
	  glScalef(p1,p2,z);

	  for (i=0;str[i]!='\0';i++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , str[i]);
	  }
	  glPopMatrix();
}
void display() {
   // printf("%d\n",playerPush);

    if(flag==0) {
            glClearColor(1.0,0.0,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_POLYGON);
            glColor3f(0.984,0.406,0.003);
            glVertex2f(0,1000);
            glVertex2f(1000,1000);
            glColor3f(0,0,0);
            glVertex2f(1000,0);
            glVertex2f(0,0);
            glEnd();

        //char headline[]="SOKOBAN";
       // char play[]="Play";
        //char help[]="Help";
        //unsigned int a=110;
        //unsigned int b=120;
        //unsigned logoWidth=100;
        //unsigned logoHeight=120;
        glRasterPos2i(60,70);
        glDrawPixels(logoWidthBachha,logoHeightBachha, GL_RGBA, GL_UNSIGNED_BYTE,&chotaBachha[0]);
        glColor3f(0.0,1.0,0.0);
        drawStrokeText("LAZY SOKOBAN",90,430,0,0.30,0.30);
        glColor3f(1.0,0.0,0.0);
        drawStrokeText("Press P to play game.",300,300,0,0.10,0.15);
        //glColor3f(0.0,1.0,0.0);
        drawStrokeText("Press H for help.",300,250,0,0.10,0.15);
        /*glColor3f(0.0,1.0,1.0);
        drawStrokeText("By: ",120,90,0,0.12,0.12);
        drawStrokeText("1.Utkarsh Deep - 1MV14CS115",120,60,0,0.12,0.12);
        drawStrokeText("2.Shubham Sinha - 1MV14CS101",120,40,0,0.12,0.12);
        */
        //glClear(GL_COLOR_BUFFER_BIT);
    /*glColor3f(1.0,0.0,0.0);
        int i,j;
    int x[m+1];
    int y[m+1];
    dx=180/m;
    dy=220/m;
    int x0=70;
    int y0=130;
    //for(i=0;i<n;i++)
    for(i=0;i<=m;i++) {
        x[i]=x0+(i*dx);
    }
    for(j=0;j<=m;j++) {
        y[j]=y0+((m-j)*dy);
    }
    for(j=0;j<m;j++)
    for(i=0;i<m;i++) {
           // flag=0;
            switch(sample[j][i]) {
                case '.': makeFloor(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                            break;
                case 'X': makeWall(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'B': makeBox(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'D': makeDestination(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'S' : makeSokoban(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);

                break;
                case 'L': makeDestination(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                makeFace(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                default: break;
            }
            //if(i>=n-1||j>=n-1) continue;
           /* glBegin(GL_POLYGON);
            glVertex2f(x[i],y[j]);
            glVertex2f(x[i+1],y[j]);
            glVertex2f(x[i+1],y[j+1]);
            glVertex2f(x[i],y[j+1]);
            glEnd();
            if(flag==1) {
                makeFace(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
            }
    }
    }
    glColor3f(1.0,1.0,1.0);
    for(i=0;i<m;i++)
    for(j=0;j<m;j++) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x[i],y[j]);
        glVertex2f(x[i+1],y[j]);
        glVertex2f(x[i+1],y[j+1]);
        glVertex2f(x[i],y[j+1]);
        glEnd();

    }*/
    glutSwapBuffers();


        //glFlush();
    }
    else if(flag==4) {
        glClearColor(0.0,1.0,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
            glColor3f(0.003,0.984,0.851);
            glVertex2f(0,1000);
            glVertex2f(1000,1000);
            glColor3f(1,1,0);
            glVertex2f(1000,0);
            glVertex2f(0,0);
            glEnd();

    glColor3f(0.0,0.0,0.0);
        drawStrokeText("HELP",190,450,0,0.25,0.25);
        drawStrokeText("CONTROLS:",20,400,0,0.10,0.10);
        drawStrokeText("Use arrow keys to move sokoban and push the box.",20,380,0,0.07,0.07);
        drawStrokeText("OBJECTIVE OF GAME:",20,340,0,0.10,0.10);
        drawStrokeText("Objective is to minimize number of pushes by sokoban player to reach the destination.",20,320,0,0.07,0.07);
        drawStrokeText("END OF GAME:",20,280,0,0.10,0.10);
        drawStrokeText("At the end of game, the ideal path computed by our background algorithm will be shown to you.",20,260,0,0.07,0.07);
        drawStrokeText("Your efficiency :",70,220,0,0.085,0.085);
        drawStrokeText("No of pushes computed by our algorithm",170,220,0,0.085,0.085);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(170.0,210.0);
            glVertex2f(400.0,210.0);
        glEnd();
        drawStrokeText("No of pushes taken by player",170,190,0,0.085,0.085);
        drawStrokeText("X 100 ",415,210,0,0.085,0.085);
        drawStrokeText("DEVELOPERS: ",20,100,0,0.10,0.10);
        drawStrokeText("1. UTKARSH DEEP (1MV14CS115)",20,80,0,0.07,0.07);
        drawStrokeText("2. SHUBHAM SINHA (1MV14CS101)",20,60,0,0.07,0.07);
        drawStrokeText("Press b to go back to welcome screen",350,50,0,0.05,0.05);
        glutSwapBuffers();
    }
    else if(flag==1) {
            glClearColor(0.0,1.0,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_POLYGON);
            glColor3f(0.398,0.000,0.398);
            glVertex2f(0,1000);
            glVertex2f(1000,1000);
            glColor3f(1,1,1);
            glVertex2f(1000,0);
            glVertex2f(0,0);
            glEnd();
            //glRasterPos2i(350,0);
        //glDrawPixels(logoWidth,logoHeight, GL_RGBA, GL_UNSIGNED_BYTE,&logo[0]);
    glColor3f(0.0,0.0,0.0);
        drawStrokeText("SOKOBAN",160,450,0,0.30,0.30);
        drawStrokeText("Press S to surrender",320,100,0,0.10,0.10);
        drawStrokeText("Number of push :",320,350,0,0.10,0.10);
        char cg[3];
        //float val1=val;
        //float playerPush1=playerPush;
        sprintf(cg,"%d",playerPush);
        drawStrokeText(cg,360,300,0,0.30,0.30);
            dx=300/n;
    dy=400/n;
    int i,j;
    int x[n+1];
    int y[n+1];
    //for(i=0;i<n;i++)
    for(i=0;i<=n;i++) {
        x[i]=(i*dx);
    }
    for(j=0;j<=n;j++) {
        y[j]=((n-j)*dy);
    }

   // glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0,1.0,0.0);
    //for()


    glColor3f(1.0,0.0,0.0);
    //int flag=0;
    for(j=0;j<n;j++)
    for(i=0;i<n;i++) {
           // flag=0;
            switch(duplicate[j][i]) {
                case '.': makeFloor(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                            break;
                case 'X': makeWall(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'B': makeBox(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'D': makeDestination(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'S' : makeSokoban(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);

                break;
                case 'L': makeDestination(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                makeFace(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                default: break;
            }
            //if(i>=n-1||j>=n-1) continue;
           /* glBegin(GL_POLYGON);
            glVertex2f(x[i],y[j]);
            glVertex2f(x[i+1],y[j]);
            glVertex2f(x[i+1],y[j+1]);
            glVertex2f(x[i],y[j+1]);
            glEnd();
            if(flag==1) {
                makeFace(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
            }*/
    }
    glColor3f(1.0,1.0,1.0);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x[i],y[j]);
        glVertex2f(x[i+1],y[j]);
        glVertex2f(x
                   [i+1],y[j+1]);
        glVertex2f(x[i],y[j+1]);
        glEnd();

    }

        //glFlush();
    glutSwapBuffers();


    }
    else if(flag==2||flag==3) {
        //code to surrender
        //printf("hello hello\n");
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0,1.0,1.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_POLYGON);
            glColor3f(0.976,0.777,0.023);
            glVertex2f(0,1000);
            glVertex2f(1000,1000);
            glColor3f(0.011,0.976,0.875);
            glVertex2f(1000,0);
            glVertex2f(0,0);
            glEnd();
    glColor3f(1.0,0.0,0.0);
        if(flag==2)
            drawStrokeText("OOPS! YOU FAILED TO FINISH THE GAME",50,470,0,0.13,0.13);
        else
            drawStrokeText("CONGRATS! YOU MADE IT!!",50,470,0,0.13,0.13);
        drawStrokeText("Optimum path with minimum number of pushes is shown below: ",30,420,0,0.10,0.10);
        //i changed it
        /*int val=26;
        char str[3];
        sprintf(str,"%d\0",val);
        drawStrokeText(str,300,250,0,0.1,0.1);*/
         dx=300/n;
    dy=400/n;
    int i,j;
    int x[n+1];
    int y[n+1];
    //for(i=0;i<n;i++)
    for(i=0;i<=n;i++) {
        x[i]=(i*dx);
    }
    for(j=0;j<=n;j++) {
        y[j]=((n-j)*dy);
    }
         /*dx=200/n;
    dy=250/n;
    int i,j;
    int x[n+1];
    int y[n+1];
    //for(i=0;i<n;i++)
    int i0=50;
    int y0=120;
    for(i=0;i<=n;i++) {
        x[i]=i0+(i*dx);
    }
    for(j=0;j<=n;j++) {
        y[j]=y0+((n-j)*dy);
    }*/

   // glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0,1.0,0.0);
    //for()

    char sinha[100][100];
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            sinha[i+1][j+1]=grid[i][j];
        }

    }
    for(i=0;i<n+2;i++) {
        sinha[0][i]='X';
        sinha[n+1][i]='X';
        sinha[i][0]='X';
        sinha[i][n+1]='X';
    }
    /*for(i=0;i<n+2;i++) {
        for(j=0;j<n+2;j++)
            printf("%c\t",sinha[i][j]);
        printf("\n");
    }*/
    int bahubali[100];
    for(i=0;i<100;i++)
        bahubali[i]=-1;
    sokoban(sinha,n+2,bahubali);
    i=2;
    while(bahubali[i]!=-1) {
        bahubali[i]=bahubali[i+1];
        i++;
    }
    bahubali[i-2]=-1;
    //i=0;
    /*while(bahubali[i]!=-1) {
        printf("%d\t",bahubali[i]);
        i++;
    }*/
    i=2;

    while(bahubali[i]!=-1) {

        sinha[bahubali[i]/(n+2)][bahubali[i]%(n+2)]='U';
        i++;
    }


    i=2;
    while(bahubali[i]!=-1) {
        //printf("%d\t",bahubali[i]);
        i++;
    }
    int push=i;

    //bahubali[i-2]=-1;
    /*for(i=0;i<n+2;i++) {
        for(j=0;j<n+2;j++)
            printf("%c\t",sinha[i][j]);
        printf("\n");
    }*/
    drawStrokeText("YOUR SCORE:",330,370,0,0.15,0.15);
     int val=push-1;

    if(flag==2)
        drawStrokeText("0%",400,300,0,0.15,0.15);
    else
    {
        char str11[3];
        float val1=val;
        float playerPush1=playerPush;
        sprintf(str11,"%.2f %%",(val1/(playerPush1))*100);
        drawStrokeText(str11,380,300,0,0.15,0.15);

    }
    drawStrokeText("OPTIMUM NUMBER OF PUSHES:",310,220,0,0.08,0.08);
    char str22[3];
        sprintf(str22,"%d%",val);
        drawStrokeText(str22,400,150,0,0.15,0.15);
    drawStrokeText("PRESS E TO EXIT",330,60,0,0.10,0.10);
    //I CHANGED IT


    char utkarsh[100][100];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            utkarsh[i-1][j-1]=sinha[i][j];
    /*for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            printf("%c\t",utkarsh[i][j]);
        printf("\n");
    }*/




    glColor3f(1.0,0.0,0.0);
    //int flag=0;
    for(j=0;j<n;j++)
    for(i=0;i<n;i++) {
           // flag=0;
            switch(utkarsh[j][i]) {
                case '.': makeFloor(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                            break;
                case 'X': makeWall(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'B': makeBox(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'D': makeDestination(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                break;
                case 'S' : makeSokoban(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);

                break;
                case 'L': makeDestination(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                makeFace(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);

                break;
                case 'U' : makePath(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
                default: break;
            }
            //if(i>=n-1||j>=n-1) continue;
           /* glBegin(GL_POLYGON);
            glVertex2f(x[i],y[j]);
            glVertex2f(x[i+1],y[j]);
            glVertex2f(x[i+1],y[j+1]);
            glVertex2f(x[i],y[j+1]);
            glEnd();
            if(flag==1) {
                makeFace(x[i],y[j],x[i+1],y[j],x[i+1],y[j+1],x[i],y[j+1]);
            }*/
    }
    glColor3f(1.0,1.0,1.0);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x[i],y[j]);
        glVertex2f(x[i+1],y[j]);
        glVertex2f(x[i+1],y[j+1]);
        glVertex2f(x[i],y[j+1]);
        glEnd();

    }

        //glFlush();
    //glutSwapBuffers();
        glutSwapBuffers();
    }
    //printf("%d\n",bahubali[0]);
    glFlush();
}
void init() {
    //glClearColor(1.0,0.0,0.0,1.0);
   // glColor3f(1.0,1.0,1.0);
   // glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  //  gluOrtho2D(0.0,199.0,0.0,100.0);
    gluOrtho2D(0.0,500.0,0.0,500.0);
  //  glutPostRedisplay();

  glMatrixMode(GL_MODELVIEW);

}
void myKey(int key,int x,int y) {
    switch(key) {
    case 103 :
        printf("GLUT_KEY_DOWN %d\n",key);
        if(sx<n-1) {
                if(bx==sx+1&&by==sy) {
                    if(duplicate[bx+1][by]!='X'&&bx+1<n) {
                        playerPush++;
                        sx=sx+1;
                        bx=bx+1;
                        update();
                        if(bx==desx&&by==desy) {
                            //exit(0);
                            flag=3;
                            glutPostRedisplay();

                        }
                    }
                }
                else if(duplicate[sx+1][sy]=='.'||duplicate[sx+1][sy]=='D') {
                    sx=sx+1;
                    update();
                }
        }
        break;
    case 101 :
        printf("GLUT_KEY_UP %d\n",key);
         if(sx>0) {
                if(bx==sx-1&&by==sy) {
                    if(duplicate[bx-1][by]!='X'&&bx-1>=0) {
                        playerPush++;
                        sx=sx-1;
                        bx=bx-1;
                        update();
                        if(bx==desx&&by==desy) {
                            //exit(0);
                            flag=3;
                            glutPostRedisplay();
                        }
                    }
                }
                else if(duplicate[sx-1][sy]=='.'||duplicate[sx-1][sy]=='D') {
                    sx=sx-1;
                    update();
                }
        }
        break;
    case 102 :
        printf("GLUT_KEY_RIGHT %d\n",key);
         if(sy<n-1) {
                if(by==sy+1&&bx==sx) {
                    if(duplicate[bx][by+1]!='X'&&by+1<n) {
                        playerPush++;
                        sy=sy+1;
                        by=by+1;
                        update();
                        if(bx==desx&&by==desy) {
                            //exit(0);
                            flag=3;
                            glutPostRedisplay();
                        }
                    }
                }
                else if(duplicate[sx][sy+1]=='.'||duplicate[sx][sy+1]=='D') {
                    sy=sy+1;
                    update();
                }
        }
        break;
    case 100 :
        printf("GLUT_KEY_LEFT %d\n",key);
        if(sy>0) {
                if(by==sy-1&&bx==sx) {
                    if(duplicate[bx][by-1]!='X'&&by-1>=0) {
                        playerPush++;
                        sy=sy-1;
                        by=by-1;
                        update();
                        if(bx==desx&&by==desy) {
                            //exit(0);
                            flag=3;
                            glutPostRedisplay();
                        }
                    }
                }
                else if(duplicate[sx][sy-1]=='.'||duplicate[sx][sy-1]=='D') {
                    sy=sy-1;
                    update();
                }
        }
        break;
        default: break;

    }
    glutPostRedisplay();
}
void keyfunc(unsigned char key,int x,int y) {
    if(key=='p'||key=='P') {
        if(flag!=2) {
            flag=1;
            glutPostRedisplay();
        }
        else
            glutPostRedisplay();
    }
    else if(key=='s'||key=='S') {
        if(flag==0) {
            glutPostRedisplay();
        }
        else {
            flag=2;
            glutPostRedisplay();
        }
    }
    else if(key=='h'||key=='H') {
        if(flag==0) {
                flag=4;
            glutPostRedisplay();
        }
        else {
            //flag=2;
            glutPostRedisplay();
        }
    }
    else if(key=='b'||key=='B') {
        if(flag==4) {
                flag=0;
            glutPostRedisplay();
        }
        else {
            //flag=2;
            glutPostRedisplay();
        }
    }
    else if(key=='e'||key=='E') {
        if(flag==0||flag==1) {
            glutPostRedisplay();
        }
        else {
            //flag=2;
            //glutPostRedisplay();
            exit(0);
        }
    }

}
void invert(std::vector<unsigned char> &img,const unsigned width,const unsigned height)
{
    unsigned char *imagePtr = &img[0];
    unsigned char *top = NULL;
    unsigned char *bottom = NULL;
    unsigned char temp = 0;
    for( int h = 0; h <(int) height/2; ++h )
    {

        top = imagePtr + h * width * 4;
        bottom = imagePtr + (height - h - 1) * width*4;
        for( int w = 0; w < (int)width*4; ++w )
        {
            temp = *top;
            *top = *bottom;
            *bottom = temp;
            ++top;
            ++bottom;
        }
    }
}
void makeBox(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    /*glColor3f(0.545,0.271,0.0745);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();*/
    if(n==3&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox3,logoHeightBox3, GL_RGBA, GL_UNSIGNED_BYTE,&box3[0]);
    }
    else if(n==4&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox4,logoHeightBox4, GL_RGBA, GL_UNSIGNED_BYTE,&box4[0]);
    }
    else if(n==5&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox5,logoHeightBox5, GL_RGBA, GL_UNSIGNED_BYTE,&box5[0]);
    }
    else if(n==6&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox6,logoHeightBox6, GL_RGBA, GL_UNSIGNED_BYTE,&box6[0]);
    }
    else if(n==7&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox7,logoHeightBox7, GL_RGBA, GL_UNSIGNED_BYTE,&box7[0]);
    }
    else if(n==8&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox8,logoHeightBox8, GL_RGBA, GL_UNSIGNED_BYTE,&box8[0]);
    }
    else {
    glRasterPos2i(x4,y4);
    glDrawPixels(logoWidthBox3,logoHeightBox3, GL_RGBA, GL_UNSIGNED_BYTE,&box3[0]);
    }
    glFlush();
}
void makeFace(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {

    //unsigned int logoWidth=150;
    //unsigned int logoHeight=150;
    if(n==3&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth3,logoHeight3, GL_RGBA, GL_UNSIGNED_BYTE,&logo3[0]);
    }
    else if(n==4&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth4,logoHeight4, GL_RGBA, GL_UNSIGNED_BYTE,&logo4[0]);
    }
    else if(n==5&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth5,logoHeight5, GL_RGBA, GL_UNSIGNED_BYTE,&logo5[0]);
    }
    else if(n==6&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth6,logoHeight6, GL_RGBA, GL_UNSIGNED_BYTE,&logo6[0]);
    }
    else if(n==7&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth7,logoHeight7, GL_RGBA, GL_UNSIGNED_BYTE,&logo7[0]);
    }
    else if(n==8&&(flag==1||flag==2||flag==3)) {
       glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth8,logoHeight8, GL_RGBA, GL_UNSIGNED_BYTE,&logo8[0]);
    }
    else {
    glRasterPos2i(x4,y4);
    glDrawPixels(logoWidth,logoHeight, GL_RGBA, GL_UNSIGNED_BYTE,&logo[0]);
    }


    /*double length=distance(x1,y1,x2,y2);

    double xp1=x1+(length/5);
    double yp1=y1-(length/5);
    double xp2=x2-(length/5);
    double yp2=y2-(length/5);
    double xp3=x3-(length/5);
    double yp3=y3+(length/5);
    double xp4=x4+(length/5);
    double yp4=y4+(length/5);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(xp1,yp1);
        glVertex2f(xp2,yp2);
        glVertex2f(xp3,yp3);
        glVertex2f(xp4,yp4);
    glEnd();
    //glFlush();
    length=distance(xp1,yp1,xp2,yp2);
    double unit;
    //1st eye
    unit=length/6;
    double e1xp1=xp1+(1.5*unit);
    double e1yp1=yp1-(1.5*unit);
    double e1xp2=xp1+(1.5*unit)+unit;
    double e1yp2=yp1-(1.5*unit);
    double e1yp3=yp1-(1.5*unit)-unit;
    double e1xp3=e1xp2;
    double e1xp4=e1xp1;
    double e1yp4=e1yp3;
    glColor3f(0.0,0.933,0.463);
    glBegin(GL_POLYGON);
        glVertex2f(e1xp1,e1yp1);
        glVertex2f(e1xp2,e1yp2);
        glVertex2f(e1xp3,e1yp3);
        glVertex2f(e1xp4,e1yp4);
    glEnd();
    //glFlush();
    //2nd eye
    double e2xp1=xp2-(1.5*unit)-unit;
    double e2yp1=yp2-(1.5*unit);
    double e2xp2=xp2-(1.5*unit);
    double e2yp2=e2yp1;
    double e2xp3=e2xp2;
    double e2yp3=yp2-(1.5*unit)-unit;
    double e2yp4=e2yp3;
    double e2xp4=e2xp1;
    glColor3f(0.0,0.933,0.463);
    glBegin(GL_POLYGON);
        glVertex2f(e2xp1,e2yp1);
        glVertex2f(e2xp2,e2yp2);
        glVertex2f(e2xp3,e2yp3);
        glVertex2f(e2xp4,e2yp4);
    glEnd();
    //glFlush();
    unit=length/12;
    double mxp1=xp4+(3*unit);
    double myp1=yp4+(4*unit);
    double mxp2=xp4+(9*unit);
    double myp2=myp1;
    double mxp3=mxp2;
    double myp3=yp3+(3*unit);
    double mxp4=mxp1;
    double myp4=myp3;
    glColor3f(0.0,0.933,0.463);
    glBegin(GL_POLYGON);
        glVertex2f(mxp1,myp1);
        glVertex2f(mxp2,myp2);
        glVertex2f(mxp3,myp3);
        glVertex2f(mxp4,myp4);
    glEnd();*/

    glFlush();


}

void makeSokoban(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    makeFace(x1,y1,x2,y2,x3,y3,x4,y4);
    glFlush();
}
int main(int argc,char **argv) {
    int i,j;
    int error;
    int choice;
    printf("Welcome to SOKOBAN game.\nChoose any one mode to play:\nSystem Defined Input:   PRESS 1\nCustom input:      PRESS 2\n");
    scanf("%d",&choice);
    const char* logoNameBox3="box3.png";
    const char* logoNameBox5="box5.png";
    const char* logoNameBox4="box4.png";
    const char* logonameBachha="chotaBachha.png";
    const char* logoName="img.png";
    const char* logoName3="img3.png";
    const char* logoName4="img4.png";
    const char* logoName5="img5.png";
    const char* logoNameBox6="box6.png";
    const char* logoName6="img6.png";
    const char* logoNameBox7="box7.png";
    const char* logoName7="img7.png";
    const char* logoNameBox8="box8.png";
    const char* logoName8="img8.png";
    //double a1=20.0,b1=20.0;
    //unsigned int a=(unsigned int)a1;
    //unsigned int b=(unsigned int)b1;

        if(choice==2) {
            scanf("%d",&n);
    for(i=0;i<n;i++) {
            fflush(stdin);
        for(j=0;j<n;j++) {
        //grid[i][j]=getchar();

        scanf("%c",&grid[i][j]);
        duplicate[i][j]=grid[i][j];
       if(grid[i][j]=='S') {
            sx=i;
            sy=j;
        }
        else if(grid[i][j]=='B') {
            bx=i;
            by=j;
        }
        else if(grid[i][j]=='D') {
            desx=i;
            desy=j;
        }
        //printf("%d,%d\n",i,j);
        }


    }
    }
    else if(choice==1) {
        n=8;
        char aaa[8][8]={{'.','.','.','.','.','.','.','S'},{'.','D','X','.','.','.','.','.'},{'.','.','X','.','X','.','.','X'},
                        {'.','.','X','.','X','X','.','X'},{'.','.','X','.','X','.','.','.'},{'.','.','.','.','.','X','B','.'},
                        {'.','.','X','.','.','.','.','.'},{'X','X','X','.','.','.','.','.'}};
        /*grid[0]={'.','.','.','.','.','.','.','S'};
        duplicate[0]=grid[0];
        grid[1]={'.','D','X','.','.','.','.','.'};
        duplicate[1]=grid[1];
        grid[2]={'.','.','X','.','X','.','.','X'};
        duplicate[2]=grid[2];
        grid[3]={'.','.','X','.','X','X','.','X'};
        duplicate[3]=grid[3];
        grid[4]={'.','.','X','.','X','.','.','.'};
        duplicate[4]=grid[4];
        grid[5]={'.','.','.','.','.','X','B','.'};
        duplicate[5]=grid[5];
        grid[6]={'.','.','X','.','.','.','.','.'};
        duplicate[6]=grid[6];
        grid[7]={'X','X','X','.','.','.','.','.'};
        duplicate[7]=grid[7];*/
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                grid[i][j]=aaa[i][j];
                duplicate[i][j]=aaa[i][j];
            }
        }
        sx=0;
        sy=7;
        bx=5;
        by=6;
        desx=1;
        desy=1;

    }
    else {
        printf("invalid response\n");
    }
    if((error=lodepng::decode(logo,logoWidth,logoHeight,logoName)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(logo,logoWidth,logoHeight);
    if((error=lodepng::decode(chotaBachha,logoWidthBachha,logoHeightBachha,logonameBachha)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(chotaBachha,logoWidthBachha,logoHeightBachha);
    switch(n) {
        case 3: if((error=lodepng::decode(logo3,logoWidth3,logoHeight3,logoName3)))
        {
        printf("image error\n");
        exit(1);
        }
        else
            invert(logo3,logoWidth3,logoHeight3);
        if((error=lodepng::decode(box3,logoWidthBox3,logoHeightBox3,logoNameBox3)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(box3,logoWidthBox3,logoHeightBox3);

    break;
    case 4: if((error=lodepng::decode(logo4,logoWidth4,logoHeight4,logoName4)))
        {
        printf("image error\n");
        exit(1);
        }
        else
            invert(logo4,logoWidth4,logoHeight4);
         if((error=lodepng::decode(box4,logoWidthBox4,logoHeightBox4,logoNameBox4)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(box4,logoWidthBox4,logoHeightBox4);
        break;
    case 5: if((error=lodepng::decode(logo5,logoWidth5,logoHeight5,logoName5)))
        {
        printf("image error\n");
        exit(1);
        }
        else
            invert(logo5,logoWidth5,logoHeight5);
        if((error=lodepng::decode(box5,logoWidthBox5,logoHeightBox5,logoNameBox5)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(box5,logoWidthBox5,logoHeightBox5);

    break;
    case 6: if((error=lodepng::decode(logo6,logoWidth6,logoHeight6,logoName6)))
        {
        printf("image error\n");
        exit(1);
        }
        else
            invert(logo6,logoWidth6,logoHeight6);
        if((error=lodepng::decode(box6,logoWidthBox6,logoHeightBox6,logoNameBox6)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(box6,logoWidthBox6,logoHeightBox6);
    break;
    case 7: if((error=lodepng::decode(logo7,logoWidth7,logoHeight7,logoName7)))
        {
        printf("image error\n");
        exit(1);
        }
        else
            invert(logo7,logoWidth7,logoHeight7);
        if((error=lodepng::decode(box7,logoWidthBox7,logoHeightBox7,logoNameBox7)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(box7,logoWidthBox7,logoHeightBox7);
    break;
    case 8: if((error=lodepng::decode(logo8,logoWidth8,logoHeight8,logoName8)))
        {
        printf("image error\n");
        exit(1);
        }
        else
            invert(logo8,logoWidth8,logoHeight8);
        if((error=lodepng::decode(box8,logoWidthBox8,logoHeightBox8,logoNameBox8)))
    {
        printf("image error\n");
        exit(1);
    }
    else
        invert(box8,logoWidthBox8,logoHeightBox8);
    default: break;
}


    //printf("%d\n",n);
    //char matrix[n][n];

    //printf("sx=%d sy=%d",sx,sy);




    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("SOKOBAN");

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    init();
    glutDisplayFunc(display);
    //init();
    //fflush(stdin);

    glutSpecialFunc(myKey);
    glutKeyboardFunc(keyfunc);
   /*for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        printf("%c ",duplicate[i][j]); */
    //glFlush();
    glutFullScreen();
    glutMainLoop();
    return 0;

}
