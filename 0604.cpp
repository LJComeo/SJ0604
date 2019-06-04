#include <iostream>
#include<ctime>
using  namespace std;
const int maxn = 1000 + 10;
int compare_cnt;
int binarySearch(char*a, int len, char x)//折半查找
{
	int mid;// 中间下标
	int low = 0;// 区间的左端下标
	int high = len - 1;// 区间的右端下标
	compare_cnt = 0;
	while (low <= high)
	{
		compare_cnt++;
		mid = low + (high - low) / 2;// 计算中间下标， 若使用(low+high)/2可能会有整数溢出：当low和high的值较大时(接近整型数所能表示的范围),low+high的值就会溢出
		if (x == a[mid])
			return mid;// 若找到返回元素的下标
		else if (x > a[mid])
			low = mid + 1;// 在右半边区间搜索
		else
			high = mid - 1;// 在左半边区间搜索
	}
	return -1;// 没有找到
}
void quickSort(char *a, int left, int right){//快速排序
	int i = left;
	int j = right;
	int temp = a[left];
	if (left >= right) return;
	while (i != j) {
		while (i<j&&a[j] >= temp)
			j--;
		if (j>i)
			a[i] = a[j];//a[i]已经赋值给temp,所以直接将a[j]赋值给a[i],赋值完之后a[j],有空位　　　　
		while (i<j&&a[i] <= temp)
			i++;
		if (i<j)
			a[j] = a[i];
	}
	a[i] = temp;//把基准插入,此时i与j已经相等R[low..pivotpos-1].keys≤R[pivotpos].key≤R[pivotpos+1..high].keys　　
	quickSort(a, left, i - 1);//递归左边
	quickSort(a, i + 1, right);//递归右边
}
int main(){
	char str[maxn];
	int vis[maxn];
	memset(vis, 0, sizeof(vis));
	time_t t;
	srand((unsigned)time(&t));//由时间确定随机序列，执行一次
	int n, cnt = 0;
	cout << "请输入数组的元素的个数：";//（1）请输入随机数组的元素个数
	cin >> n;
	while (cnt <= n - 1){//（2）生成n个随机元素，并且唯一
		char c = char(rand() % 26 + 'a');
		if (vis[c - 'a'] == 0){
			vis[c - 'a'] = 1;
			str[cnt++] = c;
		}
	}
	cout << "生成的随机元素为：";
	char temp;
	for (int i = 0; i<n; i++)//（3）将生成的n个随机元素输出
		printf("%c%c", str[i], i == n - 1 ? '\n' : ' ');
	cout << "排序后的随机元素为：";
	quickSort(str, 0, n - 1);//（6）开始折半查找之前先给随机数组进行排序
	for (int i = 0; i<n; i++)//（7）将生成的n个排序后的随机元素输出
		printf("%c%c", str[i], i == n - 1 ? '\n' : ' ');
	cout << "折半查找数组的元素请输入元素的内容，跳过请输入$：";
	cin >> temp;//（8）输入一个元素，折半查找该元素是否在随机数组中，当输入'$'时，结束折半查找
	while (temp != '$'){
		int pos = binarySearch(str, n, temp);//（9）折半查找，查找成功返回下标，查找失败返回-1
		if (pos == -1){
			cout << "查找失败，该元素在数组中不存在,比较次数为：" << compare_cnt << endl;
		}
		else{
			cout << "查找成功，元素" << temp << "数组的第" << pos << "位," << "比较次数为：" << compare_cnt << endl;
		}
		cout << "折半查找数组的元素请输入元素的内容，跳过请输入$：";
		cin >> temp;
	}
	return 0;
}

