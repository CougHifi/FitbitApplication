#include "Libraries.h"
/*Weekly plan will have the same member functions as the dietplan so use either inheritance
or just hard code it in. Might not need the manager stuff.*/
//class WeeklyPlan
//{
//private:
//	double mNewset;
//	int mNewworkout;
//	string mName;
//	string mDateCreated;
//	string mWorkout;
//public:
//	/*This is the weeklyplans information*/
//	WeeklyPlan(double initaldietplan = 0.0, int Newworkout = 0 /* might need to make this into a char */,
//		/*you will also be asking the user for the days.*/
//		string name = "",
//		string day = "",
//		string datecreated = "",
//		string theworkoutduration = "");
//	WeeklyPlan(WeeklyPlan &copyDietplan);/*This creates a Shallow copy*/
//	~WeeklyPlan();
//
//	WeeklyPlan &operator= (const WeeklyPlan &rhs);
//
//	double getWeeklyplan() const;
//	int getNewworkout() const;
//	string getName() const;
//	string getDateCrated() const;
//	string getWorkout() const;
//
//	void setWeeklyplan(double newWeeklyplan);
//	void setNewworkout(int Newworkout);
//	void setName(string newName);
//	void setDatecreated(string newDateCreated);
//	void setWorkout(string newWorkout);
//
//	double days(double newDays);
//	double time(double newTime);
//	void printWeeklyplan();
//};

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
	//double NameOfDay
};