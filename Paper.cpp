// Paper.cpp

#include "Paper.h"

Paper::Paper() 
{
	this->length = 0;
	this->current = 0;
}

Paper::Paper(const Paper& source):linkedList(source.linkedList)
{
	this->length = source.length;
	this->current = 0;
}

Paper::~Paper() {}

Paper& Paper::operator=(const Paper& source) 
{
	this->linkedList = source.linkedList;
	this->length = source.length;
	this->current = 0;

	return *this;
}

Label& Paper::GetAt(int index) 
{
	return this->linkedList.GetAt(index);
}

Label* Paper::Attach(Label label) 
{
	LinkedList<Label>::Node* node = this->linkedList.GetCurrent();

	if(node == 0) 
	{
		node = this->linkedList.AppendFromHead(label);
	}
	else 
	{
		node = this->linkedList.InsertAfter(node, label);
	}

	this->current = &(node->GetObject());
	this->length++;

	return this->current;
}

Label Paper::Detach()
{
	Label label = *(this->current);

	LinkedList<Label>::Node* node = this->linkedList.Delete();

	if(node != 0)
	{
		this->current = &(node->GetObject());
	}
	else 
	{
		this->current = 0;
	}

	this->length--;	
	
	return label;
}

int CompareLabel(void* one, void* other)
{
	int ret = -1;

	if(one == other)
	{
		ret = 0;
	}

	return ret;
}

Label* Paper::MoveUp()
{
	if(this->length > 1)
	{
		LinkedList<Label>::Node* previous = this->linkedList.Previous();
		this->current = &(previous->GetObject());
	}
	return this->current;
}

Label* Paper::MoveDown()
{
	if(this->length > 1)
	{
		LinkedList<Label>::Node* next = this->linkedList.Next();
		this->current = &(next->GetObject());
	}
	return this->current;
}