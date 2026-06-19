#include <stdlib.h>

int main(int argc, char **argv)
{
	/*
	1. open the file 
		- handle open file error 
	2. read the file 
		- file rules :
			- must be .cub extension (using strchr to get if values after . is cub)
			- map must be composed of 
				- 0 for empty
				- 1 for wall
				- NSWE for player's star position and spawninf orentation
				- > use get_next_line to check lines one by one?
			- must be closed by walls (1) 
				- > flood fill? figure out the algorithm to check if walls are close
		- from the subject pdf, there can be other elements within the file
			- NO , SO , WE , EA , F, C followed by location to texture
		- if the paths to the texture and the colors to the F and C are invalid, print an error message
	3. Pass the map to execution
		- how does execution read or use the map ?

		
	*/
}