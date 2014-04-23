#include "Party.h"

class Player
{
private:
	Queue<Card> block;
	const int size;
public: 
	Player(uint=0);
	Card* GetCardsList();
	Card* DoStep(int*,int);
	bool TakeFrom(CardsBlock&);
	bool TakeFrom(CardsBlock&,int);
	bool CheckPairs(int*,int);
	bool IsBeatThisSet(int*, Card*,int,CardLear);
	bool IsEmpty();
	void SkipStep(Party::PartyBuffer&);
	int GetCardsQuantity();
};