#include "Player.h"

Player::Player(uint n) : block(), size(n)
{}

Card* Player::DoStep(int* index, int n)
{
	if (block.getLen() >= n)
	{
		Card* selected = new Card[n]{};

		for (int i = 0; i < n; i++)
		{
			selected[i] = block[index[i]];
		}

		for (int i = 0; i < n; i++)
		{
			block.del(index[i]);
		}

		return selected;
	}
	else
	{
		return 0;
	}
}

bool Player::TakeFrom(CardsBlock& cardsBlock)
{
	int empty = size - block.getLen();

	if (empty > 0)
	{
		while (empty)
		{
			block.put(cardsBlock.pop());
		    empty--;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::TakeFrom(CardsBlock& cardsBlock, int n)
{
	int empty = size - block.getLen();

	if (empty > 0)
	{
		for (int i = 0; i < n; i++)
		{
			block.put(cardsBlock.pop());
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::CheckPairs(int* index, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (block[index[i]].GetValue() != block[index[i+1]].GetValue())
		{
			return false;
		}
	}
	return true;
}

bool Player::IsBeatThisSet(int* index, Card* cardsSet, int n, CardLear trump)
{
	for (int i = 0; i < n; i++)
	{
		if (block[index[i]].GetLear() != cardsSet[i].GetLear() && block[index[i]].GetLear() != trump ||
			block[index[i]].GetLear() == cardsSet[i].GetLear() && block[index[i]].GetValue() < cardsSet[i].GetValue())
		{
			return false;
		}
	}

	return true;
}

void Player::SkipStep(Party::PartyBuffer& buffer)
{
	while (!buffer.isEmpty())
	{
		block.put(buffer.pop());
	}
}

Card* Player::GetCardsList()
{
	int len = block.getLen();

	Card* list = new Card[len];

	for (int i = 0; i < len; i++)
	{
		list[i] = block[i];
	}

	return list;
}

int Player::GetCardsQuantity()
{
	return block.getLen();
}

bool Player::IsEmpty()
{
	return !block.getLen();
}