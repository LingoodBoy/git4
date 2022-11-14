#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
	int _x;         //��ĺ�����
	int _y;         //���������
public:
	//�ⲿ�ӿ�
	Point();
	Point(int x, int y);
	int get_x();           //��ȡ������
	int get_y();           //��ȡ������
	double get_r();        //��ȡ�õ㵽ԭ���ŷʽ����
};
class Point_set {
private:
	int    _N;                         //������ĳ���
	Point* _set;                       //������ָ��
	bool* _is_valid;                   //�������N��λ���Ƿ��Ѿ����룬�������á�1����δ�����á�0��
public:
	//�ⲿ�ӿ�
	Point_set(int N);
	~Point_set();
	bool  set(int n_index, Point src); //�����src���롰_set���е�������Ԫ�ػ��죬����src����ֵ��ֵ����_set���������±�Ϊ��n_index����PointԪ�أ��ҷ���true
	                                   //                                   ���򣬷���false��
	Point get(int n_index);            //��ȡ��_set���������±�Ϊ��n_index����PointԪ�ء�
	bool  has_point(Point src);        //��顰_set�������е�������ֵ���Ƿ��к͡�src����ͬ����ĵ㣬�з���true���޷���false��
	void  sort();                      //����ԭ���ŷʽ����Ӵ�С��������
	void  show();
};
//��Ĵ������������
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
//		if (success != true) return 0;//����г���Υ�����ϻ����Ե�Ԫ�����룬��ֹ��������
	}
	cout << "Point set sorted Euclidean distance: " << endl;
	point_set.sort();
	point_set.show();
	return 0;
}
