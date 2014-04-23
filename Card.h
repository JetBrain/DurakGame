enum CardLear                                                                        
{ LEAR_NOT_INIT = 0, HEARTS = 3, DIAMONDS, CLUBS, SPADES };

enum CardValue                                                                      
{ VALUE_NOT_INIT = 0, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card                                                                          
{
     private:
	         CardLear lear;                                                          
			 CardValue value;
     public: 
     	     Card (const Card&);
			 Card (CardLear = LEAR_NOT_INIT, CardValue = VALUE_NOT_INIT);                                                                                                                    
			 CardLear GetLear ();                   
	         CardValue GetValue ();
};