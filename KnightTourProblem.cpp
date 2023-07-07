/// Problem Statement:

/*
Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each
square exactly once. Print the order of each cell in which they are visited.
*/

/// Backtracking Solution

#include<bits/stdc++.h>
using namespace std;

#define n 8

int delrow[8]={1,2,-1,2,1,-2,-1,-2};
int delcol[8]={2,1,2,-1,2,1,-2,-1};

int solveKnightTour(int i, int j, int steps, vector<vector<int>> &sol){
    if(steps==n*n) return 1;
    for(int k=0;k<8;k++){
        int nrow=i+delrow[k];
        int ncol=j+delcol[k];
        if(nrow>=0 and ncol>=0 and nrow<n and ncol<n and sol[nrow][ncol]==-1){
            sol[nrow][ncol]=steps;
            if(solveKnightTour(nrow,ncol,steps+1,sol)==1) return 1;
            else sol[nrow][ncol]=-1;
        }
    }
return 0;
}

int main(){

    vector<vector<int>> sol(n,vector<int>(n,-1));
    sol[0][0]=0;
    if(solveKnightTour(0,0,1,sol)==0){
        cout<<"Solution Doesn't exist"<<endl;
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" "<<setw(2)<<sol[i][j]<<" ";
            }
        cout<<endl;
        }
    }

    return 0;
}


/// Warnsdorff’s algorithm for Knight’s tour problem

// C++ program to for Knight's tour problem using
// Warnsdorff's algorithm
#include <bits/stdc++.h>
#define N 8

// Move pattern on basis of the change of
// x coordinates and y coordinates respectively
static int cx[N] = {1,1,2,2,-1,-1,-2,-2};
static int cy[N] = {2,-2,1,-1,2,-2,1,-1};

// function restricts the knight to remain within
// the 8x8 chessboard
bool limits(int x, int y)
{
	return ((x >= 0 && y >= 0) && (x < N && y < N));
}

/* Checks whether a square is valid and empty or not */
bool isempty(int a[], int x, int y)
{
	return (limits(x, y)) && (a[y*N+x] < 0);
}

/* Returns the number of empty squares adjacent
to (x, y) */
int getDegree(int a[], int x, int y)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
		if (isempty(a, (x + cx[i]), (y + cy[i])))
			count++;

	return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
bool nextMove(int a[], int *x, int *y)
{
	int min_deg_idx = -1, c, min_deg = (N+1), nx, ny;

	// Try all N adjacent of (*x, *y) starting
	// from a random adjacent. Find the adjacent
	// with minimum degree.
	int start = rand()%N;
	for (int count = 0; count < N; ++count)
	{
		int i = (start + count)%N;
		nx = *x + cx[i];
		ny = *y + cy[i];
		if ((isempty(a, nx, ny)) &&
		(c = getDegree(a, nx, ny)) < min_deg)
		{
			min_deg_idx = i;
			min_deg = c;
		}
	}

	// IF we could not find a next cell
	if (min_deg_idx == -1)
		return false;

	// Store coordinates of next point
	nx = *x + cx[min_deg_idx];
	ny = *y + cy[min_deg_idx];

	// Mark next move
	a[ny*N + nx] = a[(*y)*N + (*x)]+1;

	// Update next point
	*x = nx;
	*y = ny;

	return true;
}

/* displays the chessboard with all the
legal knight's moves */
void print(int a[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d\t",a[j*N+i]);
		printf("\n");
	}
}

/* checks its neighbouring squares */
/* If the knight ends on a square that is one
knight's move from the beginning square,
then tour is closed */
bool neighbour(int x, int y, int xx, int yy)
{
	for (int i = 0; i < N; ++i)
		if (((x+cx[i]) == xx)&&((y + cy[i]) == yy))
			return true;

	return false;
}

/* Generates the legal moves using warnsdorff's
heuristics. Returns false if not possible */
bool findClosedTour()
{
	// Filling up the chessboard matrix with -1's
	int a[N*N];
	for (int i = 0; i< N*N; ++i)
		a[i] = -1;

	// Random initial position
	int sx = rand()%N;
	int sy = rand()%N;

	// Current points are same as initial points
	int x = sx, y = sy;
	a[y*N+x] = 1; // Mark first move.

	// Keep picking next points using
	// Warnsdorff's heuristic
	for (int i = 0; i < N*N-1; ++i)
		if (nextMove(a, &x, &y) == 0)
			return false;

	// Check if tour is closed (Can end
	// at starting point)
	if (!neighbour(x, y, sx, sy))
		return false;

	print(a);
	return true;
}

// Driver code
int main()
{
	// To make sure that different random
	// initial positions are picked.
	srand(time(NULL));

	// While we don't get a solution
	while (!findClosedTour())
	{
	;
	}

	return 0;
}

