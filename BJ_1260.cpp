#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> edge[1001];
queue<int> q;
bool isFinished[1001];

void dfs(int start){
	isFinished[start] = true;
	cout << start << ' ';
	for(int i = 0;i<edge[start].size();i++){
		if(!isFinished[edge[start][i]]){
			dfs(edge[start][i]);
		}
	}
}

void bfs(int start){
	q.push(start);
	isFinished[start] = true;
	while(!q.empty()){
		int temp = q.front(); q.pop();
		cout << temp << ' ';
		for(int i = 0;i<edge[temp].size();i++){
			if(!isFinished[edge[temp][i]]) {
				isFinished[edge[temp][i]] = true;
				q.push(edge[temp][i]);
			}
		}
	}
	
	
}

int main(){
	int N, M, V;
	cin >> N >> M >> V;
	
	for(int i = 0;i<M;i++){
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i = 1;i<N + 1;i++){
		sort(edge[i].begin(),edge[i].end());
	}
	dfs(V);
	cout << endl;
	for(int i = 1;i<N + 1;i++){
		isFinished[i] = false;
	}
	bfs(V);
	cout << endl;
}