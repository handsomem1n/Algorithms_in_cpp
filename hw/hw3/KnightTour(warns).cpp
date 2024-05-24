/*
특정한 크기의 체스판에서, 기사가 주어진 위치의 셀에서 출발하여 체스판의 모든 셀을 오직 한
번만 방문하면서, 모든 셀을 모두 방문하는 경로를 계산하는 프로그램을 작성하시오.

한 개의 테스트 케이스에 해당하는 네 개의 정수 m n s t가 입력된다. 첫 번째 정수 𝑚은 체스판의 행의 개수를 나타내고, 두 번째 정수 𝑛은 열의
개수를 나타낸다. 또한 두 정수 s ,t 는 각각 기사가 처음 출발한 셀의 위치를 나타내는 행과 열의 번호를 나타낸다
*/

#include <iostream>
#include <string>
#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

using namespace std;
void mark(int m, int n);
typedef struct Point {int x,y;} point;
point direction[8] = {{-2,1},{-2,-1},{-1,2},{-1,-2}, {1,-2},{1,2},{2,-1},{2,1}};
int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knightTour(int m,int n, point pos,int count);
void mark(int m, int n);

int main(void)
{
    int cases;
    cin >> cases;
    for(int k=0;k<cases;k++)
    {
        int i,j;
        point start;
        int m = 0;
        int n = 0;
        start.y=0;
        start.x=0;
        cin >> m >> n >> start.y >> start.x;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                board[i][j] = UNMARK;
            }
        }
        board[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;
        if(knightTour(m,n,start,1))
        {
            cout << 1 << endl;
            mark(m,n);
        }
        else
            cout << 0 << endl;
    }
}


int knightTour(int m,int n, point pos,int count)
{
    int i;
    point next;

    if(count == m*n) return 1;
    for(i=0;i<8;i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if(next.x>0 && next.x<=n && next.y>0 && next.y<=m && board[next.y][next.x] != MARK)
        {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = count + 1;

            if(knightTour(m,n,next,count+1)) return 1;

            board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}
void mark(int m, int n)
{
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    return;
}