vector<vector<int>>cost;
vector<bool>visited ;
ans=__INT_MAX__
void tsp(int city,int cnt,int curr){
    if(city==n){
        ans=min(ans,curr+cost[city][0]);
        return ;
    }
    for(int next=0;next<n;next++){
        if(!vis[next]){
            vis[next]=true;
            tsp(next,cnt+1,cur+cost[city][next]);
            vis[next]=false;
        }
    }
}