
//Will solve

class Solution {
public:
	bool digitcheck(int n,vector<int> nums)
	{
		vector<int>temp(10);
		for(int i=n;i>0;i/=10)
		{
			temp[i%10]++;
		}
		for(int i=0;i<10;i++)
		{
			if(nums[i]!=temp[i])
				return false;
		}
		return true;
	}
	bool reorderedPowerOf2(int n) {
		vector<int> nums(10);
		for(int i=n;i>0;i/=10)
		{
			nums[i%10]++;
		}
		int t=1;
		for(int i=0;i<30;i++)
		{
			if(digitcheck(t,nums))
				return true;
			t=t*2;
		}
		return false;
	}
};