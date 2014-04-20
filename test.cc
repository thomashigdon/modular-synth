class A
{
public:
	A(int a);

	int GetA() { return ma; }

private:
	int ma;
};

A::A(int a)
	: ma(a)
{
}

class B : public A
{
public:
	B(int c);
};

B::B(int c)
	: A(c)
{
}

class C: public B
{
	C();

	void func() { int a = GetA(); }

};

int main()
{
}
