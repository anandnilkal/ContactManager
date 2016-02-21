#ifndef _CMARRAY_H
#define _CMARRAY_H

#include <Interface.h>
#include <vector>
#include <algorithm>

using namespace ContactManager;

/**
* template class for storing basic contact data structure.
*	this implementation uses list for storing contact data structure.
*	Advantage of list container
*	1.	memory efficient for smaller size of contacts.
*	2.	traversal is easy on either ends of the list.
*	3.	addition is constant time.
*	4.	vector contains only pointer to data structor.
*	Disadvantages
*	1.	no random access.
*	2.	find and deletation complexity is O(n).
*/
template <typename T>
class ContactVector {
	private:
		typedef T*      	 			        cpointer;
		typedef T&               			    creference;
		typedef contact::tags_t  			    dataType;	
		typename std::vector<T*>::iterator 		cv_iter;
		typename std::vector<T*>::const_iterator 	ccv_iter;
		std::vector<cpointer> 				    _cvector;
		uint32_t              				    Size;
		string                				    cname;
		uint64_t              				    cnum;
	public:
		ContactVector() {
			_cvector.clear();
			Size = _cvector.size();
		}
		~ContactVector() {
			_cvector.clear();
			Size = _cvector.size();
		}
		void displayContact(cpointer c) {
			c->dump_contact_details();
		}
		void displayAll() {
			cout << "Total Number of contacts [" << Size << "]" << endl;
			/**
			* using lambda function for traversing complete list.
			*/
			std::find_if(std::begin(_cvector), std::end(_cvector),
				[&](cpointer c) { displayContact(c); return false;});
		}

		void addContact(string name, string email, uint64_t home, uint64_t office) {
			cpointer c = new contact();
			/**
			* overloaded constructor could be called.
			*	used individual property update mechanism to show capability.
			*/
			c->contact_add(contact::NAME, &name);
			c->contact_add(contact::EMAIL, &email);
			c->contact_add(contact::H_NUM, &home);
			c->contact_add(contact::O_NUM, &office);
			_cvector.push_back(c);
			Size = _cvector.size();
		}

		bool removeContact(string name) {
			cname.assign(name);
			cout << "Removing contact with name [" << name << "]" << endl;
			_cvector.erase(std::remove_if(std::begin(_cvector), std::end(_cvector),
				[&](cpointer c) { return (cname.compare(c->_name) == 0);}), 
					std::end(_cvector));
			Size = _cvector.size();
		}

		bool removeContact(uint64_t num) {
			cnum = num;
			cout << "Removing contact with contact number [" << num << "]" << endl;
			/**
			* removes entries which matches the unary predicate function.
			*	unary predicate function is applied on all elements.
			*	all occurances of the entries matching the unary predicate will be erased.
			*/
			_cvector.erase(std::remove_if(std::begin(_cvector), std::end(_cvector),
				[&](cpointer c) { return ((cnum == (c->_num_home)) 
					|| (cnum == (c->_num_office)));}), std::end(_cvector));
			Size = _cvector.size();
		}

		bool displayContact(string name) {
			cname.assign(name);
			cout << "Displaying contact with name [" << name << "]" << endl;
			cv_iter = std::begin(_cvector);
			/**
			* find_if interface provides only first occurance. For subsequent occurances
			*	loop is run from next entry in the list.
			*/
			while(cv_iter != std::end(_cvector)) {
				cv_iter = std::find_if(cv_iter, std::end(_cvector),
						[&](cpointer c) { return (cname.compare(c->_name) == 0);});
				if(cv_iter != std::end(_cvector)) {
					displayContact(*cv_iter);
					cv_iter++;
				}
			}
		}

		bool displayContact(uint64_t num) {
			cnum = num;
			cout << "Displaying contact with contact number [" << num << "]" << endl;
			cv_iter = std::begin(_cvector);
			while(cv_iter != std::end(_cvector)) {
				cv_iter = std::find_if(cv_iter, std::end(_cvector),
					[&](cpointer c) { return ((cnum == (c->_num_home)) 
						|| (cnum == (c->_num_office)));});
				if(cv_iter != std::end(_cvector)) {
					displayContact(*cv_iter);
					cv_iter++;
				}
			}
		}

};

#endif
