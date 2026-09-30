set<vector<int>st;

for(int i =0;i<n;i++){

    vector<int>temp;
    int cnt=0;
    for(int j =i;j<n;j++){
        temp.push_back(codes[j]);

        if(codes[j]%p==0){
            cnt++;
        }
        if(cnt>k)
        break;

        st.insert(temp);
    }
}
return st.size();


vector<int>minDist(n,INT_MAX);
vector<bool>vis(n,false);
int ans =0;
minDist[0]=0;

for(int i=0;i<n;i++){

    int u =-1;
    for(int j=0;j<n;j++){
        if(!vis[j] &&(u==-1 || minDist[j]<minDist[u])){
            u=j;
        }
    }

    vis[u]=true;
    ans += minDist[u];

    for(int v=0;v<n;v++){
        if(!vis[v]){
            int distance = abs(points[u][0]-points[v][0]) + abs(points[u][1]- points[v][1]);
            minDist[v] = min(minDist[v],distance); 
        }
    }
}
return ans;



int sensors = 0 ;
struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

int dfs(Node* root){
    if(root==NULL)
        return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if(left ==0 || right ==0){
        sensors++;
        return 1;
    }

    if(left==1||right==1){
        return 2;
    }
    return 0;
}

if(n==0) return 0;

Node* root = new Node(arr[0]);
queue<Node *> q;
q.push(root);
int i =1;
while(!q.empty()){
    Node* curr = q.front();
    q.pop();

    if(i<n && arr[i]!=-1){
        curr->left = new Node(arr[i]);
        q.push(curr->left);
    }
    i++;
    if(i<n && arr[i]!=-1){
        curr->right = new Node(arr[i]);
        q.push(curr->right);
    }
    i++;
}
sensors = 0;

int state = dfs(root);
if(state==0)
sensors++;


return sensors;
