#include<bits/stdc++.h>
using namespace std;
typedef struct _Edge
{
float x;
float dx;
int ymax;
struct _Edge *next;
}Edge;

typedef struct _Point
{
int x;
int y;
}Point;

static Edge *edges[480], *active;

void InsertEdge(Edge *list, Edge *edge)
{
Edge *p, *q = list;
p = q->next;
while(p != NULL)
{
if(edge->x < p->x)
p = NULL;
else
{
q = p;
p = p->next;
}
}
edge->next = q->next;
q->next = edge;
}

void MakeEdgeRec(Point lower, Point upper, int yComp, Edge *edge, Edge *edges[])
{
edge->dx = (float)(upper.x - lower.x)/(upper.y - lower.y);
edge->x = lower.x;
if(upper.y < yComp)
edge->ymax = upper.y - 1;
else
edge->ymax = upper.y;
InsertEdge(edges[lower.y],edge);
}

int yNext(int k, int num, Point *pts)
{
int j;
if((k + 1) > (num - 1))
j = 0;
else
j = k + 1;
while(pts[k].y == pts[j].y)
if((j + 1) > (num - 1))
j = 0;
else
++j;
return (pts[j].y);
}

void BuildEdgeList(Point *pts, int num, Edge *edges[])
{
Edge *edge;
Point v1,v2;
int i, yPrev = pts[num-2].y;
v1.x = pts[num-1].x;
v1.y = pts[num-1].y;
for( i = 0; i < num; ++i)
{
v2 = pts[i];
if(v1.y != v2.y)
{
edge = (Edge *)malloc(sizeof(Edge));
edge = (Edge *)malloc(sizeof(Edge));
if(v1.y < v2.y)
MakeEdgeRec(v1,v2,yNext(i,num,pts),edge,edges);
else
MakeEdgeRec(v2,v1,yPrev,edge,edges);
}
yPrev = v1.y;
v1 = v2;
}
}

void BuildActiveList(int scan, Edge *active, Edge *edge[])
{
Edge *p, *q;
p = edges[scan]->next;
while(p)
{
q = p->next;
InsertEdge(active, p);
p = q;
}
}

void FillScan(int scan, Edge *active)
{
Edge *p1, *p2;
int i;
p1 = active->next;
while(p1)
{
p2 = p1->next;
for( i = p1->x; i < p2->x; ++i)
//printf(".");
p1 = p2->next;
}
}

void DeleteAfter(Edge *q)
{
Edge *p = q->next;
q->next = p->next;
free(p);
}

void UpdateActiveList(int scan, Edge *active)
{
Edge *q=active, *p = active->next;
while(p)
{
if(scan >= p->ymax)
{
p = p->next;
DeleteAfter(q);
}
else
{
p->x = p->x + p->dx;
q = p;
p = p->next;
}
}
}

void ResortActiveList(Edge *active)
{
Edge *q, *p = active->next;
active->next = NULL;
while(p)
{
q = p->next;
InsertEdge(active, p);
p = q;
}
}

void ScanLineFillPolygon(Point *pts, int num)
{
int i,scan,scanmax=0,scanmin = 480;

/* 扫描线的边界*/

for( i = 0; i < num -1; ++i)
{
if(pts[i].y > scanmax)
scanmax = pts[i].y;
if(pts[i].y < scanmin)
scanmin = pts[i].y;
}

/* 初始化边表*/

for( scan = scanmin; scan < scanmax; ++scan )
{
edges[scan] = (Edge *) malloc(sizeof(Edge));
edges[scan]->next = NULL;
}
BuildEdgeList(pts,num,edges);
active = (Edge *)malloc(sizeof(Edge));
active->next = NULL;
for(scan = scanmin; scan <=scanmax; scan++)
{
BuildActiveList(scan,active,edges);
if(active->next)
{
FillScan(scan,active);
UpdateActiveList(scan,active);
ResortActiveList(active);
}
}
}

int main()
{
Point pts[] = {{100,40},{220,140},{280,80},{350,300},
               {200,380},{50,280},{100,40}};
int num = sizeof(pts)/sizeof(Point);
ScanLineFillPolygon(pts,num);
return 0;
}
