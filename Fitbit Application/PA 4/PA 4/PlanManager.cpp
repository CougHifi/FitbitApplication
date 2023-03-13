#include "PlanManager.h"
/*instead of dietplan change it to weekly plan. no arry required for dietplan. dietplan means one object one plan.*/
PlanManager::PlanManager()
{
	mWeeklyplanPtr = new WeeklyPlan[1000];
	mWeeklyplanAvailablePtr = new bool[1000];

	for (int counter = 0; counter < 1000; counter++)
	{
		mWeeklyplanAvailablePtr[counter] = true;
	}
	mNumberOfPlans = 1000;
}

/*Daily Plan*/
PlanManager::PlanManager(int maxNumberOfPlans)
{
	mDietplanPtr = new DietPlan[maxNumberOfPlans];
	mDietplanAvailablePtr = new bool[maxNumberOfPlans];

	for (int counter = 0; counter < maxNumberOfPlans; counter++)
	{
		mDietplanAvailablePtr[counter] = true;
	}
	mNumberOfPlans = maxNumberOfPlans;
}


PlanManager::~PlanManager()
{
	
	
}


DietPlan * PlanManager::getDietplanPtr()const
{
	return mDietplanPtr;
}

bool * PlanManager::getDietplanFoundPtr()const
{
	return mDietplanAvailablePtr;
}

int PlanManager::getNumberofPlans()const
{
	return mNumberOfPlans;
}


/*I think that the mDietplanAvailablePtr = newDietPlanPtr should work.*/
void PlanManager::setDietplanPtr(DietPlan *newDietplanPtr)
{
	mDietplanPtr = newDietplanPtr;
}

void PlanManager::setDietplanAvailablePtr(bool *newDietPlanPtr)
{
	mDietplanAvailablePtr = newDietPlanPtr;
}

void PlanManager::setNumberOfPlans(int newDietPlan)
{
	mNumberOfPlans = newDietPlan;
}

void PlanManager::displayMenu()
{
	cout << "1. Load Weekly Diet Plan From File" << endl;
	cout << "2. Load Weekly Exercise Plan From File" << endl;
	cout << "3. Store Weekly Diet Plan To File" << endl;
	cout << "4. Store Weekly Exercise Plan To File" << endl;
	cout << "5. Display Weekly Diet Plan To Screen" << endl;
	cout << "6. Display Weekly Exercise Plan To Screen" << endl;
	cout << "7. Edit Daily Diet Plan" << endl;
	cout << "8. Edit Daily Exercise Plan" << endl;
	cout << "9. Exit." << endl;
	
}

int PlanManager::getMenuOption() const
{
	int option = 0;
	cin >> option;
	return option;
}
//This is where you are making the Dietplan account.
/*http://www.cplusplus.com/doc/tutorial/files/*/

void PlanManager::loadDailyDietPlan(DietPlan &DietPlan)
{
	ifstream DietplanFile;
	DietplanFile.open("TestingDietPlan.txt", std::ios::in);
	if (!DietplanFile)
	{
		cout << "Error cannot open txt file" << endl;
	}
	else
	{
				
		for (int i = 0; i < 7; i++)
		{
			DietplanFile >> WeeklyDiet[i];
		}
	}
	//for (int i = 0; i < 7; i++)
	//{
	//	//DietPlan(WeeklyDiet[i]);
	//	DietplanFile >> WeeklyDiet[i];
	//}
	//
}
//void PlanManager::LoadDietExercisePlan(fstream &fileStream, DietPlan &plan)
//{
//	fstream DietplanFile;
//	DietplanFile.open("TestingDietPlan.txt");
//	
//}

/*The create plan function will be used for both edit function and also the store functions. This will also change to get the days and information for that.*/
bool PlanManager::createPlan()
{
	ofstream DietplanFile;
	DietplanFile.open("TestingDietPlan.txt");
	int DietPlanNumber = 0;
	char cStringName[100];
	string name = "", dateCreated = "";
	bool success = true;
	
	cout << "Enter Diet Plan Number:";
	cin >> DietPlanNumber;
	cin.get();//this reads in the newline and discards the old one.

	cout << "Enter Name: ";
	cin.sync();
	cin.getline(cStringName, 100);
	name = cStringName;

	
	cout << "Enter Date:";
	cin >> dateCreated;

	
	
	/*This prints out one of the workouts onto the txt file.*/
	DietplanFile << "Number on the plan: " << DietPlanNumber << endl;
	DietplanFile << "Name on the plan: " << name << endl;
	DietplanFile << "Date in which it is created: " << dateCreated << endl;//this prints out the information that you insert into the insertion opperator.
	DietplanFile.close();
	/***********************************/
	return success;
}

