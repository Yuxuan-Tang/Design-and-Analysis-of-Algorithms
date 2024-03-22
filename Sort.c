#include <stdio.h>

//冒泡排序
void Bubble_Sort(int arr[],int length) {
	for (int j = 0; j < length - 1; j++) { //外层循环，次数为序列长度减一
		for (int i = 0; i < length - 1 - j; i++) { //内层循环，每经历一次外层循环，内层循环次数-1
			if (arr[i] > arr[i + 1]) {
				//定义一个中间变量tmp，实现邻近的两个元素之间的交换，保证每轮循环后最大的元素位于待排序序列的最后
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	return;
}

//快速排序
void Quick_sort(int arr[], int left, int right) { //left为左下标，right为右下标
	if (left >= right)
		return;  //左下标大于等于右下标说明该序列已排序完成
	else if (left < right) {
		int pivot = arr[left]; // 取第一个元素作为基准
		int i = left, j = right;
		while (i < j) {
			while (i < j && arr[j] >= pivot) // 从右向左找第一个小于基准的元素
				j--; 
			if (i < j)
				arr[i++] = arr[j]; //将小于基准的元素置于左下标所指的位置，并且左下标加1，即i + 1
			while (i < j && arr[i] < pivot) // 从左向右找第一个大于或等于基准的元素
				i++; 
			if (i < j)
				arr[j--] = arr[i]; //将大于基准的元素置于右下标所指的位置，并且右下标减1，即j - 1
		}
		arr[i] = pivot; //将基准元素放在i与j重合的位置
		//递归调用
		Quick_sort(arr, left, i - 1); // 对基准左边的子数组进行快速排序
		Quick_sort(arr, i + 1, right); // 对基准右边的子数组进行快速排序
	}
}

/*本次实验数据中数组长度为15
实验数据为：99 65 42 31 3 48 77 25 84 185 34 11 39 55 88*/

//数据的输入、处理与输出
int main() {
	int arr[15] = { 0 };  //初始化数组，长度为15
	printf("请输入你要进行排序的数组，数组长度限制为15，各数字之间请用空格隔开：\n");
	for (int i = 0; i < 15; i++) {
		//利用scanf函数提取待排序数组中的每个元素，实现数据输入功能
		scanf_s("%d", &arr[i]);
	}
	//两种排序二选一，不需要的排序方法注释掉即可
	Bubble_Sort(arr, 15);
	Quick_sort(arr, 0, 14);
	printf("\n排序后的数字如下：\n");
	for (int i = 0; i < 15; i++)
	{
		//利用for循环和printf函数实现数据输出功能
		printf("%d  ", arr[i]);
	}
}