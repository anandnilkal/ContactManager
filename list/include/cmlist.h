#ifndef _CMLIST_H
#define _CMLIST_H
#include <Interface.h>
#include <algorithm>
#include <list>

using namespace ContactManager;

/**
* template class for storing basic contact data structure.
*	this implementation uses list for storing contact data structure.
*	Advantage of list container
*	1.	memory efficient.
*	2.	traversal is easy on either ends of the list.
*	3.	addition is constant time.
*	4.	list contains only pointer to data structor.
*	Disadvantages
*	1.	no random access.
*	2.	find and deletation complexity is O(n).
*/
template <typename T>
class ContactList {
	private:
		typedef T*          	 			    cpointer;
		typedef T&               			    creference;
		typedef contact::tags_t  			    dataType;	
		typename std::list<T*>::iterator 	    cl_iter;
		typename std::list<T*>::const_iterator 	ccl_iter;
		std::list<cpointer> 				    _clist;
		uint32_t              				    Size;
		string                				    cname;
		uint64_t              				    cnum;

	public:
		ContactList() {
			_clist.clear();
			Size = _clist.size();
		}
		~ContactList() {
			_clist.clear();
			Size = _clist.size();
		}
		void displayContact(cpointer c) {
			c->dump_contact_details();
		}
		void displayAll() {
			cout << "Total Number of contacts [" << Size << "]" << endl;
			/**
			* using lambda function for traversing complete list.
			*/
			std::find_if(std::begin(_clist), std::end(_clist),
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
			_clist.push_back(c);
			Size = _clist.size();
		}

		bool removeContact(string name) {
			cname.assign(name);
			cout << "Removing contact with name [" << name << "]" << endl;
			/**
			* removes entries which matches the unary predicate function.
			*	unary predicate function is applied on all elements.
			*	all occurances of the entries matching the unary predicate will be erased.
			*/
			_clist.erase(std::remove_if(std::begin(_clist), std::end(_clist),
				[&](cpointer c) { return (cname.compare(c->_name) == 0);}), 
					std::end(_clist));
			Size = _clist.size();
		}

		bool removeContact(uint64_t num) {
			cnum = num;
			cout << "Removing contact with contact number [" << num << "]" << endl;
			_clist.erase(std::remove_if(std::begin(_clist), std::end(_clist),
				[&](cpointer c) { return ((cnum == (c->_num_home)) 
					|| (cnum == (c->_num_office)));}), std::end(_clist));
			Size = _clist.size();
		}

		bool displayContact(string name) {
			cname.assign(name);
			cout << "Displaying contact with name [" << name << "]" << endl;
			cl_iter = std::begin(_clist);
			/**
			* find_if interface provides only first occurance. For subsequent occurances
			*	loop is run from next entry in the list.
			*/
			while(cl_iter != std::end(_clist)) {
				cl_iter = std::find_if(cl_iter, std::end(_clist),
						[&](cpointer c) { return (cname.compare(c->_name) == 0);});
				if(cl_iter != std::end(_clist)) {
					displayContact(*cl_iter);
					cl_iter++;
				}
			}
		}

		bool displayContact(uint64_t num) {
			cnum = num;
			cout << "Displaying contact with contact number [" << num << "]" << endl;
			cl_iter = std::begin(_clist);
			while(cl_iter != std::end(_clist)) {
				cl_iter = std::find_if(cl_iter, std::end(_clist),
					[&](cpointer c) { return ((cnum == (c->_num_home)) 
						|| (cnum == (c->_num_office)));});
				if(cl_iter != std::end(_clist)) {
					displayContact(*cl_iter);
					cl_iter++;
				}
			}
		}
	
};

#endif
