#include <stdio.h>

//ð������
void Bubble_Sort(int arr[],int length) {
	for (int j = 0; j < length - 1; j++) { //���ѭ��������Ϊ���г��ȼ�һ
		for (int i = 0; i < length - 1 - j; i++) { //�ڲ�ѭ����ÿ����һ�����ѭ�����ڲ�ѭ������-1
			if (arr[i] > arr[i + 1]) {
				//����һ���м����tmp��ʵ���ڽ�������Ԫ��֮��Ľ�������֤ÿ��ѭ��������Ԫ��λ�ڴ��������е����
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	return;
}

//��������
void Quick_sort(int arr[], int left, int right) { //leftΪ���±꣬rightΪ���±�
	if (left >= right)
		return;  //���±���ڵ������±�˵�����������������
	else if (left < right) {
		int pivot = arr[left]; // ȡ��һ��Ԫ����Ϊ��׼
		int i = left, j = right;
		while (i < j) {
			while (i < j && arr[j] >= pivot) // ���������ҵ�һ��С�ڻ�׼��Ԫ��
				j--; 
			if (i < j)
				arr[i++] = arr[j]; //��С�ڻ�׼��Ԫ���������±���ָ��λ�ã��������±��1����i + 1
			while (i < j && arr[i] < pivot) // ���������ҵ�һ�����ڻ���ڻ�׼��Ԫ��
				i++; 
			if (i < j)
				arr[j--] = arr[i]; //�����ڻ�׼��Ԫ���������±���ָ��λ�ã��������±��1����j - 1
		}
		arr[i] = pivot; //����׼Ԫ�ط���i��j�غϵ�λ��
		//�ݹ����
		Quick_sort(arr, left, i - 1); // �Ի�׼��ߵ���������п�������
		Quick_sort(arr, i + 1, right); // �Ի�׼�ұߵ���������п�������
	}
}

/*����ʵ�����������鳤��Ϊ15
ʵ������Ϊ��99 65 42 31 3 48 77 25 84 185 34 11 39 55 88*/

//���ݵ����롢���������
int main() {
	int arr[15] = { 0 };  //��ʼ�����飬����Ϊ15
	printf("��������Ҫ������������飬���鳤������Ϊ15��������֮�����ÿո������\n");
	for (int i = 0; i < 15; i++) {
		//����scanf������ȡ�����������е�ÿ��Ԫ�أ�ʵ���������빦��
		scanf_s("%d", &arr[i]);
	}
	//���������ѡһ������Ҫ�����򷽷�ע�͵�����
	Bubble_Sort(arr, 15);
	Quick_sort(arr, 0, 14);
	printf("\n�������������£�\n");
	for (int i = 0; i < 15; i++)
	{
		//����forѭ����printf����ʵ�������������
		printf("%d  ", arr[i]);
	}
}