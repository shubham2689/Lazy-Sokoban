/* This header file is exclusively prepared for the graphics project titled "SOKOBAN" and is not meant for any other purpose.
    Credits : 1.Utkarsh Deep(1MV14CS115) 2. Shubham Sinha(1MV14CS101)

*/



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void bfs(int map1[100][100],int target,int box,int n,int path[500],int notReach[100]);
int bfs1(int map1[100][100],int pos,int you,int n);
/*int check(int map1[100][100],int notReach[100],int n,int box) {
	int deep[100][100];
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			deep[i][j]=map1[i][j];
	int var=0;
	while(notReach[var]!=-1) {
		int tem=notReach[var];
		deep[tem][tem+1]=deep[tem][tem-1]=deep[tem][tem-n]=deep[tem][tem+n]=0;
		deep[tem+1][tem]=deep[tem-1][tem]=deep[tem-n][tem]=deep[tem+n][tem]=0;
		var++;
	}
	if(deep[box][box+1]==0&&deep[box][box-1]==0&&deep[box][box-n]==0&&deep[box][box+n]==0) {
		return 0;
	}
	else
		return 1;
}
*/

void sokoban(char matrix[100][100],int n,int bahubali[100]) {

	int notReach[100];

    int map1[100][100];
    int noOfPush=0;
    int totalWalk=0;
    int i,j,k;
    /*for(i=0;i<n;i++){
	for(j=0;j<n;j++)
		printf("%c\t",matrix[i][j]);
	printf("\n");
    }*/
    for(i=0;i<100;i++)
	notReach[i]=-1;
    for(i=0;i<n*n;i++) {
	for(j=0;j<n*n;j++) {
	    map1[i][j]=0;
	}
    }
    int target=0,box=0,you=0,cnt=0;
    for(i=0;i<n;i++) {
	for(j=0;j<n;j++) {
	    char temp=matrix[i][j];
	    if(temp!='X') {
		if(i-1>=0&&matrix[i-1][j]!='X') {
		    map1[cnt][cnt-n]=1;
		    map1[cnt-n][cnt]=1;
		}
		if(j-1>=0&&matrix[i][j-1]!='X') {
		    map1[cnt][cnt-1]=1;
		    map1[cnt-1][cnt]=1;
		}
	    }
	    if(temp=='D') {
		target=cnt;

	    }
	    if(temp=='B')
		box=cnt;
	    if(temp=='S')
		you=cnt;
	    cnt++;
	}
    }
    int pathCompute=1,canPush=1;
    int path[500];
    //int arr[100];
    while(pathCompute==1&&canPush==1) {
    totalWalk=0;
    noOfPush=0;
	int you1=you;
	int box1=box;
	//printf("hello utkarsh\n");
	bfs(map1,target,box,n,path,notReach);
	//printf("hello shubham\n");
	if(path[0]==-1){
		//printf("-1\n");
		noOfPush=0;
		totalWalk=-1;
		break;
	}
	//printf("path0=%d\n",path[0]);
	int localPush=1;
	j=0;
	while(path[j]!=-1)
		j++;
	noOfPush=j-1;
	//printf("no of push=%d\n",noOfPush);
	for(j=1;j<=noOfPush;j++) {
		int difference=path[j]-box1;
		//printf("pathj=%d\tbox1=%d\n",path[j],box1);
		int pos=box1-difference;
	       //	printf("pos=%d\tyou1=%d\n",pos,you1);
		int temp[100][100];
		for(i=0;i<n*n;i++) {
			for(k=0;k<n*n;k++) {
				temp[i][k]=map1[i][k];

			}
		}
	       //	if(box1+1<n*n&&box1-1>=0&&box1-n>=0&&box1+n<n*n) {
			temp[box1][box1+1]=temp[box1][box1-1]=temp[box1][box1-n]=temp[box1][box1+n]=0;
			temp[box1+1][box1]=temp[box1-1][box1]=temp[box1-n][box1]=temp[box1+n][box1]=0;
	       //	}
		localPush=bfs1(temp,pos,you1,n);
		//printf("localPush=%d\n",localPush);
		if(localPush==-1/*&&box1+1<n*n&&box1-1>=0&&box1-n>=0&&box1+n<n*n*/) {
		       //	map1[box1][box1+1]=map1[box1][box1-1]=map1[box1][box1-n]=map1[box1][box1+n]=0;
		       //	map1[box1+1][box1]=map1[box1-1][box1]=map1[box1-n][box1]=map1[box1+n][box1]=0;
			int var=0;
			while(notReach[var]!=-1)
			var++;
			notReach[var]=box1;
			break;
		}
		totalWalk+=localPush;
		you1=box1;
		box1=path[j];
	}
	if(map1[box][box+1]==0&&map1[box][box-1]==0&&map1[box][box-n]==0&&map1[box][box+n]==0/*check(map1,notReach,n,box)*/) {

		//printf("hello beta\n");
		totalWalk=-1;
		break;
	}
	if(box1==target)    {
		//printf("hello beti\n");
		break;
	}

    }

    /*if(noOfPush==0||totalWalk==-1) {
	//printf("push=%d\nwalk=%d\n",noOfPush,totalWalk);
	printf("nOT REACHABLE\n");
    }
    else {
	printf("Push=%d\n Walk= %d\n",noOfPush,totalWalk);
    }*/
    //printf("path: %d\n",path[3]);

   /*for(i=0;i<n*n;i++) {
    for(j=0;j<n*n;j++)
	printf("%d\t",map1[i][j]);
    printf("\n");
    }*/
   // bfs(map1,target,box,n,path);
   bahubali[0]=noOfPush;
   bahubali[1]=totalWalk;
   i=0;
   while(path[i]!=-1) {
        bahubali[i+2]=path[i];
        i++;
   }
}
int bfs1(int map1[100][100],int pos,int you,int n) {

	int q[100];
	int level[100];
	int parent[100];
	int i,j,k;
	for(i=0;i<n*n;i++){
		level[i]=-1;
		parent[i]=-1;
	}
       level[you]=0;
       int front1=0;
       int rear=0;
       q[front1]=you;
       front1++;
       while(front1!=rear) {
		j=q[rear];
		rear++;
		for(k=0;k<n*n;k++) {
			if(map1[j][k]==1) {
				if(level[k]==-1) {
					level[k]=1+level[j];
					q[front1]=k;
					front1++;
					parent[k]=j;
				}
			}
		}
       }
       /*i=pos;
       while(parent[i]!=-1){
        printf("%d\t",i);
        i=parent[i];
       }
       printf("\n");*/
       if(level[pos]==-1)
	return -1;
	else
		return level[pos];

}
void bfs(int map1[100][100],int target,int box,int n,int path[500],int notReach[100]) {
    //printf("box=%d\ttarget=%d",box,target);
   // printf("node=%d\n",map1[1][0]);
   int utk[100][100];

    int q[100];
    int parent[100];
    int i,j,k;
    for(i=0;i<n*n;i++)
	for(j=0;j<n*n;j++)
		utk[i][j]=map1[i][j];

    i=0;
    j=0;
    //int arr[n*n];
    //path[0]=-1;
    int var=0;
    //printf("1\n");
    while(notReach[var]!=-1) {
	int tem=notReach[var];
	utk[tem][tem+1]=utk[tem][tem-1]=utk[tem][tem-n]=utk[tem][tem+n]=0;
	utk[tem+1][tem]=utk[tem-1][tem]=utk[tem-n][tem]=utk[tem+n][tem]=0;
	var++;
    }
    //printf("2\n");
    for(i=0;i<500;i++)
	path[i]=-1;
    int level[100];
    //printf("3\n");
    for(i=0;i<n*n;i++) {
	level[i]=-1;
	parent[i]=-1;
    }
    level[box]=0;
    int front1=0;
    int rear=0;
    q[front1]=box;
    front1++;
    //printf("4\n");
    while(front1!=rear) {
       //	printf("node=%d\t",map1[1][0]);
	j=q[rear];
	//printf("\nj=%d\n",j);
	rear++;
	for(k=0;k<n*n;k++) {
	       //	printf("node=%d\t",map1[1][0]);
	    if(utk[j][k]==1) {
	       //	printf("\nk'=%d\t",k);
		if(level[k]==-1) {
		       //	printf("\nk=%d\n",k);
		    level[k]=1+level[j];
		    parent[k]=j;
		    q[front1]=k;
		    front1++;

		}
	    }
	}
    }
    //printf("5\n");
    if(level[target]==-1) {
       //	printf("HEHE\n");
	return;
    }
    //int achha[level[target]+1];
    path[0]=target;
    i=target;
    j=1;
    //printf("6\n");
    while(parent[i]!=-1) {
	path[j]=parent[i];
	j++;
	i=parent[i];
    }
    i=0;
    //printf("7\n");
    while(path[i]!=-1){

       //	printf("%d\t",path[i++]);
       i++;
    }
    j=0;
    i--;
    for(j=0;j<=i/2;j++) {
	int temp=path[j];
	path[j]=path[i-j];
	path[i-j]=temp;
    }
   /* printf("\n");
    for(j=0;j<=i;j++) {
	printf("%d\t",path[j]);
    }*/

    //printf("8\n");




}
/*int main()
{
	int n;
	char ch[100][100];
    int i,j;
	//clrscr();
	scanf("%d",&n);
	int bahubali[100];
	for(i=0;i<100;i++)
        bahubali[i]=-1;
	for(i=0;i<n+2;i++) {
		fflush(stdin);
		for(j=0;j<n+2;j++) {
			if(i==0||j==0||i==n+1||j==n+1)
				ch[i][j]='X';
			else
				scanf("%c",&ch[i][j]);
		}
	}

	sokoban(ch,n+2,bahubali);
	printf("HEHEpush=%d\nHEHEwalk=%d\n",bahubali[0],bahubali[1]);
	printf("path computed:\n");
	i=2;
	while(bahubali[i]!=-1) {
        printf("%d\t",bahubali[i]);
        i++;
	}
	return 0;
	//getch();
}
*/
