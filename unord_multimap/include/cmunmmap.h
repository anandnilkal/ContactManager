#ifndef _UNORDERED_MMAP_H
#define _UNORDERED_MMAP_H

#include <functional>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace ContactManager;

template <typename T>
class ContactUMap {
    private:
		typedef T*          	 			    cpointer;
		typedef T&               			    creference;
		typedef contact::tags_t  			    dataType;	
            struct _hash_function {
                std::size_t operator()(const std::string s) const {
                    return ((std::hash<std::string>()(s)) % 5);
                }
            };

            struct _eq_function {
                bool operator()(const std::string& lhs, const std::string& rhs) const {
                    return (lhs).compare(rhs) == 0;
                }
            };
        typedef _hash_function                  myHash;
        typedef _eq_function                    myEq;
		typename std::unordered_multimap<string, cpointer, myHash, myEq>     _cumap;
		typename std::unordered_multimap<string, cpointer, myHash, myEq>::iterator     cm_iter;
        std::map<uint64_t, string>              _numMap;
        std::map<uint64_t, string>::iterator    _numMapIt;
		uint32_t              				    Size;
		string                				    cname;
		uint64_t              				    cnum;

    public:
        ContactUMap() {
        }
        ~ContactUMap() {
            _cumap.clear();
        }
		void displayContact(cpointer c) {
			c->dump_contact_details();
		}
		void displayAll() {
			cout << "Total Number of contacts [" << Size << "]" << endl;
			for(auto i : _cumap) {
				displayContact(i.second);
			}
		}

		void addContact(string name, string email, uint64_t home, uint64_t office) {
			cpointer c = new contact();
			c->contact_add(contact::NAME, &name);
			c->contact_add(contact::EMAIL, &email);
			c->contact_add(contact::H_NUM, &home);
			c->contact_add(contact::O_NUM, &office);
			_cumap.insert(::pair<string, cpointer>(name, c));
            _numMap.insert(::pair<uint64_t, string>(home, name));
            _numMap.insert(::pair<uint64_t, string>(office, name));
			Size = _cumap.size();
		}

		bool removeContact(string name) {
			cname.assign(name);
			cout << "Removing contact with name [" << name << "]" << endl;
            /**
             * this erases all occurances of cname.
             */
			_cumap.erase(cname);
			Size = _cumap.size();
		}

		bool removeContact(uint64_t num) {
			cnum = num;
			cout << "Removing contact with contact number [" << num << "]" << endl;
            /**
             * for removing elements using property other than key will require
             * traversing through whole list.
             */
            _numMapIt = _numMap.find(num);
            if(_numMapIt != std::end(_numMap)) {
                _cumap.erase(_numMapIt->second);
            }
			Size = _cumap.size();
		}

		bool displayContact(string name) {
			cname.assign(name);
			cout << "Displaying contact with name [" << name << "]" << endl;
            cout << "load factor [" << _cumap.load_factor() << "]" << endl;
            cout << "bucket count [" << _cumap.bucket_count() << "]" << endl;
            auto bucket = _cumap.bucket(name);
            /**
             * whose key values are not less than and not more than respectively.
             */
			for(auto cm_iter = _cumap.cbegin(bucket); cm_iter != _cumap.cend(bucket); ++cm_iter) {
                displayContact(cm_iter->second);
			}
		}

		bool displayContact(uint64_t num) {
			cnum = num;
			cout << "Displaying contact with contact number [" << num << "]" << endl;
            _numMapIt = _numMap.find(num);
            if(_numMapIt != std::end(_numMap)) {
                displayContact(_numMapIt->second);
            }
		}
};

#endif
