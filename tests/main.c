#include "libtest/coordtest.h"
#include "libtest/mattest.h"

// keeps in track of the points allocated in the
// heap

static int freeMemory(int count, ...) {
	/*summary: free the memory of any datatype
	note: wrong usage result to unknown behaviour
	pass the count for correct usage
	args:
		int count -> count of the items

		matrix *m;
		cartesiancoord* c;
		polarcoord* c;
	*/
}


int main(void)
{
    int number_failed;
	Suite *s;
	Suite *m;
    SRunner *sr;

	s = coordinate_suite();
	m = matrix_suite();

	sr = srunner_create(s);
    srunner_add_suite(sr, m);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);

    /*freeing the resources*/
    srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
