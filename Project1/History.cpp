#include "History.h"
#include "Mesa.h"

History::History(int nRows, int nCols) {
	m_row = nRows;
	m_col = nCols;
	// initialize map
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			map[i][j] = '.';
		}
	}
}
bool History::record(int r, int c) {
    if (r <= 0 || r > m_row || c <= 0 || c > m_col) { // if out of boundary
        return 0;//return false
    }
    else {
        char& gridChar = map[r - 1][c - 1];
        switch (gridChar)
        {
        case '.':  gridChar = 'A'; break;
        case 'Z':  break;
        default:   gridChar++; break;//cases B~Z
        }
        return 1;//return true
    }
}
void History::display() const {
    clearScreen();
    for (int r = 0; r < m_row; r++)
    {
        for (int c = 0; c < m_col; c++)
            cout << map[r][c];
        cout << endl;
    }
    cout << endl;
}