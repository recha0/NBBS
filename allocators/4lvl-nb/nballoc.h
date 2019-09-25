#ifndef __NB_ALLOC__
#define __NB_ALLOC__

/****************************************************
				ALLOCATOR PARAMETES
****************************************************/

#ifndef MIN_ALLOCABLE_BYTES
#define MIN_ALLOCABLE_BYTES 8ULL //(2KB) numero minimo di byte allocabili
#endif
#ifndef MAX_ALLOCABLE_BYTE
#define MAX_ALLOCABLE_BYTE  16384ULL //(16KB)
#endif
#ifndef NUM_LEVELS
#define NUM_LEVELS  20ULL //(16KB)
#endif

#define PAGE_SIZE (4096)


typedef unsigned long long nbint; 


typedef struct _taken_list_elem{
	struct _taken_list_elem* next;
	node* elem;
}taken_list_elem;

typedef struct _taken_list{
	struct _taken_list_elem* head;
	unsigned int number;
}taken_list;


extern __thread unsigned int myid;
extern unsigned int number_of_leaves;

void  bd_xx_free(void* n);
void* bd_xx_malloc(size_t pages);


#ifdef DEBUG
extern unsigned long long *node_allocated, *size_allocated;
#endif


#ifndef BD_SPIN_LOCK
	#define BD_LOCK_TYPE /**/
	#define INIT_BD_LOCK /**/
	#define BD_LOCK(x)   	 /**/
	#define BD_UNLOCK(x) 	 /**/
#endif

#endif
