#include "Libraries.h"

/*See as to if you have time to implement Inheritence later down the line.*/
class DietPlan
{
private:
	double mNewset;
	int mNewworkout;
	string mName;
	string mDateCreated;
	string mWorkout;
	
public:
	/*This is the dietplans information*/
	DietPlan(double initalDietPlan = 0.0, int Newworkout = 0 /* might need to make this into a char */, 
		string name = "",
		string datecreated = "",
		string theworkoutduration = "");
	DietPlan(DietPlan &copyDietplan);/*This creates a Shallow copy*/
	~DietPlan();

	;
	DietPlan & operator= (const DietPlan &rhs);

	double getDietPlan() const;
	int getNewworkout() const;
	string getName() const;
	string getDateCrated() const;
	string getWorkout() const;
	
	void setDietplan(double newDietplan);
	void setNewworkout(int Newworkout);
	void setName(string newName);
	void setDatecreated(string newDateCreated);
	void setWorkout(string newWorkout);

	double days(double newDays);
	double time(double newTime);//do I need time?
	void printDietplan();

	
};

//class ExercisePlan
//{
//private:
//	int GoalSteps = 0;
//	string PlanName;
//	string date;
//public:
//
//};

//class FitnessAppWrapper
//{
//private:
//
//public:
//
//};
