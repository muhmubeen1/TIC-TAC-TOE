#include <iostream>
#include <cstdlib>
#include <ctime>

const int BOARD_SIZE = 3;
const int NUM_BOARDS = 9;

class TicTacToe {
private:
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;

public:
    TicTacToe() {
        initializeBoard();
        currentPlayer = 'X';
    }

    void initializeBoard() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() {
        std::cout << "   1   2   3\n";
        for (int i = 0; i < BOARD_SIZE; i++) {
            std::cout << i + 1 << "  ";
            for (int j = 0; j < BOARD_SIZE; j++) {
                std::cout << board[i][j];
                if (j < BOARD_SIZE - 1) {
                    std::cout << " | ";
                }
            }
            std::cout << "\n";
            if (i < BOARD_SIZE - 1) {
                std::cout << "  ---|---|---\n";
            }
        }
        std::cout << "\n";
    }

    bool checkWin() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void getXMove() {
        int row, col;
        do {
            row = std::rand() % BOARD_SIZE;
            col = std::rand() % BOARD_SIZE;
        } while (board[row][col] != ' ');
        board[row][col] = 'X';
    }

    void getOMove() {
        int row, col;
        do {
            std::cout << "Player O, enter your move (row and column): ";
            std::cin >> row >> col;
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                std::cout << "Invalid move. Try again.\n";
            }
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');
        board[row - 1][col - 1] = 'O';
    }

    void play() {
        while (true) {
            displayBoard();
            if (currentPlayer == 'X') {
                getXMove();
            } else {
                getOMove();
            }

            if (checkWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                break;
            } else if (isBoardFull()) {
                displayBoard();
                std::cout << "It's a tie! The game is over.\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};

class NBTicTacToe1 {
private:
    TicTacToe boards[NUM_BOARDS];

public:
    void displayBoards() {
        for (int i = 0; i < NUM_BOARDS; i++) {
            std::cout << "Board " << i + 1 << ":\n";
            boards[i].displayBoard();
        }
    }

    void playSelectedBoard(int selectedBoard) {
        if (selectedBoard >= 1 && selectedBoard <= NUM_BOARDS) {
            boards[selectedBoard - 1].play();
        } else {
            std::cout << "Invalid board selection. Please choose a board between 1 and 9.\n";
        }
    }

    void play() {
        displayBoards();
        int selectedBoard;
        do {
            std::cout << "Select a board to play (1-9): ";
            std::cin >> selectedBoard;
            if (selectedBoard >= 1 && selectedBoard <= NUM_BOARDS) {
                playSelectedBoard(selectedBoard);
            } else {
                std::cout << "Invalid board selection. Please choose a board between 1 and 9.\n";
            }
        } while (true);
    }
};

int main() {
    NBTicTacToe1 game;
    game.play();

    return 0;
}
