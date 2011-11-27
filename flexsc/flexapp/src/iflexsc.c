/*
 * iflexsc.c
 *
 *  Created on: Oct 24, 2011
 *      Author: maksud
 */

#include "iflexsc.h"
#include <sys/syscall.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <semaphore.h>  /* Semaphore */
#include <pthread.h>
#define NPAGES 16

struct syscall_page* basepage; // 4 * 64 = 256 Threads
char* buffers; // 256 / 4 = 64
//
struct syscall_entry* entries[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int last_index = 0;

void printstack(void)
{
	int i, j, index;
	printf("\n");
	for (index = 0; index < NUM_THREADS; index++)
	{
		i = index % 64;
		j = index / 64;

		printf("%d ", index);
		printf("%d ", basepage[j].entries[i].syscall);
		printf("%d ", basepage[j].entries[i].num_args);
		printf("%d ", basepage[j].entries[i].status);
		printf("%ld ", basepage[j].entries[i].return_code);
		printf("%ld ", basepage[j].entries[i].args[0]);
		printf("%ld ", basepage[j].entries[i].args[1]);
		printf("%ld ", basepage[j].entries[i].args[2]);
		printf("%ld ", basepage[j].entries[i].args[3]);
		printf("%ld ", basepage[j].entries[i].args[4]);
		printf("%ld \n", basepage[j].entries[i].args[5]);
	}
	printf("\n");
}

struct syscall_page* flexsc_register_old(void)
{
	syscall(sys_flexsc_register);
	return NULL;
}

struct syscall_page* flexsc_register(void)
{
	int index, i, j;
	int fd;
	unsigned char* kadr;
	int len = NPAGES * getpagesize();

	//	syscall(sys_flexsc_register2, (void*) (NUM_THREADS * 128));

	if ((fd = open("node2", O_RDWR | O_SYNC)) < 0)
	{
		perror("open");
		exit(-1);
	}
	kadr = mmap(0, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd, len);
	if (kadr == MAP_FAILED)
	{
		perror("mmap");
		exit(-1);
	}
	close(fd);

	basepage = kadr;
	buffers = kadr + 4 * 64 * 64;
	for (index = 0; index < 12 * 4096; index++)
	{
		buffers[index] = 0;
	}

	printf("Basepage: %ld, %p\n", basepage, basepage);
	for (index = 0; index < NUM_THREADS; index++)
	{
		j = index / 64;
		i = index % 64;
		//
		entries[i] = &basepage[j].entries[i];
		basepage[j].entries[i].args[0] = 0;
		basepage[j].entries[i].args[1] = 0;
		basepage[j].entries[i].args[2] = 0;
		basepage[j].entries[i].args[3] = 0;
		basepage[j].entries[i].args[4] = 0;
		basepage[j].entries[i].args[5] = i + 100;
		basepage[j].entries[i].syscall = 0;
		basepage[j].entries[i].status = 0;
		basepage[j].entries[i].num_args = 0;
		basepage[j].entries[i].return_code = 0;
	}
	return (struct syscall_page*) kadr;
}

void flexsc_wait(void)
{
	long pid = (long) getpid();
	long ret = syscall(sys_flexsc_wait);
}

struct syscall_page* allocate_register(void)
{
	return malloc(sizeof(struct syscall_page));
}

int last_used = 0;

struct syscall_entry* free_syscall_entry_i(int i)
{

	//	free_syscall_entry();

	return &basepage[i / 64].entries[i % 64];
	//
	//	pthread_mutex_lock(&mutex);
	//	struct syscall_entry* e = free_syscall_entry();
	//	pthread_mutex_unlock(&mutex);
	//
	//	while (e == NULL)
	//	{
	//		printf("Found! Try Again\n");
	//		sleep(1);
	//
	//		pthread_mutex_lock(&mutex);
	//		e = free_syscall_entry();
	//		pthread_mutex_unlock(&mutex);
	//	}
	//	return e;
}

struct syscall_entry* free_syscall_entry(void)
{
	int i, j, index, rc;
	printf("Try to Access.\n");
	struct syscall_entry* entry = NULL;

	for (index = 0; index < NUM_THREADS; index++)
	{
		last_index = (last_index + 1) % NUM_THREADS;

		j = last_index / 64;
		i = last_index % 64;

		if (basepage[j].entries[i].status == FREE)
		{
			printf("Found! %d, %d\n", j, i);
			basepage[j].entries[i].status = 100; // RESERVED
			entry = &basepage[j].entries[i];
			break;
		}
	}
	//		if (entry == NULL)
	//		return free_syscall_entry();
	//	printf("Got Access?\n: %p", entry);
	return entry; // Sorry, No Free Entry.
}
