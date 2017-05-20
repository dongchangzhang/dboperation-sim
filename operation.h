/* author: dongchangzhang */
/* time: 2017年05月18日 星期四 16时48分58秒 */

#ifndef OPERATION_H
#define OPERATION_H

void init();

/* create data */
int create_data(char* rel, char* col1, int begin1, int end1, char* col2, int begin2, int end2, int times);

int read_data(int addr);

int liner_search(char* rel, char* col, int op, int value);


int combine(int addr1, int addr2);

int intersect(int addr1, int addr2);

int except(int addr1, int addr2);

#endif