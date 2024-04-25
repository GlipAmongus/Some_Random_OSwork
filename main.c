#include <stdint.h>
#include <malloc.h>

#define MIN_TID 300
#define MAX_TID 5000

//WORKING WITH INT (32-bit)
#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)))
#define ClearBIT(A,k)   ( A[(k/32)] &= (0 << (k%32)))


//WORKING WITH INT
/* Set Bit Step-by-Step
 * i = k/32          //Array index
 * pos = k%32        //Bit position
 * flag = 1          //Set bit information
 *
 * flag = flag << pos //shift bit by pos no. of places:
 *
 * A[i] = A[i] | flag //OR bit into place at index
 * */

/* Clear bit Step-by-step
 * i = k/32          //Array index
 * pos = k%32        //Bit position
 * flag = 0          //Set bit information
 *
 * flag = flag << pos //shift bit by pos no. of places:
 *
 * A[i] = A[i] & flag //AND bit into place at index
 * */

//Task 1 Question A
typedef struct bitmap{
    uint8_t *bits;
    size_t size_in_bytes;
    size_t occupied;
} bitmap_t;

bitmap_t *map;

int main() {
    /*
     *      Data structures options:
     *  Bitmap, implement queue to avoid bigO(N) complexity on freed locations
     *  Stack, initialized with all TIDs, pop when being unavailable, push when available
     * */


}

//
int allocate_map (void)
{
    map = malloc(sizeof(bitmap_t));
    if(map == NULL)
        return -1;

    map->occupied = 0;
    map->size_in_bytes = MAX_TID-MIN_TID;

    map->bits = calloc(map->size_in_bytes, sizeof(uint8_t));
    if(map->bits == NULL)
        return -1;
    SetBit(map->bits, 54);
    return 1;
}

int allocate_tid()
{
    map->occupied;


    return 1;
}


void release_tid(int tid)
{

}
