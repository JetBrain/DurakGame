#include <cstdlib>
#include <ctime>
#include "CardsBlock.h"

CardsBlock::CardsBlock(uint size) : Stack<Card>(size) {}

void CardsBlock::reShuffle()
{
	srand(time(0));

	for (int i = 0; i < lenght; i++)
	{
		int index1 = 0, index2 = 0;

		do
		{
			index1 = rand() % lenght;
			index2 = rand() % lenght;
		}
		while (index1 == index2);

		Card tmp = (*this)[index1];
		(*this)[index1] = (*this)[index2];
		(*this)[index2] = tmp;
	}
}