
    while(!Tqueue.empty())
    {
        TNODE* curNode = Tqueue.front();
        Tqueue.pop();
        cout << curNode->key << " ";
        if(curNode->pLeft != NULL)