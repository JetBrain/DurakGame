#include "Card.h"

Card::Card (const Card& card): lear(card.lear), value(card.value)
{}

Card::Card (CardLear Lear, CardValue Value): lear (Lear), value (Value) 
{}

CardLear Card::GetLear()
{ 
	return lear;
}    

CardValue Card::GetValue () 
{
	return value;
}