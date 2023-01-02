#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    queue<Coord> s;
    // Push (sr,sc) onto the coordinate stack and update maze[sr][sc] to 'v' to indicate visited it).
    s.push(Coord(sr, sc));
    maze[sr][sc] = 'v';

    // While the stack is not empty,
    while (!s.empty()) {
        // Pop the top coordinate off the stack. This gives you the current (r,c) location that your algorithm is exploring.
        // 
        Coord t = s.front();
        int r = t.r();
        int c = t.c();
        s.pop();
        //cout << r << "   " << c << endl;
        // If the current (r,c) coordinate is equal to the ending coordinate, then we've solved the maze so return true!
        if (r == er && c == ec) {
            return true;
        }

        if (0 <= c - 1 && maze[r][c - 1] == '.') {

            s.push(Coord(r, c - 1));
            maze[r][c - 1] = 'v';
        }
        if (r + 1 < nRows && maze[r + 1][c] == '.') {

            s.push(Coord(r + 1, c));
            maze[r + 1][c] = 'v';
        }
        if (c + 1 < nCols && maze[r][c + 1] == '.') {

            s.push(Coord(r, c + 1));
            maze[r][c + 1] = 'v';
        }
        if (0 <= r - 1 && maze[r - 1][c] == '.') {

            s.push(Coord(r - 1, c));
            maze[r - 1][c] = 'v';
        }
    }
    //There was no solution, so return false
    return false;
}