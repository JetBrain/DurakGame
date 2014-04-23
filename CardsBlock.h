#include "Card.h"
#include "Containers.h"

class CardsBlock: public Stack<Card>
{
public:
	   CardsBlock(uint = 0);
	   void reShuffle();
};