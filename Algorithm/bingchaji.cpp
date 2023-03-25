#include <vector>
using namespace std;

static vector<int> parent;
static vector<int> rank; //按秩合并，避免退化到o(n);
int find(int i)
{
   if (parent[i] != parent)
   {
      parent[i] = find(parent[i]); //路径压缩
      return parent[i];
   }
   return i;
}
bool uni(int i, int j)
{
   int parenti = find(i);
   int parentj = find(j);
   if (parenti == parentj)
      return false;
   else
   {
      if (rank[parenti] < rank[parentj])
         parent[parenti] = parentj;
      else if (rank[parenti] > rank(parentj))
         parent[parentj] = parenti;
      else
      {
         parent[parentj] = parenti;
         rank[parenti]++;
      }
      return true;
   }
}
