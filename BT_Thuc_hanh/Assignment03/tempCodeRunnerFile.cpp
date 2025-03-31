NODE* SeparateHead(LIST &L)
{
    NODE* tempNode = L.pHead;
    if(tempNode == NULL)
        return NULL;
    L.pHead = L.pHead->pNext;
    tempNode->pNext = NULL;
    if(L.pHead == NULL)
        L.pTail == NULL;
    return tempNode;
}

void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
    if(L.pHead == NULL)
        return;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    NODE* tempNode = NULL;
    pivot = SeparateHead(L);
    while(L.pHead != NULL)
    {
        tempNode = SeparateHead(L);
        if(tempNode->info <= pivot->info)
            AddTail(L1, tempNode);
        else    
            AddTail(L2, tempNode);
    }
}

void Join(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
    NODE* tempNode = NULL;
    while(L1.pHead != NULL)
    {
        tempNode = SeparateHead(L1);
        AddTail(L, tempNode);
    }
    AddTail(L, pivot);
    while(L2.pHead != NULL)
    {
        tempNode = SeparateHead(L2);
        AddTail(L, tempNode);
    }
}

void quicksort_ascending(LIST& L)
{
    if(L.pHead == L.pTail)
        return;
    LIST L1, L2;
    NODE *pivot = NULL;
    Partition(L, L1, pivot, L2);
    if(L1.pHead != L1.pTail)
        quicksort_ascending(L1);
    if(L2.pHead != L2.pTail)
        quicksort_ascending(L2);
    Join(L, L1, pivot, L2);
}
