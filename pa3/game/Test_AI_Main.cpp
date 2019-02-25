#include "Test_AI.cpp"


int main()
{
	Test_AI* test = new Test_AI();
	for(unsigned int i = 1; i < test->rand_stack_2.size(); ++i) //now run through each test stack with all difficulties
		test->run_test(test->rand_stack_2, i);
    for(unsigned int i = 1; i < test->rand_stack_3.size(); ++i)
		test->run_test(test->rand_stack_3, i);
	for(unsigned int i = 1; i < test->rand_stack_4.size(); ++i)
		test->run_test(test->rand_stack_4, i);
	for(unsigned int i = 1; i < test->rand_stack_5.size(); ++i)
		test->run_test(test->rand_stack_5, i);
	for(unsigned int i = 1; i < test->rand_stack_6.size(); ++i)
		test->run_test(test->rand_stack_6, i);
	for(unsigned int i = 1; i < test->rand_stack_7.size(); ++i)
		test->run_test(test->rand_stack_7, i);
	for(unsigned int i = 1; i < test->rand_stack_8.size(); ++i)
		test->run_test(test->rand_stack_8, i);
	for(unsigned int i = 1; i < test->rand_stack_9.size(); ++i)
		test->run_test(test->rand_stack_9, i);
	test->all_valid_moves();
	test->all_solutions_found();
	test->all_lt_150();
	if(test->all_tests_passed())
		cout << "WELL DONE ALL TEST PASSED" << endl;
	else
		cout << "OH NOOOOOOOOOOO YOU FAILED A TEEEEEEEEEEEEEEEEST" << endl;
	delete test;
}