//**************************************
// Name: Hash table functions
// Description:Hash table management by Jerry Coffin, with improvements by HenkJan Wolthuis.
// By: Bob Stout (republished under Open Content License)
// Ingmar Stieger: Added better hash function from Bob Jenkins (http://burtleburtle.net/bob/hash/)
//                 and converted the code to c++ (more or less)
//
//
//This code is copyrighted and has limited warranties.
//Please see http://www.Planet-Source-Code.com/xq/ASP/txtCodeId.710/lngWId.3/qx/vb/scripts/ShowCode.htm
//for details.
//**************************************

#include <stdlib.h>
#include <string.h>
#include "windows.h"
#include "HashTable.h"
/*
** public domain code by Jerry Coffin, with improvements by HenkJan Wolthuis and Ingmar Stieger
*/

/* Initialize the hash_table to the size asked for. Allocates space
** for the correct number of pointers and sets them to NULL. If it
** can't allocate sufficient memory, signals error by setting the size
** of the table to 0.
*/
CHashTable::CHashTable(size_t size)
{
    size_t i;
    bucket **temp;

	table = new hash_table();
    table->size = size;
    table->table = (bucket * *)malloc(sizeof(bucket *) * size);
    temp = table->table;
    if (temp == NULL)
        table->size = 0;
	else
	{
		for (i=0; i < size; i++)
			temp[i] = NULL;
	}
}

/*
** Frees a complete table by iterating over it and freeing each node.
** The associated data is not free'd.
*/
CHashTable::~CHashTable()
{
    unsigned i;
    bucket *temp;
    for (i=0; i < table->size; i++)
        if ((table->table)[i] != NULL)
            for (temp = (table->table)[i]; temp != NULL; temp = temp->next)
				del(temp->key);

    free(table->table);
	delete table;
}

/*
--------------------------------------------------------------------
hash() -- hash a variable-length key into a 32-bit value
  k     : the key (the unaligned variable-length array of bytes)
  level : can be any 4-byte value
Returns a 32-bit value.  Every bit of the key affects every bit of
the return value.  Every 1-bit and 2-bit delta achieves avalanche.
About 36+6len instructions.

The best hash table sizes are powers of 2.  There is no need to do
mod a prime (mod is sooo slow!).  If you need less than 32 bits,
use a bitmask.  For example, if you need only 10 bits, do
  h = (h & hashmask(10));
In which case, the hash table should have hashsize(10) elements.

If you are hashing n strings (ub1 **)k, do it like this:
  for (i=0, h=0; i<n; ++i) h = hash( k[i], len[i], h);

By Bob Jenkins, 1996.  bob_jenkins@burtleburtle.net.  You may use this
code any way you wish, private, educational, or commercial.  It's free.

See http://burlteburtle.net/bob/hash/evahash.html
Use for hash table lookup, or anything where one collision in 2^32 is
acceptable.  Do NOT use for cryptographic purposes.
--------------------------------------------------------------------
*/

#define mix(a,b,c) \
{ \
  a -= b; a -= c; a ^= (c>>13); \
  b -= c; b -= a; b ^= (a<<8); \
  c -= a; c -= b; c ^= (b>>13); \
  a -= b; a -= c; a ^= (c>>12);  \
  b -= c; b -= a; b ^= (a<<16); \
  c -= a; c -= b; c ^= (b>>5); \
  a -= b; a -= c; a ^= (c>>3);  \
  b -= c; b -= a; b ^= (a<<10); \
  c -= a; c -= b; c ^= (b>>15); \
}

ub4 CHashTable::hash(char *key, register ub4 initval)
{
   register ub1 *k = (ub1*) key;
   register ub4 a,b,c,len;

   /* Set up the internal state */
   len = strlen((char*)k);
   a = b = 0x9e3779b9;  /* the golden ratio; an arbitrary value */
   c = initval;           /* the previous hash value */

   /*---------------------------------------- handle most of the key */
   while (len >= 12)
   {
      a += (k[0] +((ub4)k[1]<<8) +((ub4)k[2]<<16) +((ub4)k[3]<<24));
      b += (k[4] +((ub4)k[5]<<8) +((ub4)k[6]<<16) +((ub4)k[7]<<24));
      c += (k[8] +((ub4)k[9]<<8) +((ub4)k[10]<<16)+((ub4)k[11]<<24));
      mix(a,b,c);
      k += 12; len -= 12;
   }

   /*------------------------------------- handle the last 11 bytes */
   c += len;
   switch(len)              /* all the case statements fall through */
   {
   case 11: c+=((ub4)k[10]<<24);
   case 10: c+=((ub4)k[9]<<16);
   case 9 : c+=((ub4)k[8]<<8);
      /* the first byte of c is reserved for the length */
   case 8 : b+=((ub4)k[7]<<24);
   case 7 : b+=((ub4)k[6]<<16);
   case 6 : b+=((ub4)k[5]<<8);
   case 5 : b+=k[4];
   case 4 : a+=((ub4)k[3]<<24);
   case 3 : a+=((ub4)k[2]<<16);
   case 2 : a+=((ub4)k[1]<<8);
   case 1 : a+=k[0];
     /* case 0: nothing left to add */
   }
   mix(a,b,c);
   /*-------------------------------------------- report the result */
   return c;
}


