/*
 * =====================================================================================
 *
 *       Filename:  193.c
 *
 *    Description:  Graph Coloring
 *
 *        Created:  11.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

应该是将顶点序号大小作为搜索顺序，
而我采用一般的按图的搜索进行。
这样的话就是n^n,因为每次都会扩展n个节点。
而顺序搜索则需扩展2个节点即可，2^n。
在加上剪枝，时间还是很客观的。

#include <stdio.h>

int main(int argc, const char *argv[])
{
	
	return 0;
}
