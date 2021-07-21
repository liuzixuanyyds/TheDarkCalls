#include <bits/stdc++.h>
#include <windows.h>
#define Inf 0xffffff
#define up(i,d,u)   for(int i = (d);i <= (u);i++)
#define down(i,u,d) for(int i = (u);i >= (d);i--)
#define wall -1
#define nothing 0
#define d 6
#define u 7
#define l 8
#define r 9
using namespace std;
const int m=11,n=11;
point st,ed;
vector<blocks> myBlocks;
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
};
struct point
{
    int x,y;
};
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