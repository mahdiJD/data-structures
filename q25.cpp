List concat(List a, List b)
{
    if (a.first == NULL)
    	a.first = b.first;
    else 
        if (b.first != NULL) {
       	    ListNode *p = a.first;
       	    while (p->next != NULL)
       	        p = p->next;
       	    p->next = b.first;
	   }
	return a;
}