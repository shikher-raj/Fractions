#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
int lcm(int a,int b)
{
	int z=__gcd(a,b);
	return a*b/z;
}
class fraction {
	private:
		int num,denum;
	public:
		fraction() {
			num=0;
			denum=1;
		}
		fraction(int a) {
			num=a;
			denum=1;
		}
		fraction(int a,int b) {
			assert(b!=0);
			num=a;
			denum=b;
		}
		void sf() {
			int z=__gcd(num,denum);
			num/=z;
			denum/=z;
		}
		void add(fraction a,fraction b) {
			int y=lcm(a.denum,b.denum);
			int x=y/a.denum*a.num + y/b.denum*b.num;
			num=x;denum=y;
		}
		void subtract(fraction a,fraction b) {
			int y=lcm(a.denum,b.denum);
			int x=y/a.denum*a.num - y/b.denum*b.num;
			num=x;denum=y;
		}
		void multiply(fraction a,fraction b) {
			num=a.num*b.num;
			denum=a.denum*b.denum;
		}
		void divide(fraction a,fraction b) {
			num=a.num*b.denum;
			denum=a.denum*b.num;
		}
		void print() {
			if(denum<0) {
				num*=(-1);
				denum*=(-1);
			}
			cout<<num<<"/"<<denum<<"\n";
		}
};
int main()
{
	fraction A(2,5),B(3,6);
	B.sf();
	B.print();
	fraction C;
	C.add(A,B);
	C.sf();
	C.print();
	C.subtract(A,B);
	C.sf();
	C.print();
	C.multiply(A,B);
	C.sf();
	C.print();
	C.divide(A,B);
	C.sf();
	C.print();
	//fraction D(5,0);
	return 0;
}
