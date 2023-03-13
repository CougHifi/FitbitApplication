#include "Dietplan.h"
#include "WeeklyPlan.h"


DietPlan::DietPlan(double initalDietplan, int NewWorkout,
	string Newname, string Datecreated, string workoutduration)
{
	if (initalDietplan < 0.0)
	{
		mNewset = 0.0;
	}
	else
	{
		mNewset = initalDietplan;
	}
	mNewworkout = NewWorkout;
	mName = Newname;
	mDateCreated = Datecreated;
	mWorkout = NewWorkout;
}

DietPlan::DietPlan(DietPlan &copyDietplan)//a copy
{
	mNewset = copyDietplan.getDietPlan();
	mNewworkout = copyDietplan.getNewworkout();
	mName = copyDietplan.getName();
	mDateCreated = copyDietplan.getName();
}

DietPlan::~DietPlan() {

}

DietPlan & DietPlan:: operator= (const DietPlan &rhs)
{
if (this != &rhs)
{
	mNewset = rhs.getDietPlan();
	mNewworkout = rhs.getNewworkout();
	mName = rhs.getName();
	mDateCreated = rhs.getName();
	mWorkout = rhs.getName();

}

return *this;

}

double DietPlan::getDietPlan() const
{
	return mNewset;
}

int DietPlan::getNewworkout() const
{
	return mNewworkout;
}

string DietPlan::getName() const
{
	return mName;
}

string DietPlan::getDateCrated()const
{
	return mDateCreated;
}

string DietPlan::getWorkout()const
{
	return mWorkout;
}
void DietPlan::setDietplan(double Newset)
{
	mNewset = Newset;
}

void DietPlan::setNewworkout(int Newworkout)
{
	mNewworkout = Newworkout;
}

void DietPlan::setName(string newName)
{
	mName = newName;
}

void DietPlan::setDatecreated(string newDateCreated)
{
	mDateCreated = newDateCreated;
}

void DietPlan::setWorkout(string newWorkout)
{
	mWorkout = newWorkout;
}

double DietPlan::days(double newDays)
{
	mNewset = newDays;
	return (newDays);
}

/*Do I need Time?*/
//double DietPlan::time(double newTime)
//{
//	
//}


void DietPlan::printDietplan()
{
	
	cout << "New Plan:" << mNewworkout << endl;
	cout << "Name:" << mName << endl;
	cout << "Your plan:" << mNewset << endl;
	cout << "Date Created:" << mDateCreated << endl;
	
}

