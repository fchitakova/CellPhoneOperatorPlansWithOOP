#include "Plan.h"

Plan* filterByPreference(Plan*plans,unsigned &size,unsigned mins, unsigned sms,unsigned mbs,unsigned p,unsigned termlength)
{
	int cnt = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (plans[i].getMins() >= mins && plans[i].getSms() >= sms && plans[i].getMbs() >= mbs && plans[i].getTerm() == termlength
			&& plans[i].getPrice()<=p)
		{
			cnt++;
		}
	}
	Plan* newplans = new Plan[cnt];

	size_t j = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (plans[i].getMins() >= mins && plans[i].getSms() >= sms && plans[i].getMbs() >= mbs && plans[i].getTerm() == termlength
			&& plans[i].getPrice() <= p)
		{
			newplans[j] = plans[i];
			j++;
		}
	}
	size = cnt;
	return newplans;
}

void InsertionSort(Plan *arr, size_t size)
{

	Plan value;
	unsigned emptyPos = 0; //position to shift

	for (size_t i = 1; i <= size - 1; i++)
	{
		value = arr[i];
		emptyPos = i;
		while (emptyPos>0 && arr[emptyPos - 1].getPrice() > value.getPrice())
		{
			arr[emptyPos] = arr[emptyPos - 1];
			emptyPos--;
		}
		arr[emptyPos] = value;
	}
}


int main()
{
	unsigned n;
	std::cin >> n;
	Plan*plans = new Plan[n];
    char*N=new char[MAX_NAMELEN];
	unsigned mins, sms, mbs, p, termlength; //p=price
	Date startdate;

	for (size_t i = 0; i < n; i++)
	{
		std::cin.clear();
		std::cin.sync();
		std::cin.getline(N, MAX_NAMELEN, '\n');
		std::cin.clear();
		std::cin.sync();
		std::cin >> mins >> sms >> mbs >> p >> termlength;
		std::cin.sync();
		std::cin.clear();
		startdate.readDate();
		plans[i].setName(N);
		plans[i].setMbs(mbs);
		plans[i].setMins(mins);
		plans[i].setSms(sms);
		plans[i].setPrice(p);
		plans[i].setTerm(termlength);
		plans[i].setStartDate(startdate);
	}

	
	std::cout << '\n' << "Prefered mins,sms,mbs,termlength,price:";
	std::cin>> mins >> sms >> mbs >> termlength >> p;

	Plan*newplans = filterByPreference(plans, n, mins, mbs, sms, p, termlength);

	InsertionSort(newplans, n);

	std::cout << '\n'<<"The plans which satisfy your preferences are: \n";

	for (size_t i = 0; i < n; i++)
	{
		std::cout << newplans[i].getName() << '\n' << newplans[i].getMins() << ' ' << newplans[i].getSms() << ' ' << newplans[i].getMbs() << ' $' << newplans[i].getPrice() << ' ' << newplans[i].getTerm() << "long \n";
	}

	



	delete[]newplans;
	delete[]N;
	delete[]plans;
	newplans = 0;
	plans = 0;
	n = 0;
	return 0;
}
