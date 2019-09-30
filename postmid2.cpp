#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
struct point{
int x;int y;
};
point p0;
int  swap(point &p1,point &p2){
point temp=p1;
p1=p2;
p2=temp;
}
int dist(point p1,point p2)
{
return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);}
point nextToTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
int orientation(point a,point b,point c){
int dummy =(a.y-b.y)*(b.x-c.x)-(a.x-b.x)*(b.y-c.y);
if(dummy==0){return 0;}
return (dummy>0)?1:2;//1 for clock 2 for clockwise
}
int compare(const void *vp1, const void *vp2)
{
   point *p1 = (point *)vp1;
   point *p2 = (point *)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}
void convexhull(point p[],int t)
{
  point minx;
  minx.x=p[0].x;
  minx.y=p[0].y;
  int flag=0;
  for(int i=0;i<t;i++)
    {
      if(p[i].x<minx.x)
        {
         minx.x=p[i].x;
         minx.y=p[i].y;
         flag=i;
        }
         if(p[i].x==minx.x&&p[i].y<minx.y)
        {
          minx.x=p[i].x;
          minx.y=p[i].y;flag=i;}
    }

  p0=minx;
  swap(p[0],p[flag]);

  qsort(&p[1],t-1,sizeof(point),compare);

  int m = 1; // Initialize size of modified array
   for (int i=1; i<t; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < t-1 && orientation(p0, p[i],
                                    p[i+1]) == 0){
          i++;}


       p[m] = p[i];
       m++;  // Update size of modified array
   }

   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;

   // Create an empty stack and push first three points
   // to it.
   stack<point> S;
   S.push(p[0]);
   S.push(p[1]);
   S.push(p[2]);

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), p[i]) != 2)
         S.pop();
      S.push(p[i]);
   }

   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }


/*  for(int i=1;i<t;i++){
    while(i<t&&orientation(p0,p[i],p[i+1])){
      i++;
    }
p[j]=p[i];
j++;


  }
*/
 




















  //cout<<p0.x<<p0.y<<endl;
  /*debuugging
  cout<<flag;
  cout<<p[0].x;
    if(p0.x==p[0].x&&p0.y==p[0].y){
   cout<<"hurray";*/
 }

int  main()
{
int t;
cin>>t;
point p[t];
for(int i=0;i<t;i++)
  {
    cin>>p[i].x>>p[i].y;
  }

  convexhull(&p[0],t);





return 0;


}
