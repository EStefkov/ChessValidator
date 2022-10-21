#include <iostream>
#include <string>
int main() {
	int num=0;
	int rowSize = 8;
	char columSize = 'h';
	char array[8][8];
	// for now just printing the board
	for (int row = 1; row <= rowSize; row++)
	{
		std::cout << row;
		
		for (char column = 'a'; column <= columSize; column++)
		{
			std::cout <<" - ";
			std::cout << "|";
			
			num++;
			if (num % 8 == 0) {
				std::cout << "\n";
			}
		}
	}
	
}