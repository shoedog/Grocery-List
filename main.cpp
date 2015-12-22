/******************************************************************************
 ** Program Filename: items.cpp 
 ** Author: Wesley Jinks
 ** Date: 1/28/2015
 ** Description: This is the implementation file for the program.
 ** Input: Takes information for items and prompts to display, cart, items,
		and choices to edit items.
 ** Output: Cart contents of items, options to edit, and prompts
 * ***************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "items.hpp"

void addItem( Item &, std::ofstream &, std::string );
void editList( std::fstream &, std::string );
void readList( std::ifstream &, std::string );
void editName( std::string &);
void editPrice(std::string & );
void editUnit( std::string & );
void editQuantity(std::string & );
void deleteItem( std::string & );

int main()
{
	Item item1;
	std::vector<Item> cart;
	std::ofstream outList;  //Output file to hold grocery list
	std::ifstream inList;   //Input file of grocery list
	std::fstream edList;  //File edit stream
	std::string fileName =  "gList.txt";   //Holds the filename
	int choice;

	//Testing output overload and copy constructor
	//std::cout << "Item 1: " << item1 << "\n";
	//std::cout << "Item 2: " << item2 << "\n";
	//item1 = item2;
	//std::cout << "Item 1: " << item1 << "\n";
	//std::cout << "Item 2: " << item2 << "\n";

//Testing	
//	outList.open( fileName.c_str(), std::ios::app );
//	addItem( item1, outList, fileName );
//	std::cout << item1;
//	addItem( item1, outList, fileName );
//	std::cout << item1;
//	outList.close(); 
//	readList( inList, fileName );
//	editList( edList, fileName );
	
	do
	{
		std::cout << "\n    Grocery List Menu     "
				  << "\n  1. Add Item " << "\n  2. View List "
				  << "\n  3. Edit List or Remove Item " << "\n  4. Save and Exit "
				  << "\n \n Enter your choice from the menu ( 1-4 ): ";
		std::cin >> choice;

		switch( choice )
		{
			case 1:
				addItem( item1, outList, fileName ); 
				break;
			case 2:
				readList( inList, fileName );
				break;
			case 3:
				editList( edList, fileName );
				break;
			case 4:
				std::cout << "Exiting \n";
				break;
			default:
				std::cout << "You did not enter a valid choice between 1 and 4. Try again. \n ";
				break;
		}
	}while( choice != 4 );

	return 0;
}

void addItem( Item &itemX, std::ofstream &outF, std::string fileName )
{
	std::string input;
	int num;
	float cost;

	outF.open( fileName.c_str(), std::ios::app );
	if( outF.fail() )
		std::cout << "Error: Cannot Open File \n";
	else
	{
		std::cout << "\n Enter the name of your item: ";
		std::cin.clear();
		std::cin.ignore(); 
		std::getline( std::cin, input );
		itemX.setItemName( input );

		std::cout << "Enter the type of units of your item(eg oz, box, lbs, etc): ";
		std::getline( std::cin, input );
		itemX.setUnitType( input );

		std::cout << "Enter how many of the units you would like to buy: ";
		std::cin >> num;
		itemX.setNumToBuy( num );

		std::cout << "Enter the cost per unit: ";
		std::cin >> cost;
		itemX.setPrice( cost ); 	 
	
		outF << itemX;
		outF.close();
	}
}

void editList( std::fstream &editF, std::string fileName )
{
	std::string name;  //name of item to edit
	std::string input; //variable needed to read file
	int choice;        //menu option
//	std::string newList;
	std::string gList = " ";
						
	editF.open( fileName.c_str(), std::ios::in | std::ios::out );

	if( editF.fail() )
		std::cout << "Error: Cannot Open File \n";
	else
	{
		while( !editF.eof() )
		{
			getline( editF, input, '%' );
			gList.append( input );
		}
	
		editF.clear();
		editF.close();
		editF.open( fileName.c_str(), std::ios::out | std::ios::trunc);

			std::cout << "\n Options to Edit List: \n" << "   1. Edit Name of Item \n"
					  << "   2. Edit Price of Item \n" << "   3. Edit Quantity of Item \n"
					  << "   4. Edit Unit type of Item \n" << "   5. Delete Item \n";
//					  << "   6. Return to Main Menu.  \n";
			std::cout << "   Enter choice (1 - 5): ";
			std::cin >> choice;

			switch( choice )
			{
				case 1:
					editName( gList );
					break;
				case 2:
					editPrice( gList );
					break;
				case 3:
					editQuantity( gList );
					break;
				case 4:
					editUnit( gList );		
					break;
				case 5:
					deleteItem( gList );
					break;
//				case 6:
//					std::cout << "Returning to the main menu. \n";
//					break;
				default:
					std::cout << "You did not enter a valid choice. Options are 1 - 6 in the menu. ";
			}

//		std::cout << "glist: " << gList;
//		std::cout << "\n \n copy list";
		editF << gList;
		gList.clear();
		editF.close();
	}
}

void editName( std::string &list )
{
	std::string input;
	std::string name;
	std::string items = list;

	std::cout << "Enter the name of the Item you would like to edit: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline( std::cin, name );

	int length = name.length();
	std::size_t found = items.find( name, 0 );

	std::cout << "Length: " << length << " Found: " << found;
	std::cout << "What would you like to change the name to? "; 
	std::cin.clear();
	std::getline( std::cin, input );
//Test	std::cout << items;
//Test	std::cout << "Found at: " << found << std::endl;
	items.erase( found, length );
	items.insert( found, input );

	list = items;
//	list.clear();
//	list.push_back( items );
//Test	std::cout << items;
}

void editPrice( std::string &list )
{
	std::string input;
	std::string name;
	std::string items = list;
	std::string currentPrice;
	std::string newPrice;
	float price;

	std::cout << "Enter the name of the Item you would like to edit: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline( std::cin, name );

	size_t foundName = items.find( name, 0 );
	size_t startPos = items.find( "$", foundName );
	size_t endPos = items.find( " ", startPos );
	
	currentPrice = items.substr( startPos + 1, endPos - startPos );
	std::cout << "The current price is $" << currentPrice << "\n Enter the new price: "; 
	std::cin >> price;
	std::stringstream ss ( std::stringstream::in | std::stringstream::out );
	ss << price;
	newPrice = ss.str();

	items.erase( startPos + 1, endPos - (startPos + 1) );
	items.insert( startPos + 1, newPrice );

	list = items;
//TEST	std::cout << items;
}

void editUnit( std::string &list )
{
	std::string items = list;
	std::string input;
	std::string name;
	std::string unit;
	std::string currentUnit;

	std::cout << "Enter the name of the Item you would like to edit: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline( std::cin, name );

	size_t foundName = items.find( name, 0 );
	size_t startPos = items.find( "per", foundName );
	size_t endPos = items.find( ".", startPos );
	currentUnit = items.substr( startPos + 4, endPos -( startPos + 4 ) );

	std::cout << "The current units are: " << currentUnit << ". \n";
	std::cout << "What would you like to change the units to? "; 
	std::cin.clear();
	std::getline( std::cin, input );
//Test	std::cout << items;
//Test	std::cout << "Found at: " << found << std::endl;
	items.erase( startPos + 4, endPos - (startPos + 4) );
	items.insert( startPos + 4, input );

	startPos = items.find( currentUnit, currentUnit.length() );
	items.erase( startPos, currentUnit.length() );
	items.insert( startPos, input );

	list = items;
//Test	std::cout << items;
}

void editQuantity( std::string &list )
{
	std::string input = list;
	std::string name;
	std::string items;
	std::string currentQ;
	std::string newQ;
	int quantity;
	
	std::cout << "Enter the name of the Item you would like to edit: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline( std::cin, name );

	size_t foundName = items.find( name, 0 );
	size_t startPos = items.find( "Buy", foundName );
	size_t endPos = items.find( " ", startPos );
	
	currentQ = items.substr( startPos + 3, endPos-startPos );
	std::cout << "The current quantity is" << currentQ << "\n Enter the new quantity: "; 
	std::cin >> quantity;
	std::stringstream ss ( std::stringstream::in | std::stringstream::out );
	ss << quantity;
	newQ = ss.str();

	items.erase( startPos + 4, endPos - startPos - 2  );
	items.insert( startPos + 4, newQ );

	list = items;	
//Test	std::cout << items;
}

void deleteItem( std::string &list )
{
//Test	std::cout << "List1: " << list;
	std::string items = list;
	std::string name;
	std::string currentItem;

//Test	std::cout << "Items1: " << items;
	
	std::cout << "Enter the name of the Item you would like to delete: ";
	std::cin.clear();
	std::cin.ignore();
	std::getline( std::cin, name );

	size_t startPos = items.find( name, 0 );
	size_t endPos = items.find( "Name", startPos );
	currentItem = items.substr( startPos - 6, endPos - (startPos - 5) );

	std::cout << "The item to be deleted is: \n " << currentItem << "\n";
	items.erase( startPos - 6, endPos - (startPos - 5) );

//TEst	std::cout << "List: " << list;

	list = items;

//Test	std::cout << "\n Items: " << items;
//	std::cout << items;
}

void readList( std::ifstream &inF, std::string fileName )
{
	std::string input; //variable needed to read file

	inF.open( fileName.c_str() );
	if( !inF )
		std::cout << "Error: File Open \n";
	else
	{
		getline( inF, input, '%' );
		while( !inF.fail() )
		{
			std::cout << input;
			getline( inF, input, '%' );
		}

		inF.close();
	}	
}

/*
void getTotalCost( std::ifstream &inF, std::string fileName )
{
	std::string input; //variable needed to read file
	std::string totalPrice; //gets total price from file

	inF.open( fileName.c_str() );
	if( !inF )
		std::cout << "Error: File Open \n";
	else
	{
		while( !inF.eof() )
		{
			getline( inF, input, '%' );
			totalPrice.append(input)
		}

		
	}

}*/

