#include "CrcyHead.h"
//*Var*

//*Var*
int main()
{
    inIt();
    srand((unsigned)time(NULL));
    findBlock();
    while(myBlocks.size())
    {
        int blockSize = myBlocks.size();
        int randnum = rand() % blockSize;
        blocks selectBlock = myBlocks[randnum];
        mx = selectBlock.row;
        my = selectBlock.col;
        switch (selectBlock.dire)
        {
        case d:{
            mx++;
            break;}
        case r:{
            my++;
            break;}
        case l:{
            my--;
            break;}
        case u:{
            mx--;
            break;}
        default:
            break;
        }
        if(g[mx][my] == wall){
            g[selectBlock.row][selectBlock.col] = g[mx][my] = nothing;
            findBlock();
        }
        myBlocks.erase(myBlocks.begin()+randnum);
    }
    up(i,0,m+1){
        up(j,0,n+1){
            if(i==st.x && j==st.y)
                printf("%c%c",0xa7,0xb0);
            else if(g[i][j] == nothing)
                printf("  ");
            else    printf("%c%c",0xa8,0x80);
        }
        printf("\n");
    }
    return 0;
}