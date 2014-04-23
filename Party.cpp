#include "Party.h"

Party::Party(CardLear trumpCard): trump(trumpCard){}

void Party::PutCardsInBuffer(Card* card, uint n)
{
	for (uint i = 0; i < n; i++)
	{
		buffer.put(card[i]);
	}
}

void Party::EraseBuffer()
{
	while (!buffer.isEmpty())
	{
		buffer.pop();
	}
}