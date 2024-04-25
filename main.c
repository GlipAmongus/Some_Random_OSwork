#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

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
    size_t occupied;
} bitmap_t;

bitmap_t *map;

int allocate_map (void);
int allocate_tid (void);
void release_tid(int tid);


int main() {
    /*
     *      Data structures options:
     *  Stack, initialized with all TIDs, pop when being unavailable, push when available
     * */
    if(allocate_map() == 1)
        printf("allocate_map succeed\n");

    if(allocate_tid() == 1)
    {
        printf("id found available\n");
        printf("%u\n", map->array[0]);
    }else{
        printf("id found unavailable\n");
    }
    if(allocate_tid() == 1)
    {
        printf("id found available\n");
        printf("%u\n", map->array[0]);
    }else{
        printf("id found unavailable\n");
    }
    if(allocate_tid() == 1)
    {
        printf("id found available\n");
        printf("%u\n", map->array[0]);
    }else{
        printf("id found unavailable\n");
    }
    release_tid(300);
    printf("%u\n", map->array[0]);
}

//
int allocate_map (void)
{
    map = malloc(sizeof(bitmap_t));
    if(map == NULL)
        return -1;

    map->occupied = 0;
    map->size_in_bytes = ((MAX_TID-MIN_TID)/32) + 1; //4700/32 = 146 + 1 = 147

    map->array = calloc(map->size_in_bytes, sizeof(uint8_t));
    if(map->array == NULL)
        return -1;

    memset(map->array, 0, map->size_in_bytes);
    return 1;
}

int allocate_tid(void)
{
    for(int i = 0; i < map->size_in_bytes - 1; i++)
    {
        if(map->array[i] != 0xFFFFFFFF)
        {
            for(int j = 0; j < 32; j++)
            {
                if(!TestBit(map->array, j))
                {
                    SetBit(map->array, j);
                    return 1;
                }
            }
        }
    }
    if(map->array[147] != 0xFFFFFFF0)
    {
        for(int j = 0; j < 28; ++j)
        {
            if(TestBit(map->array, j)) {
                SetBit(map->array, j);
                return 1;
            }
        }
    }
    return -1;
}


void release_tid(int tid)
{
    tid -= 300;
    ClearBIT(map->array, tid);
}
