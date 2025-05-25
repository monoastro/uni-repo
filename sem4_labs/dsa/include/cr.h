
void insert(node *list, int pos, int entry){
    node *new;
    new->data = entry;
    int counter = 0;
    for (node *iter = list; iter != NULL; iter = iter->next){
        if (counter == pos - 1) {
            new->next = iter->next; // next of new node is next of previous node
            iter->next = new; // previous node points to new node as next
            break;
        } else if (pos == 0){
            new->next = iter; // next of new is current node
            list = new; // linked list starts at new node
            break;
        } else {counter++;}
    }
}
