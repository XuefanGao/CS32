bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    // Mark the start location as visted.
    maze[sr][sc] = 'v';
    // For each of the four directions,
    if ((sr + 1 <= nRows - 1) && maze[sr + 1][sc] == '.') {
        pathExists(maze, nRows, nCols, sr + 1, sc, er, ec);
    }
    if ((sr - 1 >= 0) && maze[sr - 1][sc] == '.') {
        pathExists(maze, nRows, nCols, sr - 1, sc, er, ec);
    }
    if ((sc + 1 <= nCols - 1) && maze[sr][sc + 1] == '.') {
        pathExists(maze, nRows, nCols, sr, sc + 1, er, ec);
    }
    if ((sc - 1 >= 0) && maze[sr][sc - 1] == '.') {
        pathExists(maze, nRows, nCols, sr, sc - 1, er, ec);
    }
    if (maze[er][ec] == 'v') {
        return true;
    }
    return false;

}