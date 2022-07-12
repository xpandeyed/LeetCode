class Solution {
public:
	int knightDialer(int N) {
		long kMod=1e9+7;
		long hop1=1; // number of ways to form a distinct number ending with key 1
		long hop2=1;
		long hop3=1;
		long hop4=1;
		long hop5=1;
		long hop6=1;
		long hop7=1;
		long hop8=1;
		long hop9=1;
		long hop0=1;

		if(N==1) return 10;
		for(int i=2;i<=N;i++)
		{
			long old_1=hop1;
			long old_2=hop2;
			long old_3=hop3;
			long old_4=hop4;
			long old_5=hop5;
			long old_6=hop6;
			long old_7=hop7;
			long old_8=hop8;
			long old_9=hop9;
			long old_0=hop0;

			hop1=(old_6+old_8)%kMod;
			hop2=(old_7+old_9)%kMod;
			hop3=(old_4+old_8)%kMod;
			hop4=(old_3+old_9+old_0)%kMod;
			hop5=0;
			hop6=(old_1+old_7+old_0)%kMod;
			hop7=(old_2+old_6)%kMod;
			hop8=(old_1+old_3)%kMod;
			hop9=(old_2+old_4)%kMod;
			hop0=(old_4+old_6)%kMod;
		}

		return (hop1+hop2+hop3+hop4+hop6+hop7+hop8+hop9+hop0)%kMod;


	}
};