#include <iostream>
using namespace std;


class Payment
{
public:
	virtual void amount() = 0;
};

class FundsPaidFromAccount : public Payment
{
public:
	void amount() override { cout << "Money has been withdrawn from the user's account." << endl; }
};

class CheckProxy : public Payment
{


public:
	CheckProxy() { _payment = new FundsPaidFromAccount(); }
	~CheckProxy() {delete _payment;}
	void amount() override
	{
		cout << "Using check for payment." << endl;
		_payment->amount();
	}
private:
	Payment* _payment;
};

int main() {
	
	Payment* pay = new CheckProxy();
	pay->amount();
	system("pause");
	return 0;
}