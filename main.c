#include <stdint.h>
#include <malloc.h>

#define MIN_TID 300
#define MAX_TID 5000

//WORKING WITH uint32_t
#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)) )
#define ClearBIT(A,k)   ( A[(k/32)] &= ~(1 << (k%32)) )
#define TestBit(A,k)    ( A[(k/32)] & (1 << (k%32)) )

//WORKING WITH INT
/* Set Bit Step-by-Step
 * i = k/32          //Array index
 * pos = k%32        //Bit position
 * flag = 1          //Set bit information
 *
 * flag = flag << pos //shift bit by k places:
 *
 * A[i] = A[i] | flag //OR bit into place at index
 * */

/* Clear bit Step-by-step
 * i = k/32          //Array index
 * pos = k%32        //Bit position
 * flag = 1          //Set bit information
 *
 * flag = flag << pos //shift bit by k places:
 * flag = ~flag
 *
 * A[i] = A[i] & flag //AND bit into place at index
 * */

//Task 1 Question A
typedef struct bitmap{
    uint32_t *array;
    size_t size_in_bytes;
} bitmap_t;

bitmap_t *map;

int allocate_map (void);
int allocate_tid (void);
void release_tid (int tid);


int main() {}

int allocate_map (void)
{
    map = malloc(sizeof(bitmap_t));
    if(map == NULL)
        return -1;

    map->size_in_bytes = ((MAX_TID-MIN_TID)/32) + 1; //4700/32 = 146 + 1 = 147

    map->array = calloc(map->size_in_bytes, sizeof(uint32_t));
    if(map->array == NULL)
        return -1;

    for(int i = 0; i < map->size_in_bytes; ++i)
        map->array[i] = 0;

    return 1;
}

int allocate_tid (void)
{
    for(int i = 0; i < map->size_in_bytes-1; ++i) //A[0] - A[145]
    {
        if(map->array[i] != 0xFFFFFFFF)
        {
            for(int j = i*32; j < (i+1) * 32; ++j)
            {
                if(!TestBit(map->array, j))
                {
                    SetBit(map->array, j);
                    return 1;
                }
            }
        }
    }
    if(map->array[146] != 0x0FFFFFFF)   //A[146]
    {
        for(int j = 146*32; j < 147 * 32; ++j)
        {
            if(!TestBit(map->array, j))
            {
                SetBit(map->array, j);
                return 1;
            }
        }
    }
    return -1;
}


void release_tid (int tid)
{
    tid -= 300;
    ClearBIT(map->array, tid);
}