/*Weekly Manager for editing Function*/
bool PlanManager::createWeeklyPlan()
{
	ofstream WeeklyplanFile;
	WeeklyplanFile.open("TestingWeeklyPlan.txt");
	int WeeklyPlanNumber = 0;
	string goal = "", goal2 = "", goal3 = "", goal4 = "", goal5 = "", goal6 = "", goal7 = "";
	int CaloriesGoal;/*Got to write the calories goal going to make it go below the other goal option.*/
	char stringgoal[100];
	char cStringName[100];
	string nameofday = "",  nameofday2 = "", nameofday3 = "", nameofday4 = "", nameofday5 = "", nameofday6 = "", nameofday7 = "";
	string dateCreated = "", dateCreated2 = "", dateCreated3 = "", dateCreated4 = "", dateCreated5 = "", dateCreated6 = "", dateCreated7 = "";
	bool success = true;
	/*****************************************************************************************************/	
	cin.get();//this reads in the newline and discards the old one.
	cout << "Plan Name: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday = cStringName;
		
	cout << "Goal: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal = stringgoal;
	
	cout << "Enter Date:";
	cin >> dateCreated;
/*********************************************************************/	
	cin.get();
	cout << "Plan Name2: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday2 = cStringName;

	cout << "Goal 2: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal2 = stringgoal;

	cout << "Enter Date 2: ";
	cin >> dateCreated2;
/***********************************************************************/
	cin.get();
	cout << "Plan Name 3: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday3 = cStringName;

	cout << "Goal 3: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal3 = stringgoal;

	cout << "Enter Date 3: ";
	cin >> dateCreated3;
/*************************************************************************/
	cin.get();
	cout << "Plan Name 4: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday4 = cStringName;

	cout << "Goal 4: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal4 = stringgoal;

	cout << "Enter Date 4: ";
	cin >> dateCreated4;
/***************************************************************************/
	cin.get();
	cout << "Plan Name 5: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday5 = cStringName;

	cout << "Goal 5: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal5 = stringgoal;

	cout << "Enter Date 5: ";
	cin >> dateCreated5;
/*****************************************************************************/
	cin.get();
	cout << "Plan Name 6: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday6 = cStringName;

	cout << "Goal 6: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal6 = stringgoal;

	cout << "Enter Date 6: ";
	cin >> dateCreated6;
/******************************************************************************/
	cin.get();
	cout << "Plan Name 7: ";
	cin.sync();
	cin.getline(cStringName, 100);
	nameofday7 = cStringName;

	cout << "Goal 7: ";
	cin.sync();
	cin.getline(stringgoal, 100);
	goal7 = stringgoal;

	cout << "Enter Date 7: ";
	cin >> dateCreated7;
	
	int counter = 0;
	/*This while loop throws up a exception error after I insert information into it.*/
	while ((mWeeklyplanAvailablePtr[counter] != true) && (counter < mNumberOfWeeklyPlans))
	{
		counter++;
	}
	if (mNumberOfWeeklyPlans <= counter)
	{
		cout << "Error: Could not create an Weekly Plan!" << endl;
		success = false;
	}
	else
	{
		mWeeklyplanPtr[counter].setNewworkout1(WeeklyPlanNumber);
		mWeeklyplanPtr[counter].setNameOfDay(nameofday);
		mWeeklyplanPtr[counter].setDateCreated1(dateCreated);
		mWeeklyplanPtr[counter] = false;
		
	}
	/*This prints out one of the workouts onto the txt file.*/
	//WeeklyplanFile << "Number on the plan: " << WeeklyPlanNumber << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday << endl;
	WeeklyplanFile << "Goal: " << goal << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated << endl;//this prints out the information that you insert into the insertion opperator.
	WeeklyplanFile << "" << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday2 << endl;
	WeeklyplanFile << "Goal: " << goal2 << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated2 << endl;
	WeeklyplanFile << "" << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday3 << endl;
	WeeklyplanFile << "Goal: " << goal3 << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated3 << endl;
	WeeklyplanFile << "" << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday4 << endl;
	WeeklyplanFile << "Goal: " << goal4 << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated4 << endl;
	WeeklyplanFile << "" << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday5 << endl;
	WeeklyplanFile << "Goal: " << goal5 << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated5 << endl;
	WeeklyplanFile << "" << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday6 << endl;
	WeeklyplanFile << "Goal: " << goal6 << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated6 << endl;
	WeeklyplanFile << "" << endl;
	WeeklyplanFile << "Name Of Plan: " << nameofday7 << endl;
	WeeklyplanFile << "Goal: " << goal7 << endl;
	WeeklyplanFile << "Date in which it is created: " << dateCreated7 << endl;
	WeeklyplanFile << "" << endl;
	WeeklyplanFile.close();
	/***********************************/
	return success;
}

