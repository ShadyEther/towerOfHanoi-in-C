/*(C) Reserved __(UwU)__
simple tower of hanoi using C
If code doesnt run properly, it shows error or causes infinite loop then, reRun the code
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int size;
int *towerA,*towerB,*towerC;
int topPos(int* stack)
{
    int i=0;
    while((*(stack+i))>0)
        i+=1;
    return i-1;
}
void displayAll(int* towerA,int* towerB, int* towerC)
{
    for(register int i=size-1;i>=0;--i)
    {
        for(register int j=1;j<=size-(*(towerA+i));j++)
            printf(" ");
        for(register int j=1;j<=(*(towerA+i));j++)
            printf("* ");
        for(register int j=1;j<=size-(*(towerA+i));j++)
            printf(" ");
            printf("\t");
        for(register int j=1;j<=size-(*(towerB+i));j++)
            printf(" ");
        for(register int j=1;j<=(*(towerB+i));j++)
            printf("* ");
        for(register int j=1;j<=size-(*(towerB+i));j++)
            printf(" ");
            printf("\t");
            for(register int j=1;j<=size-(*(towerC+i));j++)
            printf(" ");
        for(register int j=1;j<=(*(towerC+i));j++)
            printf("* ");
        for(register int j=1;j<=size-(*(towerC+i));j++)
            printf(" ");
            printf("\n");

        
    }
}
int pop(int* stack,int topPos)
{
    int item=*(stack+topPos);
    *(stack+topPos)=0;
    return item;
}
void push(int* stack,int topPos,int item)
{
    topPos++;
    *(stack+topPos)=item;    
}
void moveDisk(int diskNum,int* sourceTower,int* tempTower,int* destTower)
{
    if(diskNum)
    {
        moveDisk(diskNum-1,sourceTower,destTower,tempTower);

        int item=pop(sourceTower,topPos(sourceTower));
        push(destTower,topPos(destTower),item);

        system("CLS");
        displayAll(towerA,towerB,towerC);
        Sleep(300);

        moveDisk(diskNum-1,tempTower,sourceTower,destTower);
    }
}
void fillTower(int* stack)
{
    int i=0;
    while(i<size)
    {
        *(stack+i)=size-i;
        i+=1;
    }
}
int main()
{
    printf("Enter a tower size more than 7 only if no work to do...and have loads of time: ");
    scanf("%d",&size);
    towerA=(int*) calloc(size,sizeof(int));
    towerB=(int*) calloc(size,sizeof(int));
    towerC=(int*) calloc(size,sizeof(int));
    fillTower(towerA);
    moveDisk(size,towerA,towerB,towerC);
}