Node* LinkedList::search(int item){
	Node* ptr = first;
	while (ptr && ptr->info!=item)
	    ptr = ptr->next;
	if (ptr)
	   return ptr;
	else
	   return NULL;
}
