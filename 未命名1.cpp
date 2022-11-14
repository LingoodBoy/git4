#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
	int _x;         //点的横坐标
	int _y;         //点的纵坐标
public:
	//外部接口
	Point();
	Point(int x, int y);
	int get_x();           //获取横坐标
	int get_y();           //获取纵坐标
	double get_r();        //获取该点到原点的欧式距离
};
class Point_set {
private:
	int    _N;                         //点数组的长度
	Point* _set;                       //点数组指针
	bool* _is_valid;                   //点数组的N个位置是否已经输入，已输入置“1”，未输入置“0”
public:
	//外部接口
	Point_set(int N);
	~Point_set();
	bool  set(int n_index, Point src); //如果“src”与“_set”中的已输入元素互异，将“src”的值赋值给“_set”数组中下标为“n_index”的Point元素，且返回true
	                                   //                                   否则，返回false。
	Point get(int n_index);            //获取“_set”数组中下标为“n_index”的Point元素。
	bool  has_point(Point src);        //检查“_set”数组中的已输入值中是否有和“src”相同坐标的点，有返回true，无返回false。
	void  sort();                      //按与原点的欧式距离从大到小进行排序。
	void  show();
};
//你的代码会从这里插入
void b_zero(bool a[],int n)
{
    for(int i=0;i<n;i++)
        a[i]=false;
}
Point::Point()
{
	
}
Point::Point(int x,int y)
{
    _x=x;
    _y=y;
}
int Point::get_x()
{
    return _x;
}
int Point::get_y()
{
    return _y;
}
double Point::get_r()
{
    return sqrt(_x*_x+_y*_y);
}

Point_set::Point_set(int N)
{
    _N=N;
    Point p[_N];
    _set=new Point[_N];
    bool b[_N];
    _is_valid=b;
    b_zero(_is_valid,_N);
}
Point_set::~Point_set()
{

}
Point Point_set::get(int n_index)
{
    return _set[n_index];
}
bool Point_set::has_point(Point src)
{
    for(int i=0;i<_N;i++)
    {
        if(_is_valid[i]==true)
        {
            if((_set[i].get_x()==src.get_x())&&(_set[i].get_y()==src.get_y()))
                return false;
        }
    }
    return true;
}
bool Point_set::set(int n_index,Point src)
{
	
    if(has_point(src)==false)
        return false;
    else
    {
//    	cout<<n_index<<"  "<<src.get_y()<<endl;
        _set[n_index]=src;
        cout<<_set[n_index].get_x()<<"  "<<_set[n_index].get_y()<<endl; 
        _is_valid[n_index]=true;
        return true;
    }
}
void Point_set::sort()
{
    int i,j;
    Point temp;
    for(i=0;i<_N-1;i++)
    {
        for(j=0;j<_N-1-i;j++)
        {
            if(_set[j+1].get_r()>_set[j].get_r())
            {
                temp=_set[j+1];
                _set[j+1]=_set[j];
                _set[j]=temp;
            }
        }
    }
}
void Point_set::show()
{
    cout<<"{";
    for(int i=0;i<_N;i++)
    {
        cout<<'('<<_set[i].get_x()<<','<<_set[i].get_y()<<')';
        if(i<_N-1)
            cout<<',';
    }
    cout<<"}";
}




int main() {
	int N;
	cin >> N;
	Point_set point_set(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		bool success = point_set.set(i, Point(x, y));
//		if (success != true) return 0;//如果有出现违反集合互异性的元素输入，终止整个程序
	}
	cout << "Point set sorted Euclidean distance: " << endl;
	point_set.sort();
	point_set.show();
	return 0;
}
