//X O
//i contriputed in this project " Omar Ahmed Ahmed "
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;


void display_board();
void player_turn();
bool gameover();
void play();
void check_r();
void check_c();
char turn;
bool draw = false;
char board[4][4] = { { '1','2','3','4' },{ '5','6','7','8' },{ '9','A','B','C' },{ 'D','E','F','G' } };
int r0 = 0, r1 = 0, r2 = 0, r3 = 0, c0 = 0, c1 = 0, c2 = 0, c3 = 0, d1 = 0, d2 = 0, r00 = 0, r11 = 0, r22 = 0, r33 = 0, c00 = 0, c11 = 0, c22 = 0, c33 = 0, d11 = 0, d22 = 0;
int row = 0, column = 0;
void check_r();
void check_c();
void check_d1();
void check_d2();
void check_rr();
void check_cc();
void check_d11();
void check_d22();
int h;

int main()
{
	cout << "Tic Tac Toe Game\n";
	cout << "Player 1 [X] --- Player 2 [O]\n";
	turn = 'X';

	while (!gameover())
	{
		display_board();
		player_turn();
		gameover();
	}

	if (turn == 'O' && !draw)
	{
		display_board();
		cout << endl << endl << "Player 1 [X] Wins! Game Over!\n";
	}
	else if (turn == 'X' && !draw)
	{
		display_board();
		cout << endl << endl << "Player 2 [O] Wins! Game Over!\n";
	}
	else
	{
		display_board();
		cout << endl << endl << "It's a draw! Game Over!\n";
	}
}

void display_board()
{
	//    Sleep(3000);
	cout << "-------------------------------" << endl << endl;
	cout << "     |     |     |" << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << endl;
	cout << "_____|_____|_____|_____" << endl;
	cout << "     |     |     |     " << endl;
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << endl;
	cout << "_____|_____|_____|_____" << endl;
	cout << "     |     |     |     " << endl;
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << endl;
	cout << "_____|_____|_____|_____" << endl;
	cout << "     |     |     |     " << endl;
	cout << "  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << endl;
	cout << "     |     |     |" << endl;
	cout << endl;
	cout << endl;


}

void player_turn()
{
	char choice;


	if (turn == 'X')
	{
		cout << "Player 1 turn [X]: ";
		cin >> choice;

		switch (choice)
		{
		case '1': row = 0; column = 0; break;
		case '2': row = 0; column = 1; break;
		case '3': row = 0; column = 2; break;
		case '4': row = 0; column = 3; break;

		case '5': row = 1; column = 0; break;
		case '6': row = 1; column = 1; break;
		case '7': row = 1; column = 2; break;
		case '8': row = 1; column = 3; break;

		case '9': row = 2; column = 0; break;
		case 'A': row = 2; column = 1; break;
		case 'B': row = 2; column = 2; break;
		case 'C': row = 2; column = 3; break;

		case 'D': row = 3; column = 0; break;
		case 'E': row = 3; column = 1; break;
		case 'F': row = 3; column = 2; break;
		case 'G': row = 3; column = 3; break;
		default:
			cout << "You didn't enter a correct number! Try again\n";
			player_turn();
		}

		if (board[row][column] != 'X' && board[row][column] != 'O')
		{
			board[row][column] = 'X';
			turn = 'O';
		}
		else
		{
			cout << "The cell you chose is used! Try again\n";
			player_turn();
		}
	}

	else if (turn == 'O') {


		srand(time(NULL));
		cout << "Player 2 turn [O]: ";

		play();

	}
}

bool gameover()
{
	for (int i = 0; i < 4; i++)//Check for a win
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i])


			|| (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) || (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]))
		{
			return true;
		}
	}

	for (int i = 0; i < 4; i++)//Check for draw
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				return false;
			}
		}
	}
	draw = true;
	return true;
}

void check_r()
{
	r0 = 0;
	for (int c = 0; c < 4; c++)
	{
		if (board[0][c] == 'O')
		{
			r0++;
			//   r00=r0;
		}
	}
	// cout << "r0 = " << r0 << endl;

	r1 = 0;
	for (int c = 0; c < 4; c++)
	{
		if (board[1][c] == 'O')
		{
			r1++;
			//         r11=r1;
		}
	}
	// cout << "r1 = " << r1 << endl;

	r2 = 0;
	for (int c = 0; c < 4; c++)
	{
		if (board[2][c] == 'O')
		{
			r2++;
			//      r22=r2;
		}
	}
	// cout << "r2 = " << r2 << endl;

	r3 = 0;
	for (int c = 0; c < 4; c++)
	{
		if (board[3][c] == 'O')
		{
			r3++;
			//    r33=r3;
		}
	}
	//cout << "r3 = " << r3 << endl;

}


