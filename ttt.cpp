#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstdio>
#include<ctime>

using namespace std;

// Check to see if the spot is open with current board and user space
// return false for taken and true for open

bool openSpace(vector<char> &board, int userInput){

	if(board.at(userInput-1) != '-'){
		return false;
	}
	else{
		return true;
	}
}


//Function prints the instructions and a table that shows what number corresponds with each location
void printInstructions()
{
	printf("Please enter the number where you would like to place your O.\n");
	printf("1 2 3\n4 5 6\n7 8 9\n");
	printf("Please input F if you would like to go first and S if you would like to go second.\n");
}

//Prints the table that shows what inputs are taken and what are empty after each input
void printTable(vector<char> &table)
{
	int count = 0;
	for(int i = 0; i < 3; i++)
	{   
		for(int j = 0; j < 3; j++)
		{
			printf("%c ",table.at(count));
			count++;
		}
		printf("\n");
	}
}

//this function takes the table and a bool changed to play defensively. For example if there are two O's beside each other
//the fuction puts an X to block it. The Bool checks to see if an X is placed so that the offence function knows not to execute.
//Each if statement is for each three in a row you can get.
void defence(vector<char> &table, bool &changed)
{
	int k = 0;
	if((table[0] == 'O' && (table[1] == 'O' || table[2] == 'O')) || (table[2] == 'O' && (table[0] == 'O' || table[1] == 'O')))
	{
		for(int i = 0; i < 3; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[3] == 'O' && (table[4] == 'O' || table[5] == 'O')) || (table[5] == 'O' && (table[4] == 'O' || table[3] == 'O')))
	{
		for(int i = 4; i < 6; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}

	if((table[6] == 'O' && (table[7] == 'O' || table[8] == 'O')) || (table[8] == 'O' && (table[6] == 'O' || table[7] == 'O')))
	{
		for(int i = 6; i < 9; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'O' && (table[3] == 'O' || table[6] == 'O')) || (table[6] == 'O' && (table[0] == 'O' || table[3] == 'O')))
	{
		for(int i = 0; i < 7; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[1] == 'O' && (table[4] == 'O' || table[7] == 'O')) || (table[7] == 'O' && (table[1] == 'O' || table[4] == 'O')))
	{
		for(int i = 1; i < 8; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[2] == 'O' && (table[5] == 'O' || table[8] == 'O')) || (table[8] == 'O' && (table[5] == 'O' || table[2] == 'O')))
	{
		for(int i = 2; i < 9; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'O' && (table[4] == 'O' || table[8] == 'O')) || (table[8] == 'O' && (table[4] == 'O' || table[0] == 'O')))
	{
		for(int i = 0; i < 9; i += 4)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
		if(table[0] == 'O' && table[8] == 'O' && table[4] == 'X' && changed == false)
		{
			for(int i = 1; i < 8; i += 2)
			{
				if(k == 0 && table[i] == '-')
				{
					changed = true;
					table[i] = 'X';
					k = 1;
				}
			}
		}
	}
	if((table[2] == 'O' && (table[4] == 'O' || table[6] == 'O')) || (table[6] == 'O' && (table[2] == 'O' || table[4] == 'O')))
	{
		for(int i = 2; i < 7; i += 2)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
		if(table[2] == 'O' && table[6] == 'O' && table[4] == 'X' && changed == false)
		{
			for(int i = 1; i < 8; i += 2)
			{
				if(k == 0 && table[i] == '-')
				{
					table[i] = 'X';
					changed = true;
					k = 1;
				}
			}
		}
	}
}

//If defence is not needed offence places an X beside another X

void offence(vector<char> &table, bool &changed)
{

	if((table[0] == 'X' && (table[1] == 'X' || table[2] == 'X')) || (table[2] == 'X' && (table[0] == 'X' || table[1] == 'X')))
	{
		for(int i = 0; i < 3; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[3] == 'X' && (table[4] == 'X' || table[5] == 'X')) || (table[5] == 'X' && (table[4] == 'X' || table[3] == 'X')))
	{
		for(int i = 4; i < 6; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}

	if((table[6] == 'X' && (table[7] == 'X' || table[8] == 'X')) || (table[8] == 'X' && (table[6] == 'X' || table[7] == 'X')))
	{
		for(int i = 6; i < 9; i++)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'X' && (table[3] == 'X' || table[6] == 'X')) || (table[6] == 'X' && (table[0] == 'X' || table[3] == 'X')))
	{
		for(int i = 0; i < 7; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}

	if((table[1] == 'X' && (table[4] == 'X' || table[7] == 'X')) || (table[7] == 'X' && (table[1] == 'X' || table[4] == 'X')))
	{
		for(int i = 1; i < 8; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[2] == 'X' && (table[5] == 'X' || table[8] == 'X')) || (table[8] == 'X' && (table[5] == 'X' || table[2] == 'X')))
	{
		for(int i = 2; i < 9; i += 3)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[0] == 'X' && (table[4] == 'X' || table[8] == 'X')) || (table[8] == 'X' && (table[4] == 'X' || table[0] == 'X')))
	{
		for(int i = 0; i < 9; i += 4)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}
	if((table[2] == 'X' && (table[4] == 'X' || table[6] == 'X')) || (table[6] == 'X' && (table[2] == 'X' || table[4] == 'X')))
	{
		for(int i = 2; i < 7; i += 2)
		{
			if(table[i] == '-')
			{
				table[i] = 'X';
				changed = true;
			}
		}
	}


}

bool playOffence(vector<char> &table, bool &checked)
{
	offence(table, checked);
	if(checked == true)
	{
		return true;
	}
	return false;
}


void YourTurn(int &input, vector<char> &table)
{
	printf("Your Turn\n");
	cin >> input;
	while(openSpace(table, input) == false){
		printf("Please choose an open space!\n");
		printf("Your Turn\n");
		cin >> input;
	}
	table.at(input - 1) = 'O';
	printTable(table);
}

bool Result(vector<char> &table)
{
	for(int i = 0; i < 9; i++)
	{
		if(table[i] == '-')
		{
			return false;
		}
	}
	return true;
}
string Result2(vector<char> &table)
{
	return "Tie";
}
int main()
{
	char ForS;
	int input;
	bool Win = false;
	bool changed = false;
	bool result = false;
	string playAgain = "";
	string playAgain2 = "yes";
	vector<char> table;
//	for(int i = 0; i < 11; i++)
//	{
do{
	playAgain = "no";
	ForS = 'a';
		while(ForS != 'F' && ForS != 'S')
		{
			printInstructions();
			cin >> ForS;
		}
		if(ForS == 'F')
		{
			printf("Please enter the number where you would like to place your O.\n");
		}
		table.resize(0);
		table.resize(9,'-');
		if(ForS == 'F')
		{
			printTable(table);
			YourTurn(input, table);
		}
		printf("Computer input\n");
		if(table.at(4) == '-'){
			table.at(4) = 'X';
		}
		else if(table.at(4) != '-'){
			srand(time(0));
			table.at(rand()%3) = 'X';
		}
		printTable(table);
		printf("Please enter the number where you would like to place your O.\n");

		while(result == false)
		{
			YourTurn(input, table);
			changed = false;
			if(playOffence(table, changed) == false)
			{
				defence(table, changed);
			}
			else
			{
				Win = true;
				printTable(table);
				printf("Game Over! Result: Computer Wins :(\n");
//				printf("Game Over! Result: %s\n", Result2(table).c_str());
            	printf("Play again??? or nah? \n yes or no\n");
            	cin >> playAgain;
				break;
			}
			if(changed == false)
			{
				offence(table, changed);
			}

			if(changed == false)
			{
				for(int i = 0; i < 9; i++)
				{
					if(table.at(i) == '-')
					{
						table.at(i) = 'X';
						i = 10;
					}
				}
			}


			printf("Computer input\n");
			printTable(table);
			result = Result(table);
		}
		if(result == true)
		{
			printf("Game Over! Result: %s\n", Result2(table).c_str());
			printf("Would you like to play again\n yes or no\n");
			cin >> playAgain;

		}
	}while(playAgain == "yes");

	return 0;
}                     