/*Instead of using the delete operator to remove the previous information. Just use the fstr<<"file name" to overwrite the information.
//Delete is used in dynamic memory.*/
//bool PlanManager::deletePlan()
//{
//	
//	bool success = false;
//	int planNumber = 0;
//	int counter = 0;
//
//	counter = findPlan();
//
//	if ((counter < mNumberOfPlans) && (mDietplanAvailablePtr[counter] == false))//The account was found and will be deleted
//	{
//		success = true;
//		mDietplanAvailablePtr[counter] = true;
//		cout << "Plan Deleted!" << endl;
//		
//	}
//	
//	return success;
//}
/*Note: Updating the plan seems to be opening the file but it is not properly getting the information from the file. Check on that later.*/
/*NOTE: The update can open the txt file but it deletes the information inside the txt file.*/
/*Update plan like other functions will have a different name change with the weekly txt files.*/
bool PlanManager::updatePlan()
{
	ofstream DietplanFile;
	DietplanFile.open("TestingDietPlan.txt");
	bool success = false;
	string name = "", dateCreated = "";
	int counter = 0, option = 0;
	/*Insert the information that you can modify*/
	
	//counter = findPlan();

	/*Account is found time to delete it.*/
	if ((counter < mNumberOfPlans) && (mDietplanAvailablePtr[counter] == false))
	{
		success = true;

		cout << "1. Update Dietplan" << endl;
		cout << "2. Update Workout" << endl;

		cin >> option;

		switch (option)
		{
		case 1: cout << "Enter Name:";
			cin >> name;
			mDietplanPtr[counter].setName(name);
			break;

		
		}
		
	}
	DietplanFile.close();
	return success;
}
/***********************************************************************/
/*I looked at this website to help me figure out how to read in a file. 
http://www.cplusplus.com/doc/tutorial/files/
************************************************************************/
void PlanManager::displayPlan() const
{
	ifstream DisplayDietPlanFile("TestingDietPlan.txt");
	string line;
	//int counter = 0;
	//counter = findPlan();

	if (DisplayDietPlanFile.is_open())
	{
		while (getline(DisplayDietPlanFile,line))
		{
			cout << line << endl;
		}
	}
	
	
	DisplayDietPlanFile.close();
}
/*Weekly Plan Display function*/
void PlanManager::displayWeeklyPlan() const
{
	ifstream DisplayWeeklyPlanFile("TestingWeeklyPlan.txt");
	string line;
	if (DisplayWeeklyPlanFile.is_open())
	{
		while (getline(DisplayWeeklyPlanFile, line))
		{
			cout << line << endl;
		}
	}
	DisplayWeeklyPlanFile.close();
}



void PlanManager::runDietPlanApplication()
{
	int option = 0;
	bool status = true, success = true;

	cout << "Fitness Workout System" << endl;
	cout << "Made by Cougar Fischer" << endl;

	/*Leave the Create plan for now.*/
	do
	{
		displayMenu();
		option = getMenuOption();

		switch (option)
		{
		case 1: 
			break;

		case 2:  
			break;

		case 3: 
			if (success == false)
			{
				cout << "Error: Could not store Weekly Diet Plan!" << endl;
			}
			break;

		case 4: 
			if (success == false)
			{
				cout << "Error: Could not create Weekly Exercise Plan!" << endl;
			}
			break;

		case 5: displayPlan();
			if (success == false)
			{
				cout << "Error: Could Not Display The Plan!" << endl;
			} 
			break;
		case 6: 
			displayWeeklyPlan();
			if (success == false)
			{
				cout << "Error: Could not Display Weekly Exercise Plan!" << endl;
			}
			break;
		case 7: success = createPlan();
			if (success == false)
			{
				cout << "Error: Could Not Edit The Weekly Diet Plan!" << endl;
			}
			break;
		case 8: success = createWeeklyPlan();
		if (success == false)
		{
			cout << "Error: Could Not Edit Weekly Exercise Plan" << endl;
		}

		//case 8 will be updating the daily exercise plan. while case 7 is going to update the daily diet plan. They use the same function but they will be modifying two different text files.

		

		/*case 5: createPlan();
			break;*/
			
			
		case 9: status = false;
			break;
		
		//case 6:
		default: cout << "Error: Incorrect choice try again!" << endl;
			break;
		}
	}
	while (status != false);
}
