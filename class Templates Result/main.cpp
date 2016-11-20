#include<iostream>
template<typename T> class Optional
{
	T mValue;
	bool mHasValue;
public:
	Optional() : mHasValue(false) { }
	Optional(T const &v) : mValue(v), mHasValue(true) { }
	void set(T const &v)
	{
		mValue = v;
		mHasValue = true;
	}
	void clear()
	{
		mHasValue = false;
	}
	T const &get() const
	{
		if (!mHasValue) {
			std::cerr << "Vorsicht! Leere Variable ausgelesen! \n";
		}
		return mValue;
	}
	bool hasValue() const
	{
		return mHasValue;
	}
};
int main()
{
	Optional<int> o;
	std::cout << "Hat o im Moment einen Wert?" << o.hasValue() << "\n";
	o.set(10);
	std::cout << "Hat o im Moment einen Wert?" << o.hasValue() << "\n";
	std::cout << "o = " << o.get() << "\n";
	o.clear();
	std::cout << "Hat o im Moment einen Wert?" << o.hasValue() << "\n";
	std::cin.get();
}