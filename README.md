알고리즘 주요 구현 내용 정리

----
# SCC
> 강한 연결 요소(strong connected component)
>- strong connected compoent의 집합들을 S라고 할 때, S에서 임의로 뽑은 두 노드 u, v에 대해, u->v 그리고 v->u로 가는 경로가 >있는 집합들의 집합
>- SCC를 구한 후, 위상정렬 활용가능
>- DFS

----
# M & (1<<i) 태크닉
```cpp
	for (int i = 20; i >=0; i--) {
		res = vector_merge(res, res);
		if (m & (1 << i)) res = vector_merge(res, item);
	}
```
