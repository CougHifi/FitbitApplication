#include "PlanManager.h"

DietplanManager::DietplanManager()
{
	mDietplanPtr = new DietPlan[1000];
	mDietplanAvailablePtr = new bool[1000];

	for (int counter = 0; counter < 1000; counter++)
	{
		mDietplanAvailablePtr[counter] = true;
	}
	mNumberOfPlans = 1000;
}

DietplanManager::DietplanManager(int maxNumberOfPlans)
{
	mDietplanPtr = new DietPlan[maxNumberOfPlans];
	mDietplanAvailablePtr = new bool[maxNumberOfPlans];

	for (int counter = 0; counter < maxNumberOfPlans; counter++)
	{
		mDietplanAvailablePtr[counter] = true;
	}
	mNumberOfPlans = maxNumberOfPlans;
}

DietplanManager::~DietplanManager()
{
	/*I do need to use these right now.*/
	/*delete[]mDietplanPtr;
	delete[]mDietplanAvailablePtr;*/
	
}

DietPlan * DietplanManager::getDietplanPtr()const
{
	return mDietplanPtr;
}

bool * DietplanManager::getDietplanFoundPtr()const
{
	return mDietplanAvailablePtr;
}

int DietplanManager::getNumberofPlans()const
{
	return mNumberOfPlans;
}


/*I think that the mDietplanAvailablePtr = newDietPlanPtr should work.*/
void DietplanManager::setDietplanPtr(DietPlan *newDietplanPtr)
{
	mDietplanPtr = newDietplanPtr;
}

void DietplanManager::setDietplanAvailablePtr(bool *newDietPlanPtr)
{
	mDietplanAvailablePtr = newDietPlanPtr;
}

void DietplanManager::setNumberOfPlans(int newDietPlan)
{
	mNumberOfPlans = newDietPlan;
}

void DietplanManager::displayMenu()
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

int DietplanManager::getMenuOption() const
{
	int option = 0;
	cin >> option;
	return option;
}
//This is where you are making the Dietplan account.
/*http://www.cplusplus.com/doc/tutorial/files/*/
/*The create plan function will be used for both edit function and also the store functions. This will also change to get the days and information for that.*/
bool DietplanManager::createPlan()
{
	ofstream DietplanFile;
	DietplanFile.open("TestingDietPlan.txt");
	int DietPlanNumber = 0;
	double calories = 0.0;
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

	int counter = 0;
	while ((mDietplanAvailablePtr[counter] != true) && (counter < mNumberOfPlans))
	{
		counter++;
	}
	if (mNumberOfPlans <= counter)
	{
		cout << "Error: Could not create an account!" << endl;
		success = false;
	}
	else
	{
		mDietplanPtr[counter].setNewworkout(DietPlanNumber);
		mDietplanPtr[counter].setName(name);
		mDietplanPtr[counter].setDatecreated(dateCreated);
		mDietplanPtr[counter] = false;
		//DietplanFile << &mNumberOfPlans;
	}
	/*This prints out one of the workouts onto the txt file.*/
	DietplanFile << "Number on the plan: " << DietPlanNumber << endl;
	DietplanFile << "Name on the plan: " << name << endl;
	DietplanFile << "Date in which it is created: " << dateCreated << endl;//this prints out the information that you insert into the insertion opperator.
	DietplanFile.close();
	/***********************************/
	return success;
}

/*Instead of using the delete operator to remove the previous information. Just use the fstr<<"file name" to overwrite the information.
Delete is used in dynamic memory.*/
bool DietplanManager::deletePlan()
{
	
	bool success = false;
	int planNumber = 0;
	int counter = 0;

	counter = findPlan();

	if ((counter < mNumberOfPlans) && (mDietplanAvailablePtr[counter] == false))//The account was found and will be deleted
	{
		success = true;
		mDietplanAvailablePtr[counter] = true;
		cout << "Plan Deleted!" << endl;
		
	}
	
	return success;
}
/*Note: Updating the plan seems to be opening the file but it is not properly getting the information from the file. Check on that later.*/
/*NOTE: The update can open the txt file but it deletes the information inside the txt file.*/
/*Update plan like other functions will have a different name change with the weekly txt files.*/
bool DietplanManager::updatePlan()
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
void DietplanManager::displayPlan() const
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
	
	//if ((counter < mNumberOfPlans) && (mDietplanAvailablePtr[counter] == false))/*the account has been found*/
	//{
	//	mDietplanPtr[counter].printDietplan();
	//	cout << line << '\n'<<endl;

	//}
	//else
	//{
	//	cout << "Error: The plan does not exist" << endl;
	//}
	DisplayDietPlanFile.close();
}

int DietplanManager::findPlan() const
{
	
	int planNumber = 0;

	cout << "Enter Plan Number: ";
	cin >> planNumber;

	int counter = 0;
	for (counter = 0; ((counter < mNumberOfPlans) && (mDietplanPtr[counter].getNewworkout() != planNumber)); counter++)
	{

	}
	
	return counter;
}

void DietplanManager::runDietPlanApplication()
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
		case 1: success = createPlan();
			if (success == false)
			{
				cout << "Error: Could not create Plan!" << endl;
			}
			break;

		case 2: success = deletePlan();
			if (success == false)
			{
				cout << "Error: Could not delete Plan!" << endl;
			}
			break;

		case 5: displayPlan();
			if (success == false)
			{
				cout << "Error: Could Not Display The Plan!" << endl;
			}
			break;
		case 7: success = updatePlan();
			if (success == false)
			{
				cout << "Error: Could Not Update The Plan!" << endl;
			}
			break;

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
