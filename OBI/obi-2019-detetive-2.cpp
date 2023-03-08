// Comentário Noic OBI 2019 - Fase 2 - Programação Nível 2
// Detetive

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;

// bitset indicando quais sources do grafo chegam em cada vértice
bitset<maxn> path[maxn];

// grafo das implicações
vector<int> grafo[maxn];

// ingrau de cada vértice
int grau[maxn];

// vetor de marcação da dfs
bool mark[maxn];

bool verdadeiro[maxn];

void dfs(int source, int u)
{
	// source tem um caminho para u
	path[u][source] = 1;
	mark[u] = true;

	for (auto v: grafo[u])
		if (!mark[v])
			dfs(source, v);
}

int main(void)
{
	int E, I, V;
	scanf("%d %d %d", &E, &I, &V);

	for (int i = 1; i <= I; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		// u -> v
		grafo[u].push_back(v);

		grau[v]++;
	}

	for (int i = 1; i <= E; i++)
	{
		if (grau[i] == 0)
		{
			memset(mark, 0, sizeof mark);
			dfs(i, i);
		}
	}

	for (int i = 1; i <= V; i++)
	{
		int u;
		scanf("%d", &u);

		verdadeiro[u] = true;

		for (int v = 1; v <= E; v++)
		{
			// o comando & é usado para encontrar a interseção de bitsets
			// count() calcular a quantidade de bits ligados no bitset

			if ( (path[u]&path[v]).count() == path[u].count())
				verdadeiro[v] = true;
		}
	}

	// imprime a resposta
	for (int i = 1; i <= E; i++)
		if (verdadeiro[i])
			printf("%d ", i);
	printf("\n");
}