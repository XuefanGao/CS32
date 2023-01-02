#include "globals.h"
#ifndef History_h
#define History_h
class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;

private:
	int m_row;
	int m_col;
	char map[MAXROWS][MAXCOLS];
};
#endif
