#pragma once
/*  创建文件夹用
#include"createfolder.h" 
 */
#include<direct.h>
#include<io.h>
void createfolder(const char *p) {
	for (int i = 0; p[i] != '\0'; i++) {
		int j;
		char z[100];
		if (p[i] == '\\') {
			j = i - 1;
			int m;
			for (m = 0; m <= j; m++) {
				z[m] = p[m];
			}
			z[m] = '\0';
			if (_access(z, 0) == -1)
				_mkdir(z);
		}

	}
	if (_access(p, 0) == -1)
		_mkdir(p);


}











