#pragma once
#include"ListInfo.h"
typedef struct ListItem
{
	ListInfo info;
	ListItem* pNext;
	ListItem* pPrev;
}ListItem;