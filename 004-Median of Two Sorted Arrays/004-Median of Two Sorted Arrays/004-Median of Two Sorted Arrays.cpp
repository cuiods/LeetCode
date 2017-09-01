// 004-Median of Two Sorted Arrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> tempV;
		int m = nums1.size(), n = nums2.size();
		if (m > n) {
			int temp = m; m = n; n = temp;
			tempV = nums1; nums1 = nums2; nums2 = tempV;
		}
		int istart = 0, iend = m, halfLen = (m+n+1) / 2;
		while (istart <= iend) {
			int i = (istart + iend) / 2;
			int j = halfLen - i;
			if (i < iend && nums2[j-1] > nums1[i]) {
				istart ++;
			} else if (i > istart && nums1[i-1] > nums2[j]) {
				iend --;
			} else {
				int maxLeft = 0;
				if (i == 0) maxLeft = nums2[j-1];
				else if (j == 0) maxLeft = nums1[i-1];
				else maxLeft = max(nums1[i-1], nums2[j-1]);
				if ((m+n)%2 == 1) return maxLeft;

				int minRight = 0;
				if (i == m) minRight = nums2[j];
				else if (j == n) minRight = nums1[i];
				else minRight = min(nums1[i], nums2[j]);
				return (maxLeft+minRight) / 2.0;
			}
		}
		return 0;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int myints1[] = {1,5};
	vector<int> nums1 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
	int myints2[] = {2,3,4,6};
	vector<int> nums2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
	cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
	return 0;
}

