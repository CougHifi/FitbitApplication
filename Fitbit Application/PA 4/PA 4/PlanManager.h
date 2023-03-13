#include <fstream>
#include <iostream>
#include <string>
#include "Libraries.h"
#include"Dietplan.h"
#include "WeeklyPlan.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;

class PlanManager 
{
	/*Private Diet Plan Member Functions*/
private:
	DietPlan *mDietplanPtr;
	bool *mDietplanAvailablePtr;
	int mNumberOfPlans;
	/*Private Weekly Plan Member Functions*/	
private:
	bool *mWeeklyplanAvailablePtr;
	int mNumberOfWeeklyPlans;
	WeeklyPlan *mWeeklyplanPtr;
	fstream& operator >> (fstream, DietPlan &WeeklyDiet);
	/*Diet Plan Public Functions*/
public:
	PlanManager();//default constructor
	PlanManager(int numberPlans);//This is my constructor
	~PlanManager(); //Destructor

	PlanManager &operator=(const PlanManager &rhs);

	//getters / accessors are placed here
	DietPlan * getDietplanPtr() const;
	bool * getDietplanFoundPtr() const;
	int getNumberofPlans() const;
	
	/*setters and mutators.*/
	void setDietplanPtr(DietPlan *newDietplanPtr);
	void setDietplanAvailablePtr(bool *newDietplan);
	void setNumberOfPlans(int newNumberOfDietPlans);
	void LoadDietExercisePlan(fstream &fileStream, DietPlan &plan);
	void displayMenu();
	int getMenuOption() const;
	bool createPlan();
	//bool deletePlan();
	bool updatePlan();
	void displayPlan() const;
	//int findPlan() const;
	void loadDailyDietPlan(DietPlan &plan);
	DietPlan WeeklyDiet[7];
	WeeklyPlan Exerciseplan[7];
	void runDietPlanApplication();

	/*Weekly Plan public functions*/
public:
	WeeklyPlan * getWeeklyplanPtr() const;
	bool * getWeeklyplanFoundPtr() const;
	int getNumberofWeeklyPlans() const;

	void setWeeklyPlanPtr(WeeklyPlan *newWeeklyPlanPtr);
	void setWeeklyPlanAvailablePtr(bool *newWeeklyPlan);

//	void displayMenu();
//	int getMenuOption() const;
	bool createWeeklyPlan();
	//bool deleteWeeklyPlan();
	bool updateWeeklyPlan();
	void displayWeeklyPlan() const;
	int findWeeklyPlan() const;
};

