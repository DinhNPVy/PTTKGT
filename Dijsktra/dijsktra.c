/**
* Trong nay, cac dinh khong co canh noi voi nhau se co khoang cach la -1
*/


public int[] dijkstra(int[][] graph, int s){
	int [] dist = new int[graph.length];
	for(int i = 0; i < graph.length; i++){
		dist[i] = Integer.MAX_VALUE;
	}
	dist[s] = 0;
	int [] visit = new int[graph.length]; 
	for(int i = 0; i < graph.length; i ++){
		int v = closestVertice(graph[s], visit);
		for(int j = 0; j < graph[v].length; j++){
			if (graph[v][j] != -1){ // neu co canh noi giua v va j
				int currentDist = dist[v] + graph[v][j];
				if (currentDist < dist[j]){
					dist[j] = currentDist;
				}
			}
		}
	}
	return dist;
}
/**
 * Chon ra dinh o gan s nhat va danh dau dinh do la da tham gia
 * */
public int closestVertice(int[] adjacentVertices, int[] visit){
	int closest = -1;
	int minDist = Integer.MAX_VALUE;
	for(int i = 0; i < adjacentVertices.length; i ++){
		if (visit[i] == 0 && adjacentVertices[i] < minDist){
			closest = i;
			minDist = adjacentVertices[i];
		}
	}
	visit[closest] = 1;
	return closest;
}




