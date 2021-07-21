#include "CrcyHead.h"
const int m=11,n=11;
int mx=1,my=1;
int g[101][101];
struct blocks
{
    int row,col,dire;
    blocks(int _row,int _col,int _dire)
    {
        row = _row;
        col = _col;
        dire = _dire;
    }
};vector<blocks> myBlocks;
struct point
{
    int x,y;
}st,ed;
void inIt()
{
    memset(g,wall,sizeof(g));
    g[1][1] = nothing;
    st.x = st.y = 1;
}
void findBlock()
{
    if(mx+1 <= m && g[mx+1][my] == wall)
        myBlocks.push_back(blocks(mx+1,my,d));
    if(my+1 <= n && g[mx][my+1] == wall)
        myBlocks.push_back(blocks(mx,my+1,r));
    if(mx-1 <= m && g[mx-1][my] == wall)
        myBlocks.push_back(blocks(mx-1,my,d));
    if(my-1 <= n && g[mx][my-1] == wall)
        myBlocks.push_back(blocks(mx,my-1,l));
}

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
    getchar();getchar();
    return 0;
}