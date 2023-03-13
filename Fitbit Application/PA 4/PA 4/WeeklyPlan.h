#include "Libraries.h"


class WeeklyPlan
{
private: 
	double mNewset1;
	int mNewworkout1;
	string mNameOfDay;
	string mDateCreated1;
	string mWorkout1;

public:
	WeeklyPlan(double initalWeeklyPlan = 0.0, int Newworkout1 = 0,
		string name = "", string DateCreated1 = "", string theworkoutduration = "");
	WeeklyPlan(WeeklyPlan &copyWeeklyPlan);
	~WeeklyPlan();

	WeeklyPlan &operator =(const WeeklyPlan &rhs);

	double getWeeklyPlan() const;
	int getNewworkout1() const;
	string getNameOfDay() const;
	string getDateCreated1() const;
	string getWorkout1() const;
	
	void setWeeklyPlan(double newWeeklyPlan);
	void setNewworkout1(int Newworkout);
	void setNameOfDay(string newNameOfDay);
	void setDateCreated1(string newDateCreated1);
	void setWorkout(string newWorkout1);

	void printWeeklyplan();
	
};
