class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int length = prerequisites.size();
        vector<vector<int>> edge(numCourses, vector<int>(numCourses, 0));
        vector<int> in(numCourses, 0);
        for(int i=0;i<length;i++){
            in[prerequisites[i][0]] ++;
            edge[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }        
        queue<int> Q;
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0)
                Q.push(i);
        }
        int node = 0;
        while(!Q.empty()){
            node ++;
            int point = Q.front(); 
            Q.pop();
            for(int i=0;i<numCourses;i++){
                if(edge[point][i]){
                    in[i]--;
                    edge[point][i] = 0;
                    if(in[i] == 0)
                        Q.push(i);
                }
            }
        }
        return node == numCourses;
    }
};