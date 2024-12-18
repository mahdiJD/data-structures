int LinkedList::deleteNode2(Node* p) {
	if (!first) {
		    cout << "Can not delete.";
		    exit(-1);
	}
	int item = p->info;
	if (p == first)
		first = first->next;
	else {
	    Node* prep = first;
	    while (prep->next != p)
		    prep = prep->next;
	    prep->next = p->next;
    }
	delete p;
	return item;
}
