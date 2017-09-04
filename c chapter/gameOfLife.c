//
// Created by Yair on 31-Aug-17.
//
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20
/// simulate a turn in the game
/// \param board - the game board
void turn(int board[][HEIGHT]);
/// initiate the board with zeros
/// \param board
void init_board(int board[][HEIGHT]);
/// prints the board - 1 is alive 0- is dead
/// \param board
void print_board(int board[][HEIGHT]);
/// load a board startup from a file
/// \param board
/// \param path - path the the txt file represents the board
void load_board_from_file(int board[][HEIGHT], char* path);
///prints the correct usage of the program
void print_usage();
/// check if the cell is legal and exist
/// \param i
/// \param j
/// \param k
/// \param l
/// \return 1 if legal 0 if illegal
int is_legal(int i, int j, int k, int l);
/// sums the surrounding cells of i,j
/// \param board
/// \param i
/// \param j
/// \return the sum of the surrounding cells
int get_srounding_value(int board[][HEIGHT], int i, int j);
///run the game for argv[2] turns
int main(int argc, char* argv[]);

void init_board(int board[][HEIGHT])
{
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[][HEIGHT])
{
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

void load_board_from_file(int board[][HEIGHT], char* path)
{
    int c;
    FILE* f;
    f = fopen(path, "r");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            do{
                c = getc(f);
            }while (c == '\n' || c == '\r');
            {
                board[i][j] = c-48;
            }
        }
    }
    fclose(f);
}

void print_usage()
{
    printf("Correct usage is matzov.exe <board file> <num of turns>\n");
}


int is_legal(int i, int j, int k, int l)
{
    if(i+k < 0 || i+k >= WIDTH)
    {
        return 0;
    }
    if(j+l < 0 || j+l >= HEIGHT)
    {
        return 0;
    }
    return 1;
}

int get_srounding_value(int board[][HEIGHT], int i, int j)
{
    int sum = 0;
    for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
            if(is_legal(i,j,k,l) && (k || l ))
            {
                sum += board[i+k][j+l];
            }
        }
    }
    return sum;
}

void turn(int board[][HEIGHT])
{
    int tmp_board[WIDTH][HEIGHT], count;
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            count = get_srounding_value(board, i, j);
            if (count == 2)
            {
                tmp_board[i][j] = board[i][j];
            }
            else if(count == 3)
            {
                tmp_board[i][j] = 1;
            }
            else
            {
                tmp_board[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            board[i][j] = tmp_board[i][j];
        }
    }
}


int main(int argc, char* argv[])
{
    int board[WIDTH][HEIGHT], numOfTurns;
    if (argc != 3)
    {
        print_usage();
        return (-1);
    }
    numOfTurns = atoi(argv[2]);
    init_board(board);
    load_board_from_file(board, argv[1]);
    print_board(board);
    for (int i = 0; i <= numOfTurns; ++i) {
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%d\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n", i);
        turn(board);
        print_board(board);
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%d\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n", i);
    }

    return 0;
}

