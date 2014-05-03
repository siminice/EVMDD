/*

  Program to generate a model for the virtual file system model

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OP_CREATE	1
#define OP_UNLINK	2
#define OP_MKDIR	3
#define OP_RMDIR	4

#define STEPS_CREATE	34
#define STEPS_UNLINK	23
#define STEPS_MKDIR	30
#define STEPS_RMDIR	39

int PROCS    = 1;
int DENTRIES = 4;
int INODES   = 4;
bool spec    = false;

void Init(){
   printf("Variables\n");

   for (int i=1; i<=DENTRIES; i++) {
     printf("  d_allocated_%d [0, 1]\n", i);
     printf("  d_count_%d     [0, %d]\n", i, PROCS+1);
     printf("  d_lock_%d      [0, 1]\n", i);
     printf("  d_subdirs_%d   [0, %d]\n", i, DENTRIES);
     printf("  d_parent_%d    [0, %d]\n", i, DENTRIES);
     printf("  d_inode_%d     [0, %d]\n\n", i, INODES);
   }

   for (int i=1; i<=INODES; i++) {
     printf("  i_allocated_%d [0, 1]\n", i);
     printf("  i_count_%d     [0, %d]\n", i, PROCS+1);
     printf("  i_lock_%d      [0, 1]\n", i);
     printf("  i_state_%d     [0, 1]\n", i);
     printf("  i_mutex_%d     [0, 1]\n\n", i);
   }

   for (int i=1; i<=PROCS; i++) {
     printf("  p_begin_%d  [0, 4]\n", i);
     printf("  p_parent_%d [0, %d]\n", i, DENTRIES);
     printf("  p_file_%d   [0, %d]\n", i, DENTRIES);
     printf("  p_inode_%d  [0, %d]\n", i, INODES);
     printf("  p_create_pc_%d [0, 34]\n", i);
     printf("  p_unlink_pc_%d [0, 23]\n", i);
     printf("  p_mkdir_pc_%d  [0, 30]\n", i);
     printf("  p_rmdir_pc_%d  [0, 39]\n", i);
     printf("  p_rmdir_wait_%d  [0, 1]\n\n", i);
   }

   printf("  dcache_lock [0, 1]\n");
   printf("  inode_lock  [0, 1]\n\n");


   printf("Initial states\n");
   printf("  dcache_lock = 1\n");
   printf("  inode_lock  = 1\n\n");

   for (int i=1; i<=DENTRIES;i++){
     printf("  d_allocated_%d  = %d\n", i, (i<=2?1:0));
     printf("  d_parent_%d     = %d\n", i, (i<=2?1:0));
     printf("  d_count_%d      = %d\n", i, (i<=2?1:0));
     printf("  d_lock_%d       = 1\n", i);
     printf("  d_inode_%d      = %d\n", i, (i<=2?i:0));
     printf("  d_subdirs_%d    = %d\n\n", i, (i<=2?3-i:0));
   }

   for (int i=1; i<=DENTRIES;i++){
     printf("  i_allocated_%d  = %d\n", i, (i<=2?1:0));
     printf("  i_count_%d      = %d\n", i, (i<=2?1:0));
     printf("  i_lock_%d       = 1\n", i);
     printf("  i_state_%d      = 0\n", i);
     printf("  i_mutex_%d      = 1\n\n", i);
   }

   for (int i=1; i<=PROCS; i++) {
     printf("  p_begin_%d  = 0\n", i);
     printf("  p_parent_%d = 0\n", i);
     printf("  p_file_%d   = 0\n", i);
     printf("  p_inode_%d  = 0\n", i);
     printf("  p_create_pc_%d = 0\n", i);
     printf("  p_unlink_pc_%d = 0\n", i);
     printf("  p_mkdir_pc_%d  = 0\n", i);
     printf("  p_rmdir_pc_%d  = 0\n", i);
     printf("  p_rmdir_wait_%d  = 0\n\n", i);
   }

}

void Trans(){
   printf("Transitions\n");
   for (int p=1; p<=PROCS; p++) {
    /* Initiate call, store new parameters */
    // --- cannot remove root, therefore p_file != 1
     printf("  p_begin_%d = 0  ->  p_begin_%d\' > 0 /\\ p_file_%d\' > 1 /\\ p_parent_%d\' > 0 /\\ p_inode_%d\' > 1\n", p, p, p, p, p);
     printf("\n");
    /* ---------- Create: lookup ---------- */
    // --- path_lookup(parent,file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_begin_%d = 1 /\\ p_create_pc_%d = 0 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ dcache_lock > 0  -> ", p, p, p, i, p, j);
       printf(" p_create_pc_%d\' = 1 /\\ d_count_%d\' = d_count_%d + d_allocated_%d", p, j, j, j);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d + d_allocated_%d", i, i, i); }
       printf("\n");
     }
    /* ---------- Create step 1 ---------- */
    // --- if (!parent.is_allocated)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 1 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d > 0 /\\ d_subdirs_%d = 0  -> ", p, p, i, p, j, j, j);
       printf(" d_count_%d\' = d_count_%d - d_allocated_%d", i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - 1", j, j); }
       printf(" /\\ p_create_pc_%d\' = 2\n", p);
       printf("  p_create_pc_%d = 1 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, i, p, j, j);
       printf( " p_create_pc_%d\' = 2 /\\ d_count_%d\' = d_count_%d - d_allocated_%d\n", p, i, i, i);
       printf("  p_create_pc_%d = 1 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d > 0 /\\ d_subdirs_%d > 0  -> ", p, p, i, p, j, j, j);
       printf(" p_create_pc_%d\' = 3\n", p);
     }
    /* ---------- Create step 2 ---------- */
    // --- return ERROR
     printf("  p_create_pc_%d = 2  ->  p_create_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Create step 3 ---------- */
    // --- down(parent.d_inode->i_mutex)
     for (int j=1; j<=DENTRIES; j++) for (int k=1; k<=INODES; k++) {
        printf("  p_create_pc_%d = 3 /\\ p_parent_%d = %d /\\ d_inode_%d = %d /\\ i_mutex_%d > 0  -> ", p, p, j, j, k, k);
        printf(" p_create_pc_%d\' = 4 /\\ i_mutex_%d\' = i_mutex_%d - 1\n", p, k, k);
     }
    /* ---------- Create step 4 ---------- */
    // --- if (file.is_allocated && !is_directory(file))
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_create_pc_%d = 4 /\\ p_file_%d = %d /\\ d_allocated_%d > 0 /\\ d_subdirs_%d = 0  -> ", p, p, i, i, i);
        printf(" p_create_pc_%d\' = 5\n", p);
        printf("  p_create_pc_%d = 4 /\\ p_file_%d = %d /\\ !(d_allocated_%d > 0 /\\ d_subdirs_%d = 0)  -> ", p, p, i, i, i);
        printf(" p_create_pc_%d\' = 8\n", p);
     }
    /* ---------- Create step 5 ---------- */
    // --- up(parent.d_inode->i_mutex)
     for (int j=1; j<=DENTRIES; j++) for (int k=1; k<=INODES; k++) {
        printf("  p_create_pc_%d = 5 /\\ p_parent_%d = %d /\\ d_inode_%d = %d  -> ", p, p, j, j, k);
        printf(" p_create_pc_%d\' = 6 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Create step 6 ---------- */
    // --- path_release(file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 6 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_create_pc_%d\' = 7 /\\ d_count_%d\' = d_count_%d - d_allocated_%d", p, i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - d_allocated_%d", j, j, j); }
       printf("\n");
     }
    /* ---------- Create step 7 ---------- */
    // --- return SUCCESS
     printf("  p_create_pc_%d = 7  ->  p_create_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Create step 8 ---------- */
    // --- if (file.is_allocated && is_directory(file))
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_create_pc_%d = 8 /\\ p_file_%d = %d /\\ d_allocated_%d > 0 /\\ d_subdirs_%d > 0  -> ", p, p, i, i, i);
        printf(" p_create_pc_%d\' = 9\n", p);
        printf("  p_create_pc_%d = 8 /\\ p_file_%d = %d /\\ !(d_allocated_%d > 0 /\\ d_subdirs_%d > 0)  -> ", p, p, i, i, i);
        printf(" p_create_pc_%d\' = 12\n", p);
     }
    /* ---------- Create step 9 ---------- */
    // --- up(parent.d_inode->i_mutex)
     for (int j=1; j<=DENTRIES; j++) for (int k=1; k<=INODES; k++) {
        printf("  p_create_pc_%d = 9 /\\ p_parent_%d = %d /\\ d_inode_%d = %d  -> ", p, p, j, j, k);
        printf(" p_create_pc_%d\' = 10 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Create step 10 ---------- */
    // --- path_release(file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 10 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_create_pc_%d\' = 11 /\\ d_count_%d\' = d_count_%d - d_allocated_%d", p, i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - d_allocated_%d", j, j, j); }
       printf("\n");
     }
    /* ---------- Create step 11 ---------- */
    // --- return SUCCESS
     printf("  p_create_pc_%d = 11  ->  p_create_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Create step 12 ---------- */
    // --- spin_lock(dcache_lock)
     printf("  p_create_pc_%d = 12 /\\ dcache_lock > 0  ->  p_create_pc_%d\' = 13 /\\ dcache_lock\' = dcache_lock - 1\n", p, p);
    /* ---------- Create step 13 ---------- */
    // --- allocate_dentry
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 13 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, i, p, j, i);
       printf(" p_create_pc_%d\' = 14 /\\ d_allocated_%d\' = 1 /\\ d_count_%d\' = 1 /\\ d_lock_%d\' = 1 /\\ d_parent_%d\' = %d\n", p, i, i, i, i, j);
     }
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_create_pc_%d = 13 /\\ p_file_%d = %d /\\ d_allocated_%d > 0  -> ", p, p, i, i);
       printf(" p_create_pc_%d\' = 15\n", p);
     }
    /* ---------- Create step 14 ---------- */
    // --- if (!file.is_allocated)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 14 /\\ p_parent_%d = %d /\\ d_subdirs_%d = 0  -> ", p, p, j, j);
       printf(" p_create_pc_%d\' = 15\n", p);
       printf("  p_create_pc_%d = 14 /\\ p_parent_%d = %d /\\ d_subdirs_%d > 0  -> ", p, p, j, j);
       printf(" p_create_pc_%d\' = 19\n", p);
     }
    /* ---------- Create step 15 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_create_pc_%d = 15  ->  p_create_pc_%d\' = 16 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Create step 16 ---------- */
    // --- up(parent.d_inode->i_mutex)
     for (int j=1; j<=DENTRIES; j++) for (int k=1; k<=INODES; k++) {
        printf("  p_create_pc_%d = 16 /\\ p_parent_%d = %d /\\ d_inode_%d = %d  -> ", p, p, j, j, k);
        printf(" p_create_pc_%d\' = 17 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Create step 17 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 17 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_create_pc_%d\' = 18 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Create step 18 ---------- */
    // --- return ERROR
     printf("  p_create_pc_%d = 18  ->  p_create_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Create step 19 ---------- */
    // --- dget(file)
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_create_pc_%d = 19 /\\ p_file_%d = %d /\\ d_lock_%d > 0  -> ", p, p, i, i);
        printf(" p_create_pc_%d\' = 20 /\\ d_count_%d\' = d_count_%d + 1\n", p, i, i);
     }
    /* ---------- Create step 20 ---------- */
    // --- spin_lock(inode_lock)
     printf("  p_create_pc_%d = 20 /\\ inode_lock > 0  ->  p_create_pc_%d\' = 21 /\\ inode_lock\' = inode_lock - 1\n", p, p);
    /* ---------- Create step 21 ---------- */
    // --- allocate_inode(file)
     for (int k=2; k<=INODES; k++) {
       printf("  p_create_pc_%d = 21 /\\ p_inode_%d = %d /\\ i_allocated_%d = 0  -> ", p, p, k, k);
       printf(" p_create_pc_%d\' = 22 /\\ i_count_%d\' = 1 /\\ i_allocated_%d\' = 1 /\\ i_mutex_%d\' = 1 /\\ i_lock_%d\' = 1\n", p, k, k, k, k);
       printf("  p_create_pc_%d = 21 /\\ p_inode_%d = %d /\\ i_allocated_%d > 0  -> ", p, p, k, k);
       printf(" p_create_pc_%d\' = 22 /\\ p_inode_%d\' = 0\n", p, p);
     }
    /* ---------- Create step 22 ---------- */
    // --- file.d_inode = &itmp
     for (int i=2; i<=DENTRIES; i++) for (int k=0; k<=INODES; k++) {
       printf("  p_create_pc_%d = 22 /\\ p_file_%d = %d /\\ p_inode_%d = %d  -> ", p, p, i, p, k);
       printf(" p_create_pc_%d\' = 23 /\\ d_inode_%d\' = %d\n", p, i, k);
     }
    /* ---------- Create step 23 ---------- */
    // --- spin_unlock(inode_lock)
     printf("  p_create_pc_%d = 23  ->  p_create_pc_%d\' = 24 /\\ inode_lock\' = inode_lock + 1\n", p, p);
    /* ---------- Create step 24 ---------- */
    // --- if (!file.d_inode->is_allocated)
     printf("  p_create_pc_%d = 24 /\\ p_inode_%d = 0  -> ", p, p);
     printf(" p_create_pc_%d\' = 25\n", p);
     for (int k=1; k<=INODES; k++) {
       printf("  p_create_pc_%d = 24 /\\ p_inode_%d = %d /\\ i_allocated_%d = 0  -> ", p, p, k, k);
       printf(" p_create_pc_%d\' = 25\n", p);
       printf("  p_create_pc_%d = 24 /\\ p_inode_%d = %d /\\ i_allocated_%d > 0  -> ", p, p, k, k);
       printf(" p_create_pc_%d\' = 30\n", p);
     }
    /* ---------- Create step 25 ---------- */
    // --- atomic_write(file.d_count, 0)
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_create_pc_%d = 25 /\\ p_file_%d = %d  -> ", p, p, i);
        printf(" p_create_pc_%d\' = 26 /\\ d_count_%d\' = 0 /\\ d_allocated_%d\' = 0 /\\ d_parent_%d\' = 0\n", p, i, i, i);
     }
    /* ---------- Create step 26 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 26 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_create_pc_%d\' = 27 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Create step 27 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_create_pc_%d = 27  ->  p_create_pc_%d\' = 28 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Create step 28 ---------- */
    // --- up(parent.d_inode->i_mutex)
     for (int j=1; j<=DENTRIES; j++) for (int k=1; k<=INODES; k++) {
        printf("  p_create_pc_%d = 28 /\\ p_parent_%d = %d /\\ d_inode_%d = %d  -> ", p, p, j, j, k);
        printf(" p_create_pc_%d\' = 29 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Create step 29 ---------- */
    // --- return ERROR
     printf("  p_create_pc_%d = 29  ->  p_create_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Create step 30 ---------- */
    // --- update_parent()
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 30 /\\ p_parent_%d = %d  -> ", p, p, j);
       printf(" p_create_pc_%d\' = 31 /\\ d_subdirs_%d\' = d_subdirs_%d + 1\n", p, j, j);
     }
    /* ---------- Create step 31 ---------- */
    // --- path_release(file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_create_pc_%d = 31 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_create_pc_%d\' = 32 /\\ d_count_%d\' = d_count_%d - 1", p, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - 1", j, j); }
       printf("\n");
     }
    /* ---------- Create step 32 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_create_pc_%d = 32  ->  p_create_pc_%d\' = 33 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Create step 33 ---------- */
    // --- up(parent.d_inode->i_mutex)
     for (int j=1; j<=DENTRIES; j++) for (int k=1; k<=INODES; k++) {
        printf("  p_create_pc_%d = 33 /\\ p_parent_%d = %d /\\ d_inode_%d = %d  -> ", p, p, j, j, k);
        printf(" p_create_pc_%d\' = 34 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Create step 34 ---------- */
    // --- return SUCCESS
     printf("  p_create_pc_%d = 34  ->  p_create_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);


     printf("\n");
    /* ---------- Unlink: step 0 ---------- */
    // --- if (!file.is_allocated)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_begin_%d = 2 /\\ p_unlink_pc_%d = 0 /\\ p_file_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, p, i, i);
       printf(" p_unlink_pc_%d\' = 1\n", p);
       printf("  p_begin_%d = 2 /\\ p_unlink_pc_%d = 0 /\\ p_file_%d = %d /\\ d_allocated_%d > 0  -> ", p, p, p, i, i);
       printf(" p_unlink_pc_%d\' = 2\n", p);
     }
    /* ---------- Unlink step 1 ---------- */
    // --- return ERROR
     printf("  p_unlink_pc_%d = 1  ->  p_unlink_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);    
    /* ---------- Unlink: lookup ---------- */
    // --- path_lookup(parent,file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_unlink_pc_%d = 2 /\\ p_file_%d = %d /\\ d_parent_%d = %d /\\ dcache_lock > 0  -> ", p, p, i, i, j);
       printf(" p_unlink_pc_%d\' = 3 /\\ p_parent_%d\' = d_parent_%d /\\ d_count_%d\' = d_count_%d + d_allocated_%d", p, p, i, j, j, j);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d + d_allocated_%d", i, i, i); }
       printf("\n");
     }
    /* ---------- Unlink step 3 ---------- */
    // --- if (is_directory(file))
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_unlink_pc_%d = 3 /\\ p_file_%d = %d /\\ d_subdirs_%d > 0  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 4\n", p);
       printf("  p_unlink_pc_%d = 3 /\\ p_file_%d = %d /\\ d_subdirs_%d = 0  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 6\n", p);
     }
    /* ---------- Unlink step 4 ---------- */
    // --- path_release(file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_unlink_pc_%d = 4 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_unlink_pc_%d\' = 5 /\\ d_count_%d\' = d_count_%d - d_allocated_%d", p, i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - d_allocated_%d", j, j, j); }
       printf("\n");
     }
    /* ---------- Unlink step 5 ---------- */
    // --- return ERROR
     printf("  p_unlink_pc_%d = 5  ->  p_unlink_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);    
    /* ---------- Unlink step 6 ---------- */
    // --- down(file.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_unlink_pc_%d = 6 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_mutex_%d > 0  -> ", p, p, i, i, k, k);
        printf(" p_unlink_pc_%d\' = 7 /\\ i_mutex_%d\' = i_mutex_%d - 1\n", p, k, k);
     }
    /* ---------- Unlink step 7 ---------- */
    // --- spin_lock(dcache_lock)
     printf("  p_unlink_pc_%d = 7 /\\ dcache_lock > 0  ->  p_unlink_pc_%d\' = 8 /\\ dcache_lock\' = dcache_lock - 1\n", p, p);
    /* ---------- Unlink step 8 ---------- */
    // --- while (atomic_read(file.d_count) != 0)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_unlink_pc_%d = 8 /\\ p_file_%d = %d /\\ d_count_%d > 0  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 9\n", p);
       printf("  p_unlink_pc_%d = 8 /\\ p_file_%d = %d /\\ d_count_%d = 0  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 13\n", p);
     }
    /* ---------- Unlink step 9 ---------- */
    // --- spin_lock(file.d_lock)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_unlink_pc_%d = 9 /\\ p_file_%d = %d /\\ d_lock_%d > 0  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 10 /\\ d_lock_%d\' = d_lock_%d - 1\n", p, i, i);
     }
    /* ---------- Unlink step 10 ---------- */
    // --- if (atomic_read(file.d_count) == 2)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_unlink_pc_%d = 10 /\\ p_file_%d = %d /\\ d_count_%d = 2  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 11\n", p);
       printf("  p_unlink_pc_%d = 10 /\\ p_file_%d = %d /\\ d_count_%d != 2  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 12\n", p);
     }
    /* ---------- Unlink step 11 ---------- */
    // --- deallocate(file)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_unlink_pc_%d = 11 /\\ p_file_%d = %d  -> ", p, p, i, i);
       printf(" p_unlink_pc_%d\' = 12 /\\ d_count_%d\' = 0 /\\ d_allocated_%d\' = 0\n", p, i, i);
     }
    /* ---------- Unlink step 12 ---------- */
    // --- spin_unlock(file.d_lock)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_unlink_pc_%d = 12 /\\ p_file_%d = %d  -> ", p, p, i);
       printf(" p_unlink_pc_%d\' = 8 /\\ d_lock_%d\' = d_lock_%d + 1\n", p, i, i);
     }
    /* ---------- Unlink step 13 ---------- */
    // --- spin_lock(inode_lock)
     printf("  p_unlink_pc_%d = 13 /\\ inode_lock > 0  ->  p_unlink_pc_%d\' = 14 /\\ inode_lock\' = inode_lock - 1\n", p, p);
    /* ---------- Unlink step 14 ---------- */
    // --- while (atomic_read(file.d_inode->i_count) != 0)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_unlink_pc_%d = 14 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d > 0  -> ", p, p, i, i, k, k);
       printf(" p_unlink_pc_%d\' = 15\n", p);
       printf("  p_unlink_pc_%d = 14 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d = 0  -> ", p, p, i, i, k, k);
       printf(" p_unlink_pc_%d\' = 19\n", p);
     }
    /* ---------- Unlink step 15 ---------- */
    // --- spin_lock(file.d_inode->i_lock)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_unlink_pc_%d = 15 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_lock_%d > 0  -> ", p, p, i, i, k, k);
       printf(" p_unlink_pc_%d\' = 16 /\\ i_lock_%d\' = i_lock_%d - 1\n", p, k, k);
     }
    /* ---------- Unlink step 16 ---------- */
    // --- if (atomic_read(file.d_inode->i_count) == 1)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_unlink_pc_%d = 16 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d = 1  -> ", p, p, i, i, k, k);
       printf(" p_unlink_pc_%d\' = 17\n", p);
       printf("  p_unlink_pc_%d = 16 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d != 1  -> ", p, p, i, i, k, k);
       printf(" p_unlink_pc_%d\' = 18\n", p);
     }  
    /* ---------- Unlink step 17 ---------- */
    // --- atomic_write(file.d_inode->i_count, 0)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_unlink_pc_%d = 17 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
       printf(" p_unlink_pc_%d\' = 18 /\\ i_count_%d\' = 0 /\\ i_allocated_%d\' = 0\n", p, k, k);
     }
    /* ---------- Unlink step 18 ---------- */
    // --- spin_unlock(file.d_inode->i_lock)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_unlink_pc_%d = 18 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
       printf(" p_unlink_pc_%d\' = 19 /\\ i_lock_%d\' = i_lock_%d + 1\n", p, k, k);
     }
    /* ---------- Unlink step 19 ---------- */
    // --- spin_unlock(inode_lock)
     printf("  p_unlink_pc_%d = 19  ->  p_unlink_pc_%d\' = 20 /\\ inode_lock\' = inode_lock + 1\n", p, p);
    /* ---------- Unlink step 20 ---------- */
    // --- update_parent()
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_unlink_pc_%d = 20 /\\ p_parent_%d = %d /\\ d_subdirs_%d > 0  -> ", p, p, j, j);
       printf(" p_unlink_pc_%d\' = 21 /\\ d_subdirs_%d\' = d_subdirs_%d - 1\n", p, j, j);
     }
    /* ---------- Unlink step 21 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_unlink_pc_%d = 21 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_unlink_pc_%d\' = 22 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Unlink step 22 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_unlink_pc_%d = 22  ->  p_unlink_pc_%d\' = 23 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Unlink step 23 ---------- */
    // --- return SUCCESS
     printf("  p_unlink_pc_%d = 23  ->  p_unlink_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);    

     printf("\n");
    /* ---------- Mkdir: lookup ---------- */
    // --- path_lookup(parent,file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_begin_%d = 3 /\\ p_mkdir_pc_%d = 0 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ dcache_lock > 0  -> ", p, p, p, i, p, j);
       printf(" p_mkdir_pc_%d\' = 1 /\\ d_count_%d\' = d_count_%d + d_allocated_%d", p, j, j, j);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d + d_allocated_%d", i, i, i); }
       printf("\n");
     }
    /* ---------- Mkdir step 1 ---------- */
    // --- if (dir.is_allocated)
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_mkdir_pc_%d = 1 /\\ p_file_%d = %d /\\ d_allocated_%d > 0  -> ", p, p, i, i, i);
        printf(" p_mkdir_pc_%d\' = 2\n", p);
        printf("  p_mkdir_pc_%d = 1 /\\ p_file_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, i, i, i);
        printf(" p_mkdir_pc_%d\' = 4\n", p);
     }
    /* ---------- Mkdir step 2 ---------- */
    // --- path_release(dir)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 2 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_mkdir_pc_%d\' = 3 /\\ d_count_%d\' = d_count_%d - d_allocated_%d", p, i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - d_allocated_%d", j, j, j); }
       printf("\n");
     }
    /* ---------- Mkdir step 3 ---------- */
    // --- return ERROR
     printf("  p_mkdir_pc_%d = 3  ->  p_mkdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
     /* ---------- Mkdir step 4 ---------- */
    // --- if (!parent.is_allocated)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 4 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d > 0 /\\ d_subdirs_%d = 0  -> ", p, p, i, p, j, j, j);
       printf(" p_mkdir_pc_%d\' = 5\n", p);
       printf("  p_mkdir_pc_%d = 4 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, i, p, j, j);
       printf(" p_mkdir_pc_%d\' = 5\n", p);
       printf("  p_mkdir_pc_%d = 4 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d > 0 /\\ d_subdirs_%d > 0  -> ", p, p, i, p, j, j, j);
       printf(" p_mkdir_pc_%d\' = 7\n", p);
     }
    /* ---------- Mkdir step 5 ---------- */
    // --- path_release(dir)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 5 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_mkdir_pc_%d\' = 6 /\\ d_count_%d\' = d_count_%d - d_allocated_%d", p, i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - d_allocated_%d", j, j, j); }
       printf("\n");
     }
    /* ---------- Mkdir step 6 ---------- */
    // --- return ERROR
     printf("  p_mkdir_pc_%d = 6  ->  p_mkdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Mkdir step 7 ---------- */
    // --- spin_lock(dcache_lock)
     printf("  p_mkdir_pc_%d = 7 /\\ dcache_lock > 0  ->  p_mkdir_pc_%d\' = 8 /\\ dcache_lock\' = dcache_lock - 1\n", p, p);    /* ---------- Mkdir step 8 ---------- */
    /* ---------- Mkdir step 8 ---------- */
    // --- allocate_dentry
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {  
       printf("  p_mkdir_pc_%d = 8 /\\ p_file_%d = %d /\\ p_parent_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, i, p, j, i);
       printf(" p_mkdir_pc_%d\' = 9 /\\ d_allocated_%d\' = 1 /\\ d_count_%d\' = 1 /\\ d_lock_%d\' = 1 /\\ d_parent_%d\' = %d\n", p, i, i, i, i, j);
     }
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_mkdir_pc_%d = 8 /\\ p_file_%d = %d /\\ d_allocated_%d > 0  -> ", p, p, i, i);
       printf(" p_mkdir_pc_%d\' = 10\n", p);
     }
    /* ---------- Mkdir step 9 ---------- */
    // --- if (!dir.is_allocated)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 9 /\\ p_parent_%d = %d /\\ d_subdirs_%d = 0  -> ", p, p, j, j);
       printf(" p_mkdir_pc_%d\' = 10\n", p);
       printf("  p_mkdir_pc_%d = 9 /\\ p_parent_%d = %d /\\ d_subdirs_%d > 0  -> ", p, p, j, j);
       printf(" p_mkdir_pc_%d\' = 13\n", p);
     }
    /* ---------- Mkdir step 10 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_mkdir_pc_%d = 10  ->  p_mkdir_pc_%d\' = 11 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Mkdir step 11 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 11 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_mkdir_pc_%d\' = 12 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Mkdir step 12 ---------- */
    // --- return ERROR
     printf("  p_mkdir_pc_%d = 12  ->  p_mkdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Mkdir step 13 ---------- */
    // --- dget(dir)
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_mkdir_pc_%d = 13 /\\ p_file_%d = %d /\\ d_lock_%d > 0  -> ", p, p, i, i);
        printf(" p_mkdir_pc_%d\' = 14 /\\ d_count_%d\' = d_count_%d + 1\n", p, i, i);
     }
    /* ---------- Mkdir step 14 ---------- */
    // --- spin_lock(inode_lock)
     printf("  p_mkdir_pc_%d = 14 /\\ inode_lock > 0  ->  p_mkdir_pc_%d\' = 15 /\\ inode_lock\' = inode_lock - 1\n", p, p);
    /* ---------- Mkdir step 15 ---------- */
    // --- allocate_inode(dir)
     for (int k=2; k<=INODES; k++) {
       printf("  p_mkdir_pc_%d = 15 /\\ p_inode_%d = %d /\\ i_allocated_%d = 0  -> ", p, p, k, k);
       printf(" p_mkdir_pc_%d\' = 16 /\\ i_count_%d\' = 1 /\\ i_allocated_%d\' = 1 /\\ i_mutex_%d\' = 1 /\\ i_lock_%d\' = 1\n", p, k, k, k, k);
       printf("  p_mkdir_pc_%d = 15 /\\ p_inode_%d = %d /\\ i_allocated_%d > 0  -> ", p, p, k, k);
       printf(" p_mkdir_pc_%d\' = 16 /\\ p_inode_%d\' = 0\n", p, p);
     }
    /* ---------- Mkdir step 16 ---------- */
    // --- dir.d_inode = &itmp
     for (int i=2; i<=DENTRIES; i++) for (int k=0; k<=INODES; k++) {
       printf("  p_mkdir_pc_%d = 16 /\\ p_file_%d = %d /\\ p_inode_%d = %d  -> ", p, p, i, p, k);
       printf(" p_mkdir_pc_%d\' = 17 /\\ d_inode_%d\' = %d\n", p, i, k);
     }
    /* ---------- Mkdir step 17 ---------- */
    // --- if (dir.d_inode->is_allocated)
     printf("  p_mkdir_pc_%d = 17 /\\ p_inode_%d = 0  -> ", p, p);
     printf(" p_mkdir_pc_%d\' = 19\n", p);
     for (int k=1; k<=INODES; k++) {
       printf("  p_mkdir_pc_%d = 17 /\\ p_inode_%d = %d /\\ i_allocated_%d = 0  -> ", p, p, k, k);
       printf(" p_mkdir_pc_%d\' = 19\n", p);
       printf("  p_mkdir_pc_%d = 17 /\\ p_inode_%d = %d /\\ i_allocated_%d > 0  -> ", p, p, k, k);
       printf(" p_mkdir_pc_%d\' = 18\n", p);
     }
    /* ---------- Mkdir step 18 ---------- */
    // --- down(dir.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_mkdir_pc_%d = 18 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_mutex_%d > 0  -> ", p, p, i, i, k, k);
        printf(" p_mkdir_pc_%d\' = 19 /\\ i_mutex_%d\' = i_mutex_%d - 1\n", p, k, k);
     }
    /* ---------- Mkdir step 19 ---------- */
    // --- spin_unlock(inode_lock)
     printf("  p_mkdir_pc_%d = 19  ->  p_mkdir_pc_%d\' = 20 /\\ inode_lock\' = inode_lock + 1\n", p, p);
    /* ---------- Mkdir step 20 ---------- */
    // --- if (!dir.d_inode->is_allocated)
     printf("  p_mkdir_pc_%d = 20 /\\ p_inode_%d = 0  -> ", p, p);
     printf(" p_mkdir_pc_%d\' = 21\n", p);
     for (int k=1; k<=INODES; k++) {
       printf("  p_mkdir_pc_%d = 20 /\\ p_inode_%d = %d /\\ i_allocated_%d = 0  -> ", p, p, k, k);
       printf(" p_mkdir_pc_%d\' = 21\n", p);
       printf("  p_mkdir_pc_%d = 20 /\\ p_inode_%d = %d /\\ i_allocated_%d > 0  -> ", p, p, k, k);
       printf(" p_mkdir_pc_%d\' = 25\n", p);
     }
    /* ---------- Mkdir step 21 ---------- */
    // --- atomic_write(dir.d_count, 0)
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_mkdir_pc_%d = 21 /\\ p_file_%d = %d  -> ", p, p, i);
        printf(" p_mkdir_pc_%d\' = 22 /\\ d_count_%d\' = 0 /\\ d_allocated_%d\' = 0 /\\ d_parent_%d\' = 0\n", p, i, i, i);
     }
    /* ---------- Mkdir step 22 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 22 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_mkdir_pc_%d\' = 23 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Mkdir step 23 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_mkdir_pc_%d = 23  ->  p_mkdir_pc_%d\' = 24 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Mkdir step 24 ---------- */
    // --- return ERROR
     printf("  p_mkdir_pc_%d = 24  ->  p_mkdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Mkdir step 25 ---------- */
    // --- dir.subdirs = 1
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_mkdir_pc_%d = 25 /\\ p_file_%d = %d  -> ", p, p, i);
        printf(" p_mkdir_pc_%d\' = 26 /\\ d_subdirs_%d\' = 1\n", p, i);
     }
    /* ---------- Mkdir step 26 ---------- */
    // --- update_parent()
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 26 /\\ p_parent_%d = %d  -> ", p, p, j);
       printf(" p_mkdir_pc_%d\' = 27 /\\ d_subdirs_%d\' = d_subdirs_%d + 1\n", p, j, j);
     }
    /* ---------- Mkdir step 27 ---------- */
    // --- path_release(dir)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_mkdir_pc_%d = 27 /\\ p_file_%d = %d /\\ p_parent_%d = %d  -> ", p, p, i, p, j);
       printf(" p_mkdir_pc_%d\' = 28 /\\ d_count_%d\' = d_count_%d - 1", p, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - 1", j, j); }
       printf("\n");
     }
    /* ---------- Mkdir step 28 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_mkdir_pc_%d = 28  ->  p_mkdir_pc_%d\' = 29 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Mkdir step 29 ---------- */
    // --- up(dir.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_mkdir_pc_%d = 29 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
        printf(" p_mkdir_pc_%d\' = 30 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Mkdir step 30 ---------- */
    // --- return SUCCESS
     printf("  p_mkdir_pc_%d = 30  ->  p_mkdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);

     printf("\n");
    /* ---------- Rmdir step 0 ---------- */
    // --- if (!dir.is_allocated)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_begin_%d = 4 /\\ p_rmdir_pc_%d = 0 /\\ p_file_%d = %d /\\ d_allocated_%d = 0  -> ", p, p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 1\n", p);
       printf("  p_begin_%d = 4 /\\ p_rmdir_pc_%d = 0 /\\ p_file_%d = %d /\\ d_allocated_%d > 0  -> ", p, p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 2\n", p);
     }
    /* ---------- Rmdir step 1 ---------- */
    // --- return ERROR
     printf("  p_rmdir_pc_%d = 1  ->  p_rmdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Rmdir: lookup ---------- */
    // --- path_lookup(parent,file)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_rmdir_pc_%d = 2 /\\ p_file_%d = %d /\\ d_parent_%d = %d /\\ dcache_lock > 0  -> ", p, p, i, i, j);
       printf(" p_rmdir_pc_%d\' = 3 /\\ p_parent_%d\' = d_parent_%d /\\ d_count_%d\' = d_count_%d + d_allocated_%d", p, p, i, j, j, j);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d + d_allocated_%d", i, i, i); }
       printf("\n");
     }
    /* ---------- Rmdir step 3 ---------- */
    // --- if (!is_directory(dir))
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 3 /\\ p_file_%d = %d /\\ d_subdirs_%d = 0  -> ", p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 4\n", p);  
       printf("  p_rmdir_pc_%d = 3 /\\ p_file_%d = %d /\\ d_subdirs_%d > 0  -> ", p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 6\n", p);
     }
    /* ---------- Rmdir step 4 ---------- */
    // --- path_release(dir)
     for (int i=2; i<=DENTRIES; i++) for (int j=1; j<=DENTRIES; j++) {
       printf("  p_rmdir_pc_%d = 4 /\\ p_file_%d = %d /\\ d_parent_%d = %d  -> ", p, p, i, i, j);
       printf(" p_rmdir_pc_%d\' = 5 /\\ d_count_%d\' = d_count_%d - d_allocated_%d", p, i, i, i);
       if (i!=j) { printf(" /\\ d_count_%d\' = d_count_%d - d_allocated_%d", j, j, j); }
       printf("\n");
     }
    /* ---------- Rmdir step 5 ---------- */
    // --- return ERROR
     printf("  p_rmdir_pc_%d = 5  ->  p_rmdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Rmdir step 6 ---------- */
    // --- spin_lock(dcache_lock)
     printf("  p_rmdir_pc_%d = 6 /\\ dcache_lock > 0  ->  p_rmdir_pc_%d\' = 7 /\\ dcache_lock\' = dcache_lock - 1\n", p, p);
    /* ---------- Rmdir step 7 ---------- */
    // --- down(dir.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_rmdir_pc_%d = 7 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_mutex_%d > 0  -> ", p, p, i, i, k, k);
        printf(" p_rmdir_pc_%d\' = 8 /\\ i_mutex_%d\' = i_mutex_%d - 1\n", p, k, k);
     }
    /* ---------- Rmdir step 8 ---------- */
    // --- if (#children != 0)
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_rmdir_pc_%d = 8 /\\ p_file_%d = %d /\\ d_subdirs_%d > 1  -> ", p, p, i, i);
        printf(" p_rmdir_pc_%d\' = 9\n", p);
        printf("  p_rmdir_pc_%d = 8 /\\ p_file_%d = %d /\\ d_subdirs_%d < 2  -> ", p, p, i, i);
        printf(" p_rmdir_pc_%d\' = 14\n", p);
     }
    /* ---------- Rmdir step 9 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_rmdir_pc_%d = 9  ->  p_rmdir_pc_%d\' = 10 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Rmdir step 10 ---------- */
    // --- up(dir.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_rmdir_pc_%d = 10 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
        printf(" p_rmdir_pc_%d\' = 11 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Rmdir step 11 ---------- */
    // --- dput(dir)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 11 /\\ p_file_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, i, i, i);
       printf(" p_rmdir_pc_%d\' = 12 /\\ d_count_%d\' = d_count_%d - 1\n", p, i, i);
     }
    /* ---------- Rmdir step 12 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_rmdir_pc_%d = 12 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_rmdir_pc_%d\' = 13 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Rmdir step 13 ---------- */
    // --- return ERROR
     printf("  p_rmdir_pc_%d = 13  ->  p_rmdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Rmdir step 14 ---------- */
    // --- if (dir.d_inode->i_state & DELETING)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 14 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_state_%d = 1  -> ", p, p, i, i, k, k);
       printf(" p_rmdir_pc_%d\' = 38\n", p);
       printf("  p_rmdir_pc_%d = 14 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_state_%d = 0  -> ", p, p, i, i, k, k);
       printf(" p_rmdir_pc_%d\' = 19\n", p);
     }
    /* ---------- Rmdir step 14b ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_rmdir_pc_%d = 38  ->  p_rmdir_pc_%d\' = 15 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Rmdir step 15 ---------- */
    // --- dput(dir)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 15 /\\ p_file_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, i, i, i);
       printf(" p_rmdir_pc_%d\' = 16 /\\ d_count_%d\' = d_count_%d - 1\n", p, i, i);
     }
    /* ---------- Rmdir step 16 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_rmdir_pc_%d = 16 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_rmdir_pc_%d\' = 17 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Rmdir step 17 ---------- */
    // --- up(dir.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_rmdir_pc_%d = 17 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
        printf(" p_rmdir_pc_%d\' = 18 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Rmdir step 18 ---------- */
    // --- return SUCCESS
     printf("  p_rmdir_pc_%d = 18  ->  p_rmdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
    /* ---------- Rmdir step 19 ---------- */
    // --- dir.d_inode->i_state |= DELETING
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 19 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
       printf(" p_rmdir_pc_%d\' = 20 /\\ i_state_%d\' = 1\n", p, k);
     }
    /* ---------- Rmdir step 20 ---------- */
    // --- up(dir.d_inode->i_mutex)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
        printf("  p_rmdir_pc_%d = 20 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
        printf(" p_rmdir_pc_%d\' = 21 /\\ i_mutex_%d\' = i_mutex_%d + 1\n", p, k, k);
     }
    /* ---------- Rmdir step 21 ---------- */
    // --- dir.d_parent = &dNULL
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 21 /\\ p_file_%d = %d  -> ", p, p, i);
       printf(" p_rmdir_pc_%d\' = 22 /\\ d_parent_%d\' = 0\n", p, i);
     }
    /* ---------- Rmdir step 22 ---------- */
    // --- update_parent()
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_rmdir_pc_%d = 22 /\\ p_parent_%d = %d /\\ d_subdirs_%d > 0  -> ", p, p, j, j);
       printf(" p_rmdir_pc_%d\' = 23 /\\ d_subdirs_%d\' = d_subdirs_%d - 1\n", p, j, j);
     }
    /* ---------- Rmdir step 23 ---------- */
    // --- dput(parent)
     for (int j=1; j<=DENTRIES; j++) {
       printf("  p_rmdir_pc_%d = 23 /\\ p_parent_%d = %d /\\ d_lock_%d > 0 /\\ d_count_%d > 0  -> ", p, p, j, j, j);
       printf(" p_rmdir_pc_%d\' = 24 /\\ d_count_%d\' = d_count_%d - 1\n", p, j, j);
     }
    /* ---------- Rmdir step 24 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_rmdir_pc_%d = 24  ->  p_rmdir_pc_%d\' = 25 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Rmdir step 25 ---------- */
    // --- while (!wait_done)
     printf("  p_rmdir_pc_%d = 25 /\\ p_rmdir_wait_%d = 0  ->  p_rmdir_pc_%d\' = 26\n", p, p, p);
     printf("  p_rmdir_pc_%d = 25 /\\ p_rmdir_wait_%d > 0  ->  p_rmdir_pc_%d\' = 37 /\\ p_rmdir_wait_%d\' = 0\n", p, p, p, p);
    /* ---------- Rmdir step 26 ---------- */
    // --- spin_lock(dcache_lock)
     printf("  p_rmdir_pc_%d = 26 /\\ dcache_lock > 0  ->  p_rmdir_pc_%d\' = 27 /\\ dcache_lock\' = dcache_lock - 1\n", p, p);
    /* ---------- Rmdir step 27 ---------- */
    // --- spin_lock(dir.d_lock)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 27 /\\ p_file_%d = %d /\\ d_lock_%d > 0  -> ", p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 28 /\\ d_lock_%d\' = d_lock_%d - 1\n", p, i, i);
     }
    /* ---------- Rmdir step 28 ---------- */
    // --- if (atomic_read(dir.d_count) == 2)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 28 /\\ p_file_%d = %d /\\ d_count_%d = 2  -> ", p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 29\n", p);
       printf("  p_rmdir_pc_%d = 28 /\\ p_file_%d = %d /\\ d_count_%d != 2  -> ", p, p, i, i);
       printf(" p_rmdir_pc_%d\' = 35\n", p);
     }
    /* ---------- Rmdir step 29 ---------- */
    // --- spin_lock(dir.d_inode->i_lock)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 29 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_lock_%d > 0  -> ", p, p, i, i, k, k);
       printf(" p_rmdir_pc_%d\' = 30 /\\ i_lock_%d\' = i_lock_%d - 1\n", p, k, k);
     }
    /* ---------- Rmdir step 30 ---------- */
    // --- dir.d_inode->i_count--
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 30 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d > 0  -> ", p, p, i, i, k, k);
       printf(" p_rmdir_pc_%d\' = 31 /\\ i_count_%d\' = i_count_%d - 1\n", p, k, k);
     }
    /* ---------- Rmdir step 31 ---------- */
    // --- if (atomic_read(dir.d_inode->i_count) >= 1)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 31 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d > 0  -> ", p, p, i, i, k, k);
       printf(" p_rmdir_pc_%d\' = 32\n", p);
       printf("  p_rmdir_pc_%d = 31 /\\ p_file_%d = %d /\\ d_inode_%d = %d /\\ i_count_%d = 0  -> ", p, p, i, i, k, k);
       printf(" p_rmdir_pc_%d\' = 39\n", p);
     }
    /* ---------- Rmdir step 32 ---------- */
    // --- dir.d_inode->i_state ^= DELETING
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 32 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
       printf(" p_rmdir_pc_%d\' = 33 /\\ i_state_%d\' = 0\n", p, k);
     }
    /* ---------- Rmdir step 32b ---------- */
    // --- deallocate inode ---
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 39 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
       printf(" p_rmdir_pc_%d\' = 33 /\\ i_state_%d\' = 0 /\\ i_allocated_%d\' = 0\n", p, k, k);
     }
    /* ---------- Rmdir step 33 ---------- */
    // --- spin_unlock(dir.d_inode->i_lock)
     for (int i=2; i<=DENTRIES; i++) for (int k=1; k<=INODES; k++) {
       printf("  p_rmdir_pc_%d = 33 /\\ p_file_%d = %d /\\ d_inode_%d = %d  -> ", p, p, i, i, k);
       printf(" p_rmdir_pc_%d\' = 34 /\\ i_lock_%d\' = i_lock_%d + 1\n", p, k, k);
     }
    /* ---------- Rmdir step 34 ---------- */
    // --- atomic_write(dir.d_count, 0);
     for (int i=2; i<=DENTRIES; i++) {
        printf("  p_rmdir_pc_%d = 34 /\\ p_file_%d = %d  -> ", p, p, i);
        printf(" p_rmdir_pc_%d\' = 35 /\\ d_count_%d\' = 0 /\\ d_allocated_%d\' = 0 /\\ d_parent_%d\' = 0 /\\", p, i, i, i);
        printf(" p_rmdir_wait_%d\' = 1 /\\ d_subdirs_%d\' = 0 /\\ d_inode_%d\' = 0\n", p, i, i);
     }
    /* ---------- Rmdir step 35 ---------- */
    // --- spin_unlock(dir.d_lock)
     for (int i=2; i<=DENTRIES; i++) {
       printf("  p_rmdir_pc_%d = 35 /\\ p_file_%d = %d  -> ", p, p, i);
       printf(" p_rmdir_pc_%d\' = 36 /\\ d_lock_%d\' = d_lock_%d + 1\n", p, i, i);
     }
    /* ---------- Rmdir step 36 ---------- */
    // --- spin_unlock(dcache_lock)
     printf("  p_rmdir_pc_%d = 36  ->  p_rmdir_pc_%d\' = 25 /\\ dcache_lock\' = dcache_lock + 1\n", p, p);
    /* ---------- Rmdir step 37 ---------- */
    // --- return SUCCESS
     printf("  p_rmdir_pc_%d = 37  ->  p_rmdir_pc_%d\' = 0 /\\ p_begin_%d\' = 0\n", p, p, p);
   }
}

void Spec() {
  if (spec) {
    printf("Properties\n");
    printf("  !EX(true)\n");
  }
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-spec")==0) {
      spec = true;
    }
    else if (strcmp(argv[i], "-p")==0 && i<argc-1) {
      PROCS = atoi(argv[i+1]);
      if (PROCS<1) {
        fprintf(stderr, " ERROR: illegal number of processes, %d.\n", PROCS);
        return 2;
      }
    }
    else if (strcmp(argv[i], "-d")==0 && i<argc-1) {
      DENTRIES = atoi(argv[i+1]);
      if (DENTRIES<2) {
        fprintf(stderr, " ERROR: illegal number of processes, %d.\n", DENTRIES);
        return 3;
      }
    }
    else if (strcmp(argv[i], "-i")==0 && i<argc-1) {
      INODES = atoi(argv[i+1]);
      if (INODES<2) {
        fprintf(stderr, " ERROR: illegal number of processes, %d.\n", INODES);
        return 3;
      }
    }
  }

  Init();
  Trans();
  Spec();	
  return 0;
}
