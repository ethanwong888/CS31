#include <iostream>
using namespace std;
#include <string>
#include "grid.h"
#include <cassert>
#include <cctype>
#include <sstream>


const int HORIZ = 0;
const int VERT = 1;

const int FG = 0;
const int BG = 1;

bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg) //sets characters in the grid to form a line segment
{
 
	if (c < 1 || r < 1 || r > 20 || c > 30)  //prevents user from printing outside of the grid
	{
		return false;
	}

	if (isprint(plotChar) == false)
	{
		return false;
	}


	if (fgbg == FG) //code for printing in the foreground
	{
		if (dir == HORIZ) //code for printing horizontally in the grid
		{
			if (distance + c >= 1 && distance + c <= 30 && distance > 0 )
			{
				for (int x = c; x <= distance + c; x = x + 1)
				{
					setChar(r, x, plotChar);
				}

				return true;
			}

			else if (distance + c >= 1 && distance + c <= 30 && distance < 0)
			{

				for (int x = c; x >= distance + c; x = x- 1)
				{
					setChar(r, x, plotChar);
				}

				return true;

			}

			else if (distance == 0) //plots a single character if distance is zero
			{
				setChar(r, c, plotChar);
				return true;

			}

			else
				return false;


		}

		else if ( dir == VERT) //code for printing vertically in the grid
		{
			if (distance + r >= 1 && distance + r <= 20 && distance > 0)
			{
				for (int x = r; x <= distance + r; x = x + 1)
				{
					setChar(x, c, plotChar);

				}
				return true;

			}

			else if (distance + r >= 1 && distance + r <= 20 && distance < 0)
			{
				for (int x = r; x >= distance + r; x = x - 1)
				{

					setChar(x, c, plotChar);

				}
				return true;

			}


			else if (distance == 0) //plots a single character if distance is zero
			{
				setChar(r, c, plotChar);
				return true;

			}

			else
				return false;

		}

		else
		{
			return false;
		}

	}


	else if (fgbg == BG ) //code for printing in the background
	{
		if (dir == HORIZ) //code for printing horizontally
		{
			if ( distance > 0 && distance + c >= 1 && distance + c <= 30)
			{

				for (int x = c; x <= distance + c; x = x + 1 )

				{

					if (getChar(r, x) == ' ')
					{
						setChar(r, x, plotChar);
					}

				}
				return true;

			}
			else if (distance < 0 && distance + c >= 1 && distance + c <= 30)
			{
				for (int x = c; x >= c + distance; x = x - 1)

				{


					if (getChar(r, x) == ' ')
					{
						setChar(r, x, plotChar);
					}



				}
				return true;

			}

			else if (distance == 0) //plots a single character if distance is zero

			{
				if (getChar(r, c) == ' ')
				{
					setChar(r, c, plotChar);
				}
				return true;

			}

			else
				return false;


		}

		else if (dir == VERT ) //code for printing vertically
		{
			if ( distance > 0 && distance + r >= 1 && distance + r <= 20)
			{
				for (int x = r; x <= distance + r; x ++ )
				{

					if (getChar(x, c) == ' ')
					{
						setChar(x, c, plotChar);
					}

				}
				return true;

			}
			else if ( distance < 0 && distance + r >= 1 && distance + r <= 20)
			{
				for (int x = r; x >= distance + r; x -- )
				{

					if (getChar(x, c) == ' ')
					{
						setChar(x, c, plotChar);
					}

				}
				return true;

			}

			else if (distance == 0) //plots a single character if distance is zero

			{
				if (getChar(r, c) == ' ')
				{
					setChar(r, c, plotChar);
				}

				return true;

			}

			else
				return false;
		}

		else
		{
			return false;
		}
	}

	return false;
}




