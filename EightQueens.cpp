#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class EightQueens
{
    private:

        char matrix[8][8];

        int queens = 0;

        struct position
        {
            int row;
            int column;
        };

        position positions[64];

        int positionsIndex = 0;

    public:

        int getQueens()
        {
            return queens;
        }

        void initialize()
        {
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    matrix[i][j] = '0';
                }
            }
        }

        void loadPositions()
        {
            for(int row = 0; row < 8; row++)
            {
                for(int col = 0; col < 8; col++)
                {
                    position p;
                    p.row  = row;
                    p.column = col;
                    positions[positionsIndex] = p;
                    positionsIndex++;
                }
            }
        }

        EightQueens()
        {
            queens = 0;
            initialize();
            loadPositions();
        }

        bool hasSpace()
        {
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(matrix[i][j] == '0')
                        return true;
                }
            }

            return false;
        }

        void set()
        {
            bool hasSetted = false;

            while(hasSetted == false && hasSpace())
            {
                srand(time(NULL));

                int p = rand() % positionsIndex;
                int l = positions[p].row;
                int c = positions[p].column;

                for(int _p = p; _p < positionsIndex - 1; _p++)
                {
                    positions[_p] = positions[_p + 1];
                }

                positionsIndex--;

                if(matrix[l][c] == '0')
                {
                    matrix[l][c] = 'X';
                    queens++;

                    int oldL = l;
                    l = 0;

                    while(l < 8)
                    {
                        if(l != oldL)
                            matrix[l][c] = '1';
                        l++;
                    }

                    int oldC = c;
                    c = 0;
                    l = oldL;

                    while(c < 8)
                    {
                        if(c != oldC)
                            matrix[l][c] = '1';
                        c++;
                    }

                    c = oldC;

                    while(l >= 0 && c < 8)
                    {
                        if(l != oldL)
                            matrix[l][c] = '1';
                        l--; c++;
                    }

                    l = oldL;
                    c = oldC;

                    while(c >= 0 && l < 8)
                    {
                        if(l != oldL)
                            matrix[l][c] = '1';
                        c--; l++;
                    }

                    l = oldL;
                    c = oldC;

                    while(c >= 0 && l >= 0)
                    {
                        if(l != oldL)
                            matrix[l][c] = '1';
                        l--; c--;
                    }

                    l = oldL;
                    c = oldC;

                    while(l < 8 && c < 8)
                    {
                        if(l != oldL)
                            matrix[l][c] = '1';
                        l++; c++;
                    }

                    hasSetted = true;
                }
            }
        }

        bool verify()
        {
            return queens == 8;
        }

        void show()
        {
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

};

int main(int argc, char* argv[])
{
    EightQueens* eightQueens = new EightQueens();

    while(eightQueens->verify() == false)
    {

        if(eightQueens->hasSpace() == false)
        {
            eightQueens = new EightQueens();
        }

        eightQueens->set();

    }

    eightQueens->show();

}







