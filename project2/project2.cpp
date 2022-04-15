#include "OrgTree.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// This is not the complete test harness/driver for project 2, but
// is a good starting point.  You should test your project completely
// by adding additional tests for each item in the grading rubric!

int main() {
	OrgTree o1, o2, o3;

	cout << "------Testing the addRoot function and Print Function-------" << endl;
	// Adding roots should make a linear tree
	/*o1.addRoot("R1", "R1");
	o1.addRoot("R2", "R2");
	o1.addRoot("R3", "R3");
	o1.printSubTreeInOrder();*/
	cout <<"--------Test 1 for addRoot, empty Tree--------" << endl;
	o1.addRoot("President, ", "George Orwell ");
	o1.printSubTree(o1.getRoot());
	cout << endl;
	cout << "--------Test 2 for addRoot, populated tree--------" << endl;
	o1.addRoot("Co-CEO, ", "Billy Joel ");
	o1.printSubTreeInOrder();
	cout << endl;
	cout << "--------- Testing print function on an empty tree ------" << endl;
	o3.printSubTreeInOrder();
	cout << endl;
	cout << "--------Testing getSize() function on a populated tree---------" << endl;
	cout << o1.getSize() << endl;
	cout << "--------Testing getSize() function on an empty tree---------" << endl;
	cout << o3.getSize() << endl;
	cout << "--------Testing getRoot() function on a populated tree --------" << endl;
	cout << o1.getRoot() << endl;
	cout << "--------Testing getRoot() function on an empty tree---------" << endl;
	cout << o3.getRoot() << endl;
	cout << "--------Testing find() function on a title that is in the tree----------" << endl;
		cout << o1.find("Co-CEO") << endl;
		cout << "--------Testing hire() function---------" << endl;
		o1.hire(o1.getRoot(), "VP Sales, ", " Mark Zuckerberg");
		o1.hire(o1.getRoot(), "Marking Expert, ", "Marry Shell");
		o1.hire(o1.getRoot(), "Accounting Expert ", " Phllip Road");
		o1.printSubTree(o1.getRoot());
		cout << endl;
		cout << "-----------Testing LeftMostChild() when the node as children---------" << endl;
		cout << o1.leftmostChild(o1.getRoot()) << endl;
		cout << "----------Testing LeftMostChild() when the node as no childern--------" << endl;
		cout << o1.leftmostChild(o1.getRoot()) << endl; 
		cout << "-----------Testing Rightsbiling() when the node has one-----------" << endl;
		cout << o1.rightSibling(o1.getRoot()) << endl;
		
		cout << "----------Testing Fire() function on pop tree---------" << endl;
		cout << o1.fire("Accounting Expert") << endl;
		cout << "-------Testing fire on root------" << endl;
		cout << o1.fire("Co-CEO") << endl;
		cout << "-------Testing Fire on title that does not exist -----" << endl;
		cout << o1.fire("Coder") << endl;
		//cout << o1.fire("Co-CEO") << endl;
		cout << "----- Testing F/O -----------" << endl;
		
		o1.write("output.txt");
	cout << o1.read("output.txt") << endl;
	 //printSubTree from root

	
	////add two children to root

	//o1.hire(o1.getRoot(), "R3C1", "R3C1");
	//o1.hire(o1.getRoot(), "R3C2", "R3C2");
	//o1.printSubTreeInOrder();
	//cout << "Find starts: ";
	// o1.hire(o1.find("R3C1"), "R3C1C1", "R3C1C1");//test find on leaf node and hire to it
	// o1.printSubTreeInOrder();

	//cout << o1.getSize() << endl;
	//o1.printSubTree(o1.getRoot()); //printSubTree from root


	////o1.fire("R3C1"); //fire an internal node
	//cout << o1.getSize() << endl;
	//o1.printSubTree(o1.getRoot());

	//// Write out a tree and read it back in to a new tree, then print
	//o1.write("output.txt");
	//o2.read("output.txt");
	//o2.printSubTree(o2.getRoot()); //printSubTree from root

	system("PAUSE");
	return 0;

}
