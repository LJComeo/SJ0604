#include <iostream>
#include<ctime>
using  namespace std;
const int maxn = 1000 + 10;
int compare_cnt;
int binarySearch(char*a, int len, char x)//�۰����
{
	int mid;// �м��±�
	int low = 0;// ���������±�
	int high = len - 1;// ������Ҷ��±�
	compare_cnt = 0;
	while (low <= high)
	{
		compare_cnt++;
		mid = low + (high - low) / 2;// �����м��±꣬ ��ʹ��(low+high)/2���ܻ��������������low��high��ֵ�ϴ�ʱ(�ӽ����������ܱ�ʾ�ķ�Χ),low+high��ֵ�ͻ����
		if (x == a[mid])
			return mid;// ���ҵ�����Ԫ�ص��±�
		else if (x > a[mid])
			low = mid + 1;// ���Ұ����������
		else
			high = mid - 1;// ��������������
	}
	return -1;// û���ҵ�
}
void quickSort(char *a, int left, int right){//��������
	int i = left;
	int j = right;
	int temp = a[left];
	if (left >= right) return;
	while (i != j) {
		while (i<j&&a[j] >= temp)
			j--;
		if (j>i)
			a[i] = a[j];//a[i]�Ѿ���ֵ��temp,����ֱ�ӽ�a[j]��ֵ��a[i],��ֵ��֮��a[j],�п�λ��������
		while (i<j&&a[i] <= temp)
			i++;
		if (i<j)
			a[j] = a[i];
	}
	a[i] = temp;//�ѻ�׼����,��ʱi��j�Ѿ����R[low..pivotpos-1].keys��R[pivotpos].key��R[pivotpos+1..high].keys����
	quickSort(a, left, i - 1);//�ݹ����
	quickSort(a, i + 1, right);//�ݹ��ұ�
}
int main(){
	char str[maxn];
	int vis[maxn];
	memset(vis, 0, sizeof(vis));
	time_t t;
	srand((unsigned)time(&t));//��ʱ��ȷ��������У�ִ��һ��
	int n, cnt = 0;
	cout << "�����������Ԫ�صĸ�����";//��1����������������Ԫ�ظ���
	cin >> n;
	while (cnt <= n - 1){//��2������n�����Ԫ�أ�����Ψһ
		char c = char(rand() % 26 + 'a');
		if (vis[c - 'a'] == 0){
			vis[c - 'a'] = 1;
			str[cnt++] = c;
		}
	}
	cout << "���ɵ����Ԫ��Ϊ��";
	char temp;
	for (int i = 0; i<n; i++)//��3�������ɵ�n�����Ԫ�����
		printf("%c%c", str[i], i == n - 1 ? '\n' : ' ');
	cout << "���������Ԫ��Ϊ��";
	quickSort(str, 0, n - 1);//��6����ʼ�۰����֮ǰ�ȸ���������������
	for (int i = 0; i<n; i++)//��7�������ɵ�n�����������Ԫ�����
		printf("%c%c", str[i], i == n - 1 ? '\n' : ' ');
	cout << "�۰���������Ԫ��������Ԫ�ص����ݣ�����������$��";
	cin >> temp;//��8������һ��Ԫ�أ��۰���Ҹ�Ԫ���Ƿ�����������У�������'$'ʱ�������۰����
	while (temp != '$'){
		int pos = binarySearch(str, n, temp);//��9���۰���ң����ҳɹ������±꣬����ʧ�ܷ���-1
		if (pos == -1){
			cout << "����ʧ�ܣ���Ԫ���������в�����,�Ƚϴ���Ϊ��" << compare_cnt << endl;
		}
		else{
			cout << "���ҳɹ���Ԫ��" << temp << "����ĵ�" << pos << "λ," << "�Ƚϴ���Ϊ��" << compare_cnt << endl;
		}
		cout << "�۰���������Ԫ��������Ԫ�ص����ݣ�����������$��";
		cin >> temp;
	}
	return 0;
}

