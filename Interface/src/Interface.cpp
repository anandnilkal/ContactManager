#include <Interface.h>

using namespace std;

namespace ContactManager {
	contact::add(tags_t tag, string value) {
		switch(tag) {
			case NAME:
				_name.assign(value);
				break;

			case EMAIL:
				_email.assign(value);
				break;

			case H_NUM:
				_num_home.assign(value);
				break;

			case O_NUM:
				_num_office.assign(value);
				break;
		}
	}
}