int performCommands(string commandString, char& plotChar, int& mode, int& badPos) //performs the indicated plotting commands by calling the plotLine function
{
	if (commandString == "")
	{
		return 0;
	}

	int row = 1;
	int column = 1;
	int s = 0;



	while (s < commandString.size())
	{

		if (tolower(commandString[s]) == 'h') //user wants to print characters horizontally
		{

			if (commandString[s + 1] == '-') 
			{
				if (isdigit(commandString[s + 2])) //checks if the inputted characters are digits
				{
					if (isdigit(commandString[s + 3])) //checks if the inputted characters are digits
					{


						if (plotLine(row, column, (-10 * (commandString[s + 2] - '0')) - (commandString[s + 3] - '0'), HORIZ, plotChar, mode) == true)
						{
							column = column - ((10 * (commandString[s + 2] - '0')) + (commandString[s + 3] - '0'));
							s = s + 4; // checks if the inputted command string is in the correct format
						}

						else
						{
							badPos = s; //breaks program if the input doesn't fit correctly
							return 2;
						}
					}


					else
					{
						if (plotLine(row, column, -1 * (commandString[s + 2] - '0'), HORIZ, plotChar, mode) == true)
						{
							column = column - (commandString[s + 2] - '0');
							s = s + 3;
						}

						else
						{
							badPos = s; //breaks program if the input doesn't fit correctly
							return 2;
						}
					}


				}
			}


			else if (isdigit(commandString[s + 1])) //checks if the input is a digit
			{
				if (isdigit(commandString[s + 2])) //checks if the input is a digit
				{


					if (plotLine(row, column, (10 * (commandString[s + 1] - '0')) + (commandString[s + 2] - '0'), HORIZ, plotChar, mode) == true)
					{
						plotLine(row, column, (10 * (commandString[s + 1] - '0')) + (commandString[s + 2] - '0'), HORIZ, plotChar, mode);
						column = column + ((10 * (commandString[s + 1] - '0')) + (commandString[s + 2] - '0'));
						s = s + 3; //checks if the inputted command string is in the correct format

					}

					else
					{
						badPos = s; //breaks program if the input doesn't fit correctly
						return 2;
					}
				}

				else
				{
					if (plotLine(row, column, commandString[s + 1] - '0', HORIZ, plotChar, mode) == true)
					{
						column = column + (commandString[s + 1] - '0');
						s = s + 2; //checks if the inputted command string is in the correct format
					}

					else
					{
						badPos = s; //breaks program if the input doesn't fit correctly
						return 2;
					}
				}

			}

			else
			{
				badPos = s + 1; //breaks program if the input doesn't fit correctly
				return 1;
			}
		}


		else if (tolower(commandString[s]) == 'v') //user wants to print characters vertically
		{

			if (commandString[s + 1] == '-')
			{
				if (isdigit(commandString[s + 2])) //checks if the input is a digit
				{
					if (isdigit(commandString[s + 3])) //checks if the input is a digit
					{


						if (plotLine(row, column, (-10 * (commandString[s + 2] - '0')) - (commandString[s + 3] - '0'), VERT, plotChar, mode) == true)
						{
							row = row - ((10 * (commandString[s + 2] - '0')) + (commandString[s + 3] - '0'));
							s = s + 4; // checks if the inputted command string is in the correct format
						}

						else
						{
							badPos = s; //breaks program if the input doesn't fit correctly
							return 2; 
						}
					}


					else
					{
						if (plotLine(row, column, -1 * (commandString[s + 2] - '0'), VERT, plotChar, mode) == true)
						{
							row = row - (commandString[s + 2] - '0');
							s = s + 3; // checks if the inputted command string is in the correct format
						}

						else
						{
							badPos = s; //breaks program if the input doesn't fit correctly
							return 2;
						}
					}


				}
			}


			else if (isdigit(commandString[s + 1])) //checks if the input is a digit
			{
				if (isdigit(commandString[s + 2])) //checks if the input is a digit
				{


					if (plotLine(row, column, (10 * (commandString[s + 1] - '0')) + (commandString[s + 2] - '0'), VERT, plotChar, mode) == true)
					{
						row = row + ((10 * (commandString[s + 1] - '0')) + (commandString[s + 2] - '0'));
						s = s + 3; // checks if the inputted command string is in the correct format
					}

					else
					{
						badPos = s; //breaks program if the input doesn't fit correctly
						return 2;
					}
				}

				else
				{
					if (plotLine(row, column, commandString[s + 1] - '0', VERT, plotChar, mode) == true)
					{
						row = row + (commandString[s + 1] - '0');
						s = s + 2; // checks if the inputted command string is in the correct format
					}

					else
					{
						badPos = s; //breaks program if the input doesn't fit correctly
						return 2;
					}
				}

			}

			else
			{
				badPos = s + 1; //breaks program if the input doesn't fit correctly
				return 1;
			}
		}


		else if (tolower(commandString[s]) == 'f') //user wants to print characters in the foreground
		{

			if (isprint(commandString[s + 1]))
			{
				mode = FG;
				plotChar = commandString[s + 1];
				s = s + 2;
			}

			else
			{
				badPos = s + 1; //breaks program if the input doesn't fit correctly
				return 1;
			}

		}

		else if (tolower(commandString[s]) == 'b') //user wants to print characters in the background
		{

			if (isprint(commandString[s + 1]))
			{
				mode = BG;
				plotChar = commandString[s + 1];
				s = s + 2;

			}

			else
			{
				badPos = s + 1; //breaks program if the input doesn't fit correctly
				return 1;
			}

		}

		else if (tolower(commandString[s]) == 'c') //clears all characters in the grid
		{

			for (int i = 1; i <= 20; ++i)
			{
				for (int j = 1; j <= 30; ++j)
				{
					setChar(i, j, ' ');
				}
			}

			s = s + 1;

			mode = FG;
			plotChar = '*'; //prints out the * character in the foreground
			row = 1;
			column = 1;

		}

		else
		{
			badPos = s; //breaks program if the input doesn't fit correctly
			return 1;
		}

	}

	return 0;

}


int main()
{
	setSize(20, 30); //sets the size of the grid
	char currentChar = '*';
	int currentMode = FG;
	for (;;)
	{
		cout << "Enter a command string: "; // prompts the user to input their command string
		string cmd;
		getline(cin, cmd);
		if (cmd == "") // program will not run if the user does not input anything
			break;

		int position;

		int status = performCommands(cmd, currentChar, currentMode, position);


		switch (status) //provides command for the program to draw or to break if there is a syntax error/problem with the user's input
		{
		case 0:
			draw();
			break;
		case 1:
			cout << "Syntax error at position " << position + 1 << endl;
			break;
		case 2:
			cout << "Cannot perform command at position " << position + 1 << endl;
			break;
		default:
			// It should be impossible to get here.
			cerr << "performCommands returned " << status << "!" << endl;
		}
	}
}