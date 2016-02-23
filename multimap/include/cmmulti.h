#ifndef _CMMULTI_H
#define _CMMULTI_H
#include <Interface.h>
#include <algorithm>
#include <map>

using namespace ContactManager;

/**
* template class for storing basic contact data structure.
*	this implementation uses list for storing contact data structure.
*	Advantage of list container
*	1.	random access is available.
*	2.	traversal is easy on either ends of the list.
*	3.	addition is constant time.
*	4.	vector contains only pointer to data structor.
*	5.  always in sorted order.
*/
template <typename T>
class ContactMap {
	private:
		typedef T*           	 			                        cpointer;
		typedef T&               			                        creference;
		typedef contact::tags_t  			                        dataType;	
		typename std::multimap<string, cpointer>::iterator 	        cm_iter;
		typename std::multimap<string, cpointer>::const_iterator 	ccm_iter;
        /*
         * name is used as key and container pointer as value.
         */
		std::multimap<string, cpointer> 		                    _cmultimap;
		uint32_t              				                        Size;
		string                				                        cname;
		uint64_t              				                        cnum;

	public:
		ContactMap() {
			_cmultimap.clear();
			Size = _cmultimap.size();
		}
		~ContactMap() {
			_cmultimap.clear();
			Size = _cmultimap.size();
		}
		void displayContact(cpointer c) {
			c->dump_contact_details();
		}
		void displayAll() {
			cout << "Total Number of contacts [" << Size << "]" << endl;
			for(auto i : _cmultimap) {
				displayContact(i.second);
			}
		}

		void addContact(string name, string email, uint64_t home, uint64_t office) {
			cpointer c = new T();
			c->contact_add(contact::NAME, &name);
			c->contact_add(contact::EMAIL, &email);
			c->contact_add(contact::H_NUM, &home);
			c->contact_add(contact::O_NUM, &office);
			_cmultimap.insert(::pair<string, cpointer>(name, c));
			Size = _cmultimap.size();
		}

		bool removeContact(string name) {
			cname.assign(name);
			cout << "Removing contact with name [" << name << "]" << endl;
            /**
             * this erases all occurances of cname.
             */
			_cmultimap.erase(cname);
			Size = _cmultimap.size();
		}

		bool removeContact(uint64_t num) {
			cnum = num;
			cout << "Removing contact with contact number [" << num << "]" << endl;
            /**
             * for removing elements using property other than key will require
             * traversing through whole list.
             */
			for(cm_iter = std::begin(_cmultimap); cm_iter != std::end(_cmultimap); ++cm_iter) {
				if(cm_iter != std::end(_cmultimap)) {
					if(((cm_iter->second)->getHomeNum() == cnum) || ((cm_iter->second)->getOffNum() == cnum)) {
						_cmultimap.erase(cm_iter);
					}
				}
			}
			Size = _cmultimap.size();
		}

		bool displayContact(string name) {
			cname.assign(name);
			cout << "Displaying contact with name [" << name << "]" << endl;
            /**
             * lower_bound() and upper_bound() provide the range of iterator
             * whose key values are not less than and not more than respectively.
             */
			for(cm_iter = _cmultimap.lower_bound(cname); cm_iter != _cmultimap.upper_bound(cname); ++cm_iter) {
				if(cm_iter != std::end(_cmultimap)) {
					displayContact(cm_iter->second);
				}
			}
		}

		bool displayContact(uint64_t num) {
			cnum = num;
			cout << "Displaying contact with contact number [" << num << "]" << endl;
			for(cm_iter = std::begin(_cmultimap); cm_iter != std::end(_cmultimap); ++cm_iter) {
				if(cm_iter != std::end(_cmultimap)) {
					if(((cm_iter->second)->getHomeNum() == cnum) || ((cm_iter->second)->getOffNum() == cnum)) {
						displayContact(cm_iter->second);
					}
				}
			}
		}
	
};

#endif
