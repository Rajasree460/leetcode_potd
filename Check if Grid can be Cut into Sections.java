class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) 
    {
		int l = rectangles.length;
		int[][] horizontal = new int[l][2], vertical = new int[l][2];
		
		for(int i=0;i<l;i++)
		{
			horizontal[i][0]=rectangles[i][0];
			horizontal[i][1]=rectangles[i][2];
			vertical[i][0]=rectangles[i][1];
			vertical[i][1]=rectangles[i][3];
		}
		
		Arrays.sort(horizontal, (a,b) -> a[0]-b[0]);
		Arrays.sort(vertical, (a,b) -> a[0]-b[0]);
				
		return findCuts(horizontal) || findCuts(vertical);
    }
	
	public boolean findCuts(int axis[][])
	{
		int count=0, cut=1;
		
		for(int curr[]:axis)
		{
			if(curr[0]>=cut)
			{
				count++;
			}
			
			cut = Math.max(cut, curr[1]);
			
			if(count>=2)
			{
				return true;
			}
		}
		
		return false;
	}
}
