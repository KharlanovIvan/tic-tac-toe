#include <iostream>
#include <cmath>

bool checkInput(std::string str) {
    if (str.length() != 3) return false;
    for (int i = 0; i < 3; i++) {
        if (str[i] != 'X' && str[i] != '0' && str[i] != '.') return false;
    }
    return true;
}

int counter (std::string row0, std::string row1, std::string row2, char a) {
    int charA = 0;
    std::string row = row0 + row1 + row2;
    for (int i = 0; i < 10; i++) {
        if (row[i] == a) charA++;
    }
    return charA;
}

char cell (std::string str0, std::string str1,std::string str2, int x, int y) {
    if  (y == 0) return str0[x];
    else if  (y == 1) return str1[x];
    else if  (y == 2) return str2[x];

    return 'N';
}

char winner (std::string row0, std::string row1, std::string row2){
    int numWin = 0;
    std::string row, col, diag;
    char charWinner = 'N';

    for (int i = 0; i < 3; i++) {
        row = "";
        col = "";
        diag = "";
        for (int n = 0; n < 3; n++) {
            row += cell(row0, row1, row2, n, i);
            col += cell(row0, row1, row2, i, n);
            if  (i % 2 == 0) diag += cell(row0, row1, row2, abs(i - n), n);
        }
        if (col == "XXX" || col == "000") {
            numWin++;
            charWinner = col[0];
        } else if (row == "XXX" || row == "000") {
            numWin++;
            charWinner = row[0];
        } else if (diag == "XXX" || diag == "000") {
            numWin++;
            charWinner = diag[0];
        }
    }

    if (numWin == 1) return charWinner;

    return 'N';
}

int main() {
    std::cout << "Enter 3 rows of the tic-tac-toe game table with the symbols "
                 "\"O\", \"X\" or \".\", if the cell is empty: \n";
    std::string row0, row1, row2;
    std::cin >> row0 >> row1 >> row2;

    while (!(checkInput(row0) && checkInput(row1) && checkInput(row2))) {
        std::cout << "Invalid input! Try again: \n";
        std::cin >> row0 >> row1 >> row2;
    }

    char winnersName = winner (row0, row1, row2);

    if ((winnersName == '0' && counter(row0, row1, row2, 'X') > counter(row0, row1, row2, '0'))
      || (winnersName == 'X' && counter(row0, row1, row2, '0') >= counter(row0, row1, row2, 'X'))
      || (counter(row0, row1, row2, '0') >= counter(row0, row1, row2, 'X')) && winnersName != 'N')
    std::cout << "Incorrect.\n";
    else winnersName == 'N' ? std::cout << "Nobody.\n" :
      (winnersName == 'X' ? std::cout << "Petya won.\n" : std::cout << "Vanya won.\n");

    return 0;
}