void check_c()
{
	c0 = 0;
	for (int r = 0; r < 4; r++)
	{
		if (board[r][0] == 'O')
		{
			c0++;
			//  c00=c0;
		}
	}
	// cout << "c0 = " << c0 << endl;

	c1 = 0;
	for (int r = 0; r < 4; r++)
	{
		if (board[r][1] == 'O') {

			c1++;
			// c11=c1;
		}
	}
	// cout << "c1 = " << c1 << endl;

	c2 = 0;
	for (int r = 0; r < 4; r++)
	{

		if (board[r][2] == 'O') {
			c2++;
			// c22=c2;
		}
	}
	//cout << "c2 = " << c2 << endl;

	c3 = 0;
	for (int r = 0; r < 4; r++)
	{

		if (board[r][3] == 'O') {
			c3++;
			// c33=c3;
		}
	}
	// cout << "c3 = " << c3 << endl;
}

void check_d1()
{
	d1 = 0;
	for (int r = 0, c = 0; r<4, c<4; r++, c++)
	{
		if (board[r][c] == 'O')
		{
			d1++;
			//            d11=d1;
		}
	}
	//    cout << "d1 = " << d11<< endl;
}

void check_d2()
{
	d2 = 0;
	for (int r = 0, c = 3; r<4, c>0; r++, c--)
	{
		if (board[r][c] == 'O')
		{
			d2++;
			//            d22=d2;
		}
	}
	//    cout << "d2 = " << d22<< endl;
}


//-----------------------------------------------------------------------------
void check_rr()
{
	r00 = r0;
	for (int c = 0; c < 4; c++)
	{
		if (board[0][c] == 'X')
		{
			r00--;
		}
	}
	//cout << "r00 = " << r00 << endl;

	r11 = r1;
	for (int c = 0; c < 4; c++)
	{
		if (board[1][c] == 'X')
		{
			r11--;
		}
	}
	//cout << "r11 = " << r11 << endl;

	r22 = r2;
	for (int c = 0; c < 4; c++)
	{
		if (board[2][c] == 'X')
		{
			r22--;
		}
	}
	//cout << "r22 = " << r22 << endl;

	r33 = r3;
	for (int c = 0; c < 4; c++)
	{
		if (board[3][c] == 'X')
		{
			r33--;
		}
	}
	//cout << "r33 = " << r33 << endl;
}


void check_cc()
{
	c00 = c0;
	for (int r = 0; r < 4; r++)
	{
		if (board[r][0] == 'X')
		{
			c00--;
		}
	}
	//cout << "c00 = " << c00 << endl;

	c11 = c1;
	for (int r = 0; r < 4; r++)
	{
		if (board[r][1] == 'X')
		{
			c11--;
		}
	}
	//cout << "c11 = " << c11 << endl;

	c22 = c2;
	for (int r = 0; r < 4; r++)
	{
		if (board[r][2] == 'X')
		{
			c22--;
		}
	}
	//cout << "c22 = " << c22 << endl;

	c33 = c3;
	for (int r = 0; r < 4; r++)
	{
		if (board[r][3] == 'X')
		{
			c33--;
		}
	}
	//cout << "c33 = " << c33 << endl;
}

void check_d11()
{
	d11 = d1;
	for (int r = 0, c = 0; r<4, c<4; r++, c++)
	{

		if (board[r][c] == 'X')
			d11--;
	}
	//cout << "d11 = " << d11 << endl;
}


