#include<bits/stdc++.h>
using namespace std;

const double eps=1e-7;

double sqr(double a){return a*a;}
int sgn(double a){
    if (fabs(a)<eps) return 0;
    if (a<0) return -1;
    return 1;
}

int cmp(double a,double b){
    return sgn(a-b);
}

struct Point{
    Point(double _x=0,double _y=0):x(_x),y(_y){}
    Point operator+(Point p) const{return Point(x+p.x,y+p.y);}
    Point operator-(Point p) const{return Point(x-p.x,y-p.y);}
    Point operator*(double d) const{return Point(x*d,y*d);}
    Point operator/(double d) const{return *this*(1./d);}
    double SqrLength() const {return sqr(x)+sqr(y);}
    double x,y;

    friend double Distance(Point p1,Point p2){
        return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
    }
    friend double SqrDistance(Point p1,Point p2){
        return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
    }
    friend double Rad(Point p1,Point p2){
        return atan2(Cross(p1,p2),Dot(p1,p2));
    }
    friend double Cross(Point p1,Point p2){
        return p1.x*p2.y-p1.y*p2.x;
    }
    friend double Dot(Point p1,Point p2){
        return p1.x*p2.x+p1.y*p2.y;
    }
};

struct Line{
    Line(){}
    Point s,t;
};

struct Circle{
    Circle(){}
    Circle(Point _o,double _r):o(_o),r(_r){}
    Point o; double r;

    /*
    0: on
    1: out
    -1: in
    */
    friend bool InCircle(Circle c,Point p){
        return cmp(Distance(p,c.o),c.r);        
    }

    friend vector<Point> GetIntersectCircleLine(Circle c,Line l){
        double x=Dot(l.s-c.o,l.t-l.s), y=SqrDistance(l.s,l.t), 
               d=x*x-y*(SqrDistance(l.s,c.o)-c.r*c.r);
        if (sgn(d)<0) return {};        
        d=max(d,0.); 
        Point m=l.s-(l.t-l.s)*(x/y), 
              dir=(l.t-l.s)*(sqrt(d)/y);
        return {m-dir,m+dir};
    }

    friend double GetCircleRectangleArea(
        Circle c,double px,double py,double dx,double dy){
        double ret=0;
        vector<Point> ps;
        ps.push_back(Point(px,py));
        ps.push_back(Point(px,py+dy));
        ps.push_back(Point(px-dx,py+dy));
        ps.push_back(Point(px-dx,py));
        for(int i=0;i<4;i++){
            Line l;
            l.s=ps[i];
            l.t=ps[(i+1)%4];
            ret+=GetCircleTriangleArea(c,l);
        }
        return fabs(ret);
    }

    friend double GetCircleTriangleArea(Circle c,Line l){
        l.s=l.s-c.o; l.t=l.t-c.o;
        vector<Point> is=GetIntersectCircleLine(Circle(Point(0,0),c.r),l);
        if (is.empty()) return c.r*c.r*Rad(l.s,l.t)/2;
        bool b1=cmp(l.s.SqrLength(),c.r*c.r)==1,
             b2=cmp(l.t.SqrLength(),c.r*c.r)==1;
        if (b1 && b2){
            if (sgn(Dot(l.s-is[0],l.t-is[0]))<=0 &&
                sgn(Dot(l.s-is[0],l.t-is[0]))<=0)
            {
                return c.r*c.r*(Rad(l.s,is[0])+Rad(is[1],l.t))/2
                      +Cross(is[0],is[1])/2;
            } else{
                return c.r*c.r*Rad(l.s,l.t)/2;
            }
        }
        if (b1) return (c.r*c.r*Rad(l.s,is[0])+Cross(is[0],l.t))/2; 
        if (b2) return (c.r*c.r*Rad(is[1],l.t)+Cross(l.s,is[1]))/2;
        return Cross(l.s,l.t)/2;
    }
};

vector<double> f;

int main(){
    double r,dx,dy,x,y,p;
    cin>>r>>dx>>dy>>x>>y>>p;
    Circle c(Point(0,0),r);
    for(double px=x;cmp(px,-r)>=0;px-=dx){
        for(double py=y;cmp(py+dy,-r)>=0;py-=dy){
            //cout<<px<<' '<<py<<endl;
            double area=GetCircleRectangleArea(c,px,py,dx,dy);
            if (cmp(area,0)>0){
                //cout<<px<<' '<<py<<endl;
                f.push_back(area);
            }
        }
        for(double py=y+dy;cmp(py,r)<=0;py+=dy){
            double area=GetCircleRectangleArea(c,px,py,dx,dy);
            if (cmp(area,0)>0){
                //cout<<px<<' '<<py<<endl;
                f.push_back(area);
            }
        }
    }
    for(double px=x+dx;cmp(px-dx,r)<=0;px+=dx){
        for(double py=y;cmp(py+dy,-r)>=0;py-=dy){
            double area=GetCircleRectangleArea(c,px,py,dx,dy);
            if (cmp(area,0)>0){
                //cout<<px<<' '<<py<<endl;
                f.push_back(area);
            }
        }
        for(double py=y+dy;cmp(py,r)<=0;py+=dy){
            //cout<<px<<' '<<py<<endl;
            double area=GetCircleRectangleArea(c,px,py,dx,dy);
            if (cmp(area,0)>0){
                //cout<<px<<' '<<py<<endl;
                f.push_back(area);
            }
        }
    }
    sort(f.begin(),f.end());
    double mx=f.back();
    double bas=mx*p;
    int cnt=0;
    for(int i=0;i<f.size();i++){
        if (cmp(f[i],bas)<0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}