/*
** Insert 'key' into hash table.
** Returns pointer to old data associated with the key, if any, or
** NULL if the key wasn't in the table previously.
*/
void* CHashTable::insert(char *key, void *data)
{
    unsigned val = hash(key, 42) % table->size;
    bucket *ptr;
    /*
    ** NULL means this bucket hasn't been used yet. We'll simply
    ** allocate space for our new bucket and put our data there, with
    ** the table pointing at it.
    */
    if ((table->table)[val] == NULL)
    {
        (table->table)[val] = (bucket *)malloc(sizeof(bucket));
        if ((table->table)[val] == NULL)
	        return NULL;
        (table->table)[val]->key = strdup(key);
        (table->table)[val]->next = NULL;
        (table->table)[val]->data = data;
        return (table->table)[val] -> data;
    }
    /*
    ** This spot in the table is already in use. See if the current string
    ** has already been inserted, and if so, increment its count.
    */
    for (ptr = (table->table)[val]; ptr != NULL; ptr = ptr->next)
	{
		if (strcmp(key, ptr->key) == 0)
        {
			void *old_data;
			old_data = ptr->data;
			ptr->data = data;
	        return old_data;
	    }
	}
    /*
    ** This key must not be in the table yet. We'll add it to the head of
    ** the list at this spot in the hash table. Speed would be
    ** slightly improved if the list was kept sorted instead. In this case,
    ** this code would be moved into the loop above, and the insertion would
    ** take place as soon as it was determined that the present key in the
    ** list was larger than this one.
    */
    ptr = (bucket *)malloc(sizeof(bucket));
    if (ptr == NULL)
	    return 0;
    ptr->key = strdup(key);
    ptr->data = data;
    ptr->next = (table->table)[val];
    (table->table)[val] = ptr;
    return data;
}

/*
** Look up a key and return the associated data. Returns NULL if
** the key is not in the table.
*/
void* CHashTable::lookup(char *key)
{
    unsigned val = hash(key, 42) % table->size;
    bucket *ptr;
    if ((table->table)[val] == NULL)
	    return NULL;
    for (ptr = (table->table)[val]; ptr != NULL; ptr = ptr->next )
        if (strcmp(key, ptr->key) == 0)
			return ptr->data;

	return NULL;
}

/*
** Delete a key from the hash table and return associated
** data, or NULL if not present.
*/
void* CHashTable::del(char *key)
{
    unsigned val = hash(key, 42) % table->size;
    void *data;
    bucket *ptr, *last = NULL;
    if ((table->table)[val] == NULL)
	    return NULL;
    /*
    ** Traverse the list, keeping track of the previous node in the list.
    ** When we find the node to delete, we set the previous node's next
    ** pointer to point to the node after ourself instead. We then delete
    ** the key from the present node, and return a pointer to the data it
    ** contains.
    */
    for (last = NULL, ptr = (table->table)[val]; ptr != NULL; last = ptr, ptr = ptr->next)
    {
        if (strcmp(key, ptr -> key) == 0)
        {
            if (last != NULL )
            {
                data = ptr->data;
                last->next = ptr->next;
                free(ptr->key);
                free(ptr);
                return data;
            }
            /*
            ** If 'last' still equals NULL, it means that we need to
            ** delete the first node in the list. This simply consists
            ** of putting our own 'next' pointer in the array holding
            ** the head of the list. We then dispose of the current
            ** node as above.
            */
            else
            {
                data = ptr->data;
                (table->table)[val] = ptr->next;
                free(ptr->key);
                free(ptr);
                return data;
            }
        }
    }
    /*
    ** If we get here, it means we didn't find the item in the table.
    ** Signal this by returning NULL.
    */
    return NULL;
}

/*
** Return size of table
*/
size_t CHashTable::getSize()
{
	return table->size;
}

/*
** Simply invokes the function given as the second parameter for each
** node in the table, passing it the key and the associated data.
** (should really be an iterator)
*/
void CHashTable::enumerate(void (*func)(char *, void *))
{
    unsigned i;
    bucket *temp;
    for (i=0; i < table->size; i++)
        if ((table->table)[i] != NULL)
            for (temp = (table->table)[i]; temp != NULL; temp = temp->next)
                func(temp->key, temp->data);

}
