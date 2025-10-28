#include "global.h"

/* TO BE COMPLETED: implement backpatch operations on lists */
// SRW changed to unsigned int
Backpatchlist *makelist(unsigned int location)
{
    Backpatchlist *new_list = (Backpatchlist *)malloc(sizeof(Backpatchlist));
    if (!new_list)
        error("Out of memory");
    new_list->loc = location;
    new_list->next = NULL;
    return new_list;
}
/* Backpatches all locations in the list with the target location */
void backpatchlist(Backpatchlist *list, int location)
{
    Backpatchlist *current;
    for (current = list; current; current = current->next)
    {
        /* backpatch() expects relative offset */
        backpatch(current->loc, location - current->loc);
    }
}
/* Merges two backpatch lists into one */
Backpatchlist *mergelist(Backpatchlist *list1, Backpatchlist *list2)
{Backpatchlist *current;
    if (!list1) return list2;
    if (!list2) return list1;
    /* Find end of list1 */
    for (current = list1; current->next; current = current->next)
        ;
    /* Attach list2 to end of list1 */
    current->next = list2;
    return list1;
}
