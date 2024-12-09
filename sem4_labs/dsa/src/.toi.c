#include <stdio.h>
#include <malloc.h>

char* diskToPeg;
unsigned numberOfDisks;

void printTowers()
{
	//print the towers based on the disk to peg map
	for(unsigned i = 0; i < 3; ++i)
	{
		char peg = 'A' + i;
		printf("%c :", peg);
		for(unsigned j = numberOfDisks; j>=1; --j)
		{
			if(diskToPeg[j] == peg) printf("%u ", j);
		}
		printf("\n");
	}
	//printf("\n");
}

void moveDisk(unsigned disk, char destination)
{
	//update the disk to peg map
	printf("Move disk %u from %c to %c\n", disk, diskToPeg[disk], destination);
	diskToPeg[disk] = destination;
	printTowers();
}

void tohSolve(unsigned numberOfDisks, char source, char destination, char auxiliary)
{
	if(numberOfDisks == 1)
	{
		moveDisk(1, destination);
		return;
	}
	tohSolve(numberOfDisks - 1, source, auxiliary, destination);
	moveDisk(numberOfDisks, destination);
	tohSolve(numberOfDisks-1, auxiliary, destination, source);
}

int main()
{
	scanf("%u", &numberOfDisks);
	diskToPeg = (char*)malloc(sizeof(char)*(numberOfDisks+1));
	char source = 'A', destination = 'C', auxiliary = 'B';

	//initialize the disk to peg map and print initial towers
	for(unsigned i = 0; i < numberOfDisks; ++i) diskToPeg[i+1] = source;
	printTowers();

	tohSolve(numberOfDisks, source, destination, auxiliary);
	return 0;
}
