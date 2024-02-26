#include "sha_ptr.h"

sha_ptr<int> make_sha(int twsk) {
	return sha_ptr<int>(twsk);
}
