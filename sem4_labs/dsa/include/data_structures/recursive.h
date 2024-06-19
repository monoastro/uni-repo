#include <iostream>

void towerOfHanoi(unsigned numberOfDisks, char source, char destination, char auxiliary)
{
	if(numberOfDisks == 1)
	{
		printf("Move disk 1 from %c to %c\n", source, destination);
		return;
	}

	towerOfHanoi(numberOfDisks - 1, source, auxiliary, destination);
	printf("Move disk %u from %c to %c\n", numberOfDisks, source, destination);
	towerOfHanoi(numberOfDisks-1, auxiliary, destination, source);

}

unsigned fibonacci(unsigned n)
{
	return n<2 ? n : fibonacci(n-1) + fibonacci(n-2);
}

unsigned factorial(unsigned n)
{
	return n<2 ? 1 : n*factorial(n-1);
}

class TOH
{
public:
	void printTowers()
	{
		//print the towers based on the disk to peg map
		for(unsigned i = 0; i < 3; ++i)
		{
			char peg = 'A' + i;
			std::cout << peg << ": ";
			for(unsigned j = m_numberOfDisks; j>=1; --j)
			{
				if(m_diskToPeg[j] == peg) std::cout << j << " ";
			}
			std::cout << "\n";
		}
		//std::cout << "\n";
	}

	void moveDisk(unsigned disk, char destination)
	{
		//update the disk to peg map
		m_diskToPeg[disk] = destination;
		printTowers();
	}

	void solve(unsigned numberOfDisks, char source, char destination, char auxiliary)
	{
		if(numberOfDisks == 1)
		{
			printf("Move disk 1 from %c to %c\n", source, destination);
			moveDisk(1, destination);
			return;
		}
		solve(numberOfDisks - 1, source, auxiliary, destination);
		printf("Move disk %u from %c to %c\n", numberOfDisks, source, destination);
		moveDisk(numberOfDisks, destination);
		solve(numberOfDisks-1, auxiliary, destination, source);
	}

	TOH(unsigned numberOfDisks = 3, char source = 'A', char destination = 'C', char auxiliary = 'B')
	: 
		m_numberOfDisks(numberOfDisks)
	{
		m_diskToPeg = new char[numberOfDisks+1];
		for(unsigned i = 0; i < numberOfDisks; ++i) m_diskToPeg[i+1] = source;
		//print initial towers
		printf("Initial towers:\n");
		printTowers();

		solve(numberOfDisks, source, destination, auxiliary);
	}

private:
	char* m_diskToPeg;
	unsigned m_numberOfDisks;
};
