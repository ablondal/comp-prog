/**
 * Author: Ari Blondal
 * Date: 2022-05-20
 * Source: half cp-algorithms, half Ari
 * Description: Single-source Dijkstra, with dijkstra DAG put into adj2.
 * Time: $O(|V|\log{|E|})$
 * Status: stress-tested on https://open.kattis.com/problems/travelog
 */
#pragma once

int n;
vector<pii> adj1[MX], adj2[MX];
ll d[MX] = {0};
void dij(int s){
	rep(i,0,n+1) d[i]=1e18;
	d[s]=0;
	using pli = pair<ll, int>;
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	Q.push({d[s], s});
	while(!Q.empty()){
		auto [dv, v] = Q.top();
		Q.pop();
		if (d[v]!=dv) continue;
		for(auto [to, len]: adj1[v]){
			if (d[v]+len < d[to]){
				d[to] = d[v]+len;
				Q.push({d[to],to});
			}
		}
	}
	rep(i,0,n+1) for(auto [to, len]: adj1[i]){
		if (d[i]+len==d[to]) adj2[i].push_back({to, len});
	}
}
