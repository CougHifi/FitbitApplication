#include "PlanManager.h"

WeeklyPlan::WeeklyPlan(double initalWeeklyPlan, int NewWorkout1, string NameOfDay,
	string Datecreated1, string workout)
{
	if (initalWeeklyPlan < 0.0)
	{
		mNewset1 = 0.0;
	}
	else
	{
		mNewset1 = initalWeeklyPlan;
	}
	mNewworkout1 = NewWorkout1;
	mNameOfDay = NameOfDay;
	mDateCreated1 = Datecreated1;
	mWorkout1 = NewWorkout1;
}

WeeklyPlan::WeeklyPlan(WeeklyPlan &copyWeeklyPlan)
{
	mNewset1 = copyWeeklyPlan.getWeeklyPlan();
	mNewworkout1 = copyWeeklyPlan.getNewworkout1();
	mNameOfDay = copyWeeklyPlan.getNameOfDay();
	mDateCreated1 = copyWeeklyPlan.getNameOfDay();//check to see if you need this most likely you don't.
}

WeeklyPlan::~WeeklyPlan()
{

}

WeeklyPlan &WeeklyPlan:: operator=(const WeeklyPlan &rhs)
{
	if (this != &rhs)
	{
		mNewset1 = rhs.getWeeklyPlan();
		mNewworkout1 = rhs.getNewworkout1();
		mNameOfDay = rhs.getNameOfDay();
		mDateCreated1 = rhs.getNameOfDay();
	}
	return *this;
}

double WeeklyPlan::getWeeklyPlan() const
{
	return mNewset1;
}

int WeeklyPlan::getNewworkout1() const
{
	return mNewworkout1;
}

string WeeklyPlan::getNameOfDay()const
{
	return mNameOfDay;
}

string WeeklyPlan::getWorkout1() const
{
	return mWorkout1;
}

void WeeklyPlan::setWeeklyPlan(double Newset1)
{
	mNewset1 = Newset1;
}

void WeeklyPlan::setNewworkout1(int Newworkout1)
{
	mNewworkout1 = Newworkout1;
}

void WeeklyPlan::setNameOfDay(string newNameOfDay)
{
	mNameOfDay = newNameOfDay;
}

void WeeklyPlan::setDateCreated1(string newDateCreated1)
{
	mDateCreated1 = newDateCreated1;
}

void WeeklyPlan::printWeeklyplan()
{
	cout << "New Plan:" << mNewworkout1 << endl;	
	cout << "Your Plan:" << mNewset1 << endl;
	cout << "Name Of The Day:" << mNameOfDay << endl;
	cout << "Date Crated:" << mDateCreated1 << endl;
}