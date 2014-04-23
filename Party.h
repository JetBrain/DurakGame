#include "CardsBlock.h"

class Party
{
public:
	typedef Queue<Card> PartyBuffer;
	Party(CardLear=LEAR_NOT_INIT);
	void PutCardsInBuffer(Card*, uint);
	void EraseBuffer();
	int GetTrump();
private:
	PartyBuffer buffer;
	int trump;
};