/* author: dongchangzhang */
/* time: 2017年05月18日 星期四 16时48分58秒 */

#ifndef OPERATION_H
#define OPERATION_H

void init();

int create_data(char* rel, char* col1, int begin1, int end1, char* col2, int begin2, int end2, int times);

int liner_search(char* rel, char* col, int op, int value);

int binary_search(char* rel, char* col, int op, int value);

int project(char* rel, char* col);

int join(int addr1, int addr2);

int intersect(int addr1, int addr2);

int except(int addr1, int addr2);

int nested_loop_join(int addr1, int addr2, int which1, int which2);

int sort_merge_join(int addr1, int addr2, int which1, int which2);

int hash_join(char* rel1, char* rel2);

int search_hash_index(char* rel, int key);

#endif