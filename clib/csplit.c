#include <stdlib.h>
#include <string.h>
#include "csplit.h"

int strsplit (const char *str, char *ans[], const char *delimiter) {
	char *cut_str; //切割後字串
	int i = 0;
	char *copy = NULL;
	char *tmp = NULL;
	/*
	strdup函數原型：
	strdup()主要是複製s的一個副本，由函數回傳值返回，這個副本有自己的記憶體空間，和s不相關。
	strdup函數複製一個字串，使用完後要記得删除在函數中動態取得的記憶體，strdup函數的參數不能為NULL，一旦是NULL，就會有區段錯誤，
	因為該函數包括了strlen函數，而該函數參數不能是NULL。
	*/
	copy = strdup(str); //假設回傳NULL
	if (!copy)
		goto bad; //這個一定要用free(),釋放記憶體空間

	cut_str = strtok(copy, delimiter);

	tmp = strdup(cut_str);
	if (!tmp)
		goto bad;

	ans[i++] = tmp;

	while (cut_str) {
		cut_str = strtok(NULL, delimiter);
		if (NULL == cut_str)
			break;
		tmp = strdup(cut_str);
		if (!tmp)
			goto bad;
		ans[i++] = tmp;
	}

	free(copy);
	return i;

	bad:
	free(copy);
	int j;
	for (j = 0; j < i; j++)
		free(ans[j]);
	return -1;
}