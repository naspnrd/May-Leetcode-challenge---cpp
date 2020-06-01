Find the Town Judge - 997

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3

 

Constraints:

    1 <= N <= 1000
    0 <= trust.length <= 10^4
    trust[i].length == 2
    trust[i] are all different
    trust[i][0] != trust[i][1]
    1 <= trust[i][0], trust[i][1] <= N

	code:
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<int> count(N,0);
        //lets we have (1,2) apir then i[0] will denote 1 nd i[1] denotes 2
        // so we will decrement the count of i[0] because if anyone trust someone else then he is not the           //candidate of judge because trust not trust anyone so it cant have an outgoing edge
        //so we increase trust candidate count and decreases who is trusting someone else 
        // after that at end we traverse count vector then check if count of anyone eaquals to N-1 because
        // if all except judge trust him then he will get N-1 votes
        
        for(vector<int> i:trust)
        {
            count[i[0]-1]--;
            count[i[1]-1]++;
        }
        //int res =INT_MIN;
		
        for(int i =0;i<N;i++)
            if(count[i] == N-1)
                return i+1;
        return -1;
        
    }
};