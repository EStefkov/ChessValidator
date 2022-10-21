#include <iostream>
#include <string>
int main() {
	int num=0;
	int columnSize = 8;
	char rowSize = 'h';
	char array[8][8];
	// for now just printing the board
	for (int column = 1; column <= columnSize; column++)
	{
		std::cout << column;
		
		for (char row = 'a'; row <= rowSize; row++)
		{
			std::cout <<" - ";
			std::cout << "|";
			
			num++;
			if (num % columnSize == 0) {
				std::cout << "\n";
			}
		}
	}
	
}