void check_d22()
{
	d22 = d2;
	for (int r = 0, c = 3; r<4, c>0; r++, c--)
	{
		if (board[r][c] == 'X')
			d22--;
	}
	//cout << "d22 = " << d22 << endl;
}
void play() {
	check_r();
	check_c();
	check_rr();
	check_cc();


	do
	{

		check_d1();
		check_d2();
		check_d11();
		check_d22();
		//********************************
		if (r00 == 3)
		{
			row = 0;
			for (int w = 0; w<4; w++)
			{
				if (board[0][w] != 'O'&&board[0][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//**************************
		else  if (r11 == 3)
		{
			row = 1;
			for (int w = 0; w<4; w++)
			{
				if (board[1][w] != 'O'&&board[1][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//***********************************

		else if (r22 == 3)
		{
			row = 2;
			for (int w = 0; w<4; w++)
			{
				if (board[2][w] != 'O'&&board[2][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}

		//************************************
		else if (r33 == 3)
		{
			row = 3;
			for (int w = 0; w<4; w++)
			{
				if (board[3][w] != 'O'&&board[3][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//********************************
		else if (c00 == 3)
		{
			column = 0;
			for (int w = 0; w<4; w++)
			{
				if (board[w][0] != 'O'&&board[w][0] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//********************************

		else if (c11 == 3)
		{
			column = 1;
			for (int w = 0; w<4; w++)
			{
				if (board[w][1] != 'O'&&board[w][1] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}

		//***********************************
		else if (c22 == 3)
		{
			column = 2;
			for (int w = 0; w<4; w++)
			{
				if (board[w][2] != 'O'&&board[w][2] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//*******************

		else if (c33 == 3)
		{
			column = 3;
			for (int w = 0; w<4; w++)
			{
				if (board[w][3] != 'O'&&board[w][3] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//***************************
		else  if (d11 == 3)

		{

			for (int w = 0, a = 0; w<4, a<4; w++, a++)
			{
				if (board[w][a] != 'O'&&board[w][a] != 'X') {
					row = w;
					column = a;
				}
				else
					continue;
			}
		}

		//***************************************

		else if (d22 == 3)
		{

			for (int w = 0, a = 3; w<4, a>-1; w++, a--)
			{
				if (board[w][a] != 'O'&&board[w][a] != 'X') {
					row = w;
					column = a;
				}
				else
					continue;
			}
		}
		//************************************

		else if (r00 == -3)
		{
			row = 0;
			for (int w = 0; w<4; w++)
			{
				if (board[0][w] != 'O'&&board[0][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}

		//**************************
		else  if (r11 == -3)
		{
			row = 1;
			for (int w = 0; w<4; w++)
			{
				if (board[1][w] != 'O'&&board[1][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//***********************************

		else if (r22 == -3)
		{
			row = 2;
			for (int w = 0; w<4; w++)
			{
				if (board[2][w] != 'O'&&board[2][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}

		//************************************
		else if (r33 == -3)
		{
			row = 3;
			for (int w = 0; w<4; w++)
			{
				if (board[3][w] != 'O'&&board[3][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//********************************
		else if (c00 == -3)
		{
			column = 0;
			for (int w = 0; w<4; w++)
			{
				if (board[w][0] != 'O'&&board[w][0] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//********************************
		else if (c11 == -3)
		{
			column = 1;
			for (int w = 0; w<4; w++)
			{
				if (board[w][1] != 'O'&&board[w][1] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}

		//***********************************
		else if (c22 == -3)
		{
			column = 2;
			for (int w = 0; w<4; w++)
			{
				if (board[w][2] != 'O'&&board[w][2] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//*******************

		else if (c33 == -3)
		{
			column = 3;
			for (int w = 0; w<4; w++)
			{
				if (board[w][3] != 'O'&&board[w][3] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//***************************
		else   if (d11 == -3)
		{
			for (int w = 0, a = 0; w<4, a<4; w++, a++)
			{
				if (board[w][a] != 'O'&&board[w][a] != 'X') {
					row = w;
					column = a;
				}
				else
					continue;
			}
		}
		//***************************************
		else if (d22 == -3)
		{
			for (int w = 0, a = 3; w<4, a>-1; w++, a--)
			{
				if (board[w][a] != 'O'&&board[w][a] != 'X') {
					row = w;
					column = a;
				}
				else
					continue;
			}
		}
		//*****************************
		else if (r00 == 2)
		{
			row = 0;
			for (int w = 0; w<4; w++)
			{
				if (board[0][w] != 'O'&&board[0][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//**************************
		else  if (r11 == 2)
		{
			row = 1;
			for (int w = 0; w<4; w++)
			{
				if (board[1][w] != 'O'&&board[1][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//***********************************
		else if (r22 == 2)
		{
			row = 2;
			for (int w = 0; w<4; w++)
			{
				if (board[2][w] != 'O'&&board[2][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}

		//************************************
		else if (r33 == 2)
		{
			row = 3;
			for (int w = 0; w<4; w++)
			{
				if (board[3][w] != 'O'&&board[3][w] != 'X') {
					column = w;
				}
				else
					continue;
			}
		}
		//********************************
		else if (c00 == 2)
		{
			column = 0;
			for (int w = 0; w<4; w++)
			{
				if (board[w][0] != 'O'&&board[w][0] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//********************************
		else if (c11 == 2)
		{
			column = 1;
			for (int w = 0; w<4; w++)
			{
				if (board[w][1] != 'O'&&board[w][1] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}

		//***********************************
		else if (c22 == 2)
		{
			column = 2;
			for (int w = 0; w<4; w++)
			{
				if (board[w][2] != 'O'&&board[w][2] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//*******************
		else if (c33 == 2)
		{
			column = 3;
			for (int w = 0; w<4; w++)
			{
				if (board[w][3] != 'O'&&board[w][3] != 'X') {
					row = w;
				}
				else
					continue;
			}
		}
		//***************************
		else  if (d11 == 2)
		{

			for (int w = 0, a = 0; w<4, a<4; w++, a++)
			{
				if (board[w][a] != 'O'&&board[w][a] != 'X') {
					row = w;
					column = a;
				}
				else
					continue;
			}
		}
		//***************************************
		else if (d22 == 2)
		{
			for (int w = 0, a = 3; w<4, a>-1; w++, a--)
			{
				if (board[w][a] != 'O'&&board[w][a] != 'X') {
					row = w;
					column = a;
				}
				else
					continue;
			}
		}
		//****************************
		else if (r00>-3 && r00<3)
		{
			row = 0;
			row = rand() % 4;
		}
		//******************************
		else   if (r11>-3 && r11<3)
		{
			row = 1;
			row = rand() % 4;
		}
		//******************************
		else  if (r22>-3 && r22<2)
		{
			row = 2;
			row = rand() % 4;
		}
		//*****************************
		else  if (r33>-3 && r33<2)
		{
			row = 3;
			row = rand() % 4;
		}
		//********************************
		else  if (c00>-3 && c00<2)
		{
			column = 0;
			column = rand() % 4;
		}
		//*******************************
		else  if (c11>-3 && c11<2)
		{
			column = 1;
			column = rand() % 4;
		}
		//**************************
		else  if (c22>-3 && c22<2)
		{
			column = 2;
			column = rand() % 4;
		}
		//*************************
		else  if (c33>-3 && c33<2)
		{
			column = 3;
			column = rand() % 4;
		}
		/*

		else if (r00 == 0 || r11 == 0 || r22 == 0 || r33 == 0 || c00 == 0 || c11 == 0 || c22 == 0 || c33 == 0 || d11 == 0 || d22 == 0)
		{
		row = rand() % 4;
		column = rand() % 4;
		}
		*/

	} while (board[row][column] == 'X' || board[row][column] == 'O');
	if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		if (row == 0 && column == 0) cout << "CPU will play in slot '1'" << endl;
		else if (row == 0 && column == 1) cout << "CPU will play in slot '2'" << endl;
		else if (row == 0 && column == 2) cout << "CPU will play in slot '3'" << endl;
		else if (row == 0 && column == 3) cout << "CPU will play in slot '4'" << endl;

		else if (row == 1 && column == 0) cout << "CPU will play in slot '5'" << endl;
		else if (row == 1 && column == 1) cout << "CPU will play in slot '6'" << endl;
		else if (row == 1 && column == 2) cout << "CPU will play in slot '7'" << endl;
		else if (row == 1 && column == 3) cout << "CPU will play in slot '8'" << endl;

		else if (row == 2 && column == 0) cout << "CPU will play in slot '9'" << endl;
		else if (row == 2 && column == 1) cout << "CPU will play in slot 'A'" << endl;
		else if (row == 2 && column == 2) cout << "CPU will play in slot 'B'" << endl;
		else if (row == 2 && column == 3) cout << "CPU will play in slot 'C'" << endl;

		else if (row == 3 && column == 0) cout << "CPU will play in slot 'D'" << endl;
		else if (row == 3 && column == 1) cout << "CPU will play in slot 'E'" << endl;
		else if (row == 3 && column == 2) cout << "CPU will play in slot 'F'" << endl;
		else if (row == 3 && column == 3) cout << "CPU will play in slot 'G'" << endl;
	}
	// Sleep(3000);
	board[row][column] = 'O';
	turn = 'X';
}


